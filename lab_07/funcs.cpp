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
				return c+= (rshift-26);
			}
			else if (int(toupper(c))+rshift < 65){
				return c+= (rshift+26);
			
			}else{
				return c+rshift;
			}
	}
	return c;
}	

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift){
	
	string result = "";
	for(int i = 0; i < plaintext.length(); i++){
		result += shiftChar(plaintext[i],rshift);
	}
	return result;
}


string encryptVigenere(string plaintext, string keyword){
	int counter = 0;
	string s = "";
	for(int i = 0; i < plaintext.length(); i++){
    	s += shiftChar(plaintext[i],((int)keyword[counter] - 97)%26);
    	counter += 1;
    	if(counter > keyword.length()-1){
		counter = 0;
		}
	}
	return s;
}

string decryptCaesar(string ciphertext, int rshift){
	return encryptCaesar(ciphertext, (rshift*-1));
}

string decryptVigenere(string ciphertext, string keyword){
	int counter = 0;
	string s = "";
	for(int i = 0; i < ciphertext.length(); i++){
    	s += shiftChar(ciphertext[i],-((int)keyword[counter] - 97));
    	counter += 1; 
    	if(counter > keyword.length()-1){
		counter = 0;
		}
	}
	return s;

}


