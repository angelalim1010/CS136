#include <iostream>
#include <cmath>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

TEST_CASE("Testing sumRange"){
	CHECK(sumRange(1,3) == 6);
	CHECK(sumRange(-2,10) == 52);
}

TEST_CASE("Testing sumArray"){
	int size = 10;
    int *arr = new int[size]; // allocate array dynamically
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;
	CHECK(sumArray(arr,size) == 43);
	CHECK(sumArray(arr, 5)== 34);
}

TEST_CASE("Testing isAlphanumeric"){
    CHECK(isAlphanumeric("ABCD") == 1);
    CHECK(isAlphanumeric("Abcd1234xyz") == 1);
    CHECK(isAlphanumeric("KLMN 8-7-6") == 0);
}

TEST_CASE("Testing nestedParens"){
    CHECK(nestedParens("()") == 1);
    CHECK(nestedParens("") == 1);
    CHECK(nestedParens("(((") == 0);
    CHECK(nestedParens("(()") == 0);
}

TEST_CASE("Testing divisible"){
    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    CHECK(divisible(prices,8) == true);
    CHECK(divisible(prices, 9) == false);
}
