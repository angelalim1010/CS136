#include <iostream>
#include "funcs.h"
using namespace std;

int main() {
	//just to read the image
	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); 
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row][col] = img[row][col];
		}
	}
	char iname[] = "outImage.pgm";
	writeImage(out, h, w, iname );
	// and save this new image to file "outImage.pgm"
	//task a

	char aname[] = "task-a.pgm";
	invert(out, img, h,w);
	writeImage(out, h, w, aname );

	//task b;
	char bname[] = "task-b.pgm";
	halfinvert(out, img, h , w);
	writeImage(out,h,w,bname);

	//task c;
	char cname[] = "task-c.pgm";
	whitebox(out, img, h , w);
	writeImage(out,h,w,cname);


	//task d;
	char dname[] = "task-d.pgm";
	frame(out, img, h , w);
	writeImage(out,h,w,dname);

	//task e;
	char ename[] = "task-e.pgm";
	int out2[MAX_H*2][MAX_W*2];
	scale (out2, img, h*2, w*2);
	writeImage2 (out,h,w,dname);
	return 0;
}





