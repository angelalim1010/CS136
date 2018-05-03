#include <iostream>
#include <cmath>
#include "def.h"
using namespace std;

//task a
double length(Coord3D *p){
	Coord3D d = *p;
	double distx = (d.x * d.x);
	double disty = (d.y * d.y);
	double distz = (d.z * d.z); 
	double dist = sqrt(distx + disty + distz);
	return dist;
}
//task b
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){

	if(length (p1) < length (p2)){
		return p2;
	}
	else {
		return p1; 
	}
}
//task c
void move(Coord3D *ppos, Coord3D *pvel, double dt){

	Coord3D vel = *pvel;
	ppos -> x += vel.x*dt;
	ppos -> y += vel.y*dt;
	ppos -> z += vel.z*dt;
}

//task d
string * createAPoemDynamically() {

    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}
//f
// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z);

// free memory
void deleteCoord3D(Coord3D *p);
