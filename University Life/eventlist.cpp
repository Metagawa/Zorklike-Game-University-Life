#include "eventlist.h"
#include "event.h"
#include <algorithm>
#include <vector>
#define getRand(a) ((rand() % a))
EventList::EventList() {

  // REMEMBER TO ADD EVENT CALL HERE
  // REMEMBER TO ADD EVENT TO HEADER
  // createEvent();

  // createMissingDogEvent();
  createPoem();
  createShoppingList();
  createGoForStrollEvent();
}

Event *EventList::getRandomEvent() {
  int randomNumber = getRand(events.size());
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
void EventList::createPoem() {
  Event *toplevelScene =
      new Event("I have an idea for a poem!", "Yay, I love poems",
                "But I hate poems!", "", false, false, -1, -1);

  // top level's left option
  Event *midlevelSceneA = new Event(
      "Whose pen is that? I think I know. Its owner is quite happy though. "
      "Full of joy like a vivid rainbow, I watch him laugh. I cry hello. He "
      "gives his pen a shake, And laughs until her belly aches. The only other "
      "sound's the break, Of distant waves and birds awake. The pen is black, "
      "powerful and deep, But he has promises to keep, After cake and lots of "
      "sleep. Sweet dreams come to him cheap. He rises from his gentle bed, "
      "With thoughts of kittens in his head, He eats his jam with lots of "
      "bread. Ready for the day ahead.",
      "I need to jot that down!", "", "", true, true, -1, -1);

  Event *midlevelSceneB = new Event("Maybe I will think of a song next time",
                                    "Maybe...", "", "", true, true, -1, -1);

  toplevelScene->leftOption = midlevelSceneA;
  // connects the top level's second option with MidLevelB
  toplevelScene->rightOption = midlevelSceneB;

  // puts the event into the list of events.
  events.push_back(*toplevelScene);
}
void EventList::createShoppingList() {
  Event *toplevelScene =
      new Event("I need to write my shopping list", "I want noodles",
                "I want pasta!", "", false, false, -1, -1);

  // top level's left option
  Event *midlevelSceneA =
      new Event("Noodles!", "Thats all.", "", "", true, true, -1, -1);

  Event *midlevelSceneB =
      new Event("Pasta!", "Thats all.", "", "", true, true, -1, -1);

  toplevelScene->leftOption = midlevelSceneA;
  // connects the top level's second option with MidLevelB
  toplevelScene->rightOption = midlevelSceneB;

  // puts the event into the list of events.
  events.push_back(*toplevelScene);
}
void EventList::createGoForStrollEvent() {
  Event *toplevelScene =
      new Event("I need to clear my head, maybe I should go for a stroll",
                "I will walk around the Quad", "I will walk to to the shop", "",
                false, false, -1, -1);

  // top level's left option
  Event *midlevelSceneA =
      new Event("Seeing busy people in the quad always relaxes me",
                "Stay at the quad", "", "", true, true, 8, 8);

  Event *midlevelSceneB = new Event("I'm all better after getting some food",
                                    "Eat food", "", "", true, true, 11, 11);

  toplevelScene->leftOption = midlevelSceneA;
  // connects the top level's second option with MidLevelB
  toplevelScene->rightOption = midlevelSceneB;

  // puts the event into the list of events.
  events.push_back(*toplevelScene);
}
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
Event *EventList::createDayOneEvent() {
  Event *toplevelScene =
      new Event("I have just arrived on campus. ", "It's chilly this morning.",
                "", "", false, true, -1, -1);

  // top level's left option
  Event *midlevelSceneA =
      new Event("I think I should have a walk around the "
                "UL campus today to get my bearings",
                "Maybe I will meet some people?", "", "", false, true, -1, -1);

  // Mid level a's left option
  Event *bottomlevelSceneA = new Event(
      "I think that sketching out the map of the campus should also help me",
      "I sure do love to sketch!", "", "", true, true, -1, -1);

  toplevelScene->leftOption = midlevelSceneA;
  // connects the top level's second option with MidLevelB
  midlevelSceneA->leftOption = bottomlevelSceneA;

  // puts the event into the list of events.
  return toplevelScene;
}

Event *EventList::createFinalEvent() {
  Event *toplevelScene = new Event(
      "Hard to believe it's Sunday already, feels like the last week went by "
      "in minutes... But I had a lot of fun",
      "This is just the start after all.", "", "", false, true, -1, -1);

  // top level's left option
  Event *midlevelSceneA = new Event(
      "Sure was a craaaaaaazy week feels like so much happened. I probably "
      "missed a ton of lectures with all that walking around.",
      "Eh I'm sure I'll catch up... Probably.", "", "", false, true, -1, -1);

  // Mid level a's left option
  Event *bottomlevelSceneA =
      new Event("If my first week was this hectic, I'm sure there's lots more "
                "in store for me over the next few years.",
                "My University Life starts here!", "", "", false, true, -1, -1);
  Event *finallevelSceneA =
      new Event("Exit Game", "", "", "", true, true, -1, -1);
  toplevelScene->leftOption = midlevelSceneA;
  // connects the top level's second option with MidLevelB
  midlevelSceneA->leftOption = bottomlevelSceneA;
  bottomlevelSceneA->leftOption = finallevelSceneA;

  // puts the event into the list of events.
  return toplevelScene;
}
EventList::~EventList() { events.~vector<Event>(); }

vector<Event> EventList::getShuffledDeepCopy() {
  vector<Event> copy = events; // deep copy, unlike java, All Events copied
  random_shuffle(copy.begin(), copy.end());
  return copy;
}
