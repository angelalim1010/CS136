/*
Author: Angela Lim
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab1A

This program will ask the user for a year and determine if it was a leap year.
*/
#include <iostream>
using namespace std;
int main(){
	int year;
	cout << "Enter year: ";
	cin >> year;
	if (year%4 != 0){
		cout << "Common Year";
	}
	else if (year%100 != 0){
		cout << "Leap Year";
	}
	else if (year%400 != 0){
		cout << "Common Year";
	}
	else {
		cout << "Leap Year";
	}
	return 0;
}