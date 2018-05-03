#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "labstructs.h"
#include "doctest.h"

TEST_CASE("Testing minutesSinceMidnight"){
	CHECK(minutesSinceMidnight({2,10}) == 130);
	CHECK(minutesSinceMidnight({0,0}) == 0);
	CHECK(minutesSinceMidnight({4,30}) == 270);
}

TEST_CASE("Testing minutesUntil"){
	CHECK(minutesUntil({10,30}, {13,40}) == 190);
	CHECK(minutesUntil({0,0}, {0,0}) == 0);
	CHECK(minutesUntil({1,20},{4,40}) == 200);
	CHECK(minutesUntil({10,30}, {13,20}) == 170);
}

TEST_CASE("Testing "{
	CHECK( == )
})