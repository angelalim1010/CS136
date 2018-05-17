#include <iostream>

#include "funcs.h"
using namespace std;

//task a
void printRange(int left, int right){
	
	if(left <= right){
		cout << left << endl;
		printRange(left+1, right);
	}
	else{
		cout << " " << endl;
	}
}
//b
int sumRange(int left, int right){
	//left + (left+1) till left+ 1 = right 
	if (left < right){
		return left + sumRange(left+1, right);
	}

	return right;
}
//c
int sumArray(int *arr, int size){
	if (size > 1 ){
		return arr[size-1] + sumArray(arr, size-1);
	}
	return arr[0];
}
//d
bool isAlphanumeric(string s){
	if(s.length()>1){
		return (isalpha(s[0]) || isdigit(s[0])) && isAlphanumeric(s.substr(1));

	}
	return (isalpha(s[0]) || isdigit(s[0]));
}	
//e
bool nestedParens(string s){
	if(s.length()%2 == 0){
		if(s.length()>0){
			return (((s[0] == '(') && (s[s.length()-1 == ')'])) && nestedParens(s.substr(1,s.length()-2)) );
		}
			return true;
	}


	return false;
}

//f
//helper function
bool helper(int *prices, int arraysum, int sum, int position, int size){
	sum += prices[position];
	if (sum == arraysum/2){
		return true;

	}
	else if (position == size-1){
		return false;
	}
	else{
		for (int i = position+1; i < size; i++){
			if (helper(prices, arraysum, sum, i, size) == true){
				return true;
			}
		}
		return false;
	}
}
bool divisible(int *prices, int size){
	int arraysum = sumArray(prices,size);
	int sum = 0;
	if (size == 0){
		return true;
	}
	else if (size%2 == 1 ){
		return false;
	}
	else{
		return helper(prices, arraysum, sum, 0, size);
	}
}
