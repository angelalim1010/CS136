#include <iostream>

using namespace std;
/*
Author: Angela Lim
Assignment: Project Task D
This program will read a file, accept symbols,
formulas, and non-negative integers. This will be
able to return the sum of the integers.
*/
int main() {
    int number, sum = 0;
    char op, op2;
    cin >> number;
    while (cin >> op) {
        if (op == ';') {
            cout << sum << endl;
            cin >> number;
            sum = number;
        } // this returns the first integer
        else if (op == '^') {
            cin >> op2;
            if (op2 == ';') {
                sum += (number * number);
                cout << sum << endl;
                cin >> number;
                sum = number;
            }//returns first integer if its being squared
            else {
                cin >> number;
                if (op2 == '+'){
                    sum += (number*number);
                } //add the following integers if + is the next symbol
                else if (op2 == '-'){
                    sum -=  (number*number); 
                }// subtract if - is the following symbol
            }
        }
        else {
            cin >> number >> op2;
            if (op2 == '^') {
                if (op == '+'){
                    sum += (number*number); 
                }// add if ^ is the second operator
                else if (op == '-'){
                    sum -= (number*number); 
                }// subtract is ^ is the second operator
            }
            
            else if (op == '+') {
                sum += number;
                if (op2 == ';'){
                   cout << sum << endl; 
                   cin >> number;
                   sum = number;
                } //return the sum 
            }
            else if (op == '-') {
                sum -= number;

                if (op2 == ';'){
                    cout << sum << endl;
                    cin >> number;
                    sum = number;
                } // return a difference
            }
            
        }
    }

    return 0;
}