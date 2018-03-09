#include <iostream>
using namespace std;
/*
Author: Angela Lim
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab 5

This program will define these functions:
*/
bool isDivisibleBy(int n, int d){
	if (n%d == 0){
		return true;
	}
	else{
		return false;
	}
}

bool isPrime(int n){
	if (n<=1){
		return false;
	}
	for (int i = 2; i <= n/2; i++){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}

int nextPrime(int n){
	do{
		n++;
	}while (!isPrime(n));
	return n;
}


int countPrimes(int a, int b){
	int counter = 0;
	for (int i = a; i <= b; i++){
		if(isPrime(i)){
			counter += 1;
		}	
	}	return counter;
}

bool isTwinPrime(int n){
	if(isPrime(n) && (isPrime(n-2)||isPrime(n+2))){
		return true;
	}
	return false;
}

int nextTwinPrime(int n){
	for (int i = (n+1); i > n; i++){
		if (isTwinPrime(i)){ 
			return i;
		}
	}
}
int largestTwinPrime(int a, int b){
	int num = -1;
	for(int i=a; i<=b; i++){
		if(isTwinPrime(i)){
			num = i;
		}
	}
	return num;
}



