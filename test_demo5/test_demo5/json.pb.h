// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: json.proto

#ifndef PROTOBUF_json_2eproto__INCLUDED
#define PROTOBUF_json_2eproto__INCLUDED

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

namespace Test {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_json_2eproto();
void protobuf_AssignDesc_json_2eproto();
void protobuf_ShutdownFile_json_2eproto();

class Header;
class Body;
class End;
class Data;
class Json;

// ===================================================================

class Header : public ::google::protobuf::Message {
 public:
  Header();
  virtual ~Header();

  Header(const Header& from);

  inline Header& operator=(const Header& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Header& default_instance();

  void Swap(Header* other);

  // implements Message ----------------------------------------------

  inline Header* New() const { return New(NULL); }

  Header* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Header& from);
  void MergeFrom(const Header& from);
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
  void InternalSwap(Header* other);
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

  // optional uint64 biilId = 7;
  void clear_biilid();
  static const int kBiilIdFieldNumber = 7;
  ::google::protobuf::uint64 biilid() const;
  void set_biilid(::google::protobuf::uint64 value);

  // optional uint64 code = 1;
  void clear_code();
  static const int kCodeFieldNumber = 1;
  ::google::protobuf::uint64 code() const;
  void set_code(::google::protobuf::uint64 value);

  // optional uint64 deptId = 2;
  void clear_deptid();
  static const int kDeptIdFieldNumber = 2;
  ::google::protobuf::uint64 deptid() const;
  void set_deptid(::google::protobuf::uint64 value);

  // optional uint64 HeadId = 3;
  void clear_headid();
  static const int kHeadIdFieldNumber = 3;
  ::google::protobuf::uint64 headid() const;
  void set_headid(::google::protobuf::uint64 value);

  // optional bool isInlay = 4;
  void clear_isinlay();
  static const int kIsInlayFieldNumber = 4;
  bool isinlay() const;
  void set_isinlay(bool value);

  // optional string time = 5;
  void clear_time();
  static const int kTimeFieldNumber = 5;
  const ::std::string& time() const;
  void set_time(const ::std::string& value);
  void set_time(const char* value);
  void set_time(const char* value, size_t size);
  ::std::string* mutable_time();
  ::std::string* release_time();
  void set_allocated_time(::std::string* time);

  // optional uint64 houseId = 6;
  void clear_houseid();
  static const int kHouseIdFieldNumber = 6;
  ::google::protobuf::uint64 houseid() const;
  void set_houseid(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:Test.Header)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::uint64 biilid_;
  ::google::protobuf::uint64 code_;
  ::google::protobuf::uint64 deptid_;
  ::google::protobuf::uint64 headid_;
  ::google::protobuf::internal::ArenaStringPtr time_;
  ::google::protobuf::uint64 houseid_;
  bool isinlay_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_json_2eproto();
  friend void protobuf_AssignDesc_json_2eproto();
  friend void protobuf_ShutdownFile_json_2eproto();

  void InitAsDefaultInstance();
  static Header* default_instance_;
};
// -------------------------------------------------------------------

class Body : public ::google::protobuf::Message {
 public:
  Body();
  virtual ~Body();

  Body(const Body& from);

  inline Body& operator=(const Body& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Body& default_instance();

  void Swap(Body* other);

  // implements Message ----------------------------------------------

  inline Body* New() const { return New(NULL); }

  Body* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Body& from);
  void MergeFrom(const Body& from);
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
  void InternalSwap(Body* other);
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

  // optional string barcode = 6;
  void clear_barcode();
  static const int kBarcodeFieldNumber = 6;
  const ::std::string& barcode() const;
  void set_barcode(const ::std::string& value);
  void set_barcode(const char* value);
  void set_barcode(const char* value, size_t size);
  ::std::string* mutable_barcode();
  ::std::string* release_barcode();
  void set_allocated_barcode(::std::string* barcode);

  // optional string cate = 1;
  void clear_cate();
  static const int kCateFieldNumber = 1;
  const ::std::string& cate() const;
  void set_cate(const ::std::string& value);
  void set_cate(const char* value);
  void set_cate(const char* value, size_t size);
  ::std::string* mutable_cate();
  ::std::string* release_cate();
  void set_allocated_cate(::std::string* cate);

  // optional double amount = 2;
  void clear_amount();
  static const int kAmountFieldNumber = 2;
  double amount() const;
  void set_amount(double value);

  // optional double matact = 3;
  void clear_matact();
  static const int kMatactFieldNumber = 3;
  double matact() const;
  void set_matact(double value);

  // optional uint64 bodyId = 4;
  void clear_bodyid();
  static const int kBodyIdFieldNumber = 4;
  ::google::protobuf::uint64 bodyid() const;
  void set_bodyid(::google::protobuf::uint64 value);

  // optional uint64 headId = 5;
  void clear_headid();
  static const int kHeadIdFieldNumber = 5;
  ::google::protobuf::uint64 headid() const;
  void set_headid(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:Test.Body)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr barcode_;
  ::google::protobuf::internal::ArenaStringPtr cate_;
  double amount_;
  double matact_;
  ::google::protobuf::uint64 bodyid_;
  ::google::protobuf::uint64 headid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_json_2eproto();
  friend void protobuf_AssignDesc_json_2eproto();
  friend void protobuf_ShutdownFile_json_2eproto();

  void InitAsDefaultInstance();
  static Body* default_instance_;
};
// -------------------------------------------------------------------

class End : public ::google::protobuf::Message {
 public:
  End();
  virtual ~End();

  End(const End& from);

  inline End& operator=(const End& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const End& default_instance();

  void Swap(End* other);

  // implements Message ----------------------------------------------

  inline End* New() const { return New(NULL); }

  End* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const End& from);
  void MergeFrom(const End& from);
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
  void InternalSwap(End* other);
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

  // optional uint64 fittingId = 4;
  void clear_fittingid();
  static const int kFittingIdFieldNumber = 4;
  ::google::protobuf::uint64 fittingid() const;
  void set_fittingid(::google::protobuf::uint64 value);

  // optional uint64 bodyId = 1;
  void clear_bodyid();
  static const int kBodyIdFieldNumber = 1;
  ::google::protobuf::uint64 bodyid() const;
  void set_bodyid(::google::protobuf::uint64 value);

  // optional int32 rownum = 2;
  void clear_rownum();
  static const int kRownumFieldNumber = 2;
  ::google::protobuf::int32 rownum() const;
  void set_rownum(::google::protobuf::int32 value);

  // optional string code = 3;
  void clear_code();
  static const int kCodeFieldNumber = 3;
  const ::std::string& code() const;
  void set_code(const ::std::string& value);
  void set_code(const char* value);
  void set_code(const char* value, size_t size);
  ::std::string* mutable_code();
  ::std::string* release_code();
  void set_allocated_code(::std::string* code);

  // @@protoc_insertion_point(class_scope:Test.End)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::uint64 fittingid_;
  ::google::protobuf::uint64 bodyid_;
  ::google::protobuf::internal::ArenaStringPtr code_;
  ::google::protobuf::int32 rownum_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_json_2eproto();
  friend void protobuf_AssignDesc_json_2eproto();
  friend void protobuf_ShutdownFile_json_2eproto();

  void InitAsDefaultInstance();
  static End* default_instance_;
};
// -------------------------------------------------------------------

class Data : public ::google::protobuf::Message {
 public:
  Data();
  virtual ~Data();

  Data(const Data& from);

  inline Data& operator=(const Data& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Data& default_instance();

  void Swap(Data* other);

  // implements Message ----------------------------------------------

  inline Data* New() const { return New(NULL); }

  Data* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Data& from);
  void MergeFrom(const Data& from);
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
  void InternalSwap(Data* other);
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

  // optional .Test.Header header = 3;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 3;
  const ::Test::Header& header() const;
  ::Test::Header* mutable_header();
  ::Test::Header* release_header();
  void set_allocated_header(::Test::Header* header);

  // repeated .Test.Body body = 1;
  int body_size() const;
  void clear_body();
  static const int kBodyFieldNumber = 1;
  const ::Test::Body& body(int index) const;
  ::Test::Body* mutable_body(int index);
  ::Test::Body* add_body();
  const ::google::protobuf::RepeatedPtrField< ::Test::Body >&
      body() const;
  ::google::protobuf::RepeatedPtrField< ::Test::Body >*
      mutable_body();

  // repeated .Test.End end = 2;
  int end_size() const;
  void clear_end();
  static const int kEndFieldNumber = 2;
  const ::Test::End& end(int index) const;
  ::Test::End* mutable_end(int index);
  ::Test::End* add_end();
  const ::google::protobuf::RepeatedPtrField< ::Test::End >&
      end() const;
  ::google::protobuf::RepeatedPtrField< ::Test::End >*
      mutable_end();

  // @@protoc_insertion_point(class_scope:Test.Data)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::Test::Header* header_;
  ::google::protobuf::RepeatedPtrField< ::Test::Body > body_;
  ::google::protobuf::RepeatedPtrField< ::Test::End > end_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_json_2eproto();
  friend void protobuf_AssignDesc_json_2eproto();
  friend void protobuf_ShutdownFile_json_2eproto();

  void InitAsDefaultInstance();
  static Data* default_instance_;
};
// -------------------------------------------------------------------

class Json : public ::google::protobuf::Message {
 public:
  Json();
  virtual ~Json();

  Json(const Json& from);

  inline Json& operator=(const Json& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Json& default_instance();

  void Swap(Json* other);

  // implements Message ----------------------------------------------

  inline Json* New() const { return New(NULL); }

  Json* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Json& from);
  void MergeFrom(const Json& from);
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
  void InternalSwap(Json* other);
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

  // optional int32 code = 3;
  void clear_code();
  static const int kCodeFieldNumber = 3;
  ::google::protobuf::int32 code() const;
  void set_code(::google::protobuf::int32 value);

  // optional string Msg = 1;
  void clear_msg();
  static const int kMsgFieldNumber = 1;
  const ::std::string& msg() const;
  void set_msg(const ::std::string& value);
  void set_msg(const char* value);
  void set_msg(const char* value, size_t size);
  ::std::string* mutable_msg();
  ::std::string* release_msg();
  void set_allocated_msg(::std::string* msg);

  // optional .Test.Data data = 2;
  bool has_data() const;
  void clear_data();
  static const int kDataFieldNumber = 2;
  const ::Test::Data& data() const;
  ::Test::Data* mutable_data();
  ::Test::Data* release_data();
  void set_allocated_data(::Test::Data* data);

  // @@protoc_insertion_point(class_scope:Test.Json)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr msg_;
  ::Test::Data* data_;
  ::google::protobuf::int32 code_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_json_2eproto();
  friend void protobuf_AssignDesc_json_2eproto();
  friend void protobuf_ShutdownFile_json_2eproto();

  void InitAsDefaultInstance();
  static Json* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Header

// optional uint64 biilId = 7;
inline void Header::clear_biilid() {
  biilid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Header::biilid() const {
  // @@protoc_insertion_point(field_get:Test.Header.biilId)
  return biilid_;
}
inline void Header::set_biilid(::google::protobuf::uint64 value) {
  
  biilid_ = value;
  // @@protoc_insertion_point(field_set:Test.Header.biilId)
}

// optional uint64 code = 1;
inline void Header::clear_code() {
  code_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Header::code() const {
  // @@protoc_insertion_point(field_get:Test.Header.code)
  return code_;
}
inline void Header::set_code(::google::protobuf::uint64 value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:Test.Header.code)
}

// optional uint64 deptId = 2;
inline void Header::clear_deptid() {
  deptid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Header::deptid() const {
  // @@protoc_insertion_point(field_get:Test.Header.deptId)
  return deptid_;
}
inline void Header::set_deptid(::google::protobuf::uint64 value) {
  
  deptid_ = value;
  // @@protoc_insertion_point(field_set:Test.Header.deptId)
}

// optional uint64 HeadId = 3;
inline void Header::clear_headid() {
  headid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Header::headid() const {
  // @@protoc_insertion_point(field_get:Test.Header.HeadId)
  return headid_;
}
inline void Header::set_headid(::google::protobuf::uint64 value) {
  
  headid_ = value;
  // @@protoc_insertion_point(field_set:Test.Header.HeadId)
}

// optional bool isInlay = 4;
inline void Header::clear_isinlay() {
  isinlay_ = false;
}
inline bool Header::isinlay() const {
  // @@protoc_insertion_point(field_get:Test.Header.isInlay)
  return isinlay_;
}
inline void Header::set_isinlay(bool value) {
  
  isinlay_ = value;
  // @@protoc_insertion_point(field_set:Test.Header.isInlay)
}

// optional string time = 5;
inline void Header::clear_time() {
  time_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Header::time() const {
  // @@protoc_insertion_point(field_get:Test.Header.time)
  return time_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Header::set_time(const ::std::string& value) {
  
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Test.Header.time)
}
inline void Header::set_time(const char* value) {
  
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Test.Header.time)
}
inline void Header::set_time(const char* value, size_t size) {
  
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Test.Header.time)
}
inline ::std::string* Header::mutable_time() {
  
  // @@protoc_insertion_point(field_mutable:Test.Header.time)
  return time_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Header::release_time() {
  
  return time_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Header::set_allocated_time(::std::string* time) {
  if (time != NULL) {
    
  } else {
    
  }
  time_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), time);
  // @@protoc_insertion_point(field_set_allocated:Test.Header.time)
}

// optional uint64 houseId = 6;
inline void Header::clear_houseid() {
  houseid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Header::houseid() const {
  // @@protoc_insertion_point(field_get:Test.Header.houseId)
  return houseid_;
}
inline void Header::set_houseid(::google::protobuf::uint64 value) {
  
  houseid_ = value;
  // @@protoc_insertion_point(field_set:Test.Header.houseId)
}

// -------------------------------------------------------------------

// Body

// optional string barcode = 6;
inline void Body::clear_barcode() {
  barcode_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Body::barcode() const {
  // @@protoc_insertion_point(field_get:Test.Body.barcode)
  return barcode_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Body::set_barcode(const ::std::string& value) {
  
  barcode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Test.Body.barcode)
}
inline void Body::set_barcode(const char* value) {
  
  barcode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Test.Body.barcode)
}
inline void Body::set_barcode(const char* value, size_t size) {
  
  barcode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Test.Body.barcode)
}
inline ::std::string* Body::mutable_barcode() {
  
  // @@protoc_insertion_point(field_mutable:Test.Body.barcode)
  return barcode_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Body::release_barcode() {
  
  return barcode_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Body::set_allocated_barcode(::std::string* barcode) {
  if (barcode != NULL) {
    
  } else {
    
  }
  barcode_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), barcode);
  // @@protoc_insertion_point(field_set_allocated:Test.Body.barcode)
}

// optional string cate = 1;
inline void Body::clear_cate() {
  cate_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Body::cate() const {
  // @@protoc_insertion_point(field_get:Test.Body.cate)
  return cate_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Body::set_cate(const ::std::string& value) {
  
  cate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Test.Body.cate)
}
inline void Body::set_cate(const char* value) {
  
  cate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Test.Body.cate)
}
inline void Body::set_cate(const char* value, size_t size) {
  
  cate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Test.Body.cate)
}
inline ::std::string* Body::mutable_cate() {
  
  // @@protoc_insertion_point(field_mutable:Test.Body.cate)
  return cate_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Body::release_cate() {
  
  return cate_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Body::set_allocated_cate(::std::string* cate) {
  if (cate != NULL) {
    
  } else {
    
  }
  cate_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), cate);
  // @@protoc_insertion_point(field_set_allocated:Test.Body.cate)
}

// optional double amount = 2;
inline void Body::clear_amount() {
  amount_ = 0;
}
inline double Body::amount() const {
  // @@protoc_insertion_point(field_get:Test.Body.amount)
  return amount_;
}
inline void Body::set_amount(double value) {
  
  amount_ = value;
  // @@protoc_insertion_point(field_set:Test.Body.amount)
}

// optional double matact = 3;
inline void Body::clear_matact() {
  matact_ = 0;
}
inline double Body::matact() const {
  // @@protoc_insertion_point(field_get:Test.Body.matact)
  return matact_;
}
inline void Body::set_matact(double value) {
  
  matact_ = value;
  // @@protoc_insertion_point(field_set:Test.Body.matact)
}

// optional uint64 bodyId = 4;
inline void Body::clear_bodyid() {
  bodyid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Body::bodyid() const {
  // @@protoc_insertion_point(field_get:Test.Body.bodyId)
  return bodyid_;
}
inline void Body::set_bodyid(::google::protobuf::uint64 value) {
  
  bodyid_ = value;
  // @@protoc_insertion_point(field_set:Test.Body.bodyId)
}

// optional uint64 headId = 5;
inline void Body::clear_headid() {
  headid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Body::headid() const {
  // @@protoc_insertion_point(field_get:Test.Body.headId)
  return headid_;
}
inline void Body::set_headid(::google::protobuf::uint64 value) {
  
  headid_ = value;
  // @@protoc_insertion_point(field_set:Test.Body.headId)
}

// -------------------------------------------------------------------

// End

// optional uint64 fittingId = 4;
inline void End::clear_fittingid() {
  fittingid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 End::fittingid() const {
  // @@protoc_insertion_point(field_get:Test.End.fittingId)
  return fittingid_;
}
inline void End::set_fittingid(::google::protobuf::uint64 value) {
  
  fittingid_ = value;
  // @@protoc_insertion_point(field_set:Test.End.fittingId)
}

// optional uint64 bodyId = 1;
inline void End::clear_bodyid() {
  bodyid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 End::bodyid() const {
  // @@protoc_insertion_point(field_get:Test.End.bodyId)
  return bodyid_;
}
inline void End::set_bodyid(::google::protobuf::uint64 value) {
  
  bodyid_ = value;
  // @@protoc_insertion_point(field_set:Test.End.bodyId)
}

// optional int32 rownum = 2;
inline void End::clear_rownum() {
  rownum_ = 0;
}
inline ::google::protobuf::int32 End::rownum() const {
  // @@protoc_insertion_point(field_get:Test.End.rownum)
  return rownum_;
}
inline void End::set_rownum(::google::protobuf::int32 value) {
  
  rownum_ = value;
  // @@protoc_insertion_point(field_set:Test.End.rownum)
}

// optional string code = 3;
inline void End::clear_code() {
  code_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& End::code() const {
  // @@protoc_insertion_point(field_get:Test.End.code)
  return code_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void End::set_code(const ::std::string& value) {
  
  code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Test.End.code)
}
inline void End::set_code(const char* value) {
  
  code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Test.End.code)
}
inline void End::set_code(const char* value, size_t size) {
  
  code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Test.End.code)
}
inline ::std::string* End::mutable_code() {
  
  // @@protoc_insertion_point(field_mutable:Test.End.code)
  return code_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* End::release_code() {
  
  return code_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void End::set_allocated_code(::std::string* code) {
  if (code != NULL) {
    
  } else {
    
  }
  code_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), code);
  // @@protoc_insertion_point(field_set_allocated:Test.End.code)
}

// -------------------------------------------------------------------

// Data

// optional .Test.Header header = 3;
inline bool Data::has_header() const {
  return !_is_default_instance_ && header_ != NULL;
}
inline void Data::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) delete header_;
  header_ = NULL;
}
inline const ::Test::Header& Data::header() const {
  // @@protoc_insertion_point(field_get:Test.Data.header)
  return header_ != NULL ? *header_ : *default_instance_->header_;
}
inline ::Test::Header* Data::mutable_header() {
  
  if (header_ == NULL) {
    header_ = new ::Test::Header;
  }
  // @@protoc_insertion_point(field_mutable:Test.Data.header)
  return header_;
}
inline ::Test::Header* Data::release_header() {
  
  ::Test::Header* temp = header_;
  header_ = NULL;
  return temp;
}
inline void Data::set_allocated_header(::Test::Header* header) {
  delete header_;
  header_ = header;
  if (header) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Test.Data.header)
}

// repeated .Test.Body body = 1;
inline int Data::body_size() const {
  return body_.size();
}
inline void Data::clear_body() {
  body_.Clear();
}
inline const ::Test::Body& Data::body(int index) const {
  // @@protoc_insertion_point(field_get:Test.Data.body)
  return body_.Get(index);
}
inline ::Test::Body* Data::mutable_body(int index) {
  // @@protoc_insertion_point(field_mutable:Test.Data.body)
  return body_.Mutable(index);
}
inline ::Test::Body* Data::add_body() {
  // @@protoc_insertion_point(field_add:Test.Data.body)
  return body_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Test::Body >&
Data::body() const {
  // @@protoc_insertion_point(field_list:Test.Data.body)
  return body_;
}
inline ::google::protobuf::RepeatedPtrField< ::Test::Body >*
Data::mutable_body() {
  // @@protoc_insertion_point(field_mutable_list:Test.Data.body)
  return &body_;
}

// repeated .Test.End end = 2;
inline int Data::end_size() const {
  return end_.size();
}
inline void Data::clear_end() {
  end_.Clear();
}
inline const ::Test::End& Data::end(int index) const {
  // @@protoc_insertion_point(field_get:Test.Data.end)
  return end_.Get(index);
}
inline ::Test::End* Data::mutable_end(int index) {
  // @@protoc_insertion_point(field_mutable:Test.Data.end)
  return end_.Mutable(index);
}
inline ::Test::End* Data::add_end() {
  // @@protoc_insertion_point(field_add:Test.Data.end)
  return end_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Test::End >&
Data::end() const {
  // @@protoc_insertion_point(field_list:Test.Data.end)
  return end_;
}
inline ::google::protobuf::RepeatedPtrField< ::Test::End >*
Data::mutable_end() {
  // @@protoc_insertion_point(field_mutable_list:Test.Data.end)
  return &end_;
}

// -------------------------------------------------------------------

// Json

// optional int32 code = 3;
inline void Json::clear_code() {
  code_ = 0;
}
inline ::google::protobuf::int32 Json::code() const {
  // @@protoc_insertion_point(field_get:Test.Json.code)
  return code_;
}
inline void Json::set_code(::google::protobuf::int32 value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:Test.Json.code)
}

// optional string Msg = 1;
inline void Json::clear_msg() {
  msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Json::msg() const {
  // @@protoc_insertion_point(field_get:Test.Json.Msg)
  return msg_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Json::set_msg(const ::std::string& value) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Test.Json.Msg)
}
inline void Json::set_msg(const char* value) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Test.Json.Msg)
}
inline void Json::set_msg(const char* value, size_t size) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Test.Json.Msg)
}
inline ::std::string* Json::mutable_msg() {
  
  // @@protoc_insertion_point(field_mutable:Test.Json.Msg)
  return msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Json::release_msg() {
  
  return msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Json::set_allocated_msg(::std::string* msg) {
  if (msg != NULL) {
    
  } else {
    
  }
  msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:Test.Json.Msg)
}

// optional .Test.Data data = 2;
inline bool Json::has_data() const {
  return !_is_default_instance_ && data_ != NULL;
}
inline void Json::clear_data() {
  if (GetArenaNoVirtual() == NULL && data_ != NULL) delete data_;
  data_ = NULL;
}
inline const ::Test::Data& Json::data() const {
  // @@protoc_insertion_point(field_get:Test.Json.data)
  return data_ != NULL ? *data_ : *default_instance_->data_;
}
inline ::Test::Data* Json::mutable_data() {
  
  if (data_ == NULL) {
    data_ = new ::Test::Data;
  }
  // @@protoc_insertion_point(field_mutable:Test.Json.data)
  return data_;
}
inline ::Test::Data* Json::release_data() {
  
  ::Test::Data* temp = data_;
  data_ = NULL;
  return temp;
}
inline void Json::set_allocated_data(::Test::Data* data) {
  delete data_;
  data_ = data;
  if (data) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Test.Json.data)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_json_2eproto__INCLUDED
