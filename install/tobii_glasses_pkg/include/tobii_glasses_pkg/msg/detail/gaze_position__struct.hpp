// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tobii_glasses_pkg:msg/GazePosition.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__STRUCT_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'glasses_header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tobii_glasses_pkg__msg__GazePosition __attribute__((deprecated))
#else
# define DEPRECATED__tobii_glasses_pkg__msg__GazePosition __declspec(deprecated)
#endif

namespace tobii_glasses_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GazePosition_
{
  using Type = GazePosition_<ContainerAllocator>;

  explicit GazePosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : glasses_header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->latency = 0ul;
      this->gaze_index = 0ul;
      std::fill<typename std::array<float, 2>::iterator, float>(this->gaze_position.begin(), this->gaze_position.end(), 0.0f);
    }
  }

  explicit GazePosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : glasses_header(_alloc, _init),
    gaze_position(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->latency = 0ul;
      this->gaze_index = 0ul;
      std::fill<typename std::array<float, 2>::iterator, float>(this->gaze_position.begin(), this->gaze_position.end(), 0.0f);
    }
  }

  // field types and members
  using _glasses_header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _glasses_header_type glasses_header;
  using _status_type =
    uint8_t;
  _status_type status;
  using _latency_type =
    uint32_t;
  _latency_type latency;
  using _gaze_index_type =
    uint32_t;
  _gaze_index_type gaze_index;
  using _gaze_position_type =
    std::array<float, 2>;
  _gaze_position_type gaze_position;

  // setters for named parameter idiom
  Type & set__glasses_header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->glasses_header = _arg;
    return *this;
  }
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__latency(
    const uint32_t & _arg)
  {
    this->latency = _arg;
    return *this;
  }
  Type & set__gaze_index(
    const uint32_t & _arg)
  {
    this->gaze_index = _arg;
    return *this;
  }
  Type & set__gaze_position(
    const std::array<float, 2> & _arg)
  {
    this->gaze_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tobii_glasses_pkg__msg__GazePosition
    std::shared_ptr<tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tobii_glasses_pkg__msg__GazePosition
    std::shared_ptr<tobii_glasses_pkg::msg::GazePosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GazePosition_ & other) const
  {
    if (this->glasses_header != other.glasses_header) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->latency != other.latency) {
      return false;
    }
    if (this->gaze_index != other.gaze_index) {
      return false;
    }
    if (this->gaze_position != other.gaze_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const GazePosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GazePosition_

// alias to use template instance with default allocator
using GazePosition =
  tobii_glasses_pkg::msg::GazePosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tobii_glasses_pkg

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION__STRUCT_HPP_
