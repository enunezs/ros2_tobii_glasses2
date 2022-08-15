cmake_minimum_required(VERSION 3.5)
project(tobii_glasses_pkg)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# * find packages for dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

#  TODO: Complete, ensure they match
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(OpenCV REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED) # TODO: Remove python ones
find_package(sensor_msgs REQUIRED)
find_package(pluginlib REQUIRED)
#find_package(tobii_glasses REQUIRED)

include_directories(include ${cv_bridge_INCLUDE_DIRS})

# * Dependencies for library
add_library(tobii_glasses SHARED
  src/tobii_glasses.cpp)
target_include_directories(tobii_glasses
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE "COMPOSITION_BUILDING_DLL")


  
# TODO: C++ scripts
# * Dependencies for base node
add_executable(tobii_glasses_node src/tobii_glasses_publisher.cpp)
ament_target_dependencies(tobii_glasses_node 
  rclcpp 
  std_msgs 
  sensor_msgs 
  OpenCV
  cv_bridge
  image_transport
  pluginlib
)


target_link_libraries(tobii_glasses_node tobii_glasses)

#  "tobii_glasses"
#)
#rclcpp_components_register_nodes(tobii_glasses "tobii_glasses::TobiiGlasses")
#rclcpp_components_register_nodes(TobiiGlasses "TobiiGlasses")

# * Install executables
install(
  TARGETS tobii_glasses_node
  #TobiiGlasses2
  DESTINATION lib/${PROJECT_NAME}
)

# Path to scripts
ament_python_install_package(scripts/)

install(PROGRAMS
  scripts/tobii_glasses.py
  scripts/devel_cam.py
  # scripts/visual.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  # set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  # set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
