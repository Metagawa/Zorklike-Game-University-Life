#ifndef UNILIFE_H_
#define UNILIFE_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include <iostream>
#include <string>
using namespace std;

class UniLife {
private:
  Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

public:
  UniLife();
  void printWelcome();
  void play();
  string go(string direction);
  bool processCommand(Command command);
  Parser parser;
  Room *currentRoom;
  void createRooms();
  void printHelp();
  void goRoom(Command command);
  void getLocation(int location);
};

#endif /*UNILIFE_H_*/
