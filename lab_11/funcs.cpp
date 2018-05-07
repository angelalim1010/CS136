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
//task f
// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z){
	Coord3D* ans =  new Coord3D;
	(*ans).x = x;
	(*ans).y = y;
	(*ans).z = z;
	return ans;
}

// free memory
void deleteCoord3D(Coord3D *p) {
	delete p;
}

//task e
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
	Particle* pos =  new Particle;
	(*pos).x = x;
	(*pos).y = y;
	(*pos).z = z;
	(*pos).vx = vx;
	(*pos).vy = vy;
	(*pos).vz = vz;
	return pos;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz) {
	(*p).vx = vx;
	(*p).vy = vy;
	(*p).vz = vz;
}

// get its current position
Coord3D getPosition(Particle *p) {
	Coord3D pos;
	pos.x = (*p).x;
	pos.y = (*p).y;
	pos.z = (*p).z;
	return pos;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt) {
	(*p).x = (*p).x + ((*p).vx * dt);
	(*p).y = (*p).y + ((*p).vy * dt);
	(*p).z = (*p).z + ((*p).vz * dt);
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p) {
	delete p;
}


