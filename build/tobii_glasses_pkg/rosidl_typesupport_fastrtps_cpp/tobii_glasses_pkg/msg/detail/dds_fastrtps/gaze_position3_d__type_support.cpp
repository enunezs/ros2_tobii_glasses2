// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from tobii_glasses_pkg:msg/GazePosition3D.idl
// generated code does not contain a copyright notice
#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__rosidl_typesupport_fastrtps_cpp.hpp"
#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: glasses_header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.glasses_header,
    cdr);
  // Member: status
  cdr << ros_message.status;
  // Member: latency
  cdr << ros_message.latency;
  // Member: gaze_index
  cdr << ros_message.gaze_index;
  // Member: gaze_position_3d
  {
    cdr << ros_message.gaze_position_3d;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tobii_glasses_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tobii_glasses_pkg::msg::GazePosition3D & ros_message)
{
  // Member: glasses_header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.glasses_header);

  // Member: status
  cdr >> ros_message.status;

  // Member: latency
  cdr >> ros_message.latency;

  // Member: gaze_index
  cdr >> ros_message.gaze_index;

  // Member: gaze_position_3d
  {
    cdr >> ros_message.gaze_position_3d;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tobii_glasses_pkg
get_serialized_size(
  const tobii_glasses_pkg::msg::GazePosition3D & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: glasses_header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.glasses_header, current_alignment);
  // Member: status
  {
    size_t item_size = sizeof(ros_message.status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: latency
  {
    size_t item_size = sizeof(ros_message.latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gaze_index
  {
    size_t item_size = sizeof(ros_message.gaze_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gaze_position_3d
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.gaze_position_3d[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tobii_glasses_pkg
max_serialized_size_GazePosition3D(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: glasses_header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: latency
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gaze_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gaze_position_3d
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _GazePosition3D__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tobii_glasses_pkg::msg::GazePosition3D *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GazePosition3D__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tobii_glasses_pkg::msg::GazePosition3D *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GazePosition3D__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tobii_glasses_pkg::msg::GazePosition3D *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GazePosition3D__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_GazePosition3D(full_bounded, 0);
}

static message_type_support_callbacks_t _GazePosition3D__callbacks = {
  "tobii_glasses_pkg::msg",
  "GazePosition3D",
  _GazePosition3D__cdr_serialize,
  _GazePosition3D__cdr_deserialize,
  _GazePosition3D__get_serialized_size,
  _GazePosition3D__max_serialized_size
};

static rosidl_message_type_support_t _GazePosition3D__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GazePosition3D__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace tobii_glasses_pkg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tobii_glasses_pkg
const rosidl_message_type_support_t *
get_message_type_support_handle<tobii_glasses_pkg::msg::GazePosition3D>()
{
  return &tobii_glasses_pkg::msg::typesupport_fastrtps_cpp::_GazePosition3D__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tobii_glasses_pkg, msg, GazePosition3D)() {
  return &tobii_glasses_pkg::msg::typesupport_fastrtps_cpp::_GazePosition3D__handle;
}

#ifdef __cplusplus
}
#endif
