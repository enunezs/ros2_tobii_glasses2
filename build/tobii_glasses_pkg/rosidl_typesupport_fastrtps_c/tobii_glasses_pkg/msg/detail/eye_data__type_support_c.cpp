// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tobii_glasses_pkg:msg/EyeData.idl
// generated code does not contain a copyright notice
#include "tobii_glasses_pkg/msg/detail/eye_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tobii_glasses_pkg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tobii_glasses_pkg/msg/detail/eye_data__struct.h"
#include "tobii_glasses_pkg/msg/detail/eye_data__functions.h"
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

#include "rosidl_runtime_c/string.h"  // name
#include "rosidl_runtime_c/string_functions.h"  // name

// forward declare type support functions


using _EyeData__ros_msg_type = tobii_glasses_pkg__msg__EyeData;

static bool _EyeData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _EyeData__ros_msg_type * ros_message = static_cast<const _EyeData__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: pupil_center
  {
    size_t size = 3;
    auto array_ptr = ros_message->pupil_center;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: pupil_diameter
  {
    cdr << ros_message->pupil_diameter;
  }

  // Field name: gaze_direction
  {
    size_t size = 3;
    auto array_ptr = ros_message->gaze_direction;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _EyeData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _EyeData__ros_msg_type * ros_message = static_cast<_EyeData__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr >> ros_message->status;
  }

  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: pupil_center
  {
    size_t size = 3;
    auto array_ptr = ros_message->pupil_center;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: pupil_diameter
  {
    cdr >> ros_message->pupil_diameter;
  }

  // Field name: gaze_direction
  {
    size_t size = 3;
    auto array_ptr = ros_message->gaze_direction;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tobii_glasses_pkg
size_t get_serialized_size_tobii_glasses_pkg__msg__EyeData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _EyeData__ros_msg_type * ros_message = static_cast<const _EyeData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name pupil_center
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->pupil_center;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pupil_diameter
  {
    size_t item_size = sizeof(ros_message->pupil_diameter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gaze_direction
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->gaze_direction;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _EyeData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tobii_glasses_pkg__msg__EyeData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tobii_glasses_pkg
size_t max_serialized_size_tobii_glasses_pkg__msg__EyeData(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: pupil_center
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pupil_diameter
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gaze_direction
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _EyeData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_tobii_glasses_pkg__msg__EyeData(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_EyeData = {
  "tobii_glasses_pkg::msg",
  "EyeData",
  _EyeData__cdr_serialize,
  _EyeData__cdr_deserialize,
  _EyeData__get_serialized_size,
  _EyeData__max_serialized_size
};

static rosidl_message_type_support_t _EyeData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_EyeData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, EyeData)() {
  return &_EyeData__type_support;
}

#if defined(__cplusplus)
}
#endif
