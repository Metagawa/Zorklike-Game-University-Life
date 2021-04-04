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

