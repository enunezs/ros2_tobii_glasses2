# generated from
# ament_cmake_core/cmake/uninstall_target/ament_cmake_uninstall_target.cmake.in

function(ament_cmake_uninstall_target_remove_empty_directories path)
<<<<<<< HEAD
  set(install_space "/home/ema/workspaces/ros2_tobii_glasses2/install/tobii_glasses_pkg")
=======
  set(install_space "/home/usr/workspaces/ros2_tobii_glasses2/install/tobii_glasses_pkg")
>>>>>>> 042d9849849bd86e9fad5b9d0f8e382dea69bd42
  if(install_space STREQUAL "")
    message(FATAL_ERROR "The CMAKE_INSTALL_PREFIX variable must not be empty")
  endif()

  string(LENGTH "${install_space}" length)
  string(SUBSTRING "${path}" 0 ${length} path_prefix)
  if(NOT path_prefix STREQUAL install_space)
    message(FATAL_ERROR "The path '${path}' must be within the install space '${install_space}'")
  endif()
  if(path STREQUAL install_space)
    return()
  endif()

  # check if directory is empty
  file(GLOB files "${path}/*")
  list(LENGTH files length)
  if(length EQUAL 0)
    message(STATUS "Uninstalling: ${path}/")
    execute_process(COMMAND "/usr/bin/cmake" "-E" "remove_directory" "${path}")
    # recursively try to remove parent directories
    get_filename_component(parent_path "${path}" PATH)
    ament_cmake_uninstall_target_remove_empty_directories("${parent_path}")
  endif()
endfunction()

# uninstall files installed using the standard install() function
<<<<<<< HEAD
set(install_manifest "/home/ema/workspaces/ros2_tobii_glasses2/build/tobii_glasses_pkg/install_manifest.txt")
=======
set(install_manifest "/home/usr/workspaces/ros2_tobii_glasses2/build/tobii_glasses_pkg/install_manifest.txt")
>>>>>>> 042d9849849bd86e9fad5b9d0f8e382dea69bd42
if(NOT EXISTS "${install_manifest}")
  message(FATAL_ERROR "Cannot find install manifest: ${install_manifest}")
endif()

file(READ "${install_manifest}" installed_files)
string(REGEX REPLACE "\n" ";" installed_files "${installed_files}")
foreach(installed_file ${installed_files})
  if(EXISTS "${installed_file}" OR IS_SYMLINK "${installed_file}")
    message(STATUS "Uninstalling: ${installed_file}")
    file(REMOVE "${installed_file}")
    if(EXISTS "${installed_file}" OR IS_SYMLINK "${installed_file}")
      message(FATAL_ERROR "Failed to remove '${installed_file}'")
    endif()

    # remove empty parent folders
    get_filename_component(parent_path "${installed_file}" PATH)
    ament_cmake_uninstall_target_remove_empty_directories("${parent_path}")
  endif()
endforeach()

# end of template

message(STATUS "Execute custom uninstall script")

# begin of custom uninstall code
