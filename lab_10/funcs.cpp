#include <iostream>
#include "labstructs.h"
using namespace std;
//task a
int minutesSinceMidnight(Time time){
	int minhour = 0;
	int min = 0;
	int total = 0;
	if ((time.h >=0) && (time.m >= 0)){
		minhour += (time.h * 60);
		min += time.m;
		total += (minhour + min);
	}
	return total;
}


int minutesUntil(Time earlier, Time later){
	int diffhour = 0;
	int min = 0;
	int total = 0;
	if (earlier.m < later.m){
		diffhour += (later.h - earlier.h) * 60;
		min += (later.m-earlier.m);
		total += (diffhour + min);
	}
	else if(later.m < earlier.m){
		diffhour += (later.h - earlier.h) * 60;
		min -= (later.m - earlier.m);
		total += (diffhour - min);
	}
	return total;
}

//task b

Time addMinutes(Time time0, int min){
	int newhour = 0;
	if (min > 60){
		newhour += (time0.h + (min%60));
		time0.h = newhour;
		time0.m = (min - time0.m);
	}
	else{
		time0.m = (min+time0.m);
	}
	return time0;
}
