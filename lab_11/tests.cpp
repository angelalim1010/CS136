#include <iostream>
#include <cmath>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "def.h"
#include "doctest.h"

TEST_CASE("Testing length"){
	Coord3D pointP = {10, 20, 30};
	CHECK(length(&pointP) == sqrt(pow(10,2)+pow(20,2)+pow(30,2)));
	Coord3D pointP2 = {2, 4, 2};
	CHECK(length(&pointP2) == sqrt(pow(2,2)+pow(4,2)+pow(2,2)));
	Coord3D pointP3 = {3, 7, 9};
	CHECK(length(&pointP3) == sqrt(pow(3,2)+pow(7,2)+pow(9,2)));
}

TEST_CASE("Testing fartherFromOrigin"){
	Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};
	Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
	CHECK(ans == &pointP);
	Coord3D pointP2 = {3, 0, 3};
    Coord3D pointQ2 = {0, 1, 1};
	Coord3D * ans1 = fartherFromOrigin(&pointP2, &pointQ2);
	CHECK(ans1 == &pointP2);
}

TEST_CASE("Testing move"){
	Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); 
    CHECK(pos.x == 2);
    CHECK(pos.y == -10);
    CHECK(pos.z == 100.4);
}

TEST_CASE("Testing createCoord3D"){
	Coord3D *ppos = createCoord3D(10,20,30);
    Coord3D *pvel = createCoord3D(5.5,-1.4,7.77);
    CHECK((*ppos).x == 10);
    CHECK((*ppos).y == 20);
    CHECK((*ppos).z == 30);
    CHECK((*pvel).x == 5.5);
    CHECK((*pvel).y == -1.4);
    CHECK((*pvel).z == 7.77);
}

TEST_CASE("Testing Particle"){
	Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    double ix;
    double iy;
    double iz;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);
        CHECK((*p).vx==10.0*time);
        CHECK((*p).vy==0.3);
        CHECK((*p).vz==0.1);
        ix = (*p).x; iy = (*p).y; iz = (*p).z;
        // move the particle
        move(p, dt);
        CHECK(getPosition(p).x == (ix+(*p).vx*dt));
        CHECK(getPosition(p).y == (iy+(*p).vy*dt));
        CHECK(getPosition(p).z == (iz+(*p).vz*dt));
        time += dt;

        
    }
}
