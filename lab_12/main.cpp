#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
using namespace std;
#include "funcs.h"

int main(){
	printRange(-2, 10);
	//b
    cout << "Task b:" << endl;
	int x = sumRange(1, 3);
    cout << "This is " << x << endl;   // 6
    
    int y = sumRange(-2, 10);
    cout << "That is " << y << endl;   // 52
    //c
    cout << "Task c:" << endl;
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

    int sum1 = sumArray(arr, size); // Add all elements
    cout << "Sum is " << sum1 << endl;  // Sum is 43
    
    int sum2 = sumArray(arr, 5); // Add up first five elements
    cout << "Sum is " << sum2 << endl;  // Sum is 34

    delete[] arr;         // deallocate it
    //d
    cout << "Task d:" << endl;
    cout << boolalpha << isAlphanumeric("ABCD") << endl;        // true (1)
	cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
	cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)
	//e
    cout << "Task e:" << endl;
	cout << boolalpha << nestedParens("((()))") << endl;      // true (1)
	cout << nestedParens("()") << endl;          // true (1)
	cout << nestedParens("") << endl;            // true (1)

	cout <<  nestedParens("(((") << endl;          // false (0)
	cout << nestedParens("(()") << endl;         // false (0)
	cout << nestedParens(")(") << endl;          // false (0)
	cout << nestedParens("a(b)c") << endl;       // false (0)
	//f
    cout << "Task f:" << endl;
    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    cout  << divisible(prices, 8) << endl;
	return 0;
}