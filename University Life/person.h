#ifndef PERSON_H
#define PERSON_H
#include <nameable.h>
#include <string>
using namespace std;

class Person : public Nameable {
public:
  string getName();

protected:
  string name;
};

#endif // PERSON_H
