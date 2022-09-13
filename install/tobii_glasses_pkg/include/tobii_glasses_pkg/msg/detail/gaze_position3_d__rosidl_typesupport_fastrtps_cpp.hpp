// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from tobii_glasses_pkg:msg/GazePosition3D.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "tobii_glasses_pkg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace tobii_glasses_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tobii_glasses_pkg
cdr_serialize(
  const tobii_glasses_pkg::msg::GazePosition3D & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tobii_glasses_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tobii_glasses_pkg::msg::GazePosition3D & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tobii_glasses_pkg
get_serialized_size(
  const tobii_glasses_pkg::msg::GazePosition3D & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tobii_glasses_pkg
max_serialized_size_GazePosition3D(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace tobii_glasses_pkg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tobii_glasses_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tobii_glasses_pkg, msg, GazePosition3D)();

#ifdef __cplusplus
}
#endif

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
