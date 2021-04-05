#ifndef RAMBLELIST_H
#define RAMBLELIST_H
#include "ramble.h"
#include <iostream>

class RambleList {
public:
  RambleList();
  Ramble *getRandomRambles();
  ~RambleList();
  Ramble *arrayrambles[20];

private:
};
#endif // RAMBLELIST_H
