// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ChatServer.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ChatServer_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ChatServer_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ChatServer_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ChatServer_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ChatServer_2eproto;
namespace rj_ChatServer {
class GroupRequest;
class GroupRequestDefaultTypeInternal;
extern GroupRequestDefaultTypeInternal _GroupRequest_default_instance_;
class MsgRequest;
class MsgRequestDefaultTypeInternal;
extern MsgRequestDefaultTypeInternal _MsgRequest_default_instance_;
}  // namespace rj_ChatServer
PROTOBUF_NAMESPACE_OPEN
template<> ::rj_ChatServer::GroupRequest* Arena::CreateMaybeMessage<::rj_ChatServer::GroupRequest>(Arena*);
template<> ::rj_ChatServer::MsgRequest* Arena::CreateMaybeMessage<::rj_ChatServer::MsgRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace rj_ChatServer {

// ===================================================================

class MsgRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:rj_ChatServer.MsgRequest) */ {
 public:
  MsgRequest();
  virtual ~MsgRequest();

  MsgRequest(const MsgRequest& from);
  MsgRequest(MsgRequest&& from) noexcept
    : MsgRequest() {
    *this = ::std::move(from);
  }

  inline MsgRequest& operator=(const MsgRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline MsgRequest& operator=(MsgRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const MsgRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MsgRequest* internal_default_instance() {
    return reinterpret_cast<const MsgRequest*>(
               &_MsgRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MsgRequest& a, MsgRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(MsgRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline MsgRequest* New() const final {
    return CreateMaybeMessage<MsgRequest>(nullptr);
  }

  MsgRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<MsgRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const MsgRequest& from);
  void MergeFrom(const MsgRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "rj_ChatServer.MsgRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_ChatServer_2eproto);
    return ::descriptor_table_ChatServer_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgFieldNumber = 3,
    kFromIdFieldNumber = 1,
    kToIdFieldNumber = 2,
  };
  // bytes msg = 3;
  void clear_msg();
  const std::string& msg() const;
  void set_msg(const std::string& value);
  void set_msg(std::string&& value);
  void set_msg(const char* value);
  void set_msg(const void* value, size_t size);
  std::string* mutable_msg();
  std::string* release_msg();
  void set_allocated_msg(std::string* msg);
  private:
  const std::string& _internal_msg() const;
  void _internal_set_msg(const std::string& value);
  std::string* _internal_mutable_msg();
  public:

  // int32 from_id = 1;
  void clear_from_id();
  ::PROTOBUF_NAMESPACE_ID::int32 from_id() const;
  void set_from_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_from_id() const;
  void _internal_set_from_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 to_id = 2;
  void clear_to_id();
  ::PROTOBUF_NAMESPACE_ID::int32 to_id() const;
  void set_to_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_to_id() const;
  void _internal_set_to_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:rj_ChatServer.MsgRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  ::PROTOBUF_NAMESPACE_ID::int32 from_id_;
  ::PROTOBUF_NAMESPACE_ID::int32 to_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ChatServer_2eproto;
};
// -------------------------------------------------------------------

class GroupRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:rj_ChatServer.GroupRequest) */ {
 public:
  GroupRequest();
  virtual ~GroupRequest();

  GroupRequest(const GroupRequest& from);
  GroupRequest(GroupRequest&& from) noexcept
    : GroupRequest() {
    *this = ::std::move(from);
  }

  inline GroupRequest& operator=(const GroupRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline GroupRequest& operator=(GroupRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const GroupRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GroupRequest* internal_default_instance() {
    return reinterpret_cast<const GroupRequest*>(
               &_GroupRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(GroupRequest& a, GroupRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(GroupRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GroupRequest* New() const final {
    return CreateMaybeMessage<GroupRequest>(nullptr);
  }

  GroupRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GroupRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GroupRequest& from);
  void MergeFrom(const GroupRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GroupRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "rj_ChatServer.GroupRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_ChatServer_2eproto);
    return ::descriptor_table_ChatServer_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgFieldNumber = 3,
    kFromIdFieldNumber = 1,
    kGroupIdFieldNumber = 2,
  };
  // bytes msg = 3;
  void clear_msg();
  const std::string& msg() const;
  void set_msg(const std::string& value);
  void set_msg(std::string&& value);
  void set_msg(const char* value);
  void set_msg(const void* value, size_t size);
  std::string* mutable_msg();
  std::string* release_msg();
  void set_allocated_msg(std::string* msg);
  private:
  const std::string& _internal_msg() const;
  void _internal_set_msg(const std::string& value);
  std::string* _internal_mutable_msg();
  public:

  // int32 from_id = 1;
  void clear_from_id();
  ::PROTOBUF_NAMESPACE_ID::int32 from_id() const;
  void set_from_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_from_id() const;
  void _internal_set_from_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 group_id = 2;
  void clear_group_id();
  ::PROTOBUF_NAMESPACE_ID::int32 group_id() const;
  void set_group_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_group_id() const;
  void _internal_set_group_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:rj_ChatServer.GroupRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  ::PROTOBUF_NAMESPACE_ID::int32 from_id_;
  ::PROTOBUF_NAMESPACE_ID::int32 group_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ChatServer_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MsgRequest

// int32 from_id = 1;
inline void MsgRequest::clear_from_id() {
  from_id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 MsgRequest::_internal_from_id() const {
  return from_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 MsgRequest::from_id() const {
  // @@protoc_insertion_point(field_get:rj_ChatServer.MsgRequest.from_id)
  return _internal_from_id();
}
inline void MsgRequest::_internal_set_from_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  from_id_ = value;
}
inline void MsgRequest::set_from_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_from_id(value);
  // @@protoc_insertion_point(field_set:rj_ChatServer.MsgRequest.from_id)
}

// int32 to_id = 2;
inline void MsgRequest::clear_to_id() {
  to_id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 MsgRequest::_internal_to_id() const {
  return to_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 MsgRequest::to_id() const {
  // @@protoc_insertion_point(field_get:rj_ChatServer.MsgRequest.to_id)
  return _internal_to_id();
}
inline void MsgRequest::_internal_set_to_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  to_id_ = value;
}
inline void MsgRequest::set_to_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_to_id(value);
  // @@protoc_insertion_point(field_set:rj_ChatServer.MsgRequest.to_id)
}

// bytes msg = 3;
inline void MsgRequest::clear_msg() {
  msg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& MsgRequest::msg() const {
  // @@protoc_insertion_point(field_get:rj_ChatServer.MsgRequest.msg)
  return _internal_msg();
}
inline void MsgRequest::set_msg(const std::string& value) {
  _internal_set_msg(value);
  // @@protoc_insertion_point(field_set:rj_ChatServer.MsgRequest.msg)
}
inline std::string* MsgRequest::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:rj_ChatServer.MsgRequest.msg)
  return _internal_mutable_msg();
}
inline const std::string& MsgRequest::_internal_msg() const {
  return msg_.GetNoArena();
}
inline void MsgRequest::_internal_set_msg(const std::string& value) {
  
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void MsgRequest::set_msg(std::string&& value) {
  
  msg_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rj_ChatServer.MsgRequest.msg)
}
inline void MsgRequest::set_msg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rj_ChatServer.MsgRequest.msg)
}
inline void MsgRequest::set_msg(const void* value, size_t size) {
  
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rj_ChatServer.MsgRequest.msg)
}
inline std::string* MsgRequest::_internal_mutable_msg() {
  
  return msg_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* MsgRequest::release_msg() {
  // @@protoc_insertion_point(field_release:rj_ChatServer.MsgRequest.msg)
  
  return msg_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void MsgRequest::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:rj_ChatServer.MsgRequest.msg)
}

// -------------------------------------------------------------------

// GroupRequest

// int32 from_id = 1;
inline void GroupRequest::clear_from_id() {
  from_id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 GroupRequest::_internal_from_id() const {
  return from_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 GroupRequest::from_id() const {
  // @@protoc_insertion_point(field_get:rj_ChatServer.GroupRequest.from_id)
  return _internal_from_id();
}
inline void GroupRequest::_internal_set_from_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  from_id_ = value;
}
inline void GroupRequest::set_from_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_from_id(value);
  // @@protoc_insertion_point(field_set:rj_ChatServer.GroupRequest.from_id)
}

// int32 group_id = 2;
inline void GroupRequest::clear_group_id() {
  group_id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 GroupRequest::_internal_group_id() const {
  return group_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 GroupRequest::group_id() const {
  // @@protoc_insertion_point(field_get:rj_ChatServer.GroupRequest.group_id)
  return _internal_group_id();
}
inline void GroupRequest::_internal_set_group_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  group_id_ = value;
}
inline void GroupRequest::set_group_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_group_id(value);
  // @@protoc_insertion_point(field_set:rj_ChatServer.GroupRequest.group_id)
}

// bytes msg = 3;
inline void GroupRequest::clear_msg() {
  msg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& GroupRequest::msg() const {
  // @@protoc_insertion_point(field_get:rj_ChatServer.GroupRequest.msg)
  return _internal_msg();
}
inline void GroupRequest::set_msg(const std::string& value) {
  _internal_set_msg(value);
  // @@protoc_insertion_point(field_set:rj_ChatServer.GroupRequest.msg)
}
inline std::string* GroupRequest::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:rj_ChatServer.GroupRequest.msg)
  return _internal_mutable_msg();
}
inline const std::string& GroupRequest::_internal_msg() const {
  return msg_.GetNoArena();
}
inline void GroupRequest::_internal_set_msg(const std::string& value) {
  
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void GroupRequest::set_msg(std::string&& value) {
  
  msg_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rj_ChatServer.GroupRequest.msg)
}
inline void GroupRequest::set_msg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rj_ChatServer.GroupRequest.msg)
}
inline void GroupRequest::set_msg(const void* value, size_t size) {
  
  msg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rj_ChatServer.GroupRequest.msg)
}
inline std::string* GroupRequest::_internal_mutable_msg() {
  
  return msg_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* GroupRequest::release_msg() {
  // @@protoc_insertion_point(field_release:rj_ChatServer.GroupRequest.msg)
  
  return msg_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void GroupRequest::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:rj_ChatServer.GroupRequest.msg)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace rj_ChatServer

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ChatServer_2eproto
