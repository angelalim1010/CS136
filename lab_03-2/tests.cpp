#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctests.h"

TEST_CASE("Testing east_storage"){
	CHECK(east_storage("01/01/2016")==71.99);
	CHECK(east_storage("05/04/2017")==0.0);
	CHECK(east_storage("abcde")==0.0);
}

TEST_CASE("Testing mineast"){
	CHECK(mineast()==49.34);
}

TEST_CASE("Testing maxeast"){
	CHECK(maxeast()==81);
}

TEST_CASE("Testing compare"){
	CHECK(compare("09/13/2016","09/17/2016")=="09/13/2016 East\n
		09/14/2016 East\n
		09/15/2016 Equal\n
		09/16/2016 West\n
		09/17/2016 West\n");
}

TEST_CASE("Testing reverse_order"){
	CHECK(reverse_order("05/29/2016","06/02/2016")=="06/02/2016 587.66 ft\n
		06/01/2016 587.81 ft\n
		05/31/2016 587.93 ft\n
		05/30/2016 588.02 ft\n
		05/29/2016 588.17 ft");
}