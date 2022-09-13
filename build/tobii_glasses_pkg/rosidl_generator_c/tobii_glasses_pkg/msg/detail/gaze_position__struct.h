// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tobii_glasses_pkg:msg/GazePosition.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__STRUCT_H_
#define TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'glasses_header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/GazePosition in the package tobii_glasses_pkg.
typedef struct tobii_glasses_pkg__msg__GazePosition
{
  std_msgs__msg__Header glasses_header;
  uint8_t status;
  uint32_t latency;
  uint32_t gaze_index;
  float gaze_position[2];
} tobii_glasses_pkg__msg__GazePosition;

// Struct for a sequence of tobii_glasses_pkg__msg__GazePosition.
typedef struct tobii_glasses_pkg__msg__GazePosition__Sequence
{
  tobii_glasses_pkg__msg__GazePosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tobii_glasses_pkg__msg__GazePosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__STRUCT_H_
