// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tobii_glasses_pkg:msg/GazePosition3D.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__STRUCT_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__STRUCT_HPP_

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
# define DEPRECATED__tobii_glasses_pkg__msg__GazePosition3D __attribute__((deprecated))
#else
# define DEPRECATED__tobii_glasses_pkg__msg__GazePosition3D __declspec(deprecated)
#endif

namespace tobii_glasses_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GazePosition3D_
{
  using Type = GazePosition3D_<ContainerAllocator>;

  explicit GazePosition3D_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : glasses_header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->latency = 0ul;
      this->gaze_index = 0ul;
      std::fill<typename std::array<float, 3>::iterator, float>(this->gaze_position_3d.begin(), this->gaze_position_3d.end(), 0.0f);
    }
  }

  explicit GazePosition3D_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : glasses_header(_alloc, _init),
    gaze_position_3d(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->latency = 0ul;
      this->gaze_index = 0ul;
      std::fill<typename std::array<float, 3>::iterator, float>(this->gaze_position_3d.begin(), this->gaze_position_3d.end(), 0.0f);
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
  using _gaze_position_3d_type =
    std::array<float, 3>;
  _gaze_position_3d_type gaze_position_3d;

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
  Type & set__gaze_position_3d(
    const std::array<float, 3> & _arg)
  {
    this->gaze_position_3d = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator> *;
  using ConstRawPtr =
    const tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tobii_glasses_pkg__msg__GazePosition3D
    std::shared_ptr<tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tobii_glasses_pkg__msg__GazePosition3D
    std::shared_ptr<tobii_glasses_pkg::msg::GazePosition3D_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GazePosition3D_ & other) const
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
    if (this->gaze_position_3d != other.gaze_position_3d) {
      return false;
    }
    return true;
  }
  bool operator!=(const GazePosition3D_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GazePosition3D_

// alias to use template instance with default allocator
using GazePosition3D =
  tobii_glasses_pkg::msg::GazePosition3D_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tobii_glasses_pkg

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__GAZE_POSITION3_D__STRUCT_HPP_
