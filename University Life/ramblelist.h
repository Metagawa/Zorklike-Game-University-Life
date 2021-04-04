#ifndef RAMBLELIST_H
#define RAMBLELIST_H
#include "ramble.h"
#include <vector>

using std::vector;
class RambleList
{
public:
  RambleList();
  vector<Ramble> rambles;
  Ramble *getRandomRambles();

private:
};
#endif // RAMBLELIST_H
