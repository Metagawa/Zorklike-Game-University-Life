#include "times.h"
#include <string>
using namespace std;
Times::Times() {
  setTime(9);
  setDayNum(0);
  rain = (rand() % 2) != 0;
}

int Times::getDayNum() { return this->dayNum; }
int Times::getTime() { return this->time; }
bool Times::advanceTime() {
  time += 2;
  if (time >= 24) {
    rain = (rand() % 2) != 0;
    dayNum++;
    time = 9;
    return true;
  } else if (time >= 18) {
    rain = (rand() % 2) != 0;
  }
  return false;
}
bool Times::isDayTime() { return time < 18; }
bool Times::isRaining() { return this->rain; }
string Times::getTimeString() {
  if (getTime() >= 9) {
    return "0" + to_string(getTime()) + ":00";
  } else {
    return to_string(getTime()) + ":00";
  }
}

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

string Times::getDayString() { return getDayString(getDayNum()); }
void Times::setTime(int newtime) { this->time = newtime; }
void Times::setDayNum(int newday) { this->dayNum = newday; }
