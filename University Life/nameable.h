#ifndef NAMEABLE_H
#define NAMEABLE_H
#include <string>
using namespace std;
class Nameable {
public:
  virtual string getName() { return name; };
  void setName(string name);

protected:
  string name;
};

#endif // NAMEABLE_H
