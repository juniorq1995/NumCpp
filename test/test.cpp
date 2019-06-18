#define CATCH_CONFIG_MAIN

#include "NumCpp.hpp"
#include "catch.hpp"

TEST_CASE("Vectors", "Create vector") {
	vector<int> test = NumCpp().arr({1,2});
	REQUIRE(test[0] == 1);
	REQUIRE(test[1] == 2);

}

