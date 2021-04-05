cmake_minimum_required(VERSION 3.20)
project(first-n-primes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic-errors")
endif()

set(SOURCE_LIB src/first-n-primes.cpp)
add_library(
  first-n-primes
  STATIC
  ${SOURCE_LIB}
)
target_include_directories(first-n-primes PRIVATE include)
