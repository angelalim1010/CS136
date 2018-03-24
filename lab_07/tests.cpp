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
	CHECK(encryptVigenere("World", "cake") == "Yobpf");
}

TEST_CASE("Testing decryptCaesar"){
	CHECK(decryptCaesar("Mjqqt", 5) == "Hello");
	CHECK(decryptCaesar("Btwqi", 5)== "World");
}

TEST_CASE("Testing decryptvigenere"){
	CHECK(decryptVigenere("Jevpq", "cake") == "Hello");
	CHECK(decryptVigenere("Yobpf", "cake") == "World");
}

