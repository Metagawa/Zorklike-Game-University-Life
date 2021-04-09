#include "ramblelist.h"
#include "ramble.h"
#include "ramblelist.h"
#include <stdio.h>
#define ARRAY_SIZE 20
int arrayrambles[ARRAY_SIZE];
#define getRand(a) ((rand() % a))

RambleList::RambleList() {
  Ramble *ramble1 = new Ramble("Not to self: Buy some noodles.");
  arrayrambles[0] = ramble1;
  Ramble *ramble2 = new Ramble("I saw a weird lookin bird.");
  arrayrambles[1] = ramble2;
  Ramble *ramble3 = new Ramble("I could use a pint...");
  arrayrambles[2] = ramble3;
  Ramble *ramble4 =
      new Ramble("The campus pub, the only place where you can order a pint "
                 "with your roast beef dinner at 11am, priceless.");
  arrayrambles[3] = ramble4;
  Ramble *ramble5 = new Ramble("I keep having nightmares that I'm looking for "
                               "a room in the main building but I somehow keep "
                               "ending up at Raps no matter which way I turn.");
  arrayrambles[4] = ramble5;
  Ramble *ramble6 = new Ramble(
      "Raps is mad, you get in line with a coffee and a wrap then by the time "
      "you get to the till you have a bag of Gummis, a protein bar, a pack of "
      "mints and a bottle of chocolate milk.");
  arrayrambles[5] = ramble6;
  Ramble *ramble7 = new Ramble("I could do with a student loan.");
  arrayrambles[6] = ramble7;
  Ramble *ramble8 = new Ramble("When is my SUSI coming in?.");
  arrayrambles[7] = ramble8;
  Ramble *ramble9 = new Ramble("My housemates are the worst!");
  arrayrambles[8] = ramble9;
  Ramble *ramble10 = new Ramble("I need to start my assignment...");
  arrayrambles[9] = ramble10;
  Ramble *ramble11 = new Ramble("I should try to meet some people this week");
  arrayrambles[10] = ramble11;
  Ramble *ramble12 = new Ramble("I'd love a cup of java");
  arrayrambles[11] = ramble12;
  Ramble *ramble13 = new Ramble("The €5 deal at Raps is dangerous...");
  arrayrambles[12] = ramble13;
  Ramble *ramble14 = new Ramble("I saw a weird lookin bird.");
  arrayrambles[13] = ramble14;
  Ramble *ramble15 = new Ramble("I could use a pint...");
  arrayrambles[14] = ramble15;
  Ramble *ramble16 = new Ramble("Not to self: Buy some noodles.");
  arrayrambles[15] = ramble16;
  Ramble *ramble17 = new Ramble("I saw a weird lookin bird.");
  arrayrambles[16] = ramble17;
  Ramble *ramble18 = new Ramble("I could use a pint...");
  arrayrambles[17] = ramble18;
  // shallow copy
  Ramble *ramble19 = ramble11;
  arrayrambles[18] = ramble19;
  // deep copy
  Ramble *ramble20 = new Ramble(*ramble18);
  arrayrambles[19] = ramble20;
}

Ramble *RambleList::getRandomRambles() {
  int randomNumber = getRand(ARRAY_SIZE);
  return arrayrambles[randomNumber];
}
RambleList::~RambleList() {}
