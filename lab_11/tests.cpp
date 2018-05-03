#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "def.h"
#include "doctest.h"

TEST_CASE("Testing length"){
	Coord3D pointP = {10, 20, 30};
	CHECK(length(&pointP) == 37.4166);
}
TEST_CASE("Testing "){
	
}