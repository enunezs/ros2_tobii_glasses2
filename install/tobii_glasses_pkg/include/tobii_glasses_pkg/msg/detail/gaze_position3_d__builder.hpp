// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tobii_glasses_pkg:msg/GazePosition3D.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__BUILDER_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__BUILDER_HPP_

#include "tobii_glasses_pkg/msg/detail/gaze_position3_d__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tobii_glasses_pkg
{

namespace msg
{

namespace builder
{

class Init_GazePosition3D_gaze_position_3d
{
public:
  explicit Init_GazePosition3D_gaze_position_3d(::tobii_glasses_pkg::msg::GazePosition3D & msg)
  : msg_(msg)
  {}
  ::tobii_glasses_pkg::msg::GazePosition3D gaze_position_3d(::tobii_glasses_pkg::msg::GazePosition3D::_gaze_position_3d_type arg)
  {
    msg_.gaze_position_3d = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition3D msg_;
};

class Init_GazePosition3D_gaze_index
{
public:
  explicit Init_GazePosition3D_gaze_index(::tobii_glasses_pkg::msg::GazePosition3D & msg)
  : msg_(msg)
  {}
  Init_GazePosition3D_gaze_position_3d gaze_index(::tobii_glasses_pkg::msg::GazePosition3D::_gaze_index_type arg)
  {
    msg_.gaze_index = std::move(arg);
    return Init_GazePosition3D_gaze_position_3d(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition3D msg_;
};

class Init_GazePosition3D_latency
{
public:
  explicit Init_GazePosition3D_latency(::tobii_glasses_pkg::msg::GazePosition3D & msg)
  : msg_(msg)
  {}
  Init_GazePosition3D_gaze_index latency(::tobii_glasses_pkg::msg::GazePosition3D::_latency_type arg)
  {
    msg_.latency = std::move(arg);
    return Init_GazePosition3D_gaze_index(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition3D msg_;
};

class Init_GazePosition3D_status
{
public:
  explicit Init_GazePosition3D_status(::tobii_glasses_pkg::msg::GazePosition3D & msg)
  : msg_(msg)
  {}
  Init_GazePosition3D_latency status(::tobii_glasses_pkg::msg::GazePosition3D::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GazePosition3D_latency(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition3D msg_;
};

class Init_GazePosition3D_glasses_header
{
public:
  Init_GazePosition3D_glasses_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GazePosition3D_status glasses_header(::tobii_glasses_pkg::msg::GazePosition3D::_glasses_header_type arg)
  {
    msg_.glasses_header = std::move(arg);
    return Init_GazePosition3D_status(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition3D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tobii_glasses_pkg::msg::GazePosition3D>()
{
  return tobii_glasses_pkg::msg::builder::Init_GazePosition3D_glasses_header();
}

}  // namespace tobii_glasses_pkg

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__BUILDER_HPP_
