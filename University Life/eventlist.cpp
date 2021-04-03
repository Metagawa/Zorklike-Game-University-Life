#include "eventlist.h"
#include "event.h"
#include <vector>
EventList::EventList() {
  event *child1 = new event("some text", "left option", "right option");
  event *child2 = new event("some text", "left option", "right option");

  event *head1 = new event(
      "Welcome to the Library", "Say \'Bye\'", "Leave without saying anything",
      *child1, *child2, "This event is now over", "There is an event", 5, "");
  events.push_back(*head1);
}

event EventList::getRandomEvent() {
  int randomNumber = (rand() % events.size());
  return events[randomNumber];
}
