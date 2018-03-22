#pragma once
#include <iostream>
using namespace std;

void testascii(string s);
string encryptCaesar(string plaintext, int rshift);
string encryptVigenere(string plaintext, string keyword);
string decryptCaesar(string ciphertext, int rshift);
