#include "Item.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Room {
 public:
  Room(char* newName);
  char* getCurrent();
  int inventorySize();
  vector<Item*>* getItemList();
  map<char*, Room*> getNext();
  void nextTo(Room* newRoom, char* direction);
  void addItem(Item* item);
  void deleteItem(Item* item);

 private:
  char* roomName;
  vector<Item*>* itemList;
  map<char*, Room*> nextRooms;
};