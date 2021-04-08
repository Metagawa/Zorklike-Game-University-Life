#include "character.h"
#include <string>
using namespace std;
Character::Character(string name) { this->name = name; }

string Character::getName() { return this->name; }
