// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__STRUCT_H_
#define TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'camera_image'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'right_eye'
// Member 'left_eye'
#include "tobii_glasses_pkg/msg/detail/eye_data__struct.h"

// Struct defined in msg/TobiiGlasses in the package tobii_glasses_pkg.
typedef struct tobii_glasses_pkg__msg__TobiiGlasses
{
  std_msgs__msg__Header header;
  sensor_msgs__msg__Image camera_image;
  float gaze_position[2];
  float gaze_position_3d[3];
  tobii_glasses_pkg__msg__EyeData right_eye;
  tobii_glasses_pkg__msg__EyeData left_eye;
  float acelerometer[3];
  float gyroscope[3];
} tobii_glasses_pkg__msg__TobiiGlasses;

// Struct for a sequence of tobii_glasses_pkg__msg__TobiiGlasses.
typedef struct tobii_glasses_pkg__msg__TobiiGlasses__Sequence
{
  tobii_glasses_pkg__msg__TobiiGlasses * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tobii_glasses_pkg__msg__TobiiGlasses__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__STRUCT_H_
