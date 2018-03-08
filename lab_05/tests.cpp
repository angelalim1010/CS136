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