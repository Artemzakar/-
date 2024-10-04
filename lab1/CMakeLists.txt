cmake_minimum_required(VERSION 3.30.3)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(lab1_solution src/extract_numbers.cpp)

add_executable(lab1 main.cpp)  
target_link_libraries(lab1 lab1_solution)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/0953a17a4281fc26831da647ad3fcd5e21e6473b.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(lab1_tests test/test_extract_numbers.cpp)
target_link_libraries(lab1_tests lab1_solution GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab1_tests)

enable_testing()
