cmake_minimum_required(VERSION 3.20)

project(nokia-tasks-tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic-errors")
endif()

find_package(GTest REQUIRED)

set(
  SOURCE_TEST
  ./init-tests.cpp
  ./task1-first-n-primes.cpp
  ./task2-words-counter.cpp
  ./task3-list-pick-out.cpp
  ./task4-bitwise-permutation.cpp
  ./task5-tree-paths.cpp
)

add_executable(nokia-tasks-tests ${SOURCE_TEST})

target_link_libraries(
  nokia-tasks-tests
  ${GTEST_LIBRARIES}
  first-n-primes
  words-counter
  list-pick-out
  bitwise-permutation
  tree-paths
)

target_include_directories(
  nokia-tasks-tests
  PRIVATE
  ../task1-first-n-primes/include
  ../task2-words-counter/include
  ../task3-list-pick-out/include
  ../task4-bitwise-permutation/include
  ../task5-tree-paths/include
  ${GTEST_INCLUDE_DIRS}
)

enable_testing()
add_test(TestPrimes nokia-tasks-tests)
add_test(TestWordsCounter nokia-tasks-tests)
add_test(ListPickOut nokia-tasks-tests)
add_test(BitwisePermutation nokia-tasks-tests)
add_test(TreePaths nokia-tasks-tests)
