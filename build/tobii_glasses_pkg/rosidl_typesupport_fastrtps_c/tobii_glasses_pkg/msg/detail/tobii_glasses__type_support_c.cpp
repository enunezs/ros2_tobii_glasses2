// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
// generated code does not contain a copyright notice
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tobii_glasses_pkg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__struct.h"
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__functions.h"
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

#include "sensor_msgs/msg/detail/image__functions.h"  // camera_image
#include "std_msgs/msg/detail/header__functions.h"  // header
#include "tobii_glasses_pkg/msg/detail/eye_data__functions.h"  // left_eye, right_eye
#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__functions.h"  // gaze_position_3d
#include "tobii_glasses_pkg/msg/detail/gaze_position__functions.h"  // gaze_position

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tobii_glasses_pkg
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tobii_glasses_pkg
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tobii_glasses_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();
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
size_t get_serialized_size_tobii_glasses_pkg__msg__EyeData(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tobii_glasses_pkg__msg__EyeData(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, EyeData)();
size_t get_serialized_size_tobii_glasses_pkg__msg__GazePosition(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tobii_glasses_pkg__msg__GazePosition(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, GazePosition)();
size_t get_serialized_size_tobii_glasses_pkg__msg__GazePosition3D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tobii_glasses_pkg__msg__GazePosition3D(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, GazePosition3D)();


using _TobiiGlasses__ros_msg_type = tobii_glasses_pkg__msg__TobiiGlasses;

static bool _TobiiGlasses__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TobiiGlasses__ros_msg_type * ros_message = static_cast<const _TobiiGlasses__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: camera_image
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->camera_image, cdr))
    {
      return false;
    }
  }

  // Field name: gaze_position
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, GazePosition
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->gaze_position, cdr))
    {
      return false;
    }
  }

  // Field name: gaze_position_3d
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, GazePosition3D
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->gaze_position_3d, cdr))
    {
      return false;
    }
  }

  // Field name: right_eye
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, EyeData
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->right_eye, cdr))
    {
      return false;
    }
  }

  // Field name: left_eye
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, EyeData
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->left_eye, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _TobiiGlasses__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TobiiGlasses__ros_msg_type * ros_message = static_cast<_TobiiGlasses__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: camera_image
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->camera_image))
    {
      return false;
    }
  }

  // Field name: gaze_position
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, GazePosition
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->gaze_position))
    {
      return false;
    }
  }

  // Field name: gaze_position_3d
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, GazePosition3D
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->gaze_position_3d))
    {
      return false;
    }
  }

  // Field name: right_eye
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, EyeData
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->right_eye))
    {
      return false;
    }
  }

  // Field name: left_eye
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, EyeData
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->left_eye))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tobii_glasses_pkg
size_t get_serialized_size_tobii_glasses_pkg__msg__TobiiGlasses(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TobiiGlasses__ros_msg_type * ros_message = static_cast<const _TobiiGlasses__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name camera_image

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->camera_image), current_alignment);
  // field.name gaze_position

  current_alignment += get_serialized_size_tobii_glasses_pkg__msg__GazePosition(
    &(ros_message->gaze_position), current_alignment);
  // field.name gaze_position_3d

  current_alignment += get_serialized_size_tobii_glasses_pkg__msg__GazePosition3D(
    &(ros_message->gaze_position_3d), current_alignment);
  // field.name right_eye

  current_alignment += get_serialized_size_tobii_glasses_pkg__msg__EyeData(
    &(ros_message->right_eye), current_alignment);
  // field.name left_eye

  current_alignment += get_serialized_size_tobii_glasses_pkg__msg__EyeData(
    &(ros_message->left_eye), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _TobiiGlasses__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tobii_glasses_pkg__msg__TobiiGlasses(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tobii_glasses_pkg
size_t max_serialized_size_tobii_glasses_pkg__msg__TobiiGlasses(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: camera_image
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }
  // member: gaze_position
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_tobii_glasses_pkg__msg__GazePosition(
        full_bounded, current_alignment);
    }
  }
  // member: gaze_position_3d
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_tobii_glasses_pkg__msg__GazePosition3D(
        full_bounded, current_alignment);
    }
  }
  // member: right_eye
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_tobii_glasses_pkg__msg__EyeData(
        full_bounded, current_alignment);
    }
  }
  // member: left_eye
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_tobii_glasses_pkg__msg__EyeData(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _TobiiGlasses__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_tobii_glasses_pkg__msg__TobiiGlasses(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_TobiiGlasses = {
  "tobii_glasses_pkg::msg",
  "TobiiGlasses",
  _TobiiGlasses__cdr_serialize,
  _TobiiGlasses__cdr_deserialize,
  _TobiiGlasses__get_serialized_size,
  _TobiiGlasses__max_serialized_size
};

static rosidl_message_type_support_t _TobiiGlasses__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TobiiGlasses,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tobii_glasses_pkg, msg, TobiiGlasses)() {
  return &_TobiiGlasses__type_support;
}

#if defined(__cplusplus)
}
#endif
