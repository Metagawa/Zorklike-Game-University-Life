#ifndef EVENT_H
#define EVENT_H
#include <string>

using namespace std;

class Event {
public:
  Event(string text, string leftOptiontext, string rightOptiontext,
        string pixmapCharacterResource, bool isEnd, bool isSolo,
        int locationLeft, int locationRight);
  string text;
  string leftOptiontext;
  string rightOptiontext;

  int locationLeft;
  int locationRight;
  bool isSolo;
  bool isEnd;
  string pixmapCharacterResource;
  ~Event();
  friend class Zork;
  friend class EventList;

private:
  Event *leftOption;
  Event *rightOption;
};

#endif // EVENT_H
