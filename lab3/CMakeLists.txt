cmake_minimum_required(VERSION 3.30.3)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

# Указываем директории include
include_directories(include)

# Рекурсивно находим все файлы исходников и заголовков
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Создаем библиотеку для лабораторной работы
add_library(lab3_solution ${SOURCES} ${HEADERS})

# FetchContent для подключения Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Находим все тестовые файлы
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

# Создаем исполняемый файл для тестов
add_executable(lab3_tests ${TEST_SOURCES})
target_link_libraries(lab3_tests lab3_solution GTest::gtest_main)

# Используем GoogleTest для автоматического обнаружения тестов
include(GoogleTest)
gtest_discover_tests(lab3_tests)

# Включаем поддержку тестирования
enable_testing()

# Создаем основной исполняемый файл программы
add_executable(lab3_main main.cpp)
target_link_libraries(lab3_main lab3_solution)
