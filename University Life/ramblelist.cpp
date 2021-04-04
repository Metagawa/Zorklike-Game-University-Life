#include "ramblelist.h"
#include "ramble.h"
#include <vector>
#include "ramblelist.h"
RambleList::RambleList()
{
    Ramble *ramble1 = new Ramble ("Not to self: Buy some noodles.");
            rambles.push_back(*ramble1);

            Ramble *ramble2 = new Ramble ("I saw a weird lookin bird.");
                    rambles.push_back(*ramble2);

                    Ramble *ramble3 = new Ramble ("I could use a pint...");
                            rambles.push_back(*ramble3);
}

Ramble *RambleList::getRandomRambles()
{
    int randomNumber = (rand() % rambles.size());
    return &rambles[randomNumber];
}



