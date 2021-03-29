#include <iostream>

using namespace std;
#include "uniLife.h"


UniLife::UniLife() {
	createRooms();
}

void UniLife::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l,*m;

    a = new Room("Bus Stop");
    b = new Room("Dorms");
    c = new Room("Gym");
    d = new Room("Library");
    e = new Room("Student Union");
    f = new Room("Relax Area");
    g = new Room("Pub");
    h = new Room("Computer Science");
    i = new Room("The Quad");
    j = new Room("Main Building");
    k = new Room("Shopping Area");
    l = new Room("Raps");
    m = new Room("Campus Outlet");

//             (N, E, S, W)
    a->setExits(e, b, NULL, NULL);
    b->setExits(NULL, c, NULL, a);
    c->setExits(g, NULL, NULL, b);
    d->setExits(NULL, e, NULL, NULL);
    e->setExits(i, f, a, d);
    f->setExits(NULL, g, NULL, e);
    g->setExits(NULL, NULL, c, f);
    h->setExits(NULL, i, NULL, NULL);
    i->setExits(j, k, e, h);
    j->setExits(NULL, k, i, NULL);
    k->setExits(l,NULL,m,i);
    l->setExits(NULL,NULL,k,NULL);
    m->setExits(k,NULL,NULL,NULL);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void UniLife::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the UniLife game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void UniLife::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the UniLife game, true is returned, otherwise false is
 * returned.
 */
bool UniLife::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g] --- [j]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void UniLife::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void UniLife::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string UniLife::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
