#include "eventlist.h"
#include "event.h"
#include <vector>
EventList::EventList()
{

	/*TEMPLATE EVENT
	//top level of an event

  	Event *ToplevelScene =
	  new Event(" ",  //Text box content
				" ",  //First choice  (leads to MidlevelSceneA)
				" ",  //Second Choice (leads to MidlevelSceneB)
				" ",  //EventOver Notebook text
				" ",  //EventBegin Notebook text
				0,    //Location flag
                " ",  //Character sprite flag
				false //Is this the last scene?
				);

	//top level's left option leads to...
  	Event *MidlevelSceneA =
	  new Event(" ",  //Text box content
				" ",  //First choice  (leads to BottomlevelSceneA)
				" ",  //Second choice (leads to BottomlevelSceneB)
				false //Is this the last scene?
				);

	//top level's right option leads to...
  	Event *MidlevelSceneB =
				new Event(" ",  //Text box content
				" ",  //First choice  (leads to BottomlevelSceneC)
				" ",  //Second choice (leads to BottomlevelSceneD)
				false //Is this the last scene?
				);


	//Mid level a's left option leads to...
 	Event *BottomlevelSceneA =
	  new Event(" ",  //Text box content
				" ",  //First choice  (leads to nothing)
				" ",  //Second choice (leads to nothing)
				false //Is this the last scene?
				);


	//Mid level a's right option leads to...
  	Event *BottomlevelSceneB = new Event(
	  new Event(" ",  //Text box content
				" ",  //First choice  (leads to nothing)
				" ",  //Second choice (leads to nothing)
				false //Is this the last scene?
				);


	//Mid level b's left option leads to...
    Event *BottomlevelSceneC =
	  new Event(" ",  //Text box content
				" ",  //First choice  (leads to nothing)
				" ",  //Second choice (leads to nothing)
				false //Is this the last scene?
				);

	//Mid level b's right option leads to...
    Event *BottomlevelSceneD =
	  new Event(" ",  //Text box content
				" ",  //First choice  (leads to nothing)
				" ",  //Second choice (leads to nothing)
				false //Is this the last scene?
				);

//Toplevel connections to midlevel

  	//connects the top level's first option with MidLevelA
    ToplevelScene->leftOption = MidlevelSceneA;
  	//connects the top level's second option with MidLevelB
    ToplevelScene->rightOption = MidlevelSceneB;
-----------------------------------------------------------

  //Midlevel connections to bottomlevel

	//connects MidLevelA's first option with BottomLevelA
    MidlevelSceneA->leftOption = BottomlevelSceneA;
	//connects MidLevelA's second option with BottomLevelB
    MidlevelSceneA->rightOption = BottomlevelSceneB;
	//connects MidLevelB's first option with BottomLevelC
    MidlevelSceneB->leftOption = BottomlevelSceneC;
	//connects MidLevelB's second option with BottomLevelD
    MidlevelSceneB->rightOption = BottomlevelSceneD;
-----------------------------------------------------------

  //puts the event into the list of events.
  	events.push_back(*ToplevelScene);


			END OF TEMPLATE EVENT*/

	//Actual Events below
	/*------------------------------------------------------------------------------------------------------------*/

	//top level of an event
	Event *ToplevelDogScene =
		new Event("You see a small dog lying in the road",
				  "Ignore it, it's not your problem.",
				  "Run over and see if it's ok", "I helped the doggy out.",
				  "Is there something in the road?", 0, "", false);

	//top level's left option
	Event *MidlevelDogSceneA =
		new Event("You ignore the dog, like a heartless monster. You hear him whine softly.",
				  "Keep walking.", "He needs help, go help him!", false);

	//top level's right option
	Event *MidlevelDogSceneB = new Event(
		"You ran over and grabbed the dog, he's ok he's just hungry.",
		"Take him to raps for some food?",
		"Give him your lunch so you have an excuse to go to raps?", false);

	//Mid level a's left option
	Event *BottomlevelDogSceneA =
		new Event("You've walked out of earshot of the poor whimpering dog.",
				  "Go to raps?", "Go to class?", true);

	//Mid level a's right option
	Event *BottomlevelDogSceneB = new Event(
		"Showing that you actually do have a human heart, you race to the dog's "
		"aid. You see that he's emaciated and needs food badly.",
		"Take him to raps?", "Give him your lunch?", true);

	//Mid level b's left option
	Event *BottomlevelDogSceneC =
		new Event("You bought some chicken and water for the dog to eat, "
				  "grabbing a wrap for yourself as you're at it. The dog barks "
				  "cheerfully at you and runs off after having his fill.",
				  "Go to class?", "Go home?", true);

	//Mid level b's right option
	Event *BottomlevelDogSceneD =
		new Event("You give the dog your lunch. Your stomach mourns the loss of "
				  "its anticipated breakfast roll, but you console yourself with "
				  "the promise of a wrap later. The dog seems really happy to "
				  "have a good meal and runs off after he's finished it.",
				  "Go home?", "Go to class?", true);

	//Toplevel to midlevel
	//connects the top level's first option with MidLevelA
	ToplevelDogScene->leftOption = MidlevelDogSceneA;
	//connects the top level's second option with MidLevelB
	ToplevelDogScene->rightOption = MidlevelDogSceneB;
	/*---------------------------------------------------------*/

	//Midlevel to bottomlevel
	//connects MidLevelA's first option with BottomLevelA
	MidlevelDogSceneA->leftOption = BottomlevelDogSceneA;
	//connects MidLevelA's second option with BottomLevelB
	MidlevelDogSceneA->rightOption = BottomlevelDogSceneB;
	//connects MidLevelB's first option with BottomLevelC
	MidlevelDogSceneB->leftOption = BottomlevelDogSceneC;
	//connects MidLevelB's second option with BottomLevelD
	MidlevelDogSceneB->rightOption = BottomlevelDogSceneD;
	/*---------------------------------------------------------*/

	//puts the event into the list of events.
	events.push_back(*ToplevelDogScene);

    /*-----------------------------------------------------------------------------------*/


}

Event *EventList::getRandomEvent()
{
	int randomNumber = (rand() % events.size());
	return &events[randomNumber];
}
