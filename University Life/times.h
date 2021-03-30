#ifndef TIMES_H
#include <string>
#define TIMES_H
using namespace std;

class Times {
public:
  Times();
  // monday = 0, tuesday = 1 etc
  int getDayNum();
  // 9 = 9am,
  int getTime();
  // returns true if day advances
  bool advanceTime();
  // returns time as a nice string;
  string getTimeString();

  void setTime(int newTime);
  void setDayNum(int newDay);
  string getDayString(int i);
  string getDayString();
  bool isDayTime();
  bool isRaining();

private:
  int dayNum;
  int time;
};

#endif // TIME_H
