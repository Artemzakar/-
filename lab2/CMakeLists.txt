cmake_minimum_required(VERSION 3.30.3)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(lab2_solution ${SOURCES} ${HEADERS})

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")
add_executable(lab2_tests ${TEST_SOURCES})
target_link_libraries(lab2_tests lab2_solution GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab2_tests)

enable_testing()

add_executable(lab2_main main.cpp)
target_link_libraries(lab2_main lab2_solution)

