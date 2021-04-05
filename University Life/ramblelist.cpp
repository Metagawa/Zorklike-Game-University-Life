#include "ramblelist.h"
#include "ramble.h"
#include <stdio.h>
#include "ramblelist.h"
RambleList::RambleList()
{
    Ramble *ramble1 = new Ramble("Not to self: Buy some noodles.");
    Ramble *ramble2 = new Ramble("I saw a weird lookin bird.");
    Ramble *ramble3 = new Ramble("I could use a pint...");
    Ramble *ramble4 = new Ramble("The campus pub, the only place where you can order a pint with your roast beef dinner at 11am, priceless.");
    Ramble *ramble5 = new Ramble("I keep having nightmares that I'm looking for a room in the main building but I somehow keep ending up at Raps no matter which way I turn.");
    Ramble *ramble6 = new Ramble("Raps is mad, you get in line with a coffee and a wrap then by the time you get to the till you have a bag of Gummis, a protein bar, a pack of mints and a bottle of chocolate milk.");
    Ramble *ramble7 = new Ramble("Not to self: Buy some noodles.");
    Ramble *ramble8 = new Ramble("I saw a weird lookin bird.");
    Ramble *ramble9 = new Ramble("I could use a pint...");
    Ramble *ramble10 = new Ramble("Not to self: Buy some noodles.");
    Ramble *ramble11 = new Ramble("I saw a weird lookin bird.");
    Ramble *ramble12 = new Ramble("I could use a pint...");
    Ramble *ramble13 = new Ramble("Not to self: Buy some noodles.");
    Ramble *ramble14 = new Ramble("I saw a weird lookin bird.");
    Ramble *ramble15 = new Ramble("I could use a pint...");
    Ramble *ramble16 = new Ramble("Not to self: Buy some noodles.");
    Ramble *ramble17 = new Ramble("I saw a weird lookin bird.");
    Ramble *ramble18 = new Ramble("I could use a pint...");
    Ramble *ramble19 = new Ramble("Not to self: Buy some noodles.");
    Ramble *ramble20 = new Ramble("I saw a weird lookin bird.");

    Ramble array[] = {*ramble1, *ramble2, *ramble3,*ramble4, *ramble5, *ramble6,*ramble7, *ramble8, *ramble9,*ramble10, *ramble11, *ramble12, *ramble13, *ramble14, *ramble15, *ramble16, *ramble17, *ramble18, *ramble19, *ramble20};
    int i;
    Ramble *arrayrambles[20];
    for (i=0; i < 20; i++) {
        arrayrambles[i] = &array[i];
    }

}

Ramble *RambleList::getRandomRambles()
{
    int randomNumber = (rand() % 20);
    return &arrayrambles[randomNumber];
}

