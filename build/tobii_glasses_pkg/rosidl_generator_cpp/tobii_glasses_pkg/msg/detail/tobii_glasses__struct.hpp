// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tobii_glasses_pkg:msg/TobiiGlasses.idl
// generated code does not contain a copyright notice

#ifndef TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__STRUCT_HPP_
#define TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'camera_image'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'right_eye'
// Member 'left_eye'
#include "tobii_glasses_pkg/msg/detail/eye_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tobii_glasses_pkg__msg__TobiiGlasses __attribute__((deprecated))
#else
# define DEPRECATED__tobii_glasses_pkg__msg__TobiiGlasses __declspec(deprecated)
#endif

namespace tobii_glasses_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TobiiGlasses_
{
  using Type = TobiiGlasses_<ContainerAllocator>;

  explicit TobiiGlasses_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    camera_image(_init),
    right_eye(_init),
    left_eye(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 2>::iterator, float>(this->gaze_position.begin(), this->gaze_position.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->gaze_position_3d.begin(), this->gaze_position_3d.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->acelerometer.begin(), this->acelerometer.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->gyroscope.begin(), this->gyroscope.end(), 0.0f);
    }
  }

  explicit TobiiGlasses_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    camera_image(_alloc, _init),
    gaze_position(_alloc),
    gaze_position_3d(_alloc),
    right_eye(_alloc, _init),
    left_eye(_alloc, _init),
    acelerometer(_alloc),
    gyroscope(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 2>::iterator, float>(this->gaze_position.begin(), this->gaze_position.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->gaze_position_3d.begin(), this->gaze_position_3d.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->acelerometer.begin(), this->acelerometer.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->gyroscope.begin(), this->gyroscope.end(), 0.0f);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _camera_image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _camera_image_type camera_image;
  using _gaze_position_type =
    std::array<float, 2>;
  _gaze_position_type gaze_position;
  using _gaze_position_3d_type =
    std::array<float, 3>;
  _gaze_position_3d_type gaze_position_3d;
  using _right_eye_type =
    tobii_glasses_pkg::msg::EyeData_<ContainerAllocator>;
  _right_eye_type right_eye;
  using _left_eye_type =
    tobii_glasses_pkg::msg::EyeData_<ContainerAllocator>;
  _left_eye_type left_eye;
  using _acelerometer_type =
    std::array<float, 3>;
  _acelerometer_type acelerometer;
  using _gyroscope_type =
    std::array<float, 3>;
  _gyroscope_type gyroscope;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__camera_image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->camera_image = _arg;
    return *this;
  }
  Type & set__gaze_position(
    const std::array<float, 2> & _arg)
  {
    this->gaze_position = _arg;
    return *this;
  }
  Type & set__gaze_position_3d(
    const std::array<float, 3> & _arg)
  {
    this->gaze_position_3d = _arg;
    return *this;
  }
  Type & set__right_eye(
    const tobii_glasses_pkg::msg::EyeData_<ContainerAllocator> & _arg)
  {
    this->right_eye = _arg;
    return *this;
  }
  Type & set__left_eye(
    const tobii_glasses_pkg::msg::EyeData_<ContainerAllocator> & _arg)
  {
    this->left_eye = _arg;
    return *this;
  }
  Type & set__acelerometer(
    const std::array<float, 3> & _arg)
  {
    this->acelerometer = _arg;
    return *this;
  }
  Type & set__gyroscope(
    const std::array<float, 3> & _arg)
  {
    this->gyroscope = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator> *;
  using ConstRawPtr =
    const tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tobii_glasses_pkg__msg__TobiiGlasses
    std::shared_ptr<tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tobii_glasses_pkg__msg__TobiiGlasses
    std::shared_ptr<tobii_glasses_pkg::msg::TobiiGlasses_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TobiiGlasses_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->camera_image != other.camera_image) {
      return false;
    }
    if (this->gaze_position != other.gaze_position) {
      return false;
    }
    if (this->gaze_position_3d != other.gaze_position_3d) {
      return false;
    }
    if (this->right_eye != other.right_eye) {
      return false;
    }
    if (this->left_eye != other.left_eye) {
      return false;
    }
    if (this->acelerometer != other.acelerometer) {
      return false;
    }
    if (this->gyroscope != other.gyroscope) {
      return false;
    }
    return true;
  }
  bool operator!=(const TobiiGlasses_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TobiiGlasses_

// alias to use template instance with default allocator
using TobiiGlasses =
  tobii_glasses_pkg::msg::TobiiGlasses_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tobii_glasses_pkg

#endif  // TOBII_GLASSES_PKG__MSG__DETAIL__TOBII_GLASSES__STRUCT_HPP_
