cmake_minimum_required(VERSION 3.8)
project (NumCpp)

set(NUMCPP_SRCS
   NumCpp.hpp NumCpp.cpp
)

SET (LIB_TYPE STATIC)
add_library (NumCpp ${LIB_TYPE} ${NUMCPP_SRCS})


find_package(Catch2 REQUIRED)
add_executable(foo test.cpp)
target_link_libraries(foo Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(foo)
