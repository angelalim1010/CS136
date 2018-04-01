#include <iostream>
#include "funcs.h"

using namespace std;
int main(){
	string badcode = "";
	string b;
	while(getline(cin,x)){
		badcode += removeLeadingSpaces(x) + "\n";
	}
	cout << badcode << endl;
	return 0;
}