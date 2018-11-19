// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: User.proto

#ifndef PROTOBUF_User_2eproto__INCLUDED
#define PROTOBUF_User_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Optry {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_User_2eproto();
void protobuf_AssignDesc_User_2eproto();
void protobuf_ShutdownFile_User_2eproto();

class User;

// ===================================================================

class User : public ::google::protobuf::Message {
 public:
  User();
  virtual ~User();

  User(const User& from);

  inline User& operator=(const User& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const User& default_instance();

  void Swap(User* other);

  // implements Message ----------------------------------------------

  inline User* New() const { return New(NULL); }

  User* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const User& from);
  void MergeFrom(const User& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(User* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int64 id() const;
  void set_id(::google::protobuf::int64 value);

  // optional string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional bool gender = 3;
  void clear_gender();
  static const int kGenderFieldNumber = 3;
  bool gender() const;
  void set_gender(bool value);

  // repeated string strings = 4;
  int strings_size() const;
  void clear_strings();
  static const int kStringsFieldNumber = 4;
  const ::std::string& strings(int index) const;
  ::std::string* mutable_strings(int index);
  void set_strings(int index, const ::std::string& value);
  void set_strings(int index, const char* value);
  void set_strings(int index, const char* value, size_t size);
  ::std::string* add_strings();
  void add_strings(const ::std::string& value);
  void add_strings(const char* value);
  void add_strings(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& strings() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_strings();

  // @@protoc_insertion_point(class_scope:Optry.User)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int64 id_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::RepeatedPtrField< ::std::string> strings_;
  bool gender_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_User_2eproto();
  friend void protobuf_AssignDesc_User_2eproto();
  friend void protobuf_ShutdownFile_User_2eproto();

  void InitAsDefaultInstance();
  static User* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// User

// optional int64 id = 1;
inline void User::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 User::id() const {
  // @@protoc_insertion_point(field_get:Optry.User.id)
  return id_;
}
inline void User::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:Optry.User.id)
}

// optional string name = 2;
inline void User::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& User::name() const {
  // @@protoc_insertion_point(field_get:Optry.User.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void User::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Optry.User.name)
}
inline void User::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Optry.User.name)
}
inline void User::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Optry.User.name)
}
inline ::std::string* User::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:Optry.User.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* User::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void User::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Optry.User.name)
}

// optional bool gender = 3;
inline void User::clear_gender() {
  gender_ = false;
}
inline bool User::gender() const {
  // @@protoc_insertion_point(field_get:Optry.User.gender)
  return gender_;
}
inline void User::set_gender(bool value) {
  
  gender_ = value;
  // @@protoc_insertion_point(field_set:Optry.User.gender)
}

// repeated string strings = 4;
inline int User::strings_size() const {
  return strings_.size();
}
inline void User::clear_strings() {
  strings_.Clear();
}
inline const ::std::string& User::strings(int index) const {
  // @@protoc_insertion_point(field_get:Optry.User.strings)
  return strings_.Get(index);
}
inline ::std::string* User::mutable_strings(int index) {
  // @@protoc_insertion_point(field_mutable:Optry.User.strings)
  return strings_.Mutable(index);
}
inline void User::set_strings(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:Optry.User.strings)
  strings_.Mutable(index)->assign(value);
}
inline void User::set_strings(int index, const char* value) {
  strings_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:Optry.User.strings)
}
inline void User::set_strings(int index, const char* value, size_t size) {
  strings_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Optry.User.strings)
}
inline ::std::string* User::add_strings() {
  return strings_.Add();
}
inline void User::add_strings(const ::std::string& value) {
  strings_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:Optry.User.strings)
}
inline void User::add_strings(const char* value) {
  strings_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:Optry.User.strings)
}
inline void User::add_strings(const char* value, size_t size) {
  strings_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:Optry.User.strings)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
User::strings() const {
  // @@protoc_insertion_point(field_list:Optry.User.strings)
  return strings_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
User::mutable_strings() {
  // @@protoc_insertion_point(field_mutable_list:Optry.User.strings)
  return &strings_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace Optry

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_User_2eproto__INCLUDED
