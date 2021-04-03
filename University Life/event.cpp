#include "event.h"
#include <string>
using namespace std;
// headnode constructor
Event::Event(string text, string leftOptiontext, string rightOptiontext,
             Event leftOption, Event rightOption, string eventOverText,
             string eventBeginText, int location,
             string pixmapCharacterResource, bool isEnd) {
  this->text = text;
  this->leftOptiontext = leftOptiontext;
  this->rightOptiontext = rightOptiontext;
  this->leftOption = &leftOption;
  this->rightOption = &rightOption;
  this->eventOverText = eventOverText;
  this->eventBeginText = eventBeginText;
  this->location = location;
  this->pixmapCharacterResource = pixmapCharacterResource;
  this->isEnd = isEnd;
}

// childnode constructor
Event::Event(string text, string leftOptiontext, string rightOptiontext,
             Event leftOption, Event rightOption, bool isEnd) {
  this->text = text;
  this->leftOptiontext = leftOptiontext;
  this->rightOptiontext = rightOptiontext;
  this->leftOption = &leftOption;
  this->rightOption = &rightOption;
  this->isEnd = isEnd;
}

Event::Event(string text, string leftOptiontext, string rightOptiontext,
             bool isEnd) {
  this->text = text;
  this->leftOptiontext = leftOptiontext;
  this->rightOptiontext = rightOptiontext;
  this->isEnd = isEnd;
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
