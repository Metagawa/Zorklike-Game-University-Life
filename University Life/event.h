#ifndef EVENT_H
#define EVENT_H
#include <string>

using namespace std;

class Event {
public:
  Event(string text, string leftOptiontext, string rightOptiontext,
        string pixmapCharacterResource, bool isEnd, bool isSolo,
        int locationLeft, int locationRight);

  ~Event();
  friend class Zork;
  friend class EventList;
  operator std::string();

private:
  Event *leftOption;
  Event *rightOption;
  string text;
  string leftOptiontext;
  string rightOptiontext;

  int locationLeft;
  int locationRight;
  bool isSolo;
  bool isEnd;
  string pixmapCharacterResource;
};

#endif // EVENT_H
