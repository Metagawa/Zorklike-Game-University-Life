#include <iostream>

using namespace std;
#include "uniLife.h"

UniLife::UniLife() { createRooms(); }

void UniLife::createRooms() {
  Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

  // Room(string description, string dayClear, string dayRain, string
  // nightClear, string nightRain, int lassoX, int lassoY);
  a = new Room("Bus Stop", ":/images/bg/day/sunny/bus-stop.png",
               ":/images/bg/day/rainy/bus-stop.png",
               ":/images/bg/night/sunny/bus-stop.png",
               ":/images/bg/night/rainy/bus-stop.png", 160, 285);
  b = new Room("Dorms", ":/images/bg/day/sunny/dorms.png",
               ":/images/bg/day/rainy/dorms.png",
               ":/images/bg/night/sunny/dorms.png",
               ":/images/bg/night/rainy/dorms.png", 232, 302);
  c = new Room("Gym", ":/images/bg/day/sunny/gym.png",
               ":/images/bg/day/rainy/gym.png",
               ":/images/bg/night/sunny/gym.png",
               ":/images/bg/night/rainy/gym.png", 370, 295);
  d = new Room("Library", ":/images/bg/day/sunny/library.png",
               ":/images/bg/day/rainy/library.png",
               ":/images/bg/night/sunny/library.png",
               ":/images/bg/night/rainy/library.png", 90, 225);
  e = new Room("Student Union", ":/images/bg/day/sunny/student-union.png",
               ":/images/bg/day/rainy/student-union.png",
               ":/images/bg/night/sunny/student-union.png",
               ":/images/bg/night/rainy/student-union.png", 160, 233);
  f = new Room("Relax Area", ":/images/bg/day/sunny/relax-area.png",
               ":/images/bg/day/rainy/relax-area.png",
               ":/images/bg/night/sunny/relax-area.png",
               ":/images/bg/night/rainy/relax-area.png", 230, 230);
  g = new Room("Pub", ":/images/bg/day/sunny/pub.png",
               ":/images/bg/day/rainy/pub.png",
               ":/images/bg/night/sunny/pub.png",
               ":/images/bg/night/rainy/pub.png", 310, 230);
  h = new Room("Computer Science Building",
               ":/images/bg/day/sunny/computer-science-building.png",
               ":/images/bg/day/rainy/computer-science-building.png",
               ":/images/bg/night/sunny/computer-science-building.png",
               ":/images/bg/night/rainy/computer-science-building.png", 98,
               125);
  i = new Room("Quad", ":/images/bg/day/sunny/quad.png",
               ":/images/bg/day/rainy/quad.png",
               ":/images/bg/night/sunny/quad.png",
               ":/images/bg/night/rainy/quad.png", 170, 150);
  j = new Room("Main Building", ":/images/bg/day/sunny/main-building.png",
               ":/images/bg/day/rainy/main-building.png",
               ":/images/bg/night/sunny/main-building.png",
               ":/images/bg/night/rainy/main-building.png", 130, 69);
  k = new Room("Shopping Area", ":/images/bg/day/sunny/shopping-area.png",
               ":/images/bg/day/rainy/shopping-area.png",
               ":/images/bg/night/sunny/shopping-area.png",
               ":/images/bg/night/rainy/shopping-area.png", 235, 130);
  l = new Room("Raps Shop", ":/images/bg/day/sunny/raps-shop.png",
               ":/images/bg/day/rainy/raps-shop.png",
               ":/images/bg/night/sunny/raps-shop.png",
               ":/images/bg/night/rainy/raps-shop.png", 235, 85);
  m = new Room("Campus Outlet", ":/images/bg/day/sunny/campus-outlet.png",
               ":/images/bg/day/rainy/campus-outlet.png",
               ":/images/bg/night/sunny/campus-outlet.png",
               ":/images/bg/night/rainy/campus-outlet.png", 235, 176);

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
