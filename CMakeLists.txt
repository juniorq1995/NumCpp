cmake_minimum_required(VERSION 3.8)
project (NumCpp)

set(NUMCPP_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/NumCpp)

add_subdirectory(NumCpp)


include_directories(${NUMCPP_INCLUDE_DIR})
add_executable(main main.cpp)

target_link_libraries(main NumCpp)
ADD_DEPENDENCIES(main NumCpp)