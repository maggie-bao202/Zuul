//Room.cpp file, all the functions that the Room class has
#include "Room.h"
#include <iostream>
#include <vector>
#include <map>
#include <cstring>

Room :: Room(char* newName) {//contructor
  roomName = newName;
  itemList = new vector<Item*>;
}

char* Room :: getRoomName(){//get the name of the room
  return roomName;
}

int Room :: itemListSize(){//get the size of the vector holding items in room
  return itemList->size();
}

vector<Item*>* Room :: getItemList(){//get vector of items in room
  return itemList;
}

map<char*, Room*>* Room :: getNext(){//the adjacent rooms of the current room
  return nextRooms;
}

void Room :: nextTo(Room* nextRoom, char* direction){//for exits
  (*nextRooms)[direction] = nextRoom;
}

void Room :: addItem(Item* item) {//initialize items
  itemList->push_back(item);
}

void Room :: deleteItem(Item* item){//delete items
  vector<Item*>::iterator it; //create iterator
  for(it = itemList->begin(); it != itemList->end(); it++){
    if (strcmp((*it)->getItemName(), item->getItemName()) == 0){
      delete *it;
      itemList->erase(it);
      cout << endl;
      return;
      }
    }
}
