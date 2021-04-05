#ifndef RAMBLE_H
#define RAMBLE_H
#include <string>

using namespace std;

class Ramble {
public:
  Ramble(string text);
  Ramble(Ramble &sample);
  string text;
};

#endif // RAMBLE_H
