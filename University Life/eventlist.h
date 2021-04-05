#ifndef EVENTLIST_H
#define EVENTLIST_H
#include "event.h"
#include <vector>

using std::vector;
class EventList {
public:
  EventList();
  vector<Event> events;
  Event *getRandomEvent();
  ~EventList();
  vector<Event> getShuffledDeepCopy();

private:
  void createMissingDogEvent();
  // void createEvent();
};

#endif // EVENTLIST_H
