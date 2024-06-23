// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LogServer.proto

#include "LogServer.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_LogServer_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ErrorMsg_LogServer_2eproto;
namespace rj_log {
class LogRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<LogRequest> _instance;
} _LogRequest_default_instance_;
class ErrorMsgDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ErrorMsg> _instance;
} _ErrorMsg_default_instance_;
class LogResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<LogResponse> _instance;
} _LogResponse_default_instance_;
}  // namespace rj_log
static void InitDefaultsscc_info_ErrorMsg_LogServer_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::rj_log::_ErrorMsg_default_instance_;
    new (ptr) ::rj_log::ErrorMsg();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ErrorMsg_LogServer_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ErrorMsg_LogServer_2eproto}, {}};

static void InitDefaultsscc_info_LogRequest_LogServer_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::rj_log::_LogRequest_default_instance_;
    new (ptr) ::rj_log::LogRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_LogRequest_LogServer_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_LogRequest_LogServer_2eproto}, {}};

static void InitDefaultsscc_info_LogResponse_LogServer_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::rj_log::_LogResponse_default_instance_;
    new (ptr) ::rj_log::LogResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_LogResponse_LogServer_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_LogResponse_LogServer_2eproto}, {
      &scc_info_ErrorMsg_LogServer_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_LogServer_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_LogServer_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* file_level_service_descriptors_LogServer_2eproto[1];

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_LogServer_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rj_log::LogRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rj_log::LogRequest, name_),
  PROTOBUF_FIELD_OFFSET(::rj_log::LogRequest, msg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rj_log::ErrorMsg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rj_log::ErrorMsg, state_),
  PROTOBUF_FIELD_OFFSET(::rj_log::ErrorMsg, error_msg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rj_log::LogResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rj_log::LogResponse, msg_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::rj_log::LogRequest)},
  { 7, -1, sizeof(::rj_log::ErrorMsg)},
  { 14, -1, sizeof(::rj_log::LogResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::rj_log::_LogRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::rj_log::_ErrorMsg_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::rj_log::_LogResponse_default_instance_),
};

const char descriptor_table_protodef_LogServer_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017LogServer.proto\022\006rj_log\032\033google/protob"
  "uf/empty.proto\"\'\n\nLogRequest\022\014\n\004name\030\001 \001"
  "(\014\022\013\n\003msg\030\002 \001(\014\",\n\010ErrorMsg\022\r\n\005state\030\001 \001"
  "(\010\022\021\n\terror_msg\030\002 \001(\014\",\n\013LogResponse\022\035\n\003"
  "msg\030\001 \001(\0132\020.rj_log.ErrorMsg2\270\001\n\014LogServe"
  "rRpc\0226\n\010Log_INFO\022\022.rj_log.LogRequest\032\026.g"
  "oogle.protobuf.Empty\0227\n\tLog_ERROR\022\022.rj_l"
  "og.LogRequest\032\026.google.protobuf.Empty\0227\n"
  "\tLog_FATAL\022\022.rj_log.LogRequest\032\026.google."
  "protobuf.EmptyB\003\200\001\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_LogServer_2eproto_deps[1] = {
  &::descriptor_table_google_2fprotobuf_2fempty_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_LogServer_2eproto_sccs[3] = {
  &scc_info_ErrorMsg_LogServer_2eproto.base,
  &scc_info_LogRequest_LogServer_2eproto.base,
  &scc_info_LogResponse_LogServer_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_LogServer_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_LogServer_2eproto = {
  false, false, descriptor_table_protodef_LogServer_2eproto, "LogServer.proto", 387,
  &descriptor_table_LogServer_2eproto_once, descriptor_table_LogServer_2eproto_sccs, descriptor_table_LogServer_2eproto_deps, 3, 1,
  schemas, file_default_instances, TableStruct_LogServer_2eproto::offsets,
  file_level_metadata_LogServer_2eproto, 3, file_level_enum_descriptors_LogServer_2eproto, file_level_service_descriptors_LogServer_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_LogServer_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_LogServer_2eproto)), true);
namespace rj_log {

// ===================================================================

class LogRequest::_Internal {
 public:
};

LogRequest::LogRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:rj_log.LogRequest)
}
LogRequest::LogRequest(const LogRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArena());
  }
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_msg().empty()) {
    msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_msg(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:rj_log.LogRequest)
}

void LogRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_LogRequest_LogServer_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

LogRequest::~LogRequest() {
  // @@protoc_insertion_point(destructor:rj_log.LogRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void LogRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void LogRequest::ArenaDtor(void* object) {
  LogRequest* _this = reinterpret_cast< LogRequest* >(object);
  (void)_this;
}
void LogRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void LogRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const LogRequest& LogRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_LogRequest_LogServer_2eproto.base);
  return *internal_default_instance();
}


void LogRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:rj_log.LogRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  msg_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LogRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes msg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_msg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* LogRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rj_log.LogRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes name = 1;
  if (this->name().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_name(), target);
  }

  // bytes msg = 2;
  if (this->msg().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rj_log.LogRequest)
  return target;
}

size_t LogRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rj_log.LogRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_name());
  }

  // bytes msg = 2;
  if (this->msg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_msg());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void LogRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:rj_log.LogRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const LogRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<LogRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:rj_log.LogRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:rj_log.LogRequest)
    MergeFrom(*source);
  }
}

void LogRequest::MergeFrom(const LogRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:rj_log.LogRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.msg().size() > 0) {
    _internal_set_msg(from._internal_msg());
  }
}

void LogRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:rj_log.LogRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogRequest::CopyFrom(const LogRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rj_log.LogRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogRequest::IsInitialized() const {
  return true;
}

void LogRequest::InternalSwap(LogRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  msg_.Swap(&other->msg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata LogRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class ErrorMsg::_Internal {
 public:
};

ErrorMsg::ErrorMsg(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:rj_log.ErrorMsg)
}
ErrorMsg::ErrorMsg(const ErrorMsg& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  error_msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_error_msg().empty()) {
    error_msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_error_msg(), 
      GetArena());
  }
  state_ = from.state_;
  // @@protoc_insertion_point(copy_constructor:rj_log.ErrorMsg)
}

void ErrorMsg::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ErrorMsg_LogServer_2eproto.base);
  error_msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  state_ = false;
}

ErrorMsg::~ErrorMsg() {
  // @@protoc_insertion_point(destructor:rj_log.ErrorMsg)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ErrorMsg::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  error_msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ErrorMsg::ArenaDtor(void* object) {
  ErrorMsg* _this = reinterpret_cast< ErrorMsg* >(object);
  (void)_this;
}
void ErrorMsg::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ErrorMsg::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ErrorMsg& ErrorMsg::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ErrorMsg_LogServer_2eproto.base);
  return *internal_default_instance();
}


void ErrorMsg::Clear() {
// @@protoc_insertion_point(message_clear_start:rj_log.ErrorMsg)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  error_msg_.ClearToEmpty();
  state_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ErrorMsg::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bool state = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          state_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes error_msg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_error_msg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ErrorMsg::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rj_log.ErrorMsg)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool state = 1;
  if (this->state() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_state(), target);
  }

  // bytes error_msg = 2;
  if (this->error_msg().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_error_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rj_log.ErrorMsg)
  return target;
}

size_t ErrorMsg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rj_log.ErrorMsg)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes error_msg = 2;
  if (this->error_msg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_error_msg());
  }

  // bool state = 1;
  if (this->state() != 0) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ErrorMsg::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:rj_log.ErrorMsg)
  GOOGLE_DCHECK_NE(&from, this);
  const ErrorMsg* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ErrorMsg>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:rj_log.ErrorMsg)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:rj_log.ErrorMsg)
    MergeFrom(*source);
  }
}

void ErrorMsg::MergeFrom(const ErrorMsg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:rj_log.ErrorMsg)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.error_msg().size() > 0) {
    _internal_set_error_msg(from._internal_error_msg());
  }
  if (from.state() != 0) {
    _internal_set_state(from._internal_state());
  }
}

void ErrorMsg::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:rj_log.ErrorMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ErrorMsg::CopyFrom(const ErrorMsg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rj_log.ErrorMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ErrorMsg::IsInitialized() const {
  return true;
}

void ErrorMsg::InternalSwap(ErrorMsg* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  error_msg_.Swap(&other->error_msg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(state_, other->state_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ErrorMsg::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class LogResponse::_Internal {
 public:
  static const ::rj_log::ErrorMsg& msg(const LogResponse* msg);
};

const ::rj_log::ErrorMsg&
LogResponse::_Internal::msg(const LogResponse* msg) {
  return *msg->msg_;
}
LogResponse::LogResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:rj_log.LogResponse)
}
LogResponse::LogResponse(const LogResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_msg()) {
    msg_ = new ::rj_log::ErrorMsg(*from.msg_);
  } else {
    msg_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:rj_log.LogResponse)
}

void LogResponse::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_LogResponse_LogServer_2eproto.base);
  msg_ = nullptr;
}

LogResponse::~LogResponse() {
  // @@protoc_insertion_point(destructor:rj_log.LogResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void LogResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete msg_;
}

void LogResponse::ArenaDtor(void* object) {
  LogResponse* _this = reinterpret_cast< LogResponse* >(object);
  (void)_this;
}
void LogResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void LogResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const LogResponse& LogResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_LogResponse_LogServer_2eproto.base);
  return *internal_default_instance();
}


void LogResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:rj_log.LogResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && msg_ != nullptr) {
    delete msg_;
  }
  msg_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LogResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .rj_log.ErrorMsg msg = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_msg(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* LogResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rj_log.LogResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .rj_log.ErrorMsg msg = 1;
  if (this->has_msg()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::msg(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rj_log.LogResponse)
  return target;
}

size_t LogResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rj_log.LogResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .rj_log.ErrorMsg msg = 1;
  if (this->has_msg()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *msg_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void LogResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:rj_log.LogResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const LogResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<LogResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:rj_log.LogResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:rj_log.LogResponse)
    MergeFrom(*source);
  }
}

void LogResponse::MergeFrom(const LogResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:rj_log.LogResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_msg()) {
    _internal_mutable_msg()->::rj_log::ErrorMsg::MergeFrom(from._internal_msg());
  }
}

void LogResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:rj_log.LogResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogResponse::CopyFrom(const LogResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rj_log.LogResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogResponse::IsInitialized() const {
  return true;
}

void LogResponse::InternalSwap(LogResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(msg_, other->msg_);
}

::PROTOBUF_NAMESPACE_ID::Metadata LogResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

LogServerRpc::~LogServerRpc() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* LogServerRpc::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_LogServer_2eproto);
  return file_level_service_descriptors_LogServer_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* LogServerRpc::GetDescriptor() {
  return descriptor();
}

void LogServerRpc::Log_INFO(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::rj_log::LogRequest*,
                         PROTOBUF_NAMESPACE_ID::Empty*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Log_INFO() not implemented.");
  done->Run();
}

void LogServerRpc::Log_ERROR(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::rj_log::LogRequest*,
                         PROTOBUF_NAMESPACE_ID::Empty*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Log_ERROR() not implemented.");
  done->Run();
}

void LogServerRpc::Log_FATAL(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::rj_log::LogRequest*,
                         PROTOBUF_NAMESPACE_ID::Empty*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Log_FATAL() not implemented.");
  done->Run();
}

void LogServerRpc::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_LogServer_2eproto[0]);
  switch(method->index()) {
    case 0:
      Log_INFO(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::rj_log::LogRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<PROTOBUF_NAMESPACE_ID::Empty*>(
                 response),
             done);
      break;
    case 1:
      Log_ERROR(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::rj_log::LogRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<PROTOBUF_NAMESPACE_ID::Empty*>(
                 response),
             done);
      break;
    case 2:
      Log_FATAL(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::rj_log::LogRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<PROTOBUF_NAMESPACE_ID::Empty*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& LogServerRpc::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::rj_log::LogRequest::default_instance();
    case 1:
      return ::rj_log::LogRequest::default_instance();
    case 2:
      return ::rj_log::LogRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& LogServerRpc::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return PROTOBUF_NAMESPACE_ID::Empty::default_instance();
    case 1:
      return PROTOBUF_NAMESPACE_ID::Empty::default_instance();
    case 2:
      return PROTOBUF_NAMESPACE_ID::Empty::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

LogServerRpc_Stub::LogServerRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
LogServerRpc_Stub::LogServerRpc_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
LogServerRpc_Stub::~LogServerRpc_Stub() {
  if (owns_channel_) delete channel_;
}

void LogServerRpc_Stub::Log_INFO(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::rj_log::LogRequest* request,
                              PROTOBUF_NAMESPACE_ID::Empty* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void LogServerRpc_Stub::Log_ERROR(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::rj_log::LogRequest* request,
                              PROTOBUF_NAMESPACE_ID::Empty* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
void LogServerRpc_Stub::Log_FATAL(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::rj_log::LogRequest* request,
                              PROTOBUF_NAMESPACE_ID::Empty* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(2),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace rj_log
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::rj_log::LogRequest* Arena::CreateMaybeMessage< ::rj_log::LogRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rj_log::LogRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::rj_log::ErrorMsg* Arena::CreateMaybeMessage< ::rj_log::ErrorMsg >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rj_log::ErrorMsg >(arena);
}
template<> PROTOBUF_NOINLINE ::rj_log::LogResponse* Arena::CreateMaybeMessage< ::rj_log::LogResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rj_log::LogResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
