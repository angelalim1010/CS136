/*
Author: Angela Lim
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab2A

This program will creates an array of 10 integers,
and provides the user with an interface to edit any of its elements.
*/
#include <iostream>

using namespace std;

// I couldn't figure out how to add more test cases.

int main()
{
	int index = 10;
	int value = 5;
	int data[10];

	for(int i =0; i < 10; i++){
		data[i] = 1;
	}


		do{
		for(int i =0; i < 10; i++){
			cout << data[i]<< " ";
		}
		cout << endl;
		if (index >= 0 and index < 10){
			data[index] = value;
		}
	}
	while (index >= 0 and index < 10);
			cout << "Index out of range. Exit." << endl;


	return 0;
}