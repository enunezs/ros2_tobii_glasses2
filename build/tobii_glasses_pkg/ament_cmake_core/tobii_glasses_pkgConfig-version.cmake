# generated from ament/cmake/core/templates/nameConfig-version.cmake.in
<<<<<<< HEAD
set(PACKAGE_VERSION "0.1.0")
=======
set(PACKAGE_VERSION "1.0.0")
>>>>>>> 042d9849849bd86e9fad5b9d0f8e382dea69bd42

set(PACKAGE_VERSION_EXACT False)
set(PACKAGE_VERSION_COMPATIBLE False)

if("${PACKAGE_FIND_VERSION}" VERSION_EQUAL "${PACKAGE_VERSION}")
  set(PACKAGE_VERSION_EXACT True)
  set(PACKAGE_VERSION_COMPATIBLE True)
endif()

if("${PACKAGE_FIND_VERSION}" VERSION_LESS "${PACKAGE_VERSION}")
  set(PACKAGE_VERSION_COMPATIBLE True)
endif()
