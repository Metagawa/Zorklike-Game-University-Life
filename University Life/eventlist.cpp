#include "eventlist.h"
#include "event.h"
#include <algorithm>
#include <stdio.h>
//preprocessor definitions
#define ARRAY_SIZE 20
//sets an array size
int arrayevents[ARRAY_SIZE];

//list of events in an array
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
        -1);   //Right Location (bottom choice)*/

    Event *toplevelSarahScene =
        new Event("\"Hi are you new? You look really lost haha.\"\nA helpful looking girl approaches me as I finish my map sketch.",

                  "What gave it away, the overstuffed bag or the map I sketched?", "", ":/images/people/Sarah.png", false, true, -1, -1);

    Event *midLevelSarah = new Event("\"A little of both, Hi I'm Sarah, I'm a second year arts student, what course are you in?\"\n\"Nice to meet you Sarah, I'm in Computer Science, I'm an expert coder already though. Made 3 websites over the summer.", "Want to see my l33tcode scores?", "", ":/images/people/Sarah.png", false, true, -1, -1);
    Event *bottomLevelSarah = new Event("\"No thanks I'm ok... I have to get going now bye...\"\nShe quickly hurries off, probably late for class or something.", "I should show her my scores next time I see her.", "", ":/images/people/Sarah.png", true, true, -1, -1);
    toplevelSarahScene->leftOption = midLevelSarah;
    // connects the top level's second option with MidLevelB
    midLevelSarah->leftOption = bottomLevelSarah;
    // puts the event into the list of events.
    arrayevents[0] = toplevelSarahScene;

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
        new Event("I'm exhausteed after those classes, I need to take a break. A wrap would be the proper job right about now."
                  "The line at Raps is mad, I hate this shite."
                  "\nI keep getting weird looks for writing my journal entries in the line."
                  "\n\"Hey, how are ya keepin?\"",

                  "Sorry who are you?", "", ":/images/people/Jake.png", false, true, 11, 11);

    Event *bottomLevelJake = new Event("\"Bro, it's me, Jake. You didn't forget me did you? I sat next to you in 3rd year physics remember?\" \nI faintly remembered something about a Jake in 3rd year.\n", "Ahhhh right... Jake. I remember you for sure, yep.", "", ":/images/people/Jake.png", false, true, 11, 11);
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
        new Event("My dorm room may be a good place to study without being interrupted by others", "I'm going to head back to it", "", "",
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

    Event *toplevelDancingScene =
        new Event("On the floors of Tokyo\nOr down in London town to go, go\nWith a record selection and a mirror direction", "I'm dancing with myself",
                  "", "", true, true, -1, -1);

    arrayevents[10] = toplevelDancingScene;

    Event *toplevelCourseScene =
        new Event("I sometimes wonder if I have chosen the right college course", "I guess I should figure this out pretty soon",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelCourseSceneA = new Event("Maybe it will become clearer to me after I have attended some lectures",
                                            "Maybe...", "", "", true, true, -1, -1);

    toplevelCourseScene->leftOption = midlevelCourseSceneA;

    // puts the event into the list of events.
    arrayevents[11] = toplevelCourseScene;

    Event *toplevelNotebookScene =
        new Event("My notebook is getting quite full ", "It really is",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelNotebookSceneA = new Event("I should buy another notebook",
                                              "I proabaly won't need one this week though", "", "", true, true, -1, -1);

    toplevelNotebookScene->leftOption = midlevelNotebookSceneA;

    // puts the event into the list of events.
    arrayevents[12] = toplevelNotebookScene;

    Event *toplevelUnluckyScene =
        new Event("I have the worst luck", "I'm one unfortunate cookie",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelUnluckySceneA = new Event("I just gobbled that fortune cookie whole",
                                             "I should have looked at the message inside", "", "", true, true, -1, -1);

    toplevelUnluckyScene->leftOption = midlevelUnluckySceneA;

    // puts the event into the list of events.
    arrayevents[13] = toplevelUnluckyScene;

    Event *toplevelTimeScene =
        new Event("Random thought: I will spend 4 years here", "It will probably fly",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelTimeSceneA = new Event("I'm not so sure what I will do after yet",
                                          "Time will tell", "", "", true, true, -1, -1);

    toplevelTimeScene->leftOption = midlevelTimeSceneA;

    // puts the event into the list of events.
    arrayevents[14] = toplevelTimeScene;

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
    arrayevents[15] = toplevelPoemScene;

    Event *toplevelLunchScene =
        new Event("I'm sick of eating lunch alone", "Maybe I can have luch with Jake or Sarah?",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelLunchSceneA = new Event("I will send both of them a text",
                                           "Text: hv lunch w/ me?", "", "", true, true, -1, -1);

    toplevelLunchScene->leftOption = midlevelLunchSceneA;

    // puts the event into the list of events.
    arrayevents[16] = toplevelLunchScene;

    Event *toplevelFAANGScene =
        new Event("1 week into college and I already have 4 FAANG interviews lined up", "FAANGTASTIC!",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelFAANGSceneA = new Event("I was born for the behavioural interview",
                                           "I have the worlds greatest personality", "", "", true, true, -1, -1);

    toplevelFAANGScene->leftOption = midlevelFAANGSceneA;

    // puts the event into the list of events.
    arrayevents[17] = toplevelFAANGScene;

    Event *toplevelGroupScene =
        new Event("Ugh I hate group work, why did the lecturer have to assign a group project this early!?", "I could do this by myself easy.",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelGroupSceneA = new Event("It's just a simple little fullstack javafx program using sql database management. Probably super easy to do, I just need to google what sql and javafx are first.",
                                           "I'll get it done before I get assigned a group!", "", "", true, true, -1, -1);

    toplevelGroupScene->leftOption = midlevelGroupSceneA;
    // puts the event into the list of events.
    arrayevents[18] = toplevelGroupScene;

    Event *toplevelEnergyScene =
        new Event("I just noticed I haven't actually gone to my dorm room since I arrived here, that Energy drink they sell at Raps is ridiculously good.", "I should get some more right now.",
                  "", "", false, true, 11, 11);

    // top level's left option
    Event *midlevelEnergySceneA = new Event("Ah they have my favourite in stock, \"Wonster Energy Espresso Shot\". Truly the nectar of the gods for a Computer Science student. A couple of these can keep you going for days.", "Drink a \"couple\".", "", "", true, true, 11, 11);

    toplevelEnergyScene->leftOption = midlevelEnergySceneA;
    // puts the event into the list of events.
    arrayevents[18] = toplevelEnergyScene;

    Event *toplevelStartupScene =
        new Event("If FAANG doesn't work out I will make a startup", "Maybe I will drop out of college to start it!",
                  "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelStartupSceneA = new Event("Idea: A distributed peer to peer blockchain optimized with AI on the clientside as a service",
                                             "If that doesn't work out I will pivot to a VR startup", "", "", true, true, -1, -1);

    toplevelStartupScene->leftOption = midlevelStartupSceneA;

    // puts the event into the list of events.
    arrayevents[19] = toplevelStartupScene;
}

//specific day one event
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

//specific final day event
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

//specific no events left event
Event *EventList::createNoEvent()
{
    Event *toplevelScene = new Event(
        "Wow, things have really gotten dull around here, feels like I've done all there is to do here already.",
        "I'm probably just tired.", "", "", false, true, -1, -1);

    // top level's left option
    Event *midlevelSceneA = new Event(
        "I should try and follow up on some of the people I met during this crazy week, like that Jake guy or Sarah. I still have to show her my l33tcode scores.",
        "We could make a study group or something to keep in touch.", "", "", false, true, -1, -1);

    // Mid level a's left option
    Event *bottomlevelSceneA =
        new Event("This first week was super hectic, but I pulled through really well, maybe it would've been different if I didn't manage to clear my schedule before sunday?\nMy University Life is going swimmingly.",
                  "Hopefully I can handle every week like this!", "", "", false, true, -1, -1);
    Event *finallevelSceneA =
        new Event("Exit Game", "", "", "", true, true, -1, -1);
    toplevelScene->leftOption = midlevelSceneA;
    // connects the top level's second option with MidLevelB
    midlevelSceneA->leftOption = bottomlevelSceneA;
    bottomlevelSceneA->leftOption = finallevelSceneA;

    // puts the event into the list of events.
    return toplevelScene;
}

//returns next event
Event *EventList::getNextEvent()
{
    return arrayevents[eventNumber];
}
