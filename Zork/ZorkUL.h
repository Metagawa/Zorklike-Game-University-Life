#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
	void createRooms();

	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();

public:
	ZorkUL();
    void printWelcome();
	void play();
	string go(string direction);
    bool processCommand(Command command);
};

#endif /*ZORKUL_H_*/
