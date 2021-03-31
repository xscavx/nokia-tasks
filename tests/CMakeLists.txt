cmake_minimum_required(VERSION 3.6)

project(nokia-tasks-tests)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(
    ../task1-first-n-primes/include
    ${GTEST_INCLUDE_DIRS}
)
set(SOURCE_TEST ./task1-first-n-primes.cpp)

add_executable(task1-first-n-primes-test ${SOURCE_TEST})

target_link_libraries(task1-first-n-primes-test ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()
add_test(task1-first-n-primes-test "./task1-first-n-primes-test")
