#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
using namespace std;
#include "def.h"

int main() {
	//a
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
    //b
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?
	
	//c
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // struct pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4
   

    //d
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
        delete p;
    }

}