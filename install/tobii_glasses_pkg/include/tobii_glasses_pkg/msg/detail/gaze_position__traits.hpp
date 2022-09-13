// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tobii_glasses_pkg:msg/GazePosition.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__TRAITS_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__TRAITS_HPP_

#include "tobii_glasses_pkg/msg/detail/gaze_position__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'glasses_header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tobii_glasses_pkg::msg::GazePosition>()
{
  return "tobii_glasses_pkg::msg::GazePosition";
}

template<>
inline const char * name<tobii_glasses_pkg::msg::GazePosition>()
{
  return "tobii_glasses_pkg/msg/GazePosition";
}

template<>
struct has_fixed_size<tobii_glasses_pkg::msg::GazePosition>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<tobii_glasses_pkg::msg::GazePosition>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<tobii_glasses_pkg::msg::GazePosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__TRAITS_HPP_
