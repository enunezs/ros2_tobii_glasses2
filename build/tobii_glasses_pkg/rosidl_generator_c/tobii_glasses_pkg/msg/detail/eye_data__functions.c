// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tobii_glasses_pkg:msg/EyeData.idl
// generated code does not contain a copyright notice
#include "tobii_glasses_pkg/msg/detail/eye_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
tobii_glasses_pkg__msg__EyeData__init(tobii_glasses_pkg__msg__EyeData * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    tobii_glasses_pkg__msg__EyeData__fini(msg);
    return false;
  }
  // pupil_center
  // pupil_diameter
  // gaze_direction
  return true;
}

void
tobii_glasses_pkg__msg__EyeData__fini(tobii_glasses_pkg__msg__EyeData * msg)
{
  if (!msg) {
    return;
  }
  // status
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // pupil_center
  // pupil_diameter
  // gaze_direction
}

tobii_glasses_pkg__msg__EyeData *
tobii_glasses_pkg__msg__EyeData__create()
{
  tobii_glasses_pkg__msg__EyeData * msg = (tobii_glasses_pkg__msg__EyeData *)malloc(sizeof(tobii_glasses_pkg__msg__EyeData));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tobii_glasses_pkg__msg__EyeData));
  bool success = tobii_glasses_pkg__msg__EyeData__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
tobii_glasses_pkg__msg__EyeData__destroy(tobii_glasses_pkg__msg__EyeData * msg)
{
  if (msg) {
    tobii_glasses_pkg__msg__EyeData__fini(msg);
  }
  free(msg);
}


bool
tobii_glasses_pkg__msg__EyeData__Sequence__init(tobii_glasses_pkg__msg__EyeData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  tobii_glasses_pkg__msg__EyeData * data = NULL;
  if (size) {
    data = (tobii_glasses_pkg__msg__EyeData *)calloc(size, sizeof(tobii_glasses_pkg__msg__EyeData));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tobii_glasses_pkg__msg__EyeData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tobii_glasses_pkg__msg__EyeData__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tobii_glasses_pkg__msg__EyeData__Sequence__fini(tobii_glasses_pkg__msg__EyeData__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tobii_glasses_pkg__msg__EyeData__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tobii_glasses_pkg__msg__EyeData__Sequence *
tobii_glasses_pkg__msg__EyeData__Sequence__create(size_t size)
{
  tobii_glasses_pkg__msg__EyeData__Sequence * array = (tobii_glasses_pkg__msg__EyeData__Sequence *)malloc(sizeof(tobii_glasses_pkg__msg__EyeData__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = tobii_glasses_pkg__msg__EyeData__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
tobii_glasses_pkg__msg__EyeData__Sequence__destroy(tobii_glasses_pkg__msg__EyeData__Sequence * array)
{
  if (array) {
    tobii_glasses_pkg__msg__EyeData__Sequence__fini(array);
  }
  free(array);
}
