// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tobii_glasses_pkg:msg/EyeData.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__STRUCT_H_
#define TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/EyeData in the package tobii_glasses_pkg.
typedef struct tobii_glasses_pkg__msg__EyeData
{
  uint8_t status;
  rosidl_runtime_c__String name;
  float pupil_center[3];
  float pupil_diameter;
  float gaze_direction[3];
} tobii_glasses_pkg__msg__EyeData;

// Struct for a sequence of tobii_glasses_pkg__msg__EyeData.
typedef struct tobii_glasses_pkg__msg__EyeData__Sequence
{
  tobii_glasses_pkg__msg__EyeData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tobii_glasses_pkg__msg__EyeData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__STRUCT_H_
