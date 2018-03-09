#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

TEST_CASE("Testing isDivisibleBy"){
	CHECK(isDivisibleBy(10,5) == true);
	CHECK(isDivisibleBy(2,3) == false);
}

TEST_CASE("Testing isPrime"){
	CHECK(isPrime(2)==true);
	CHECK(isPrime(5)==true);
	CHECK(isPrime(10)==false);
}

TEST_CASE("Testing nextPrime"){
	CHECK(nextPrime(12) == 13);
	CHECK(nextPrime(15)==17);
	CHECK(nextPrime(2)==3);
}

TEST_CASE("Testing countPrimes"){
	CHECK(countPrimes(1,10) == 4);
	CHECK(countPrimes(13,17) == 2);
	CHECK(countPrimes(12,20) == 3);
}

TEST_CASE("Testing isTwinPrime"){
	CHECK(isTwinPrime(3) == true);
	CHECK(isTwinPrime(21) == false);
}

TEST_CASE("Testing nextTwinPrime"){
	CHECK(nextTwinPrime(14) == 17);
	CHECK(nextTwinPrime(17) == 19);
}

TEST_CASE("Testing largestTwinPrime"){
	CHECK(largestTwinPrime(5,18) == 17);
	CHECK(largestTwinPrime(1,31) == 31);
	CHECK(largestTwinPrime(14,16) == -1);
}