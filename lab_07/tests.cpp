#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

TEST_CASE("Testing encryptCaesar"){
	CHECK(encryptCaesar("Hello, World", 5) == "Mjqqt, Btwqi");
	CHECK(encryptCaesar("Way to Go", 5) == "Bfd yt Lt");
}

TEST_CASE("Testing encryptVigenere"){
	CHECK(encryptVigenere("hello", "cake") == "jevpq");
	CHECK(encryptVigenere("world") == "wyvnd");
}

TEST_CASE("Testing decryptCaesar"){
	CHECK(decryptCaesar("Mjqqt") == "Hello");
	CHECK(decryptCaesar("Btwqi")== "World");
}

