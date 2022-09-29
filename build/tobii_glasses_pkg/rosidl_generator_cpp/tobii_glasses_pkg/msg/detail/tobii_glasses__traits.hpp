// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__TRAITS_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__TRAITS_HPP_

#include "tobii_glasses_pkg/msg/detail/tobii_glasses__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'camera_image'
#include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'gaze_position'
#include "tobii_glasses_pkg/msg/detail/gaze_position__traits.hpp"
// Member 'gaze_position_3d'
#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__traits.hpp"
// Member 'right_eye'
// Member 'left_eye'
#include "tobii_glasses_pkg/msg/detail/eye_data__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tobii_glasses_pkg::msg::TobiiGlasses>()
{
  return "tobii_glasses_pkg::msg::TobiiGlasses";
}

template<>
inline const char * name<tobii_glasses_pkg::msg::TobiiGlasses>()
{
  return "tobii_glasses_pkg/msg/TobiiGlasses";
}

template<>
struct has_fixed_size<tobii_glasses_pkg::msg::TobiiGlasses>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value && has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<tobii_glasses_pkg::msg::EyeData>::value && has_fixed_size<tobii_glasses_pkg::msg::GazePosition3D>::value && has_fixed_size<tobii_glasses_pkg::msg::GazePosition>::value> {};

template<>
struct has_bounded_size<tobii_glasses_pkg::msg::TobiiGlasses>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value && has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<tobii_glasses_pkg::msg::EyeData>::value && has_bounded_size<tobii_glasses_pkg::msg::GazePosition3D>::value && has_bounded_size<tobii_glasses_pkg::msg::GazePosition>::value> {};

template<>
struct is_message<tobii_glasses_pkg::msg::TobiiGlasses>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__TRAITS_HPP_
