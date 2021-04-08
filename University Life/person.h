#ifndef PERSON_H
#define PERSON_H
#include <ageable.h>
#include <nameable.h>
#include <string>
using namespace std;

class Person : public Nameable, public Ageable {
public:
  string getName();

protected:
  string name;
};

#endif // PERSON_H
