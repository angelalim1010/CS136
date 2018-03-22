#include <iostream>
#include <string>

using namespace std;
void testascii(string s){
	for(int i = 0; i < s.length(); i++){
    cout << s[i] << " " << (int)s[i]<< endl;
	}
}
// A helper function to shift one character by rshift
char shiftChar(char c, int rshift){
	if(isalpha(c)){
			if(int(toupper(c))+rshift > 90){
				return c+=shift-26;
			}
	return c+rshift;
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift){
	string result = "";
	for(int i = 0; i < plaintext.length(); i++){
		if(isalpha(plaintext[i])){
			result += shiftChar(plaintext[i],rshift);
		}
		else{
			result += plaintext[i];
		}
	}return result;
}

string encryptVigenere(string plaintext, string keyword){
	string s = "";
	for(int i = 0; i < keyword.length(); i++){
    cout <<(int)keyword[i]<< endl;
	}
}


int main(){
	encryptVigenere(string plaintext, string keyword)
}
