add_executable(foo test.cpp)


target_link_libraries(foo NumCpp)
include_directories(${INCLUDE_DIR})
