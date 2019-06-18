#define CATCH_CONFIG_MAIN

#include "NumCpp.hpp"
#include "catch.hpp"

TEST_CASE("Vectors", "Create vector") {
	NumCpp test = NumCpp({ 1,2 });
	REQUIRE(test.get(0) == 1);
	REQUIRE(test.get(1) == 2);

}

