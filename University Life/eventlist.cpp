#include "eventlist.h"
#include "event.h"
#include <vector>
EventList::EventList() {

  // REMEMBER TO ADD EVENT CALL HERE
  // REMEMBER TO ADD EVENT TO HEADER
  // createEvent();

  createMissingDogEvent();
}

Event *EventList::getRandomEvent() {
  int randomNumber = (rand() % events.size());
  return &events[randomNumber];
}

/*TEMPLATE EVENT START
void EventList::createEvent()
{
    Event *ToplevelScene = new Event(
        " ",   //Event Text
        " ",   //Top choice
        " ",   //Bottom choice
        " ",   //Character
        false, //Is this the last scene?
        false, //Is there one choice?
        -1,    //Left Location (top choice)
        -1);   //Right Location (bottom choice)

    //top level's left option
    Event *MidlevelSceneA = new Event(
        " ",   //Event Text
        " ",   //Top choice
        " ",   //Bottom choice
        " ",   //Character
        false, //Is this the last scene?
        false, //Is there one choice?
        -1,    //Left Location (top choice)
        -1);   //Right Location (bottom choice)

    //top level's right option
    Event *MidlevelSceneB = new Event(
        " ",   //Event Text
        " ",   //Top choice
        " ",   //Bottom choice
        " ",   //Character
        false, //Is this the last scene?
        false, //Is there one choice?
        -1,    //Left Location (top choice)
        -1);   //Right Location (bottom choice)

    //Mid level a's left option
    Event *BottomlevelSceneA = new Event(
        " ",   //Event Text
        " ",   //Top choice
        " ",   //Bottom choice
        " ",   //Character
        false, //Is this the last scene?
        false, //Is there one choice?
        -1,    //Left Location (top choice)
        -1);   //Right Location (bottom choice)

    //Mid level a's right option
    Event *BottomlevelSceneB = new Event(
        " ",   //Event Text
        " ",   //Top choice
        " ",   //Bottom choice
        " ",   //Character
        false, //Is this the last scene?
        false, //Is there one choice?
        -1,    //Left Location (top choice)
        -1);   //Right Location (bottom choice)

    //Mid level b's left option
    Event *BottomlevelSceneC = new Event(
        " ",   //Event Text
        " ",   //Top choice
        " ",   //Bottom choice
        " ",   //Character
        false, //Is this the last scene?
        false, //Is there one choice?
        -1,    //Left Location (top choice)
        -1);   //Right Location (bottom choice)

    //Mid level b's right option
    Event *BottomlevelSceneD = new Event(
        " ",   //Event Text
        " ",   //Top choice
        " ",   //Bottom choice
        " ",   //Character
        false, //Is this the last scene?
        false, //Is there one choice?
        -1,    //Left Location (top choice)
        -1);   //Right Location (bottom choice)

    //Toplevel to midlevel
    //connects the top level's first option with MidLevelA
    ToplevelScene->leftOption = MidlevelSceneA;
    //connects the top level's second option with MidLevelB
    ToplevelScene->rightOption = MidlevelSceneB;

    //Midlevel to bottomlevel
    //connects MidLevelA's first option with BottomLevelA
    MidlevelSceneA->leftOption = BottomlevelSceneA;
    //connects MidLevelA's second option with BottomLevelB
    MidlevelSceneA->rightOption = BottomlevelSceneB;
    //connects MidLevelB's first option with BottomLevelC
    MidlevelSceneB->leftOption = BottomlevelSceneC;
    //connects MidLevelB's second option with BottomLevelD
    MidlevelSceneB->rightOption = BottomlevelSceneD;

    //puts the event into the list of events.
    events.push_back(*ToplevelScene);
}
TEMPLATE EVENT END*/

void EventList::createMissingDogEvent() {
  Event *ToplevelDogScene =
      new Event("I saw a small dog lying in the road",
                "I Ignored it, not like it was my problem.",
                "I ran over to see if it was ok", "", false, false, -1, -1);

  // top level's left option
  Event *MidlevelDogSceneA =
      new Event("I ignored the dog, like a heartless monster, but then I heard "
                "him whine softly.",
                "I kept walking though, not my dog.",
                "I saw he needed help and ran over.", "", false, false, -1, -1);

  // top level's right option
  Event *MidlevelDogSceneB = new Event(
      "I ran over and grabbed the dog, he was fine, just hungry.",
      "I took him to raps for some food.", " ", "", false, true, 11, -1);

  // Mid level a's left option
  Event *BottomlevelDogSceneA = new Event(
      "I walked until I was out of earshot of the dog.",
      "I was feeling hungry so I went to raps.", "", "", true, true, 11, -1);

  // Mid level a's right option
  Event *BottomlevelDogSceneB = new Event(
      "When I ran over to the dog out of guilt, I noticed that he seemed "
      "really hungry and too weak to move because of it.",
      "I took him to Raps for some food.",
      "I felt bad and decided to give him my lunch", "", true, false, -1, 11);

  // Mid level b's left option
  Event *BottomlevelDogSceneC =
      new Event("I bought some chicken and water for the dog to eat, grabbed a "
                "wrap for myself while I was there. The dog barked cheerfully "
                "at me and ran off after having his fill.",
                "I was glad he felt better.", " ", "", true, true, 11, -1);

  // Mid level b's right option
  Event *BottomlevelDogSceneD =
      new Event("I gave the dog my lunch. My stomach mourned the loss of its "
                "anticipated breakfast roll, but I console myself with the "
                "promise of a wrap later. The dog seemed really happy to have "
                "a good meal and ran off after he finished it.",
                "I was glad to have helped.", "", "", true, true, -1, -1);

  // Toplevel to midlevel
  // connects the top level's first option with MidLevelA
  ToplevelDogScene->leftOption = MidlevelDogSceneA;
  // connects the top level's second option with MidLevelB
  ToplevelDogScene->rightOption = MidlevelDogSceneB;

  // Midlevel to bottomlevel
  // connects MidLevelA's first option with BottomLevelA
  MidlevelDogSceneA->leftOption = BottomlevelDogSceneA;
  // Connects MidLevelA's second option with BottomLevelB
  MidlevelDogSceneA->rightOption = BottomlevelDogSceneB;
  // connects MidLevelB's first option with BottomLevelC
  MidlevelDogSceneB->leftOption = BottomlevelDogSceneC;
  // connects MidLevelB's second option with BottomLevelD
  MidlevelDogSceneB->rightOption = BottomlevelDogSceneD;

  // puts the event into the list of events.
  events.push_back(*ToplevelDogScene);
}

EventList::~EventList() { events.clear(); }
