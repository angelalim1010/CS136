#include <iostream>

using namespace std;

int main() {
	int number, sum = 0;
	//int first;
	char sign, sign2;
	//cin >> first;
	//sum = first;
	cin >> number;
	while (cin >> sign ) {

		if (sign == ';') {
			cout << sum << endl;
			cin >> number;
			sum = number;
			 
		}
		
			//int first;
			//cin >> first;
		else if (sign == '^') {
			//cin >> number;
			
			//sum = (number*number);
			cin >> sign2;
			if (sign2 == ';') {
				sum += (number * number);
				cout << sum << endl;
				cin >> number;
				sum = number;
			}
			else {
				cin >> number;
				if (sign2 == '+') {sum += (number*number);}
				else if (sign2 == '-') {sum -=  (number*number);}
				else if (sign2 == '*') {sum *=  (number*number);}
				else if (sign2 == '/') {sum /=  (number*number);}
			}cout << sum << endl;
		}
		
		else {
			cin >> number >> sign2;
			if (sign2 == '^') {
				if (sign == '+') {sum += (number*number);}
				else if (sign == '-') {sum -= (number*number);}
				else if (sign == '*') {sum *= (number*number);}
				else if (sign == '/') {sum /= (number*number);}
			}
			else if (sign == '+') {
				sum += number;
				if (sign2 == ';') {cout << sum << endl;}
			}
			else if (sign == '-') {
				sum -= number;
				if (sign2 == ';') {cout << sum << endl;}
			}
		}
			
		
	}
}
