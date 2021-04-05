#include "ramble.h"
#include <string>
using namespace std;
Ramble::Ramble(string text) { this->text = text; }
// deep copy constructor
Ramble::Ramble(Ramble &sample) { text = sample.text; }
