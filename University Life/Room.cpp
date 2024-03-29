#include "Room.h"
#include "Command.h"

Room::Room(string description, string dayClear, string dayRain,
           string nightClear, string nightRain, int lassoX, int lassoY) {
  this->lassoX = lassoX;
  this->lassoY = lassoY;
  this->description = description;
  this->dayClear = dayClear;
  this->dayRain = dayRain;
  this->nightClear = nightClear;
  this->nightRain = nightRain;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
  if (north != NULL)
    exits["north"] = north;
  if (east != NULL)
    exits["east"] = east;
  if (south != NULL)
    exits["south"] = south;
  if (west != NULL)
    exits["west"] = west;
}

string Room::shortDescription() { return description; }

string Room::longDescription() { return "I went to the " + description; }

string Room::getDayClear() { return dayClear; }
string Room::getNightClear() { return nightClear; }
string Room::getDayRain() { return dayRain; }
string Room::getNightRain() { return nightRain; }

int Room::getLassoX() { return this->lassoX; }
int Room::getLassoY() { return this->lassoY; }
string Room::exitString() {
  string returnString = "\nexits =";
  for (map<string, Room *>::iterator i = exits.begin(); i != exits.end(); i++)
    // Loop through map
    returnString += "  " + i->first; // access the "first" element of the pair
                                     // (direction as a string)
  return returnString;
}

Room *Room::nextRoom(string direction) {
  map<string, Room *>::iterator next =
      exits.find(direction); // returns an iterator for the "pair"
  if (next == exits.end())
    return NULL;       // if exits.end() was returned, there's no room in that
                       // direction.
  return next->second; // If there is a room, remove the "second" (Room*)
                       // part of the "pair" (<string, Room*>) and return it.
}
