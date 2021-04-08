#include "person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person(string name) { setName(name); }
string Person::getName() { return this->name; }

void Person::greet() { cout << "Hello my name is " << name; }
