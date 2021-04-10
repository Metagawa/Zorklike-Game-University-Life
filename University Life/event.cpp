#include "event.h"
#include <string>
using namespace std;
//headnode constructor
Event::Event(string text, string leftOptiontext, string rightOptiontext,
             string pixmapCharacterResource, bool isEnd = false,
             bool isSolo = false, int locationLeft = -1, int locationRight = -1)
    : text(text), leftOptiontext(leftOptiontext),
      rightOptiontext(rightOptiontext), locationLeft(locationLeft),
      locationRight(locationRight),
      pixmapCharacterResource(pixmapCharacterResource)
{
  this->isSolo = isSolo;
  this->isEnd = isEnd;
}
Event::~Event()
{
  delete leftOption;
  delete rightOption;
}
Event::operator std::string() { return text; }
