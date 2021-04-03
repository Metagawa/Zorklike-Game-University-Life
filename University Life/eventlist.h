#ifndef EVENTLIST_H
#define EVENTLIST_H
#include "event.h"
using std::vector;
class EventList {
public:
  EventList();
  vector<event> events();
};

#endif // EVENTLIST_H
