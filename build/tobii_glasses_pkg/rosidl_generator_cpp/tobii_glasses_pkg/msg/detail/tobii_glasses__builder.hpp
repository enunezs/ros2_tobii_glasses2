// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__BUILDER_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__BUILDER_HPP_

#include "tobii_glasses_pkg/msg/detail/tobii_glasses__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tobii_glasses_pkg
{

namespace msg
{

namespace builder
{

class Init_TobiiGlasses_left_eye
{
public:
  explicit Init_TobiiGlasses_left_eye(::tobii_glasses_pkg::msg::TobiiGlasses & msg)
  : msg_(msg)
  {}
  ::tobii_glasses_pkg::msg::TobiiGlasses left_eye(::tobii_glasses_pkg::msg::TobiiGlasses::_left_eye_type arg)
  {
    msg_.left_eye = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::TobiiGlasses msg_;
};

class Init_TobiiGlasses_right_eye
{
public:
  explicit Init_TobiiGlasses_right_eye(::tobii_glasses_pkg::msg::TobiiGlasses & msg)
  : msg_(msg)
  {}
  Init_TobiiGlasses_left_eye right_eye(::tobii_glasses_pkg::msg::TobiiGlasses::_right_eye_type arg)
  {
    msg_.right_eye = std::move(arg);
    return Init_TobiiGlasses_left_eye(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::TobiiGlasses msg_;
};

class Init_TobiiGlasses_gaze_position_3d
{
public:
  explicit Init_TobiiGlasses_gaze_position_3d(::tobii_glasses_pkg::msg::TobiiGlasses & msg)
  : msg_(msg)
  {}
  Init_TobiiGlasses_right_eye gaze_position_3d(::tobii_glasses_pkg::msg::TobiiGlasses::_gaze_position_3d_type arg)
  {
    msg_.gaze_position_3d = std::move(arg);
    return Init_TobiiGlasses_right_eye(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::TobiiGlasses msg_;
};

class Init_TobiiGlasses_gaze_position
{
public:
  explicit Init_TobiiGlasses_gaze_position(::tobii_glasses_pkg::msg::TobiiGlasses & msg)
  : msg_(msg)
  {}
  Init_TobiiGlasses_gaze_position_3d gaze_position(::tobii_glasses_pkg::msg::TobiiGlasses::_gaze_position_type arg)
  {
    msg_.gaze_position = std::move(arg);
    return Init_TobiiGlasses_gaze_position_3d(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::TobiiGlasses msg_;
};

class Init_TobiiGlasses_camera_image
{
public:
  explicit Init_TobiiGlasses_camera_image(::tobii_glasses_pkg::msg::TobiiGlasses & msg)
  : msg_(msg)
  {}
  Init_TobiiGlasses_gaze_position camera_image(::tobii_glasses_pkg::msg::TobiiGlasses::_camera_image_type arg)
  {
    msg_.camera_image = std::move(arg);
    return Init_TobiiGlasses_gaze_position(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::TobiiGlasses msg_;
};

class Init_TobiiGlasses_header
{
public:
  Init_TobiiGlasses_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TobiiGlasses_camera_image header(::tobii_glasses_pkg::msg::TobiiGlasses::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TobiiGlasses_camera_image(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::TobiiGlasses msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tobii_glasses_pkg::msg::TobiiGlasses>()
{
  return tobii_glasses_pkg::msg::builder::Init_TobiiGlasses_header();
}

}  // namespace tobii_glasses_pkg

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__BUILDER_HPP_
