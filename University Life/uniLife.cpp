#include <iostream>

using namespace std;
#include "uniLife.h"

UniLife::UniLife() { createRooms(); }

void UniLife::createRooms() {
  Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

  a = new Room("Bus Stop", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 160, 285);
  b = new Room("Dorms", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 232, 302);
  c = new Room("Gym", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 370, 295);
  d = new Room("Library", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 90, 225);
  e = new Room("Student Union", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 160, 233);
  f = new Room("Relax Area", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 230, 230);
  g = new Room("Pub", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 310, 230);
  h = new Room("Computer Science", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 98, 125);
  i = new Room("The Quad", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 170, 150);
  j = new Room("Main Building", ":/images/bg/day/sunny/business-room.png",
               ":/images/bg/day/sunny/business-room.png",
               ":/images/bg/day/sunny/business-room.png",
               ":/images/bg/day/sunny/business-room.png", 130, 69);
  k = new Room("Shopping Area", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 235, 130);
  l = new Room("Raps", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 235, 85);
  m = new Room("Campus Outlet", ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png",
               ":/images/bg/day/sunny/gym-room.png", 235, 176);

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
  k->setExits(l, NULL, m, i);
  l->setExits(NULL, NULL, k, NULL);
  m->setExits(k, NULL, NULL, NULL);

  currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void UniLife::play() {
  // Enter the main command loop.  Here we repeatedly read commands and
  // execute them until the UniLife game is over.

  bool finished = false;
  while (!finished) {
    // Create pointer to command and give it a command.
    Command *command = parser.getCommand();
    // Pass dereferenced command and check for end of game.
    finished = processCommand(*command);
    // Free the memory allocated by "parser.getCommand()"
    //   with ("return new Command(...)")
    delete command;
  }
  cout << endl;
  cout << "end" << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the UniLife game, true is returned, otherwise false is
 * returned.
 */
bool UniLife::processCommand(Command command) {
  if (command.isUnknown()) {
    cout << "invalid input" << endl;
    return false;
  }

  string commandWord = command.getCommandWord();

  if (commandWord.compare("go") == 0)
    goRoom(command);

  else if (commandWord.compare("quit") == 0) {
    return true; /**signal to quit*/
  }
  return false;
}

void UniLife::goRoom(Command command) {

  string direction = command.getSecondWord();

  // Try to leave current room.
  Room *nextRoom = currentRoom->nextRoom(direction);

  if (nextRoom == NULL)
    cout << "underdefined input" << endl;
  else {
    currentRoom = nextRoom;
  }
}

string UniLife::go(string direction) {
  // Make the direction lowercase
  // transform(direction.begin(), direction.end(), direction.begin(),::
  // tolower); Move to the next room
  Room *nextRoom = currentRoom->nextRoom(direction);
  if (nextRoom == NULL)
    return ("direction null");
  else {
    currentRoom = nextRoom;
    return currentRoom->longDescription();
  }
}
