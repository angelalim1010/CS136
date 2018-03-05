#include <iostream>
using namespace std;
/*
Author: Angela Lim
Assignment: Project Task C
This program will read a file, accept symbols,
formulas, and non-negative integers. This will be
able to return the sum of the integers.
*/
int main() {
	int sum = 0;
    // the sum of the read file
    int first, number;
    //first is the first integer we're reading
    //number is the integers we're reading past the first operator
    char op;
    //this is to represent the + and - 
    cin >> first;
    sum = first;
    // this will allow us to read and store the first integer
    while (cin >> op >> number){
    	if (op == ';') {
    		cout << sum << endl;
    		sum = number;
            //this if statement will read ";" and return the sum
            //then it will reset sum each time it reads ";"
    	}
        else if (op == '+'){
            sum += number;
            //this will add the next integer to the sum
        }
        else if (op == '-'){
            sum -= number;
            // this will subtract the next integer from the sum
        }
    }
    cout << sum << "\n";
    return 0;
}