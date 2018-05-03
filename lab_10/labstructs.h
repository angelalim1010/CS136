#pragma once
#include <iostream>
using namespace std;
struct Time {
    int h;
    int m;
};

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printTime(Time time);