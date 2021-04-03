#include "eventlist.h"
#include "event.h"
#include <vector>
EventList::EventList() {
    Event *ToplevelDogScene = new Event(
                "You see a small dog lying in the road", "Ignore it, it's not your problem.", "Run over and see if it's ok",
                "I helped the doggy out.", "Is there something in the road?",0,"",false);

    Event *MidlevelDogSceneA = new Event(
                "You ignore the dog, like a heartless monster. You hear him whine softly.","Keep walking.","He needs help, go help him!",
                false);

    Event *MidlevelDogSceneB = new Event(
                "You ran over and grabbed the dog, he's ok he's just hungry.", "Take him to raps for some food?","Give him your lunch so you have an excuse to go to raps?",false);

    Event *BottomlevelDogSceneA = new Event(
                "You've walked out of earshot of the poor whimpering dog.","Go to raps?","Go to class?",true
                );

            Event *BottomlevelDogSceneB = new Event(
                        "Showing that you actually do have a human heart, you race to the dog's aid. You see that he's emaciated and needs food badly.","Take him to raps?","Give him your lunch?",true
                        );

            Event *BottomlevelDogSceneC = new Event(
                       "You bought some chicken and water for the dog to eat, grabbing a wrap for yourself as you're at it. The dog barks cheerfully at you and runs off after having his fill.","Go to class?","Go home?",true
                        );

            Event *BottomlevelDogSceneD = new Event(
                        "You give the dog your lunch. Your stomach mourns the loss of its anticipated breakfast roll, but you console yourself with the promise of a wrap later. The dog seems really happy to have a good meal and runs off after he's finished it.","Go home?","Go to class?",true
                        );

            ToplevelDogScene->leftOption=MidlevelDogSceneA;
            ToplevelDogScene->rightOption=MidlevelDogSceneB;
            MidlevelDogSceneA->leftOption=BottomlevelDogSceneA;
            MidlevelDogSceneA->rightOption=BottomlevelDogSceneB;
            MidlevelDogSceneB->leftOption=BottomlevelDogSceneC;
            MidlevelDogSceneB->rightOption=BottomlevelDogSceneD;

            events.push_back(*ToplevelDogScene);


}

Event *EventList::getRandomEvent() {
  int randomNumber = (rand() % events.size());
  return &events[randomNumber];
}
