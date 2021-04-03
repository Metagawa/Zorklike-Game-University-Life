#include "eventlist.h"
#include "event.h"
#include <vector>
EventList::EventList() {
  Event *head1 = new Event(
      "Welcome to the Library", "Say \'Bye\'", "Leave without saying anything",
      "This event is now over", "There is an event", 5, "", false);
  head1->leftOption =
      new Event("some text", "left option", "right option", true);


  Event *head2 = new Event(
      "Welcome to the kitchen", "Say \'Bye\'", "Leave without saying anything",
      "This event is now over", "There is an event", 5, "", false);
  head2->rightOption =
      new Event("some text", "left option", "right option", true);
  head2->leftOption =
      new Event("some text", "left option", "right option", true);

  head1->rightOption=head2;

  events.push_back(*head1);

}

Event *EventList::getRandomEvent() {
  int randomNumber = (rand() % events.size());
  return &events[randomNumber];
}
