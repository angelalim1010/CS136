#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "funcs.h"

using namespace std;

void writeImage1(int image[MAX_H][MAX_W], int height, int width) {
	ofstream outImage1;
	outImage1.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	outImage1 << "P2" << endl;
	// width, height
	outImage1 << width << ' ';
	outImage1 << height << endl;
	outImage1 << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			outImage1 << image[row][col] << ' ';
			outImage1 << endl;
		}
	}
	outImage1.close();
	return;
}