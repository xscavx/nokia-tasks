cmake_minimum_required(VERSION 3.20)
project(bitwise-permutation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic-errors")
endif()

set(SOURCE_LIB src/bitwise-permutation.cpp)
add_library(
  bitwise-permutation
  STATIC
  ${SOURCE_LIB}
)
target_include_directories(bitwise-permutation PRIVATE include)
