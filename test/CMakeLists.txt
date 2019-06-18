add_executable(foo "")
add_test(test foo)
target_sources(
	foo
		PRIVATE
		test.cpp
)

target_link_libraries(foo NumCpp)
include_directories(${INCLUDE_DIR})
