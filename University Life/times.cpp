#include "times.h"
#include <string>
#define NUM_HOURS_IN_DAY 24

using namespace std;
// Variable created inside namespace
namespace timespace {
string season = "Autumn";
} // namespace timespace

// gets the current season
string Times::getSeason() { return timespace::season; }

// Constructor which sets the current time to 9am and the current day to 0
Times::Times() {
  setTime(9);
  setDayNum(0);
  rain = (rand() % 2) != 0;
}

// gets the current day as an int
int Times::getDayNum() { return this->dayNum; }

// gets the current time
int Times::getTime() { return this->time; }

// advances the time by 1 hour. If it is a new day it will set the time back and
// increment the current day, furthermore the rain boolean is updated on every
// new day and every evening
// returns a boolean if there is a new day (This info is needed in unizork.cpp
// as we need to know when to make a new day of the week tab
bool Times::advanceTime() {
  time += 1;
  if (time >= NUM_HOURS_IN_DAY) {
    rain = (rand() % 2) != 0;
    dayNum++;
    time = 9;
    return true;
  } else if (time == 18) {
    rain = (rand() % 2) != 0;
  }
  return false;
}

// returns whether or not it is daytime (before 6pm)
bool Times::isDayTime() { return time < 18; }

// reutrns whether or not it is raining
bool Times::isRaining() { return this->rain; }

// returns the current time as a string for the lcd display
string Times::getTimeString() {
  if (getTime() >= 9) {
    return "0" + to_string(getTime()) + ":00";
  } else {
    return to_string(getTime()) + ":00";
  }
}

// overloaded method which returns the day of the week as a string when given an
// int
string Times::getDayString(int i) {
  switch (i) {
  case 0:
    return "Monday";
  case 1:
    return "Tuesday";
  case 2:
    return "Wednesday";
  case 3:
    return "Thursday";
  case 4:
    return "Friday";
  case 5:
    return "Saturday";
  case 6:
    return "Sunday";

  // you can have any number of case statements.
  default: // Optional
    return getDayString(i % 7);
  }
}

// returns the current day of the week as a string
string Times::getDayString() { return getDayString(getDayNum()); }

// set the current time
void Times::setTime(int newtime) { this->time = newtime; }

// set the current day
void Times::setDayNum(int newday) { this->dayNum = newday; }

// postfix ++ operator overrided
void Times::operator++(int) { time = time + 1; }
