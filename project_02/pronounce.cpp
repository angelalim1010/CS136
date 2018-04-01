/*
Author: Angela Lim
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 2

This program will allow the user to input a word
If the word is part of the dictionary, 
it will return its pronouncation, words with identical pronouncation,
words produced if added a phoneme, if you removed a phoneme and replaced a phoneme.
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

//splits the string into two parts
void splitOnSpace(string s, string &before, string &after) {
  before = "";
  after = "";
  int i = 0;
  while ( i < s.size() && !isspace(s[i]) ) { 
    before += s[i]; i++; 
  }
  i++;
  while (i < s.size() ) { after += s[i]; i++;}
}

//finds the prounciation of a string
string pronunciation(string w) {
  ifstream fin("cmudict.0.7a");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
  }
  string line;
  for (int i = 0; i < 54; i++) { getline(fin, line); }
  while(getline(fin, line)) {
    string before = "", after = "";
    splitOnSpace(line, before, after);
    // if the input is the same as the first half of the line, return the second half
    if (w == before) {
      return after;
    }
  }
  return "Not found";
  fin.close();
}

//finds words with identical pronunciations
string identical(string w) {
  string identicalString;
  string pronounce = pronunciation(w);
  ifstream fin("cmudict.0.7a");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
  }
  string line;
  //skips the header of the dictionary
  for (int i = 0; i < 54; ++i) { getline(fin, line); }
  while(getline(fin, line)){
        string before = "", after = "";
    splitOnSpace(line, before, after);
    //if the second half of the line is the same as the input's pronunciation
    // and if the input isn't the same as the first half of the line, return the word
        if ((after == pronounce) && (before != w)){
          identicalString += before;
          identicalString += " ";
        }
  }     
  return identicalString;
}

//counts the number of phonemes in a word
int count_phonemes(string s) {
  int counter = 1;
  string before, after;
  splitOnSpace(s, before, after);
  while (after != "") {
    splitOnSpace(after, before, after);
    counter += 1;
  }
  return counter;
}



//to check if the input is usable
bool isValid (string w) {
  for (int i = 0; i < w.length(); i++) {
    char c = w[i];
    if ( !(isalpha(c) || c == '\'') ) {
      return false;
    }
  }
  return true;
}

//will return words that have one more phoneme than the input
string add(string w) {
string add_phoneme, pronounce;
  int phoneme_counter;
  //Reading dictionary data
  ifstream fin("cmudict.0.7a");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
  }


  string line;
  //skips the header
  for (int i = 0; i < 54; ++i) { getline(fin, line); }
  string before = "", after = "";
  // this loop does the same as the pronunciation function but stores the phoneme count
  while (getline(fin, line)) {
    splitOnSpace(line, before, after); 
    if (before == w) {
      splitOnSpace(after, before, after); 
      pronounce = after;
      phoneme_counter = count_phonemes(pronounce);
    }
  } 
  fin.clear();
  fin.seekg(0, ios::beg);
  string current_word, current_pronunciation;
  while (getline(fin, line)) {
    splitOnSpace(line, before, after); 
    current_word = before;
    splitOnSpace(after, before, after); 
    current_pronunciation = after; 
    if (isValid(current_word) && (current_word != w) ){
      int current_phoneme_counter = count_phonemes(current_pronunciation); 
      int diff_phonemes = 0;
      string before_input, after_input, before_current, after_current;
      //splitting the pronunciation 
      splitOnSpace(pronounce, before_input, after_input);
      splitOnSpace(current_pronunciation, before_current, after_current); 
      if ( current_phoneme_counter == phoneme_counter + 1 ) {
        while ( diff_phonemes < 2 && (before_input != "" && before_current != "") ) { 
          // if the current word and input were different, go through the phonemes
          if ( before_input != before_current ) {
            splitOnSpace(after_current, before_current, after_current);
            diff_phonemes += 1; 
          }
          else {
            splitOnSpace(after_input, before_input, after_input);
            splitOnSpace(after_current, before_current, after_current);
          }
        }
        if (diff_phonemes < 2) { 
          add_phoneme += current_word + " "; 
        }
      }
    }
  }
return add_phoneme;
}

//will return a word with one less phoneme than the original
string remove(string w){
  string remove_phoneme, pronounce;
  int phoneme_counter;
  //Reading dictionary data
  ifstream fin("cmudict.0.7a");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
  }

  string line;
  //skips the header
  for (int i = 0; i < 54; ++i) { getline(fin, line); }
  string before = "", after = "";
  // this loop does the same as the pronunciation function but stores the phoneme count
  while (getline(fin, line)) {
    splitOnSpace(line, before, after); 
    if (before == w) {
      splitOnSpace(after, before, after); 
      pronounce = after;
      phoneme_counter = count_phonemes(pronounce);
    }
  } 
  fin.clear();
  fin.seekg(0, ios::beg);
  
  string current_word, current_pronunciation;
  while (getline(fin, line)) {
    splitOnSpace(line, before, after); 
    current_word = before; //saves the current word
    splitOnSpace(after, before, after); 
    current_pronunciation = after; //saves the current pronunciation
    if (isValid(current_word) && (current_word != w) ){
      int current_phoneme_counter = count_phonemes(current_pronunciation); 
      int diff_phonemes = 0;
      string before_input, after_input, before_current, after_current;
      //splitting the pronunciation 
      splitOnSpace(pronounce, before_input, after_input);
      splitOnSpace(current_pronunciation, before_current, after_current); 
      if ( current_phoneme_counter == phoneme_counter - 1 ) {
           // if the current word and input were different, go through the phonemes
        while ( diff_phonemes < 2 && (before_input != "" && before_current != "") ) { 
          if ( before_input != before_current ) {
            splitOnSpace(after_input, before_input, after_input);
            diff_phonemes += 1; 
          }
          else {
            splitOnSpace(after_input, before_input, after_input);
            splitOnSpace(after_current, before_current, after_current);
          }
        }
        if (diff_phonemes < 2) { 
          remove_phoneme += current_word + " "; 
        }
      }
    }
  }
return remove_phoneme; 
}

//will return a word with one phoneme replaced than the original
string replace(string w){
  string replace_phoneme, pronounce;
  int phoneme_counter;
  //Reading dictionary data
  ifstream fin("cmudict.0.7a");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
  }
  string line;
  //skips the header
  for (int i = 0; i < 54; ++i) { getline(fin, line); }
  string before = "", after = "";
  // this loop does the same as the pronunciation function but stores the phoneme count
  while (getline(fin, line)) {
    splitOnSpace(line, before, after); 
    if (before == w) {
      splitOnSpace(after, before, after); 
      pronounce = after;
      phoneme_counter = count_phonemes(pronounce);
    }
  } 
  fin.clear();
  fin.seekg(0, ios::beg);
  string current_word, current_pronunciation;
  while (getline(fin, line)) {
    splitOnSpace(line, before, after);
    current_word = before; //saves the current word
    splitOnSpace(after, before, after); 
    current_pronunciation = after; //saves the current pronunciation
    if (isValid(current_word) && (current_word != w) ){
      int current_phoneme_counter = count_phonemes(current_pronunciation); 
      int diff_phonemes = 0;
      string before_input, after_input, before_current, after_current;
      //splitting the pronunciation 
      splitOnSpace(pronounce, before_input, after_input);
      splitOnSpace(current_pronunciation, before_current, after_current); 
    if ( current_phoneme_counter == phoneme_counter ) {
      //makes sure we don't repeat the identical words
        if (current_pronunciation != pronounce && isValid(current_word) && current_word != w ){
          while ( diff_phonemes < 2 && (before_input != "" && before_current != "") ) {
            if ( before_input != before_current ) {
              //if there is a difference, keep parsing phonemes of BOTH words
              splitOnSpace(after_input, before_input, after_input);
              splitOnSpace(after_current, before_current, after_current);
              diff_phonemes += 1; //keep track of differences
            }
            else {
              splitOnSpace(after_input, before_input, after_input);
              splitOnSpace(after_current, before_current, after_current);
            }
          }
          if (diff_phonemes < 2) { 
            replace_phoneme += current_word + " "; 
          }
        }
      }
    }
  }
  return replace_phoneme;
}

int main() {
  string w, after;
  cin >> w;
  for (int i = 0; i < w.length(); ++i){ w[i] = toupper(w[i]); }
  after = pronunciation(w);
  cout << endl;
  cout << "Pronunciation: " << after << endl;
  cout << "Identical: " << identical(w) << endl;
  cout << "Add phoneme: " << add(w) << endl;
  cout << "Remove phoneme: " << remove(w) << endl;
  cout << "Replace phoneme: " << replace(w) << endl;
}