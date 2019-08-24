import pathlib
import socket
import sys
from multiprocessing import Process

import cloudpickle

from lambdastream.aws.lambda_handler import operator_handler
from lambdastream.aws.utils import wait_for_s3_object, read_from_s3, write_to_s3, synchronize_operators
from lambdastream.executors.executor import Executor, executor
from lambdastream.utils import random_string


def dummy_handler(event, context):
    pathlib.Path('logs').mkdir(parents=True, exist_ok=True)
    sys.stdout = open('logs/' + event.get('stream_operator') + ".out", "a", buffering=1)
    sys.stderr = open('logs/' + event.get('stream_operator') + ".err", "a", buffering=1)
    return operator_handler(event, context)


class DummyLambda(object):
    def __init__(self, operator, host, path_prefix):
        self.operator = operator
        self.host = host
        self.path_prefix = path_prefix
        self.input_path = path_prefix + operator.operator_id + '.in'
        self.output_path = path_prefix + operator.operator_id + '.out'
        self.handle = None
        self.throughput = None
        self.latency = None
        self.read_latency = None
        self.write_latency = None

    def start(self):
        pickled = cloudpickle.dumps(self.operator)
        print('Writing pickled operator for {} to S3 ({} bytes)...'.format(self.input_path, len(pickled)))
        write_to_s3(self.input_path, pickled)
        e = dict(stream_operator=self.operator.operator_id, host=self.host, path_prefix=self.path_prefix)
        print('Invoking aws with payload: {}...'.format(e))
        self.handle = Process(target=dummy_handler, args=(e, None,))
        self.handle.start()

    def join(self):
        wait_for_s3_object(self.output_path)
        self.throughput, self.latency, self.read_latency, self.write_latency = cloudpickle.loads(
            read_from_s3(self.output_path))


@executor('dummy_lambda')
class DummyLambdaExecutor(Executor):
    def __init__(self, **kwargs):
        super(DummyLambdaExecutor, self).__init__(**kwargs)
        self.host = kwargs.get('sync_host', socket.gethostname())

    def exec(self, dag):
        sync_worker = Process(target=synchronize_operators, args=(self.host, sum(map(len, dag))))
        sync_worker.start()
        lambdas = []
        num_stages = len(dag)
        path_prefix = random_string() + '/'
        for i in range(num_stages):
            stage = dag.pop()
            for operator in stage:
                lambda_handle = DummyLambda(operator, self.host, path_prefix)
                lambdas.append(lambda_handle)
                lambda_handle.start()

        print('Invoked {} lambdas, synchronizing execution...'.format(len(lambdas)))
        sync_worker.join()
        for l in lambdas:
            l.join()
        print('All lambdas completed')
        return {l.operator.operator_id: l.throughput for l in lambdas}, \
               {l.operator.operator_id: l.latency for l in lambdas if l.latency is not None}, \
               {l.operator.operator_id: l.read_latency for l in lambdas if l.read_latency is not None}, \
               {l.operator.operator_id: l.write_latency for l in lambdas if l.write_latency is not None}
