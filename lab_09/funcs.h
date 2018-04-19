#pragma once
#include <iostream>
using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(int image[MAX_H][MAX_W], int height, int width, char name[]);
void invert(int out[MAX_H][MAX_W],int image[MAX_H][MAX_W], int height, int width);
void halfinvert(int out[MAX_H][MAX_W],int image[MAX_H][MAX_W], int height, int width);
void whitebox(int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width);
void frame(int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width);
void scale (int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width);
void pixelate(int out[MAX_H][MAX_W], int image[MAX_H][MAX_W], int height, int width);