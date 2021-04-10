#ifndef PERSON_H
#define PERSON_H
#include <ageable.h>
#include <nameable.h>
#include <string>
using namespace std;

class Person : public Nameable, public Ageable {
public:
  Person(string name);
  string getName();
  void greet();

protected:
  string gender;

private:
  string id;
};

#endif // PERSON_H
