cmake_minimum_required (VERSION 3.1.0...3.27.0)

project (ray_tracing)

set (CMAKE_CXX_STANDARD          20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)

set (SOURCE
  src/ray_tracing_simple/vec3.cpp
  src/ray_tracing_simple/color.cpp

  src/ray_tracing_simple/main.cpp
)

include_directories(src)
add_executable(ray_tracing_simple ${SOURCE})
