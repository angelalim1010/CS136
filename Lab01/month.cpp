/*
Author: Angela Lim
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab1A

This program will ask the user for a year and determine if it was a leap year.
*/
#include <iostream>
using namespace std;

bool isleap(int year)
{
	if (year%4 != 0){
		return false;
	}
	else if (year%100 != 0){
		return true;
	}
	else if (year%400 != 0){
		return false;
	}
	else {
		return true;
	}
}

int main()
{
	int year;
	int month;
	cout << "Enter a year: ";
	cin >> year;
	cout << "Enter a month: ";
	cin >> month;

	if ((month == 2) and (isleap(year))){
		cout << "29 days";
	}
	
	else if ((month == 2) and (!(isleap(year)))){
	cout << "28 days";
	}

	else if ((month>=7) and (month%2 == 1)){
		cout << "31 days";
	}
	else if (month ==8){
		cout << "31 days";
	}

	else if (month%2 == 0){
		cout << "30 days";
	}
	return 0;
}
