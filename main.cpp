#include  <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"
#include "Item.h"

using namespace std;

/*12/2/19 Maggie Bao Description: In MAKE A SANDWICH, the user starts off in their bedroom and have to go to the store to find all the ingredients to make the perfect sandwich. They must then take everything back into the kitchen to assemble the sandwich.*/

void printRoom(vector<Item*>* inventory, Room* current);
void printInventory(vector<Item*>* inventory);
void dropItem(vector<Item*>* inventory, Room* current);
void getItem(vector<Item*>* inventory, Room* current);

int main(){
  cout << "MAKE A SANDWICH" << endl; //title
  cout << "The most exciting game ever developed." << endl; //description

  vector<Room*>* roomList = new vector<Room*>();
  vector<Item*>* inventory = new vector<Item*>();//vector pointer of items inside inventory

  //create Items
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

  //create Rooms
  Room* bedRoom = new Room ("You are in your bedroom, thinking about eating a delicious sandwich.");
  Room* bathRoom = new Room ("You are in the bathroom. You are thinking about blowing up that toilet once you eat that scrumptious sandwich.");
  Room* livingRoom = new Room ("You are in your living room.");
  livingRoom->addItem(phone);//add Items to Rooms
  livingRoom->addItem(keys);
  Room* kitchen = new Room ("in your kitchen. The sun is shining through the windows. It's a beautiful day for a sandwich.");
  Room* hallway = new Room ("You are in the hallway. It's kinda spooky, not gonna lie.");
  Room* garage = new Room ("You are in your garage. There is a Lamborghini Veneno there because you are one rich boi. But you are lonely so you don't have a bultler to make your own sandwich.");
  Room* car = new Room ("in your Lamborghini Veneno. You use your money to hide behind your frequent thoughts of sadness. Hopefully that sandwich will cheer you up. :)");
  Room* drive = new Room ("You are driving in your car. The radio plays of late 80s metal rock.");
  drive->addItem(CDs);
  Room* parkLot = new Room ("You are standing in in the parking lot. You see the towering letters of Fred Meyer's in the distance."):
  Room* entrance = new Room ("You are at the entrance of Fred Meyer's");
  Room* mainAsle = new Room ("You are standing in the main asle of Fred Meyer's.");
  Room* grains = new Room ("standing in the grain section of Fred Meyer's. So many breads to choose from.");
  grains->addItem(wBread);
  grains->addItem(sdBread);
  grains->addItem(wwBread);
  Room* dairy = new Room ("You are standing in the dairy section of Fred Meyer's. You need cheese.");
  dairy->addItem(mCheese);
  dairy->addItem(cCheese);
  dairy->addItem(pCheese);
  Room* poultry = new Room ("You are standing in the poultry section of Fred Meyer's. Any kind of sandwich meat is fine.");
  poultry->addItem(ssHam);
  poultry->addItem(ssBeef);
  Room* produce = new Room ("You are standing in the produce section of Fred Meyer's. You need either Lettuce or Spinach.");
  produce->addItem(lettuce);
  produce->addItem(spinach);

  //adjacent rooms, for exits
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

  Room* current = bedRoom; //start in bedroom
  char keyword[40];
  char input[40];
  while (true){
    if (current == kitchen){//winning condition
      return 0;
    }

    printRoom(inventory, current); //print a description of the room

    cin.get(keyword, 40);
    cin.clear();
    cin.ignore(999, '\n');
    if (strcmp(keyword, "GO") == 0){//if the keyword is GO
      bool found = false;
      cout << "Go to: " << endl;
      cin.get(input, 40);
      cin.clear();
      cin.ignore(999, '\n');
      map<char*, Room*> :: iterator it;
      for (it = current->getNext()->begin(); it != current->getNext()->end(); it++) {
	if(strcmp(it->first, input) == 0){
	  current = it->second;
	  found = true;
	  break;
	}
      }
      if (found == false){
	cout << "Enter Valid Room Name." << endl;
      }
    }
    else if (strcmp(keyword, "INVENTORY") == 0){//Similar to above
      cout << endl;
      printInventory(inventory);//printInventory method
      cout << endl;
    }
    else if (strcmp(keyword, "GET") == 0){
      cout << endl;
      getItem(inventory, current);//getItem method
      cout << endl;
    }
    else if (strcmp(keyword, "DROP") == 0){
      cout << endl;
      dropItem(inventory, current);//droptItem method
      cout << endl;
    }
    else if (strcmp(keyword, "QUIT") == 0){//QUIT, must delete memory too
      cout << "GAME OVER." << endl;
      return 0;
    }
    else{
      cout << "Enter a valid keyword (GO, INVENTORY, GET, DROP, QUIT)." << endl;
    }
  }
}

void printRoom(vector<Item*>* inventory, Room* current){//prints the description, items, and exits of a room
 vector<Item*> :: iterator it;
 cout << "- - -" << endl;
 cout <<current->getRoomName()<< endl;//get description
 cout << endl;
 cout << "ITEMS:" << endl;
 if(current->itemListSize() == 0){//if no items
    cout << "No Items." << endl;
  }
  else{
    vector<Item*>* itemList = current -> getItemList();//print items
    for(it = itemList->begin(); it != itemList->end(); it++){
      cout << "<" << (*it)->getItemName() << ">" << endl;
    }
    cout << endl;
  }
 cout << endl;
 cout << "EXITS:" << endl;
 map<char*, Room*>* nextRooms = current->getNext();//show exits
 map<char*, Room*> :: iterator itr = nextRooms->begin();
 for (itr = nextRooms->begin(); itr != nextRooms->end(); itr++) {//print adjacent rooms
   cout << "<" << itr->first << ">" << endl;
 }
 cout << "- - - " << endl;
}


void printInventory(vector<Item*>* inventory){//print out whatever is in vector pointer inventory
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

void dropItem(vector<Item*>* inventory, Room* current){//drop item into a room from inventory
  Item* item;
  vector<Item*>* roomItems = current -> getItemList();
  vector<Item*> :: iterator it;
  char* dropItem = new char();
  cout << inventory->size()<<endl;
  if(inventory->size() == 0){
    cout << "Inventory is empty." << endl;
  }
  
  else{
    cout << "Enter Item Name to be Dropped: " << endl;
    cin.getline(dropItem, 40, '\n');
    for(it = inventory->begin(); it != inventory->end(); it++){
      if (strcmp((*it)->getItemName(), dropItem) == 0){//if matches, add to room and remove inventory
	cout << endl;
	current->addItem(*it);
	inventory->erase(it);
	cout << "hi" << endl;
	return;
      }
      else {
	cout << "Invalid Item." << endl;
      }
    }
  }
}

void getItem(vector<Item*>* inventory, Room* current){//pick up item from room
  vector<Item*> :: iterator it;
  char* getItem = new char();
  //cout <<current->itemListSize()<<endl;
  if(current->itemListSize() == 0){
    cout << "No Items in Room." << endl;
  }
  else{
    cout << "Enter Item Name to be Picked: " << endl;
    cin.get(getItem, 40);//take input getItem
    cin.clear();
    cin.ignore(999, '\n');
    for(it = current->getItemList()->begin(); it != current->getItemList()->end(); it++){//search through itemList
      if (strcmp((*it)->getItemName(), getItem) == 0){//if there is a match, add to inventory delete from room
        inventory->push_back(*it);
	cout << "hello" << endl;
        current->deleteItem(*it);
	return;
      }
      else {
        cout << "Invalid Item." << endl;
      }
    }
  }
}

