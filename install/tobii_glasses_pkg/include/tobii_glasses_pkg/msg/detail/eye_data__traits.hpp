// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tobii_glasses_pkg:msg/EyeData.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__TRAITS_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__TRAITS_HPP_

#include "tobii_glasses_pkg/msg/detail/eye_data__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tobii_glasses_pkg::msg::EyeData>()
{
  return "tobii_glasses_pkg::msg::EyeData";
}

template<>
inline const char * name<tobii_glasses_pkg::msg::EyeData>()
{
  return "tobii_glasses_pkg/msg/EyeData";
}

template<>
struct has_fixed_size<tobii_glasses_pkg::msg::EyeData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tobii_glasses_pkg::msg::EyeData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tobii_glasses_pkg::msg::EyeData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__TRAITS_HPP_
