#include "ramblelist.h"
#include "ramble.h"
#include <vector>
#include "ramblelist.h"
RambleList::RambleList()
{
    Ramble *ramble1 = new Ramble("Not to self: Buy some noodles.");
    rambles.push_back(*ramble1);

    Ramble *ramble2 = new Ramble("I saw a weird lookin bird.");
    rambles.push_back(*ramble2);

    Ramble *ramble3 = new Ramble("I could use a pint...");
    rambles.push_back(*ramble3);

    Ramble *ramble4 = new Ramble("The campus pub, the only place where you can order a pint with your roast beef dinner at 11am, priceless.");
    rambles.push_back(*ramble4);

    Ramble *ramble5 = new Ramble("I keep having nightmares that I'm looking for a room in the main building but I somehow keep ending up at Raps no matter which way I turn.");
    rambles.push_back(*ramble5);

    Ramble *ramble6 = new Ramble("Raps is mad, you get in line with a coffee and a wrap then by the time you get to the till you have a bag of Gummis, a protein bar, a pack of mints and a bottle of chocolate milk.");
    rambles.push_back(*ramble6);

}

Ramble *RambleList::getRandomRambles()
{
    int randomNumber = (rand() % rambles.size());
    return &rambles[randomNumber];
}
