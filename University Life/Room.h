#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();



public:
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
};

#endif
