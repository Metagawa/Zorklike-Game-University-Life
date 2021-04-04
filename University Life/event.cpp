#include "event.h"
#include <string>
using namespace std;
// headnode constructor
Event::Event(string text, string leftOptiontext, string rightOptiontext,
             string eventOverText, string eventBeginText,
             string pixmapCharacterResource, bool isEnd, bool isSolo,
             int locationLeft, int locationRight) {
  this->text = text;
  this->leftOptiontext = leftOptiontext;
  this->rightOptiontext = rightOptiontext;
  this->eventOverText = eventOverText;
  this->eventBeginText = eventBeginText;
  this->pixmapCharacterResource = pixmapCharacterResource;
  this->isEnd = isEnd;
  this->isSolo = isSolo;
  this->locationLeft = locationLeft;
  this->locationRight = locationRight;
}

string Event::getLocation(int location) {
  switch (location) {
  case -1:
    return "";
  case 0:
    return "a";
  case 1:
    return "b";
  case 2:
    return "c";
  case 3:
    return "d";
  case 4:
    return "e";
  case 5:
    return "f";
  case 6:
    return "g";
  case 7:
    return "h";
  case 8:
    return "i";
  case 9:
    return "j";
  case 10:
    return "k";
  case 11:
    return "l";
  case 12:
    return "m";
  case 13:
    return "n";

  // you can have any number of case statements.
  default: // Optional
    return "";
  }
}
