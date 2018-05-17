#pragma once
#include <iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);
bool nestedParens(string s);
bool helper(int *prices, int arraysum, int sum, int position, int size);
bool divisible(int *prices, int size);