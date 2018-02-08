/*
Author: Angela Lim
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab1A

This program will ask the user for two integers and prints out the smaller integer.
*/

#include <iostream>
using namespace std;


int main ()
{
// printing out the statement to get 2 integers

int integer1;
int integer2;
cout << "Enter the first number: ";
cin >> integer1;
// prints out the first integer
cout << "Enter the second number: ";
cin >> integer2;
// prints out the second integer
if (integer1 > integer2){
	cout << "The smaller of the two is " << integer2 << endl;
}
else{
	cout << "The smaller of the two is " << integer1 << endl;
}
return 0;

}
