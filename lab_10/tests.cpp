#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "labstructs.h"
#include "doctest.h"

TEST_CASE("Testing minutesSinceMidnight"){
	CHECK(minutesSinceMidnight({2,10}) == 130);
	CHECK(minutesSinceMidnight({0,0}) == 0);
	CHECK(minutesSinceMidnight({4,30}) == 270);
}

TEST_CASE("Testing minutesUntil"){
	CHECK(minutesUntil({10,30}, {13,40}) == 190);
	CHECK(minutesUntil({0,0}, {0,0}) == 0);
	CHECK(minutesUntil({1,20},{4,40}) == 200);
	CHECK(minutesUntil({10,30}, {13,20}) == 170);
}

TEST_CASE("Testing addMinutes"){
	CHECK(minutesSinceMidnight(addMinutes({8, 10}, 75)) == minutesSinceMidnight({9, 25}) );
	CHECK(minutesSinceMidnight(addMinutes({8, 10}, 0)) == minutesSinceMidnight({8, 10}) );
	CHECK(minutesSinceMidnight(addMinutes({2, 45}, 60)) == minutesSinceMidnight({3, 45}) );
}

Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};

TimeSlot morning = {movie1, {9, 15}};
TimeSlot daytime = {movie1, {12, 15}};
TimeSlot evening = {movie2, {16, 45}};

TEST_CASE("Testing TimeSlotString"){
	string m = "Back to the Future COMEDY (116 mins) [starts at 9:15, ends by 11:11]";
	CHECK(TimeSlotString(morning) == m);
	string d = "Back to the Future COMEDY (116 mins) [starts at 12:15, ends by 14:11]";
	CHECK(TimeSlotString(daytime) == d);
	string e = "Black Panther ACTION (134 mins) [starts at 16:45, ends by 18:59]";
	CHECK(TimeSlotString(evening) == e);
}

TEST_CASE("Testing scheduleAfter"){
	CHECK(minutesSinceMidnight(addMinutes({14, 10}, 120)) == minutesSinceMidnight({16, 10}));
}

TimeSlot ts1 = scheduleAfter(morning, movie2);

TEST_CASE("Testing timeOverlap") {
	CHECK(timeOverlap(morning, evening) == false);
	CHECK(timeOverlap(morning, ts1) == false);
	CHECK(timeOverlap(daytime, ts1) == true);
}
