#include <iostream>
#include "labstructs.h"
using namespace std;

void printTime(Time time) {
    cout << time.h << ":" << time.m << endl;
}
void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}
//task a
int minutesSinceMidnight(Time time){
	int minhour = 0;
	int min = 0;
	int total = 0;

		minhour += (time.h * 60);
		min += time.m;
		total += (minhour + min);
	
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
	Time time = time0;
	
	time.h = time0.h + ( (time0.m + min) / 60 );
	time.m = (time0.m + min) % 60;
	
	return time;
}

//task c
string TimeSlotString(TimeSlot ts){
	Movie m = ts.movie;
	string title = m.title; //title
	string g; //genre
	switch (m.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
	string duration = to_string(m.duration) + " mins"; //duration
	string start = to_string(ts.startTime.h) + ":" + to_string(ts.startTime.m); //startTime
	Time endTime = ts.startTime; //endTime
	endTime = addMinutes(endTime, ts.movie.duration);
	string end = to_string(endTime.h) + ":" + to_string(endTime.m);

	
	return title + " " + g + " (" + duration + ") [starts at " + start + ", ends by " + end + "]";
}


//task d
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
	Time endTime = ts.startTime;
	endTime = addMinutes(endTime, ts.movie.duration);
	TimeSlot next = {nextMovie, endTime};
	
	return next;

}
//task e;
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
	
	Movie movie1, movie2;
	Time movie1end, movie2start;
	if ( minutesUntil(ts1.startTime, ts2.startTime) > 0 ) {
		movie1 = ts1.movie;
		movie2 = ts2.movie;
		movie1end = ts1.startTime;
		movie2start = ts2.startTime;
	}
	else {
		movie1 = ts2.movie;
		movie2 = ts1.movie;
		movie1end = ts2.startTime;
		movie2start = ts1.startTime;
	}
	
	movie1end = addMinutes (movie1end, movie1.duration); 
	
	if ( minutesUntil(movie1end, movie2start) >= 0 ) { 
		return false; 
	} 
	else { 
		return true;
	} 
	
}

