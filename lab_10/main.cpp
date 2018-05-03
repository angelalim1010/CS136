#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
using namespace std;
#include "labstructs.h"

int main(){
	cout << minutesSinceMidnight({2,10}) << endl;
	cout << minutesUntil({10,30}, {13,40}) << endl;
	Time time0 = addMinutes({8,10}, 75);
	printTime(time0);
	return 0;
}