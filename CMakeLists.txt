cmake_minimum_required(VERSION 3.8)
project (NumCpp LANGUAGES CXX VERSION 0.0.1)

set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)

