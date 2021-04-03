#include "event.h"
#include <string>
using namespace std;
event::event(string text, string leftOptiontext, string rightOptiontext,
             event leftOption, event rightOption, string eventOverText, string eventBeginText,
             int location, string pixmapCharacterResource) {
  this->text = text;
  this->leftOptiontext = leftOptiontext;
  this->rightOptiontext = rightOptiontext;
  this->leftOption = &leftOption;
  this->rightOption = &rightOption;
  this->eventOverText = eventOverText;
  this->eventBeginText=eventBeginText;
  this->location = location;
  this->pixmapCharacterResource = pixmapCharacterResource;
}

event::event(string text, string leftOptiontext, string rightOptiontext,
             event leftOption, event rightOption) {
  this->text = text;
  this->leftOptiontext = leftOptiontext;
  this->rightOptiontext = rightOptiontext;
  this->leftOption = &leftOption;
  this->rightOption = &rightOption;
}

string event::getLocation(int location) {
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
