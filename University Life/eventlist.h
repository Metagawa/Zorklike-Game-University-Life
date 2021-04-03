#ifndef EVENTLIST_H
#define EVENTLIST_H
#include "event.h"
#include <vector>

using std::vector;
class EventList {
public:
  EventList();
  vector<event> events;
  event getRandomEvent();
};

#endif // EVENTLIST_H
