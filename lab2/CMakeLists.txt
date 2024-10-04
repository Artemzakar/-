cmake_minimum_required(VERSION 3.30.3)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_library(lab2_solution Eleven.cpp)

add_executable(lab2_main main.cpp)
target_link_libraries(lab2_main lab2_solution)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(lab2_tests test_eleven.cpp)
target_link_libraries(lab2_tests lab2_solution GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab2_tests)

enable_testing()