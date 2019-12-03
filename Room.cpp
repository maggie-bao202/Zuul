#include "Room.h"
#include <iostream>
#include <vector>
#include <map>
#include <cstring>

Room :: Room(char* newName) {
  roomName = newName;
  itemList = new vector<Item*>;
}

char* Room :: getCurrent(){
  return roomName;
}

int Room :: inventorySize(){
  return itemList->size();
}

vector<Item*>* Room :: getItemList(){
  return itemList;
}

map<char*, Room*>* Room :: getNext(){
  return nextRooms;
}

void Room :: nextTo(Room* nextRoom, char* direction){
  (*nextRooms)[direction] = nextRoom;
}

void Room :: addItem(Item* item) {
  itemList->push_back(item);
  return;
}

void Room :: deleteItem(Item* item){
  vector<Item*>::iterator it; //create iterator
  for(it = itemList->begin(); it != itemList->end(); it++){
    if (strcmp((*it)->getItemName(), item->getItemName()) == 0){
      delete *it;
      itemList->erase(it);
      cout << endl;
      }
    }
}
//ROOM CPP FILE
