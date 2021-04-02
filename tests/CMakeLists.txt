cmake_minimum_required(VERSION 3.20)

project(nokia-tasks-tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

find_package(GTest REQUIRED)

include_directories(
    ../task1-first-n-primes/include
    ../task2-words-counter/include
    ${GTEST_INCLUDE_DIRS}
)

set(
  SOURCE_TEST
  ./init-tests.cpp
  ./task1-first-n-primes.cpp
  ./task2-words-counter.cpp
)

add_executable(nokia-tasks-tests ${SOURCE_TEST})

target_link_libraries(nokia-tasks-tests ${GTEST_LIBRARIES} words-counter first-n-primes)

enable_testing()
add_test(TestPrimes nokia-tasks-tests)
add_test(TestWordsCounter nokia-tasks-tests)
