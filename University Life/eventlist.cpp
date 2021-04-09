#include "eventlist.h"
#include "event.h"
#include <algorithm>
#include <stdio.h>
#define ARRAY_SIZE 10
int arrayevents[ARRAY_SIZE];
#define getRand(a) ((rand() % a))

EventList::EventList()
{

    /* Event *ToplevelScene = new Event(
        " ",   //Event Text
        " ",   //Top choice
        " ",   //Bottom choice
        " ",   //Character
        false, //Is this the last scene?
        false, //Is there one choice?
        -1,    //Left Location (top choice)
        -1);   //Right Location (bottom choice)

*/

    Event *toplevelPoemScene =
        new Event("I have an idea for a poem!", "Yay, I love poems",
                  "But I hate poems!", "", false, false, -1, -1);

    // top level's left option
    Event *midlevelPoemSceneA = new Event(
        "Whose pen is that? I think I know. Its owner is quite happy though. "
        "Full of joy like a vivid rainbow, I watch him laugh. I cry hello. He "
        "gives his pen a shake, And laughs until her belly aches. The only other "
        "sound's the break, Of distant waves and birds awake. The pen is black, "
        "powerful and deep, But he has promises to keep, After cake and lots of "
        "sleep. Sweet dreams come to him cheap. He rises from his gentle bed, "
        "With thoughts of kittens in his head, He eats his jam with lots of "
        "bread. Ready for the day ahead.",
        "I need to jot that down!", "", "", true, true, -1, -1);

    Event *midlevelPoemSceneB = new Event("Maybe I will think of a song next time",
                                          "Maybe...", "", "", true, true, -1, -1);

    toplevelPoemScene->leftOption = midlevelPoemSceneA;
    // connects the top level's second option with MidLevelB
    toplevelPoemScene->rightOption = midlevelPoemSceneB;

    // puts the event into the list of events.
    arrayevents[0] = toplevelPoemScene;

    Event *toplevelShopScene =
        new Event("I need to write my shopping list", "I want noodles",
                  "I want pasta!", "", false, false, -1, -1);

    // top level's left option
    Event *midlevelShopSceneA =
        new Event("Noodles!", "Thats all.", "", "", true, true, -1, -1);

    Event *midlevelShopSceneB =
        new Event("Pasta!", "Thats all.", "", "", true, true, -1, -1);

    toplevelShopScene->leftOption = midlevelShopSceneA;
    // connects the top level's second option with MidLevelB
    toplevelShopScene->rightOption = midlevelShopSceneB;

    // puts the event into the list of events.
    arrayevents[1] = toplevelShopScene;

    Event *toplevelStrollScene =
        new Event("I need to clear my head, maybe I should go for a stroll",
                  "I will walk around the Quad", "I will walk to to the shop", "",
                  false, false, -1, -1);

    // top level's left option
    Event *midlevelStrollSceneA =
        new Event("Seeing busy people in the quad always relaxes me",
                  "Stay at the quad", "", "", true, true, 8, 8);

    Event *midlevelStrollSceneB = new Event("I'm all better after getting some food",
                                          "Eat food", "", "", true, true, 11, 11);

    toplevelStrollScene->leftOption = midlevelStrollSceneA;
    // connects the top level's second option with MidLevelB
    toplevelStrollScene->rightOption = midlevelStrollSceneB;

    // puts the event into the list of events.
    arrayevents[2] = toplevelStrollScene;

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
    arrayevents[3] = ToplevelDogScene;

Event *toplevelJakeScene =
    new Event("That lecture was mind-numbing, I need to take a break. A wrap would be the proper job right about now."
              "The line at Raps is mad, I hate this shite."
              "\nI keep getting weird looks for writing my journal entries in the line."
              "\n\"Hey, how are ya keepin?\"",

               "Sorry who are you?", "", ":/images/people/Jake.png", false, true, 11, 11);

Event *bottomLevelJake = new Event("\"Bro, it's me, Jake. You didn't forget me did you? I sat next to you in 3rd year physics remember?\" \nI faintly remembered something about a Jake in 3rd year.\n","Ahhhh right... Jake. I remember you for sure, yep.","", ":/images/people/Jake.png", false, true, 11, 11);
Event *endJake = new Event("\"Anyway it was nice to see you again Mark, talk to ya later.\"\n", "I'm so embarrassed I could die.", "", ":/images/people/Jake.png", true, true, 11, 11);
toplevelJakeScene->leftOption = bottomLevelJake;
// connects the top level's second option with MidLevelB
bottomLevelJake->leftOption = endJake;
// puts the event into the list of events.
arrayevents[4] = toplevelJakeScene;


Event *toplevelStudyScene =
      new Event("Its only week one but it appears the workload is alread piling up.", "I need to find a studybuddy",
                "I'm a lone ranger and I'll get it all done by myself", "", false, false, -1, -1);

  // top level's left option
  Event *midlevelStudySceneA = new Event("Perhaps I could find a study buddy at the library",
      "Maybe, lets find out!", "", "", true, true, 3, 3);

  Event *midlevelStudySceneB =
      new Event("My drom room may be a good place to study without being interrupted by others", "I'm going to head back to it", "", "",
                true, true, 1, 1);

  toplevelStudyScene->leftOption = midlevelStudySceneA;
  // connects the top level's second option with MidLevelB
  toplevelStudyScene->rightOption = midlevelStudySceneB;

  // puts the event into the list of events.
  arrayevents[5] = toplevelStudyScene;

  Event *toplevelShakespeareScene =
        new Event("To be or not to be", "That is the question",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelShakespeareSceneA = new Event(" Whether ’tis Nobler in the mind to suffer The Slings and Arrows of outrageous Fortune",
        "Or to take Arms against a Sea of troubles", "", "", true, true, -1, -1);



    toplevelShakespeareScene->leftOption = midlevelShakespeareSceneA;
    // connects the top level's second option with MidLevelB


    // puts the event into the list of events.
    arrayevents[6] = toplevelShakespeareScene;

    Event *toplevelHungryScene =
          new Event("I feel my stomach grumbling", "Grumble...",
                    "", "", false, true, -1, -1);

      // top level's left option
      Event *midlevelHungrySceneA = new Event("My stomach continues to grumble",
          "Grumble grumble", "", "", true, true, -1, -1);

      toplevelHungryScene->leftOption = midlevelHungrySceneA;
      // connects the top level's second option with MidLevelB

      // puts the event into the list of events.
      arrayevents[7] = toplevelHungryScene;


      Event *toplevelFreedomScene =
            new Event("I feel as though I do not have free will", "Of course I do! What am I thinking!",
                      "", "", false, true, -1, -1);

        // top level's left option
        Event *midlevelFreedomSceneA = new Event("But I must believe in free will",
            "I have no choice but to believe", "", "", true, true, -1, -1);

        toplevelFreedomScene->leftOption = midlevelFreedomSceneA;
        // connects the top level's second option with MidLevelB

        // puts the event into the list of events.
        arrayevents[8] = toplevelFreedomScene;

        Event *toplevelGymScene =
              new Event("Perhaps I should start going to the gym", "Yeah I should",
                        "No that aint for me dawg", "", false, false, -1, -1);

          // top level's left option
          Event *midlevelGymSceneA = new Event("I will probably have to give up wraps",
              "Now that's not really an option is it", "", "", true, true, -1, -1);

         Event *midlevelGymSceneB = new Event("I shall go and eat a wrap",
              "Damn right dawg", "", "", true, true, -1, -1);
          toplevelGymScene->leftOption = midlevelGymSceneA;
        toplevelGymScene->rightOption = midlevelGymSceneB;
          // connects the top level's second option with MidLevelB

          // puts the event into the list of events.
          arrayevents[9] = toplevelGymScene;
}




Event *EventList::createDayOneEvent()
{
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

Event *EventList::createFinalEvent()
{
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

Event *EventList::getRandomEvent()
{
    int randomNumber = getRand(ARRAY_SIZE);
    return arrayevents[randomNumber];
}
