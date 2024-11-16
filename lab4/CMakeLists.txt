cmake_minimum_required(VERSION 3.30.3)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB_RECURSE HEADERS "include/*.h")

add_library(lab4_solution INTERFACE)
target_sources(lab4_solution INTERFACE ${HEADERS})

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES "test/*.cpp")

add_executable(lab4_tests ${TEST_SOURCES})
target_link_libraries(lab4_tests lab4_solution GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab4_tests)

enable_testing()

add_executable(lab4_main main.cpp)
target_link_libraries(lab4_main lab4_solution)
