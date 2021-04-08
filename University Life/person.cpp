#include "person.h"
#include <string>
using namespace std;

Person::Person(string name) { setName(name); }
string Person::getName() { return this->name; }
