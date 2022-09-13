// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__struct.h"
#include "tobii_glasses_pkg/msg/detail/tobii_glasses__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);
bool tobii_glasses_pkg__msg__gaze_position__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tobii_glasses_pkg__msg__gaze_position__convert_to_py(void * raw_ros_message);
bool tobii_glasses_pkg__msg__gaze_position3_d__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tobii_glasses_pkg__msg__gaze_position3_d__convert_to_py(void * raw_ros_message);
bool tobii_glasses_pkg__msg__eye_data__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tobii_glasses_pkg__msg__eye_data__convert_to_py(void * raw_ros_message);
bool tobii_glasses_pkg__msg__eye_data__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tobii_glasses_pkg__msg__eye_data__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tobii_glasses_pkg__msg__tobii_glasses__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("tobii_glasses_pkg.msg._tobii_glasses.TobiiGlasses", full_classname_dest, 49) == 0);
  }
  tobii_glasses_pkg__msg__TobiiGlasses * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // camera_image
    PyObject * field = PyObject_GetAttrString(_pymsg, "camera_image");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->camera_image)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // gaze_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "gaze_position");
    if (!field) {
      return false;
    }
    if (!tobii_glasses_pkg__msg__gaze_position__convert_from_py(field, &ros_message->gaze_position)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // gaze_position_3d
    PyObject * field = PyObject_GetAttrString(_pymsg, "gaze_position_3d");
    if (!field) {
      return false;
    }
    if (!tobii_glasses_pkg__msg__gaze_position3_d__convert_from_py(field, &ros_message->gaze_position_3d)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // right_eye
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_eye");
    if (!field) {
      return false;
    }
    if (!tobii_glasses_pkg__msg__eye_data__convert_from_py(field, &ros_message->right_eye)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // left_eye
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_eye");
    if (!field) {
      return false;
    }
    if (!tobii_glasses_pkg__msg__eye_data__convert_from_py(field, &ros_message->left_eye)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tobii_glasses_pkg__msg__tobii_glasses__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TobiiGlasses */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tobii_glasses_pkg.msg._tobii_glasses");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TobiiGlasses");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tobii_glasses_pkg__msg__TobiiGlasses * ros_message = (tobii_glasses_pkg__msg__TobiiGlasses *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // camera_image
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->camera_image);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "camera_image", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gaze_position
    PyObject * field = NULL;
    field = tobii_glasses_pkg__msg__gaze_position__convert_to_py(&ros_message->gaze_position);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "gaze_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gaze_position_3d
    PyObject * field = NULL;
    field = tobii_glasses_pkg__msg__gaze_position3_d__convert_to_py(&ros_message->gaze_position_3d);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "gaze_position_3d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_eye
    PyObject * field = NULL;
    field = tobii_glasses_pkg__msg__eye_data__convert_to_py(&ros_message->right_eye);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_eye", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_eye
    PyObject * field = NULL;
    field = tobii_glasses_pkg__msg__eye_data__convert_to_py(&ros_message->left_eye);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_eye", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
