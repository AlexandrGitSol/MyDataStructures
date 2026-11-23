cmake_minimum_required(VERSION 3.10)
project(MyDataStructures)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)

# Предполагаем, что тесты в папке tests
add_executable(MainApp
    src/MyDataStructures.cpp
    tests/test_bst_tree.cpp
    tests/test_vector.cpp
    tests/test_list.cpp
)

target_include_directories(MainApp PRIVATE src tests)
target_link_libraries(MainApp PRIVATE gtest gtest_main)