#ifndef EVENT_H
#include <string>
#define EVENT_H
using namespace std;

class event {
public:
  event(string text, string leftOptiontext, string rightOptiontext,
        event leftOption, event rightOption, string eventOverText,
        string eventBeginText, int location, string pixmapCharacterResource);
  event(string text, string leftOptiontext, string rightOptiontext,
        event leftOption, event rightOption);
  event(string text, string leftOptiontext, string rightOptiontext);
  string getLocation(int location);
  string text;
  string leftOptiontext;
  string rightOptiontext;
  event *leftOption;
  event *rightOption;
  string eventOverText;
  string eventBeginText;
  int location;
  string pixmapCharacterResource;
};

#endif // EVENT_H
