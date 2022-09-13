// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tobii_glasses_pkg:msg/EyeData.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__BUILDER_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__BUILDER_HPP_

#include "tobii_glasses_pkg/msg/detail/eye_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tobii_glasses_pkg
{

namespace msg
{

namespace builder
{

class Init_EyeData_gaze_direction
{
public:
  explicit Init_EyeData_gaze_direction(::tobii_glasses_pkg::msg::EyeData & msg)
  : msg_(msg)
  {}
  ::tobii_glasses_pkg::msg::EyeData gaze_direction(::tobii_glasses_pkg::msg::EyeData::_gaze_direction_type arg)
  {
    msg_.gaze_direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::EyeData msg_;
};

class Init_EyeData_pupil_diameter
{
public:
  explicit Init_EyeData_pupil_diameter(::tobii_glasses_pkg::msg::EyeData & msg)
  : msg_(msg)
  {}
  Init_EyeData_gaze_direction pupil_diameter(::tobii_glasses_pkg::msg::EyeData::_pupil_diameter_type arg)
  {
    msg_.pupil_diameter = std::move(arg);
    return Init_EyeData_gaze_direction(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::EyeData msg_;
};

class Init_EyeData_pupil_center
{
public:
  explicit Init_EyeData_pupil_center(::tobii_glasses_pkg::msg::EyeData & msg)
  : msg_(msg)
  {}
  Init_EyeData_pupil_diameter pupil_center(::tobii_glasses_pkg::msg::EyeData::_pupil_center_type arg)
  {
    msg_.pupil_center = std::move(arg);
    return Init_EyeData_pupil_diameter(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::EyeData msg_;
};

class Init_EyeData_name
{
public:
  explicit Init_EyeData_name(::tobii_glasses_pkg::msg::EyeData & msg)
  : msg_(msg)
  {}
  Init_EyeData_pupil_center name(::tobii_glasses_pkg::msg::EyeData::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_EyeData_pupil_center(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::EyeData msg_;
};

class Init_EyeData_status
{
public:
  Init_EyeData_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EyeData_name status(::tobii_glasses_pkg::msg::EyeData::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_EyeData_name(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::EyeData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tobii_glasses_pkg::msg::EyeData>()
{
  return tobii_glasses_pkg::msg::builder::Init_EyeData_status();
}

}  // namespace tobii_glasses_pkg

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__EYE_DATA__BUILDER_HPP_
