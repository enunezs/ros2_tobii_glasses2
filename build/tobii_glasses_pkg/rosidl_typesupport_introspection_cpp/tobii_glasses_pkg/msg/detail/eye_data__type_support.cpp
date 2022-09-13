// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tobii_glasses_pkg:msg/EyeData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tobii_glasses_pkg/msg/detail/eye_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tobii_glasses_pkg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void EyeData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tobii_glasses_pkg::msg::EyeData(_init);
}

void EyeData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tobii_glasses_pkg::msg::EyeData *>(message_memory);
  typed_message->~EyeData();
}

size_t size_function__EyeData__pupil_center(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__EyeData__pupil_center(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__EyeData__pupil_center(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

size_t size_function__EyeData__gaze_direction(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__EyeData__gaze_direction(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__EyeData__gaze_direction(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EyeData_message_member_array[5] = {
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::EyeData, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::EyeData, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pupil_center",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::EyeData, pupil_center),  // bytes offset in struct
    nullptr,  // default value
    size_function__EyeData__pupil_center,  // size() function pointer
    get_const_function__EyeData__pupil_center,  // get_const(index) function pointer
    get_function__EyeData__pupil_center,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pupil_diameter",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::EyeData, pupil_diameter),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gaze_direction",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::EyeData, gaze_direction),  // bytes offset in struct
    nullptr,  // default value
    size_function__EyeData__gaze_direction,  // size() function pointer
    get_const_function__EyeData__gaze_direction,  // get_const(index) function pointer
    get_function__EyeData__gaze_direction,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EyeData_message_members = {
  "tobii_glasses_pkg::msg",  // message namespace
  "EyeData",  // message name
  5,  // number of fields
  sizeof(tobii_glasses_pkg::msg::EyeData),
  EyeData_message_member_array,  // message members
  EyeData_init_function,  // function to initialize message memory (memory has to be allocated)
  EyeData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EyeData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EyeData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tobii_glasses_pkg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tobii_glasses_pkg::msg::EyeData>()
{
  return &::tobii_glasses_pkg::msg::rosidl_typesupport_introspection_cpp::EyeData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tobii_glasses_pkg, msg, EyeData)() {
  return &::tobii_glasses_pkg::msg::rosidl_typesupport_introspection_cpp::EyeData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
