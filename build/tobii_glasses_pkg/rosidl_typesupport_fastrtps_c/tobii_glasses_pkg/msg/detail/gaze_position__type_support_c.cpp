// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tobii_glasses_pkg:msg/GazePosition.idl
// generated code does not contain a copyright notice
#include "tobii_glasses_pkg/msg/detail/gaze_position__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tobii_glasses_pkg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tobii_glasses_pkg/msg/detail/gaze_position__struct.h"
#include "tobii_glasses_pkg/msg/detail/gaze_position__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // glasses_header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tobii_glasses_pkg
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tobii_glasses_pkg
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tobii_glasses_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _GazePosition__ros_msg_type = tobii_glasses_pkg__msg__GazePosition;

static bool _GazePosition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GazePosition__ros_msg_type * ros_message = static_cast<const _GazePosition__ros_msg_type *>(untyped_ros_message);
  // Field name: glasses_header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->glasses_header, cdr))
    {
      return false;
    }
  }

  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: latency
  {
    cdr << ros_message->latency;
  }

  // Field name: gaze_index
  {
    cdr << ros_message->gaze_index;
  }

  // Field name: gaze_position
  {
    size_t size = 2;
    auto array_ptr = ros_message->gaze_position;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _GazePosition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GazePosition__ros_msg_type * ros_message = static_cast<_GazePosition__ros_msg_type *>(untyped_ros_message);
  // Field name: glasses_header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->glasses_header))
    {
      return false;
    }
  }

  // Field name: status
  {
    cdr >> ros_message->status;
  }

  // Field name: latency
  {
    cdr >> ros_message->latency;
  }

  // Field name: gaze_index
  {
    cdr >> ros_message->gaze_index;
  }

  // Field name: gaze_position
  {
    size_t size = 2;
    auto array_ptr = ros_message->gaze_position;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tobii_glasses_pkg
size_t get_serialized_size_tobii_glasses_pkg__msg__GazePosition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GazePosition__ros_msg_type * ros_message = static_cast<const _GazePosition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name glasses_header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->glasses_header), current_alignment);
  // field.name status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name latency
  {
    size_t item_size = sizeof(ros_message->latency);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gaze_index
  {
    size_t item_size = sizeof(ros_message->gaze_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gaze_position
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->gaze_position;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GazePosition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tobii_glasses_pkg__msg__GazePosition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tobii_glasses_pkg
size_t max_serialized_size_tobii_glasses_pkg__msg__GazePosition(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: glasses_header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: latency
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gaze_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gaze_position
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _GazePosition__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_tobii_glasses_pkg__msg__GazePosition(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_GazePosition = {
  "tobii_glasses_pkg::msg",
  "GazePosition",
  _GazePosition__cdr_serialize,
  _GazePosition__cdr_deserialize,
  _GazePosition__get_serialized_size,
  _GazePosition__max_serialized_size
};

static rosidl_message_type_support_t _GazePosition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GazePosition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, GazePosition)() {
  return &_GazePosition__type_support;
}

#if defined(__cplusplus)
}
#endif
