#
# Autogenerated by Thrift Compiler (0.12.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
#  options string: py:no_utf8strings,slots
#

from thrift.Thrift import TType, TMessageType, TFrozenDict, TException, TApplicationException
from thrift.protocol.TProtocol import TProtocolException
from thrift.TRecursive import fix_spec


from thrift.transport import TTransport
all_structs = []


class response_type(object):
    subscribe = 0
    unsubscribe = 1

    _VALUES_TO_NAMES = {
        0: "subscribe",
        1: "unsubscribe",
    }

    _NAMES_TO_VALUES = {
        "subscribe": 0,
        "unsubscribe": 1,
    }


class block_exception(TException):
    """
    Attributes:
     - msg

    """

    __slots__ = (
        'msg',
    )


    def __init__(self, msg=None,):
        self.msg = msg

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 1:
                if ftype == TType.STRING:
                    self.msg = iprot.readString()
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('block_exception')
        if self.msg is not None:
            oprot.writeFieldBegin('msg', TType.STRING, 1)
            oprot.writeString(self.msg)
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        return

    def __str__(self):
        return repr(self)

    def __repr__(self):
        L = ['%s=%r' % (key, getattr(self, key))
             for key in self.__slots__]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        for attr in self.__slots__:
            my_val = getattr(self, attr)
            other_val = getattr(other, attr)
            if my_val != other_val:
                return False
        return True

    def __ne__(self, other):
        return not (self == other)


class chain_failure_exception(TException):
    """
    Attributes:
     - msg

    """

    __slots__ = (
        'msg',
    )


    def __init__(self, msg=None,):
        self.msg = msg

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 1:
                if ftype == TType.STRING:
                    self.msg = iprot.readString()
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('chain_failure_exception')
        if self.msg is not None:
            oprot.writeFieldBegin('msg', TType.STRING, 1)
            oprot.writeString(self.msg)
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        return

    def __str__(self):
        return repr(self)

    def __repr__(self):
        L = ['%s=%r' % (key, getattr(self, key))
             for key in self.__slots__]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        for attr in self.__slots__:
            my_val = getattr(self, attr)
            other_val = getattr(other, attr)
            if my_val != other_val:
                return False
        return True

    def __ne__(self, other):
        return not (self == other)


class sequence_id(object):
    """
    Attributes:
     - client_id
     - client_seq_no
     - server_seq_no

    """

    __slots__ = (
        'client_id',
        'client_seq_no',
        'server_seq_no',
    )


    def __init__(self, client_id=None, client_seq_no=None, server_seq_no=None,):
        self.client_id = client_id
        self.client_seq_no = client_seq_no
        self.server_seq_no = server_seq_no

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 1:
                if ftype == TType.I64:
                    self.client_id = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 2:
                if ftype == TType.I64:
                    self.client_seq_no = iprot.readI64()
                else:
                    iprot.skip(ftype)
            elif fid == 3:
                if ftype == TType.I64:
                    self.server_seq_no = iprot.readI64()
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('sequence_id')
        if self.client_id is not None:
            oprot.writeFieldBegin('client_id', TType.I64, 1)
            oprot.writeI64(self.client_id)
            oprot.writeFieldEnd()
        if self.client_seq_no is not None:
            oprot.writeFieldBegin('client_seq_no', TType.I64, 2)
            oprot.writeI64(self.client_seq_no)
            oprot.writeFieldEnd()
        if self.server_seq_no is not None:
            oprot.writeFieldBegin('server_seq_no', TType.I64, 3)
            oprot.writeI64(self.server_seq_no)
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        if self.client_id is None:
            raise TProtocolException(message='Required field client_id is unset!')
        if self.client_seq_no is None:
            raise TProtocolException(message='Required field client_seq_no is unset!')
        if self.server_seq_no is None:
            raise TProtocolException(message='Required field server_seq_no is unset!')
        return

    def __repr__(self):
        L = ['%s=%r' % (key, getattr(self, key))
             for key in self.__slots__]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        for attr in self.__slots__:
            my_val = getattr(self, attr)
            other_val = getattr(other, attr)
            if my_val != other_val:
                return False
        return True

    def __ne__(self, other):
        return not (self == other)
all_structs.append(block_exception)
block_exception.thrift_spec = (
    None,  # 0
    (1, TType.STRING, 'msg', None, None, ),  # 1
)
all_structs.append(chain_failure_exception)
chain_failure_exception.thrift_spec = (
    None,  # 0
    (1, TType.STRING, 'msg', None, None, ),  # 1
)
all_structs.append(sequence_id)
sequence_id.thrift_spec = (
    None,  # 0
    (1, TType.I64, 'client_id', None, None, ),  # 1
    (2, TType.I64, 'client_seq_no', None, None, ),  # 2
    (3, TType.I64, 'server_seq_no', None, None, ),  # 3
)
fix_spec(all_structs)
del all_structs
