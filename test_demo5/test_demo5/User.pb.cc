// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: User.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "User.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Optry {

namespace {

const ::google::protobuf::Descriptor* User_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  User_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_User_2eproto() {
  protobuf_AddDesc_User_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "User.proto");
  GOOGLE_CHECK(file != NULL);
  User_descriptor_ = file->message_type(0);
  static const int User_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, gender_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, strings_),
  };
  User_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      User_descriptor_,
      User::default_instance_,
      User_offsets_,
      -1,
      -1,
      -1,
      sizeof(User),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_User_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      User_descriptor_, &User::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_User_2eproto() {
  delete User::default_instance_;
  delete User_reflection_;
}

void protobuf_AddDesc_User_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nUser.proto\022\005Optry\"A\n\004User\022\n\n\002id\030\001 \001(\003\022"
    "\014\n\004name\030\002 \001(\t\022\016\n\006gender\030\003 \001(\010\022\017\n\007strings"
    "\030\004 \003(\tb\006proto3", 94);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "User.proto", &protobuf_RegisterTypes);
  User::default_instance_ = new User();
  User::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_User_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_User_2eproto {
  StaticDescriptorInitializer_User_2eproto() {
    protobuf_AddDesc_User_2eproto();
  }
} static_descriptor_initializer_User_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int User::kIdFieldNumber;
const int User::kNameFieldNumber;
const int User::kGenderFieldNumber;
const int User::kStringsFieldNumber;
#endif  // !_MSC_VER

User::User()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Optry.User)
}

void User::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

User::User(const User& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Optry.User)
}

void User::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = GOOGLE_LONGLONG(0);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  gender_ = false;
}

User::~User() {
  // @@protoc_insertion_point(destructor:Optry.User)
  SharedDtor();
}

void User::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void User::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* User::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return User_descriptor_;
}

const User& User::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_User_2eproto();
  return *default_instance_;
}

User* User::default_instance_ = NULL;

User* User::New(::google::protobuf::Arena* arena) const {
  User* n = new User;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void User::Clear() {
  id_ = GOOGLE_LONGLONG(0);
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  gender_ = false;
  strings_.Clear();
}

bool User::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Optry.User)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &id_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // optional string name = 2;
      case 2: {
        if (tag == 18) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Optry.User.name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_gender;
        break;
      }

      // optional bool gender = 3;
      case 3: {
        if (tag == 24) {
         parse_gender:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &gender_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_strings;
        break;
      }

      // repeated string strings = 4;
      case 4: {
        if (tag == 34) {
         parse_strings:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_strings()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->strings(this->strings_size() - 1).data(),
            this->strings(this->strings_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Optry.User.strings");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_strings;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Optry.User)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Optry.User)
  return false;
#undef DO_
}

void User::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Optry.User)
  // optional int64 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->id(), output);
  }

  // optional string name = 2;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Optry.User.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // optional bool gender = 3;
  if (this->gender() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->gender(), output);
  }

  // repeated string strings = 4;
  for (int i = 0; i < this->strings_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->strings(i).data(), this->strings(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "Optry.User.strings");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->strings(i), output);
  }

  // @@protoc_insertion_point(serialize_end:Optry.User)
}

::google::protobuf::uint8* User::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Optry.User)
  // optional int64 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->id(), target);
  }

  // optional string name = 2;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Optry.User.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // optional bool gender = 3;
  if (this->gender() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->gender(), target);
  }

  // repeated string strings = 4;
  for (int i = 0; i < this->strings_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->strings(i).data(), this->strings(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Optry.User.strings");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(4, this->strings(i), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Optry.User)
  return target;
}

int User::ByteSize() const {
  int total_size = 0;

  // optional int64 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->id());
  }

  // optional string name = 2;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // optional bool gender = 3;
  if (this->gender() != 0) {
    total_size += 1 + 1;
  }

  // repeated string strings = 4;
  total_size += 1 * this->strings_size();
  for (int i = 0; i < this->strings_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->strings(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void User::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const User* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const User>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void User::MergeFrom(const User& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  strings_.MergeFrom(from.strings_);
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.gender() != 0) {
    set_gender(from.gender());
  }
}

void User::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void User::CopyFrom(const User& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool User::IsInitialized() const {

  return true;
}

void User::Swap(User* other) {
  if (other == this) return;
  InternalSwap(other);
}
void User::InternalSwap(User* other) {
  std::swap(id_, other->id_);
  name_.Swap(&other->name_);
  std::swap(gender_, other->gender_);
  strings_.UnsafeArenaSwap(&other->strings_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata User::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = User_descriptor_;
  metadata.reflection = User_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// User

// optional int64 id = 1;
void User::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
 ::google::protobuf::int64 User::id() const {
  // @@protoc_insertion_point(field_get:Optry.User.id)
  return id_;
}
 void User::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:Optry.User.id)
}

// optional string name = 2;
void User::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& User::name() const {
  // @@protoc_insertion_point(field_get:Optry.User.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void User::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Optry.User.name)
}
 void User::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Optry.User.name)
}
 void User::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Optry.User.name)
}
 ::std::string* User::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:Optry.User.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* User::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void User::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Optry.User.name)
}

// optional bool gender = 3;
void User::clear_gender() {
  gender_ = false;
}
 bool User::gender() const {
  // @@protoc_insertion_point(field_get:Optry.User.gender)
  return gender_;
}
 void User::set_gender(bool value) {
  
  gender_ = value;
  // @@protoc_insertion_point(field_set:Optry.User.gender)
}

// repeated string strings = 4;
int User::strings_size() const {
  return strings_.size();
}
void User::clear_strings() {
  strings_.Clear();
}
 const ::std::string& User::strings(int index) const {
  // @@protoc_insertion_point(field_get:Optry.User.strings)
  return strings_.Get(index);
}
 ::std::string* User::mutable_strings(int index) {
  // @@protoc_insertion_point(field_mutable:Optry.User.strings)
  return strings_.Mutable(index);
}
 void User::set_strings(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:Optry.User.strings)
  strings_.Mutable(index)->assign(value);
}
 void User::set_strings(int index, const char* value) {
  strings_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:Optry.User.strings)
}
 void User::set_strings(int index, const char* value, size_t size) {
  strings_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Optry.User.strings)
}
 ::std::string* User::add_strings() {
  return strings_.Add();
}
 void User::add_strings(const ::std::string& value) {
  strings_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:Optry.User.strings)
}
 void User::add_strings(const char* value) {
  strings_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:Optry.User.strings)
}
 void User::add_strings(const char* value, size_t size) {
  strings_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:Optry.User.strings)
}
 const ::google::protobuf::RepeatedPtrField< ::std::string>&
User::strings() const {
  // @@protoc_insertion_point(field_list:Optry.User.strings)
  return strings_;
}
 ::google::protobuf::RepeatedPtrField< ::std::string>*
User::mutable_strings() {
  // @@protoc_insertion_point(field_mutable_list:Optry.User.strings)
  return &strings_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace Optry

// @@protoc_insertion_point(global_scope)
