#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"
using namespace std;
int main()
{	
	cout << boolalpha;
	cout << isDivisibleBy(100,25) << endl;
	cout << isPrime(3) << endl;
	cout << nextPrime(12) << endl;
	cout << countPrimes(12,20) << endl;
	cout << isTwinPrime(5) << endl;
	cout << nextTwinPrime(4) << endl;
	cout << largestTwinPrime(5,11) << endl;
    return 0;
}