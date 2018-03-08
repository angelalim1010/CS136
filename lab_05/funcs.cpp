#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d){
	if (n%2 == 0){
		return true;
	}
	else{
		return false;
	}
}

bool isPrime(int n){
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


int main(){
	cout << nextPrime(15) << endl;
}
