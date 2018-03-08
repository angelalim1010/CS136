#include <iostream>
using namespace std;

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

int nextTwinPrime(int n){
	
}



