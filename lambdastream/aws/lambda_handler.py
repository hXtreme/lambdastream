import socket

from cloudpickle import cloudpickle

from lambdastream.aws.config import LAMBDA_SYNC_PORT
from lambdastream.aws.utils import read_from_s3, write_to_s3


def operator_handler(event, context):
    operator_id = event.get('stream_operator')
    path_prefix = event.get('path_prefix')
    operator_in = path_prefix + operator_id + '.in'
    operator_out = path_prefix + operator_id + '.out'
    host = event.get('host')
    port = LAMBDA_SYNC_PORT

    print('Creating stream_operator from file: {}...'.format(operator_in))
    operator_binary = read_from_s3(operator_in)
    print('Read data from file: {}, unpickling...'.format(operator_in))
    operator = cloudpickle.loads(operator_binary)
    assert operator.operator_id == operator_id, 'Loaded operator does not match provided operator'
    print('Successfully reconstructed {} object'.format(operator.__class__.__name__))

    print('Connecting to host: {}, port: {} for synchronization...'.format(host, port))
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(None)
    sock.connect((host, port))

    print('Sending READY message...')
    msg = 'READY:{}'.format(operator_id)
    sock.send(msg.encode())
    msg = sock.recv(1024)
    if msg != b'RUN':
        print('Expected {}, got {}'.format(b'RUN', msg))
        print('Aborting operator...')
        return
    print('Running operator...')
    operator_out_data = operator.run()
    print('Operator execution complete!')
    print('Writing operator output to S3 @ {}...'.format(operator_out))
    write_to_s3(operator_out, cloudpickle.dumps(operator_out_data))
    msg = 'DONE:{}'.format(operator_id)
    sock.send(msg.encode())
    print('All done!')
    return
