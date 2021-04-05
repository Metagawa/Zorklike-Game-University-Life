#include "event.h"
#include <string>
using namespace std;
// headnode constructor
Event::Event(string text, string leftOptiontext, string rightOptiontext,
             string pixmapCharacterResource, bool isEnd, bool isSolo,
             int locationLeft, int locationRight) {
  this->text = text;
  this->leftOptiontext = leftOptiontext;
  this->rightOptiontext = rightOptiontext;
  this->pixmapCharacterResource = pixmapCharacterResource;
  this->isEnd = isEnd;
  this->isSolo = isSolo;
  this->locationLeft = locationLeft;
  this->locationRight = locationRight;
}
Event::~Event() {
  delete leftOption;
  delete rightOption;
}
