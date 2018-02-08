/*
Author: Angela Lim
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab1A

This program will ask the user for three integers and prints out the smaller integer.
*/

#include <iostream>
using namespace std;


int main ()
{
// printing out the statement to get 2 integers

int integer1;
int integer2;
int integer3;
cout << "Enter the first number: ";
cin >> integer1;
// prints out the first integer

cout << "Enter the second number: ";
cin >> integer2;
// prints out the second integer
cout << "Enter the third number: ";
cin >> integer3;
//prints out the third integer
if ((integer1 < integer2) and (integer2 < integer3)){
	cout << "The smaller of the three is " << integer1 << endl;
}
if ((integer2 < integer1) and (integer1 < integer3)){
	cout << "The smaller of the three is " << integer2 << endl;
}
if ((integer3 < integer2) and (integer2 < integer1)){
	cout << "The smaller of the three is " << integer3 << endl;
}

return 0;

}