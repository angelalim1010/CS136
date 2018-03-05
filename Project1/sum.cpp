#include <iostream>
using namespace std;
/*
Author: Angela Lim
Assignment: Project Task A
This program will read a file and report the sum.
*/
int main(){
	int sum = 0;
    // this is the sum of the file as it's being read
    int s;
    // this is what the file reads
    while(cin >> s) { 
    // While the reading operation is a success print the read word
    
    	sum += s;
    }
    cout << sum << endl;
    return 0;
}
