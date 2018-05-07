#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
using namespace std;
#include "labstructs.h"

int main(){
	cout << minutesSinceMidnight({2,10}) << endl;
	cout << minutesUntil({10,30}, {13,40}) << endl;
	Time time0 = addMinutes({8,10}, 75);
	printTime(time0);
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};

	TimeSlot morning = {movie1, {9, 15}};  
	TimeSlot daytime = {movie2, {12, 15}}; 
	TimeSlot evening = {movie2, {16, 45}}; 
	cout << TimeSlotString(morning) << endl;
	Time nextMovie = addMinutes({14,10}, 120);
	printTime(nextMovie);

	return 0;
}