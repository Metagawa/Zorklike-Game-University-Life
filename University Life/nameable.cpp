#include "nameable.h"
#include <string>
using namespace std;
string Nameable::getName() { return name; }

void Nameable::setName(string name) { this->name = name; }
