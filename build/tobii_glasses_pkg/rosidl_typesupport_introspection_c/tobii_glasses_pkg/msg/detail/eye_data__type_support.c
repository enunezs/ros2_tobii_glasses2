// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tobii_glasses_pkg:msg/EyeData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tobii_glasses_pkg/msg/detail/eye_data__rosidl_typesupport_introspection_c.h"
#include "tobii_glasses_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tobii_glasses_pkg/msg/detail/eye_data__functions.h"
#include "tobii_glasses_pkg/msg/detail/eye_data__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void EyeData__rosidl_typesupport_introspection_c__EyeData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tobii_glasses_pkg__msg__EyeData__init(message_memory);
}

void EyeData__rosidl_typesupport_introspection_c__EyeData_fini_function(void * message_memory)
{
  tobii_glasses_pkg__msg__EyeData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember EyeData__rosidl_typesupport_introspection_c__EyeData_message_member_array[5] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__EyeData, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__EyeData, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pupil_center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__EyeData, pupil_center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pupil_diameter",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__EyeData, pupil_diameter),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gaze_direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(tobii_glasses_pkg__msg__EyeData, gaze_direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers EyeData__rosidl_typesupport_introspection_c__EyeData_message_members = {
  "tobii_glasses_pkg__msg",  // message namespace
  "EyeData",  // message name
  5,  // number of fields
  sizeof(tobii_glasses_pkg__msg__EyeData),
  EyeData__rosidl_typesupport_introspection_c__EyeData_message_member_array,  // message members
  EyeData__rosidl_typesupport_introspection_c__EyeData_init_function,  // function to initialize message memory (memory has to be allocated)
  EyeData__rosidl_typesupport_introspection_c__EyeData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t EyeData__rosidl_typesupport_introspection_c__EyeData_message_type_support_handle = {
  0,
  &EyeData__rosidl_typesupport_introspection_c__EyeData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tobii_glasses_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tobii_glasses_pkg, msg, EyeData)() {
  if (!EyeData__rosidl_typesupport_introspection_c__EyeData_message_type_support_handle.typesupport_identifier) {
    EyeData__rosidl_typesupport_introspection_c__EyeData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &EyeData__rosidl_typesupport_introspection_c__EyeData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
