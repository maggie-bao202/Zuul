//header of room class, function prototypes and varible declaration
#include "Item.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Room {
public://all functions are public
  Room(char* newName);
  char* getRoomName();
  int itemListSize();
  vector<Item*>* getItemList();
  map<char*, Room*>* getNext();
  void nextTo(Room* newRoom, char* direction);
  void addItem(Item* item);
  void deleteItem(Item* item);
  virtual ~Room();
private://variables are kept private
  char* roomName;
  vector<Item*>* itemList;
  map<char*, Room*>* nextRooms;
};
