#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"
using namespace std;
int main(){
	testascii("Cat :3 Dog");
	cout << encryptCaesar("hello", 5) << endl;
	cout << encryptVigenere("hello", "cake") << endl;
	cout << decryptCaesar("Mjqqt", 5) << endl;
	cout << decryptVigenere("Jevpq", "cake") << endl;
	return 0;
}