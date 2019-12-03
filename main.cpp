#include  <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"
#include "Item.h"

using namespace std;

void printRoom(vector<Item*>* inventory, Room* current);
void printInventory(vector<Item*>* inventory);
void dropItem(vector<Item*>* inventory, Room* current);
void getItem(vector<Item*>* inventory, Room* current);

int main(){
  cout << "MAKE A SANDWICH" << endl;
  cout << "The most exciting game ever developed." << endl;

  vector<Room*>* roomList = new vector<Room*>();
  vector<Item*>* inventory = new vector<Item*>();
  Item* phone = new Item ("Phone");
  Item* keys = new Item ("Keys");
  Item* CDs = new Item ("Heavy Metal CDs");
  Item* wBread = new Item ("White Bread");
  Item* sdBread = new Item ("Sourdough Bread");
  Item* wwBread = new Item ("Whole Wheat Bread");
  Item* mCheese = new Item ("Mozarella Cheese");
  Item* cCheese = new Item ("Cheddar Cheese");
  Item* pCheese = new Item ("Parmesean Cheese");
  Item* ssHam = new Item ("Sliced Smoked Ham");
  Item* ssBeef = new Item ("Sliced Smoked Beef");
  Item* lettuce = new Item ("Lettuce");
  Item* spinach = new Item ("Spinach");

  Room* bedRoom = new Room ("Bedroom");
  Room* bathRoom = new Room ("Bathroom");
  Room* livingRoom = new Room ("Livingroom");
  livingRoom->addItem(phone);
  livingRoom->addItem(keys);
  Room* kitchen = new Room ("Kitchen");
  Room* hallway = new Room ("Hallway");
  Room* garage = new Room ("Garage");
  Room* car = new Room ("Lambourgini");
  Room* drive = new Room ("Driving");
  drive->addItem(CDs);
  Room* parkLot = new Room ("Parking Lot");
  Room* entrance = new Room ("Entrance of Fred Meyer's");
  Room* mainAsle = new Room ("Main Asle");
  Room* grains = new Room ("GRAINS");
  grains->addItem(wBread);
  grains->addItem(sdBread);
  grains->addItem(wwBread);
  Room* dairy = new Room ("DAIRY");
  dairy->addItem(mCheese);
  dairy->addItem(cCheese);
  dairy->addItem(pCheese);
  Room* poultry = new Room ("POULTRY");
  poultry->addItem(ssHam);
  poultry->addItem(ssBeef);
  Room* produce = new Room ("PRODUCE");
  produce->addItem(lettuce);
  produce->addItem(spinach);

  bedRoom->nextTo(hallway, "Hallway");
  bathRoom->nextTo(hallway, "Hallway");
  kitchen->nextTo(hallway, "Hallway");
  livingRoom->nextTo(hallway, "Hallway");

  hallway->nextTo(bedRoom, "Bedroom");
  hallway->nextTo(bathRoom, "Bathroom");
  hallway->nextTo(kitchen, "Kitchen");
  hallway->nextTo(livingRoom, "Living Room");
  hallway->nextTo(garage, "Garage");

  garage->nextTo(car, "Car");
  car->nextTo(drive, "DRIVE");
  drive->nextTo(parkLot, "Parking Lot");
  parkLot->nextTo(entrance, "Fred Meyer's");
  entrance->nextTo(mainAsle, "Main Asle");

  mainAsle->nextTo(grains, "GRAINS");
  mainAsle->nextTo(dairy, "DAIRY");
  mainAsle->nextTo(poultry, "POULTRY");
  mainAsle->nextTo(produce, "PRODUCE");
  mainAsle->nextTo(kitchen, "Kitchen"),//testing winning condition


  grains->nextTo(mainAsle, "Main Asle");
  grains->nextTo(dairy, "DAIRY");

  dairy->nextTo(mainAsle, "Main Asle");
  dairy->nextTo(poultry, "POULTRY");
  dairy->nextTo(grains, "GRAINS");

  poultry->nextTo(mainAsle, "Main Asle");
  poultry->nextTo(produce, "PRODUCE");
  poultry->nextTo(dairy, "DAIRY");

  produce->nextTo(mainAsle, "Main Asle");
  produce->nextTo(poultry, "POULTRY");

  Room* current = bedRoom;
  char keyword[40];
  char input[40];
  while (true){
    if (current == kitchen){//winning condition
      return 0;
    }

    printRoom(inventory, current);

    cin.get(keyword, 40);
    cin.clear();
    cin.ignore(999, '\n');
    if (strcmp(keyword, "GO") == 0){//if the input is GO
      cout << "Go to: " << endl;
      cin >> input;
      cin.ignore();
      map<char*, Room*> :: iterator it = current->getNext().begin();
      for (it = roomList->begin(); it != roomList->end(); it++) {
  
      }
     }
    }
    else if (strcmp(keyword, "INVENTORY") == 0){//Similar to above
      cout << endl;
      printInventory(inventory);
      cout << endl;
    }
    else if (strcmp(keyword, "GET") == 0){
      cout << endl;
      getItem(inventory, current);
      cout << endl;
    }
    else if (strcmp(keyword, "DROP") == 0){
      cout << endl;
      dropItem(inventory, current);
      cout << endl;
    }
    else if (strcmp(keyword, "QUIT") == 0){
      cout << "GAME OVER." << endl;
      return 0;
    }
    else{
      cout << "Enter a valid keyword (GO, INVENTORY, GET, DROP, QUIT)." << endl;
    }
  }
}

void printRoom(vector<Item*>* inventory, Room* current){
 vector<Item*> :: iterator it;
 cout << "- - -" << endl;
 cout <<current->getCurrent()<< endl;
 cout << endl;
 cout << "ITEMS:" << endl;
 if(current->inventorySize() == 0){
    cout << "No Items." << endl;
  }
  else{
    vector<Item*>* itemList = current -> getItemList();
    for(it = itemList->begin(); it != itemList->end(); it++){
      cout << "<" << (*it)->getItemName() << ">" << endl;
    }
    cout << endl;
  }
 cout << endl;
 cout << "EXITS:" << endl;
 map<char*, Room*>* nextRooms = current->getNext();
 map<char*, Room*> :: iterator itr = nextRooms->begin();
 for (itr = nextRooms->begin(); itr != nextRooms->end(); itr++) {
   cout << "<" << itr->first << ">" << endl;
 }
 cout << "- - - " << endl;
}


void printInventory(vector<Item*>* inventory){
  vector<Item*>::iterator it;
  cout << "INVENTORY:" << endl;
  if (inventory->size() == 0){
    cout << "EMPTY" << endl;
  }
  else{
    for (it = inventory -> begin(); it != inventory -> end(); ++it) {
      cout << "<" << (*it)->getItemName() << ">" << endl;
    }
  }
}

void dropItem(vector<Item*>* inventory, Room* current){
  Item* item;
  vector<Item*>* roomItems = current -> getItemList();
  vector<Item*> :: iterator it;
  char* dropItem = new char();
  
  if(inventory->size() == 0){
    cout << "Inventory is empty." << endl;
  }
  
  else{
    cout << "Enter Item Name to be Dropped: " << endl;
    cin.getline(dropItem, 40, '\n');
    for(it = inventory->begin(); it != inventory->end(); it++){
      if (strcmp((*it)->getItemName(), dropItem) == 0){
	cout << endl;
	current->addItem(*it);
	inventory->erase(it);
	break;
      }
      else {
	cout << "Invalid Item." << endl;
      }
    }
  }
}

void getItem(vector<Item*>* inventory, Room* current){
  vector<Item*> :: iterator it;
  char* getItem = new char();
  
  if(inventory->size() == 0){
    cout << "No Items in Room." << endl;
  }
  else{
    cout << "Enter Item Name to be Picked: " << endl;;
    cin.get(getItem, 40);
    cin.clear();
    cin.ignore(999, '\n');
    for(it = inventory->begin(); it != inventory->end(); it++){
      if (strcmp((*it)->getItemName(), getItem) == 0){
        cout << endl;
        inventory->push_back(*it);
        current->getItemList()->erase(it);
	break;
      }
      else {
        cout << "Invalid Item." << endl;
      }
    }
  }
}

