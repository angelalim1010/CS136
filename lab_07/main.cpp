#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"
using namespace std;
int main(){
	testascii("Cat :3 Dog");
	cout << encryptCaesar("hello", 5) << endl;
	return 0;
}