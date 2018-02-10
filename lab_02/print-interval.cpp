/*
Author: Angela Lim
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab2A

This program will print out all integers in the range L ≤ i < U separated by spaces
*/
#include <iostream>

using namespace std;


int main()
{

	int low = -5;
	int upper = 10;
	cout << "The interval from -5 to 10: \n";
	for(int i = low; i < upper; i++) {
  

		cout << i << " ";
}

	
	return 0;
}

