#include <iostream>
using namespace std;
string removeLeadingSpaces(string line){
	
	string s ;
	while (cin >> line){
		for (int i = 0; i < line.length(); i++){
			if (!isspace(line[i])){
			s += line[i];	
		}
	}
	line = s;
	return line;
	}
	
}

//int countChar(string line, char c){
//
//}

int main(){
	string word;
	while(cin >> )
	
}
