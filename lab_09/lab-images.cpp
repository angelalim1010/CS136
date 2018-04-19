
/*
  Author:   Angela Lim
  Description:
    The program reads a PGM image from the file "inImage.pgm",
    and outputs a modified image to "outImage.pgm"
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "funcs.h"

using namespace std;


// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width, char name[]) {
	ofstream ostr;
	ostr.open(name);
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}


void invert(int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width){
	for(int row = 0; row < height; row++) {
		for(int col = 0; col < width; col++) {
			out[row][col] = (255-image[row][col]);
		}
	}
}

void halfinvert(int out[MAX_H][MAX_W],int image[MAX_H][MAX_W], int height, int width){
	 for(int row = 0; row < height; row++) {
		for(int col = 0; col < width; col++) {
			if (col > width/2){
				out[row][col] = (255-image[row][col]);
			}
			else {
				out[row][col] = (image[row][col]);
			}
		}
	}
}

void whitebox(int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width){
	int w1,h1,w2,h2;
	w1 = width/4;
	w2 = w1+ (width/2);
	h1 = height/4;
	h2 = h1 + (height/2);
	 for(int row = 0; row < height; row++) {
		for(int col = 0; col < width; col++) {
			if ((row >= h1 && row <= h2) && (col >= w1 && col <= w2)){
				out[row][col] = 255;
			}
			else{
				out[row][col] = image[row][col];
			}
		}
	}
}

void frame(int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width){
	int w1,h1,w2,h2,x,y;
	w1 = width/4;
	w2 = w1+ (width/2);
	h1 = height/4;
	h2 = h1 + (height/2);
	 for(int row = 0; row < height; row++) {
		for(int col = 0; col < width; col++) {
			if (((row == h1 || row == h2) && (col >= w1 && col <= w2)) 
				|| ((col == w1 || col == w2) && (row >= h1 && row <= h2))){
				out[row][col] = 255;
			}
			else{
				out[row][col] = image[row][col];
			}
		}
	}
}

void scale (int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width){
	for(int row = 0; row < height; row++) {
		for(int col = 0; col < width; col++) {
			out[row*2][col*2] = image[row][col];
			out[row *2 ][col *2 +1 ] = image[row][col];
			out[row *2 +1 ][col *2 ] = image[row][col];
			out[row *2 +1 ][col *2 +1 ] = image[row][col];
		}
	}
}

void pixelate(int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width){
	int sum = 0;
	int avg = 0;
	for(int row = 0; row < height; row+=2) {
		for(int col = 0; col < width; col+=2) {
			sum = 0;
			sum += image[row][col] + image[row+1][col] + image[row][col+1] + image[row+1][col+1];
			out[row][col] = image[row][col];
			out[row +1 ][col] = image[row][col];
			out[row][col + 1] = image[row][col];
			out[row + 1 ][col + 1] = image[row][col];
		}
	}
}
