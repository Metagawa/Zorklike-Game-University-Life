#include "eventlist.h"
#include "event.h"
#include <vector>
EventList::EventList() {
  Event *child1 = new Event("some text", "left option", "right option", true);
  Event *child2 = new Event("some text", "left option", "right option", true);

  Event *head1 =
      new Event("Welcome to the Library", "Say \'Bye\'",
                "Leave without saying anything", *child1, *child2,
                "This event is now over", "There is an event", 5, "", false);
  head1->rightOption =
      new Event("some text", "left option", "right option", true);
  head1->leftOption =
      new Event("some text", "left option", "right option", true);

  events.push_back(*head1);
}

Event *EventList::getRandomEvent() {
  int randomNumber = (rand() % events.size());
  return &events[randomNumber];
}
