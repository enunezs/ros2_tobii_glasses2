// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tobii_glasses_pkg:msg/GazePosition.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__BUILDER_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__BUILDER_HPP_

#include "tobii_glasses_pkg/msg/detail/gaze_position__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tobii_glasses_pkg
{

namespace msg
{

namespace builder
{

class Init_GazePosition_gaze_position
{
public:
  explicit Init_GazePosition_gaze_position(::tobii_glasses_pkg::msg::GazePosition & msg)
  : msg_(msg)
  {}
  ::tobii_glasses_pkg::msg::GazePosition gaze_position(::tobii_glasses_pkg::msg::GazePosition::_gaze_position_type arg)
  {
    msg_.gaze_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition msg_;
};

class Init_GazePosition_gaze_index
{
public:
  explicit Init_GazePosition_gaze_index(::tobii_glasses_pkg::msg::GazePosition & msg)
  : msg_(msg)
  {}
  Init_GazePosition_gaze_position gaze_index(::tobii_glasses_pkg::msg::GazePosition::_gaze_index_type arg)
  {
    msg_.gaze_index = std::move(arg);
    return Init_GazePosition_gaze_position(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition msg_;
};

class Init_GazePosition_latency
{
public:
  explicit Init_GazePosition_latency(::tobii_glasses_pkg::msg::GazePosition & msg)
  : msg_(msg)
  {}
  Init_GazePosition_gaze_index latency(::tobii_glasses_pkg::msg::GazePosition::_latency_type arg)
  {
    msg_.latency = std::move(arg);
    return Init_GazePosition_gaze_index(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition msg_;
};

class Init_GazePosition_status
{
public:
  explicit Init_GazePosition_status(::tobii_glasses_pkg::msg::GazePosition & msg)
  : msg_(msg)
  {}
  Init_GazePosition_latency status(::tobii_glasses_pkg::msg::GazePosition::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GazePosition_latency(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition msg_;
};

class Init_GazePosition_glasses_header
{
public:
  Init_GazePosition_glasses_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GazePosition_status glasses_header(::tobii_glasses_pkg::msg::GazePosition::_glasses_header_type arg)
  {
    msg_.glasses_header = std::move(arg);
    return Init_GazePosition_status(msg_);
  }

private:
  ::tobii_glasses_pkg::msg::GazePosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tobii_glasses_pkg::msg::GazePosition>()
{
  return tobii_glasses_pkg::msg::builder::Init_GazePosition_glasses_header();
}

}  // namespace tobii_glasses_pkg

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__BUILDER_HPP_
