#include "person.h"
#include <iostream>
#include <string>
using namespace std;
// this constructor calls the method setName from the nameable abstract class
Person::Person(string name) { setName(name); }
// implements the getName() virtual function from the nameable abstract class
string Person::getName() { return this->name; }

// prints a greeting with the characters name to the console
void Person::greet() { cout << "Hello my name is " << name << endl; }
