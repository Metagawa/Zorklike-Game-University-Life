#include "eventlist.h"
#include "event.h"
#include <vector>
EventList::EventList() {
  Event *child1 = new Event("some text", "left option", "right option");
  Event *child2 = new Event("some text", "left option", "right option");

  Event *head1 = new Event(
      "Welcome to the Library", "Say \'Bye\'", "Leave without saying anything",
      *child1, *child2, "This event is now over", "There is an event", 5, "");
  events.push_back(*head1);
}

Event EventList::getRandomEvent() {
  int randomNumber = (rand() % events.size());
  return events[randomNumber];
}
