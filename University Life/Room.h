#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;

class Room
{

private:
  string description;
  string dayClear;
  string dayRain;
  string nightClear;
  string nightRain;
  map<string, Room *> exits;
  string exitString();
  int lassoX;
  int lassoY;

public:
  Room(string description, string dayClear, string dayRain, string nightClear,
       string nightRain, int lassoX, int lassoY);
  void setExits(Room *north, Room *east, Room *south, Room *west);
  string shortDescription();
  string longDescription();
  string getDayClear();
  string getDayRain();
  string getNightClear();
  string getNightRain();
  int getLassoX();
  int getLassoY();
  Room *nextRoom(string direction);
};

#endif
