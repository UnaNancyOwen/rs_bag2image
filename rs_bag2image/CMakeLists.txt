cmake_minimum_required( VERSION 3.6 )

# Require C++17 (or later)
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Compiler Option
set( FILESYSTEM )
if( "${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU" )
  set( FILESYSTEM "stdc++fs" )
elseif( "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" )
  set( FILESYSTEM "c++fs" )
endif()

# Create Project
project( rs_bag2image )
add_executable( rs_bag2image version.h realsense.h realsense.cpp main.cpp )

# Set StartUp Project
set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "rs_bag2image" )

# Find Package
# librealsense2
set( realsense2_DIR "C:/Program Files/librealsense2/lib/cmake/realsense2" CACHE PATH "Path to librealsense2 config directory." )
find_package( realsense2 REQUIRED )

# OpenCV
set( OpenCV_DIR "C:/Program Files/opencv/build" CACHE PATH "Path to OpenCV config directory." )
find_package( OpenCV REQUIRED )

if( realsense2_FOUND AND OpenCV_FOUND )
  # Additional Include Directories
  include_directories( ${realsense_INCLUDE_DIR} )
  include_directories( ${OpenCV_INCLUDE_DIRS} )

  # Additional Dependencies
  target_link_libraries( rs_bag2image ${realsense2_LIBRARY} )
  target_link_libraries( rs_bag2image ${OpenCV_LIBS} )
  if( NOT WIN32 )
      target_link_libraries( rs_bag2image ${FILESYSTEM} )
  endif()
endif()