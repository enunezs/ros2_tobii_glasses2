// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tobii_glasses_pkg:msg/GazePosition3D.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__struct.hpp"
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

void GazePosition3D_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tobii_glasses_pkg::msg::GazePosition3D(_init);
}

void GazePosition3D_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tobii_glasses_pkg::msg::GazePosition3D *>(message_memory);
  typed_message->~GazePosition3D();
}

size_t size_function__GazePosition3D__gaze_position_3d(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__GazePosition3D__gaze_position_3d(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__GazePosition3D__gaze_position_3d(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GazePosition3D_message_member_array[5] = {
  {
    "glasses_header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::GazePosition3D, glasses_header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::GazePosition3D, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "latency",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::GazePosition3D, latency),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gaze_index",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::GazePosition3D, gaze_index),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gaze_position_3d",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg::msg::GazePosition3D, gaze_position_3d),  // bytes offset in struct
    nullptr,  // default value
    size_function__GazePosition3D__gaze_position_3d,  // size() function pointer
    get_const_function__GazePosition3D__gaze_position_3d,  // get_const(index) function pointer
    get_function__GazePosition3D__gaze_position_3d,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GazePosition3D_message_members = {
  "tobii_glasses_pkg::msg",  // message namespace
  "GazePosition3D",  // message name
  5,  // number of fields
  sizeof(tobii_glasses_pkg::msg::GazePosition3D),
  GazePosition3D_message_member_array,  // message members
  GazePosition3D_init_function,  // function to initialize message memory (memory has to be allocated)
  GazePosition3D_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GazePosition3D_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GazePosition3D_message_members,
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
get_message_type_support_handle<tobii_glasses_pkg::msg::GazePosition3D>()
{
  return &::tobii_glasses_pkg::msg::rosidl_typesupport_introspection_cpp::GazePosition3D_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tobii_glasses_pkg, msg, GazePosition3D)() {
  return &::tobii_glasses_pkg::msg::rosidl_typesupport_introspection_cpp::GazePosition3D_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
