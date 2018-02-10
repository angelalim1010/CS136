/*
Author: Angela Lim
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab2A

This program print out the fibonacci sequence.
*/

#include <iostream>

using namespace std;

int main()
{
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <60; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i = 0; i < 60; i++){
        cout << fib[i] << endl;
    }
    return 0;
}
