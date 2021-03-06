/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "auto_scaling_service.h"
#ifndef auto_scaling_service_TCC
#define auto_scaling_service_TCC


namespace jiffy { namespace auto_scaling {


template <class Protocol_>
uint32_t auto_scaling_service_auto_scaling_args::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->current_replica_chain.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readListBegin(_etype5, _size2);
            this->current_replica_chain.resize(_size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              xfer += iprot->readString(this->current_replica_chain[_i6]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.current_replica_chain = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->path);
          this->__isset.path = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->conf.clear();
            uint32_t _size7;
            ::apache::thrift::protocol::TType _ktype8;
            ::apache::thrift::protocol::TType _vtype9;
            xfer += iprot->readMapBegin(_ktype8, _vtype9, _size7);
            uint32_t _i11;
            for (_i11 = 0; _i11 < _size7; ++_i11)
            {
              std::string _key12;
              xfer += iprot->readString(_key12);
              std::string& _val13 = this->conf[_key12];
              xfer += iprot->readString(_val13);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.conf = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t auto_scaling_service_auto_scaling_args::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("auto_scaling_service_auto_scaling_args");

  xfer += oprot->writeFieldBegin("current_replica_chain", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->current_replica_chain.size()));
    std::vector<std::string> ::const_iterator _iter14;
    for (_iter14 = this->current_replica_chain.begin(); _iter14 != this->current_replica_chain.end(); ++_iter14)
    {
      xfer += oprot->writeString((*_iter14));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("path", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->path);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("conf", ::apache::thrift::protocol::T_MAP, 3);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->conf.size()));
    std::map<std::string, std::string> ::const_iterator _iter15;
    for (_iter15 = this->conf.begin(); _iter15 != this->conf.end(); ++_iter15)
    {
      xfer += oprot->writeString(_iter15->first);
      xfer += oprot->writeString(_iter15->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


template <class Protocol_>
uint32_t auto_scaling_service_auto_scaling_pargs::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("auto_scaling_service_auto_scaling_pargs");

  xfer += oprot->writeFieldBegin("current_replica_chain", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->current_replica_chain)).size()));
    std::vector<std::string> ::const_iterator _iter16;
    for (_iter16 = (*(this->current_replica_chain)).begin(); _iter16 != (*(this->current_replica_chain)).end(); ++_iter16)
    {
      xfer += oprot->writeString((*_iter16));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("path", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString((*(this->path)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("conf", ::apache::thrift::protocol::T_MAP, 3);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->conf)).size()));
    std::map<std::string, std::string> ::const_iterator _iter17;
    for (_iter17 = (*(this->conf)).begin(); _iter17 != (*(this->conf)).end(); ++_iter17)
    {
      xfer += oprot->writeString(_iter17->first);
      xfer += oprot->writeString(_iter17->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
void auto_scaling_serviceClientT<Protocol_>::auto_scaling(const std::vector<std::string> & current_replica_chain, const std::string& path, const std::map<std::string, std::string> & conf)
{
  send_auto_scaling(current_replica_chain, path, conf);
}

template <class Protocol_>
void auto_scaling_serviceClientT<Protocol_>::send_auto_scaling(const std::vector<std::string> & current_replica_chain, const std::string& path, const std::map<std::string, std::string> & conf)
{
  int32_t cseqid = 0;
  this->oprot_->writeMessageBegin("auto_scaling", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  auto_scaling_service_auto_scaling_pargs args;
  args.current_replica_chain = &current_replica_chain;
  args.path = &path;
  args.conf = &conf;
  args.write(this->oprot_);

  this->oprot_->writeMessageEnd();
  this->oprot_->getTransport()->writeEnd();
  this->oprot_->getTransport()->flush();
}

template <class Protocol_>
bool auto_scaling_serviceProcessorT<Protocol_>::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  typename ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second.generic))(seqid, iprot, oprot, callContext);
  return true;
}

template <class Protocol_>
bool auto_scaling_serviceProcessorT<Protocol_>::dispatchCallTemplated(Protocol_* iprot, Protocol_* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  typename ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second.specialized))(seqid, iprot, oprot, callContext);
  return true;
}

template <class Protocol_>
void auto_scaling_serviceProcessorT<Protocol_>::process_auto_scaling(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  (void) seqid;
  (void) oprot;
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("auto_scaling_service.auto_scaling", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "auto_scaling_service.auto_scaling");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "auto_scaling_service.auto_scaling");
  }

  auto_scaling_service_auto_scaling_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "auto_scaling_service.auto_scaling", bytes);
  }

  try {
    iface_->auto_scaling(args.current_replica_chain, args.path, args.conf);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "auto_scaling_service.auto_scaling");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "auto_scaling_service.auto_scaling");
  }

  return;
}

template <class Protocol_>
void auto_scaling_serviceProcessorT<Protocol_>::process_auto_scaling(int32_t, Protocol_* iprot, Protocol_*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("auto_scaling_service.auto_scaling", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "auto_scaling_service.auto_scaling");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "auto_scaling_service.auto_scaling");
  }

  auto_scaling_service_auto_scaling_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "auto_scaling_service.auto_scaling", bytes);
  }

  try {
    iface_->auto_scaling(args.current_replica_chain, args.path, args.conf);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "auto_scaling_service.auto_scaling");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "auto_scaling_service.auto_scaling");
  }

  return;
}

template <class Protocol_>
::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > auto_scaling_serviceProcessorFactoryT<Protocol_>::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< auto_scaling_serviceIfFactory > cleanup(handlerFactory_);
  ::apache::thrift::stdcxx::shared_ptr< auto_scaling_serviceIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > processor(new auto_scaling_serviceProcessorT<Protocol_>(handler));
  return processor;
}

template <class Protocol_>
void auto_scaling_serviceConcurrentClientT<Protocol_>::auto_scaling(const std::vector<std::string> & current_replica_chain, const std::string& path, const std::map<std::string, std::string> & conf)
{
  send_auto_scaling(current_replica_chain, path, conf);
}

template <class Protocol_>
void auto_scaling_serviceConcurrentClientT<Protocol_>::send_auto_scaling(const std::vector<std::string> & current_replica_chain, const std::string& path, const std::map<std::string, std::string> & conf)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(&this->sync_);
  this->oprot_->writeMessageBegin("auto_scaling", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  auto_scaling_service_auto_scaling_pargs args;
  args.current_replica_chain = &current_replica_chain;
  args.path = &path;
  args.conf = &conf;
  args.write(this->oprot_);

  this->oprot_->writeMessageEnd();
  this->oprot_->getTransport()->writeEnd();
  this->oprot_->getTransport()->flush();

  sentry.commit();
}

}} // namespace

#endif
