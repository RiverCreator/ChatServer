// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ChatServer.proto

#include "ChatServer.pb.h"

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
namespace rj_ChatServer {
class MsgRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<MsgRequest> _instance;
} _MsgRequest_default_instance_;
class GroupRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GroupRequest> _instance;
} _GroupRequest_default_instance_;
}  // namespace rj_ChatServer
static void InitDefaultsscc_info_GroupRequest_ChatServer_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::rj_ChatServer::_GroupRequest_default_instance_;
    new (ptr) ::rj_ChatServer::GroupRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GroupRequest_ChatServer_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_GroupRequest_ChatServer_2eproto}, {}};

static void InitDefaultsscc_info_MsgRequest_ChatServer_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::rj_ChatServer::_MsgRequest_default_instance_;
    new (ptr) ::rj_ChatServer::MsgRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_MsgRequest_ChatServer_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_MsgRequest_ChatServer_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_ChatServer_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_ChatServer_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_ChatServer_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_ChatServer_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rj_ChatServer::MsgRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rj_ChatServer::MsgRequest, from_id_),
  PROTOBUF_FIELD_OFFSET(::rj_ChatServer::MsgRequest, to_id_),
  PROTOBUF_FIELD_OFFSET(::rj_ChatServer::MsgRequest, msg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rj_ChatServer::GroupRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::rj_ChatServer::GroupRequest, from_id_),
  PROTOBUF_FIELD_OFFSET(::rj_ChatServer::GroupRequest, group_id_),
  PROTOBUF_FIELD_OFFSET(::rj_ChatServer::GroupRequest, msg_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::rj_ChatServer::MsgRequest)},
  { 8, -1, sizeof(::rj_ChatServer::GroupRequest)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::rj_ChatServer::_MsgRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::rj_ChatServer::_GroupRequest_default_instance_),
};

const char descriptor_table_protodef_ChatServer_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020ChatServer.proto\022\rrj_ChatServer\"9\n\nMsg"
  "Request\022\017\n\007from_id\030\001 \001(\005\022\r\n\005to_id\030\002 \001(\005\022"
  "\013\n\003msg\030\003 \001(\014\">\n\014GroupRequest\022\017\n\007from_id\030"
  "\001 \001(\005\022\020\n\010group_id\030\002 \001(\005\022\013\n\003msg\030\003 \001(\014b\006pr"
  "oto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_ChatServer_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_ChatServer_2eproto_sccs[2] = {
  &scc_info_GroupRequest_ChatServer_2eproto.base,
  &scc_info_MsgRequest_ChatServer_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_ChatServer_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ChatServer_2eproto = {
  false, false, descriptor_table_protodef_ChatServer_2eproto, "ChatServer.proto", 164,
  &descriptor_table_ChatServer_2eproto_once, descriptor_table_ChatServer_2eproto_sccs, descriptor_table_ChatServer_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_ChatServer_2eproto::offsets,
  file_level_metadata_ChatServer_2eproto, 2, file_level_enum_descriptors_ChatServer_2eproto, file_level_service_descriptors_ChatServer_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_ChatServer_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_ChatServer_2eproto)), true);
namespace rj_ChatServer {

// ===================================================================

class MsgRequest::_Internal {
 public:
};

MsgRequest::MsgRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:rj_ChatServer.MsgRequest)
}
MsgRequest::MsgRequest(const MsgRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_msg().empty()) {
    msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_msg(), 
      GetArena());
  }
  ::memcpy(&from_id_, &from.from_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&to_id_) -
    reinterpret_cast<char*>(&from_id_)) + sizeof(to_id_));
  // @@protoc_insertion_point(copy_constructor:rj_ChatServer.MsgRequest)
}

void MsgRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_MsgRequest_ChatServer_2eproto.base);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&from_id_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&to_id_) -
      reinterpret_cast<char*>(&from_id_)) + sizeof(to_id_));
}

MsgRequest::~MsgRequest() {
  // @@protoc_insertion_point(destructor:rj_ChatServer.MsgRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void MsgRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void MsgRequest::ArenaDtor(void* object) {
  MsgRequest* _this = reinterpret_cast< MsgRequest* >(object);
  (void)_this;
}
void MsgRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void MsgRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const MsgRequest& MsgRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_MsgRequest_ChatServer_2eproto.base);
  return *internal_default_instance();
}


void MsgRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:rj_ChatServer.MsgRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  msg_.ClearToEmpty();
  ::memset(&from_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&to_id_) -
      reinterpret_cast<char*>(&from_id_)) + sizeof(to_id_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MsgRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 from_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          from_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 to_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          to_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes msg = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
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

::PROTOBUF_NAMESPACE_ID::uint8* MsgRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rj_ChatServer.MsgRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 from_id = 1;
  if (this->from_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_from_id(), target);
  }

  // int32 to_id = 2;
  if (this->to_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_to_id(), target);
  }

  // bytes msg = 3;
  if (this->msg().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rj_ChatServer.MsgRequest)
  return target;
}

size_t MsgRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rj_ChatServer.MsgRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes msg = 3;
  if (this->msg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_msg());
  }

  // int32 from_id = 1;
  if (this->from_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_from_id());
  }

  // int32 to_id = 2;
  if (this->to_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_to_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MsgRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:rj_ChatServer.MsgRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const MsgRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<MsgRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:rj_ChatServer.MsgRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:rj_ChatServer.MsgRequest)
    MergeFrom(*source);
  }
}

void MsgRequest::MergeFrom(const MsgRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:rj_ChatServer.MsgRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.msg().size() > 0) {
    _internal_set_msg(from._internal_msg());
  }
  if (from.from_id() != 0) {
    _internal_set_from_id(from._internal_from_id());
  }
  if (from.to_id() != 0) {
    _internal_set_to_id(from._internal_to_id());
  }
}

void MsgRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:rj_ChatServer.MsgRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgRequest::CopyFrom(const MsgRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rj_ChatServer.MsgRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgRequest::IsInitialized() const {
  return true;
}

void MsgRequest::InternalSwap(MsgRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  msg_.Swap(&other->msg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MsgRequest, to_id_)
      + sizeof(MsgRequest::to_id_)
      - PROTOBUF_FIELD_OFFSET(MsgRequest, from_id_)>(
          reinterpret_cast<char*>(&from_id_),
          reinterpret_cast<char*>(&other->from_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata MsgRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class GroupRequest::_Internal {
 public:
};

GroupRequest::GroupRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:rj_ChatServer.GroupRequest)
}
GroupRequest::GroupRequest(const GroupRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_msg().empty()) {
    msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_msg(), 
      GetArena());
  }
  ::memcpy(&from_id_, &from.from_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&group_id_) -
    reinterpret_cast<char*>(&from_id_)) + sizeof(group_id_));
  // @@protoc_insertion_point(copy_constructor:rj_ChatServer.GroupRequest)
}

void GroupRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GroupRequest_ChatServer_2eproto.base);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&from_id_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&group_id_) -
      reinterpret_cast<char*>(&from_id_)) + sizeof(group_id_));
}

GroupRequest::~GroupRequest() {
  // @@protoc_insertion_point(destructor:rj_ChatServer.GroupRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void GroupRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void GroupRequest::ArenaDtor(void* object) {
  GroupRequest* _this = reinterpret_cast< GroupRequest* >(object);
  (void)_this;
}
void GroupRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GroupRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GroupRequest& GroupRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GroupRequest_ChatServer_2eproto.base);
  return *internal_default_instance();
}


void GroupRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:rj_ChatServer.GroupRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  msg_.ClearToEmpty();
  ::memset(&from_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&group_id_) -
      reinterpret_cast<char*>(&from_id_)) + sizeof(group_id_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GroupRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 from_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          from_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 group_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          group_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes msg = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
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

::PROTOBUF_NAMESPACE_ID::uint8* GroupRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rj_ChatServer.GroupRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 from_id = 1;
  if (this->from_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_from_id(), target);
  }

  // int32 group_id = 2;
  if (this->group_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_group_id(), target);
  }

  // bytes msg = 3;
  if (this->msg().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rj_ChatServer.GroupRequest)
  return target;
}

size_t GroupRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rj_ChatServer.GroupRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes msg = 3;
  if (this->msg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_msg());
  }

  // int32 from_id = 1;
  if (this->from_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_from_id());
  }

  // int32 group_id = 2;
  if (this->group_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_group_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GroupRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:rj_ChatServer.GroupRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const GroupRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GroupRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:rj_ChatServer.GroupRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:rj_ChatServer.GroupRequest)
    MergeFrom(*source);
  }
}

void GroupRequest::MergeFrom(const GroupRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:rj_ChatServer.GroupRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.msg().size() > 0) {
    _internal_set_msg(from._internal_msg());
  }
  if (from.from_id() != 0) {
    _internal_set_from_id(from._internal_from_id());
  }
  if (from.group_id() != 0) {
    _internal_set_group_id(from._internal_group_id());
  }
}

void GroupRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:rj_ChatServer.GroupRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GroupRequest::CopyFrom(const GroupRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rj_ChatServer.GroupRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GroupRequest::IsInitialized() const {
  return true;
}

void GroupRequest::InternalSwap(GroupRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  msg_.Swap(&other->msg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(GroupRequest, group_id_)
      + sizeof(GroupRequest::group_id_)
      - PROTOBUF_FIELD_OFFSET(GroupRequest, from_id_)>(
          reinterpret_cast<char*>(&from_id_),
          reinterpret_cast<char*>(&other->from_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata GroupRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace rj_ChatServer
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::rj_ChatServer::MsgRequest* Arena::CreateMaybeMessage< ::rj_ChatServer::MsgRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rj_ChatServer::MsgRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::rj_ChatServer::GroupRequest* Arena::CreateMaybeMessage< ::rj_ChatServer::GroupRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rj_ChatServer::GroupRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>