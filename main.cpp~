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
bool find(char* item, vector<Item*>* inventory);


int main(){
  cout << "~ MAKE A SANDWICH ~" << endl; //title
  cout << "The most exciting game ever developed." << endl; //description
  cout << "- - -" << endl;
  cout << "TASK: Go to the supermarket, buy your choice of bread, cheese, meat, and lettuce, then come back to the kitchen to make the perfect sandwich." << endl;
  vector<Item*>* inventory = new vector<Item*>();//vector pointer of items inside inventory

  //create Items
  Item* phone = new Item ("Phone");
  Item* keys = new Item ("Keys");
  Item* CDs = new Item ("Heavy Metal CDs");
  Item* wBread = new Item ("White Bread");
  Item* sdBread = new Item ("Sourdough Bread");
  Item* wwBread = new Item ("Whole Wheat Bread");
  Item* mCheese = new Item ("Mozzarella Cheese");
  Item* cCheese = new Item ("Cheddar Cheese");
  Item* pCheese = new Item ("Parmesan Cheese");
  Item* ssHam = new Item ("Sliced Smoked Ham");
  Item* ssBeef = new Item ("Sliced Smoked Beef");
  Item* lettuce = new Item ("Lettuce");
  Item* spinach = new Item ("Spinach");

  //create Rooms
  Room* bedRoom = new Room ("You are in your bedroom, thinking about eating a delicious sandwich.");
  Room* bathRoom = new Room ("You are in the bathroom. You are thinking about blowing up that toilet once you eat that scrumptious sandwich.");
  Room* livingRoom = new Room ("You are in your living room. The silence is disrupted by the sound of your grumbling stomach.");
  livingRoom->addItem(phone);//add Items to Rooms
  livingRoom->addItem(keys);
  Room* kitchen = new Room ("You are in your kitchen. The sun is shining through the windows. It's a beautiful day for a sandwich; however, you still need some more ingredients to complete the sandwich. You\
 do not want to eat a disappointment.");
  Room* hallway = new Room ("You are in the hallway. It's kinda spooky, not gonna lie.");
  Room* garage = new Room ("You are in your garage. There is a Lamborghini Veneno there because you are one rich chad. But you are lonely so you don't have a butler to make your own sandwich.");
  Room* car = new Room ("You are sitting in your Lamborghini. You use your money to hide behind your frequent thoughts of sadness. Hopefully that sandwich will cheer you up. :)");
  Room* drive = new Room ("You are driving in your Lamborghini. The radio plays of late 80s metal rock. You see Fred Meyer's in the distance.");
  drive->addItem(CDs);
  Room* parkLot = new Room ("You are standing in in the parking lot. You see the towering letters of Fred Meyer's in the distance.");
  Room* entrance = new Room ("You are at the entrance of Fred Meyer's.");
  Room* mainAisle = new Room ("You are standing in the main asle of Fred Meyer's.");
  Room* grains = new Room ("You are standing in the grain section of Fred Meyer's. So many breads to choose from.");
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
  Room* produce = new Room ("You are standing in the produce section of Fred Meyer's. You need either lettuce or spinach.");
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

  garage->nextTo(car, "Lamborghini");
  garage->nextTo(hallway, "Hallway");

  car->nextTo(drive, "Start Driving");
  car->nextTo(garage, "Back in Garage");

  drive->nextTo(parkLot, "Parking Lot");
  drive->nextTo(car, "Back to House");
  
  parkLot->nextTo(entrance, "Fred Meyer's Entrance");
  parkLot->nextTo(drive, "Lamborghini");
  
  entrance->nextTo(mainAisle, "Main Aisle");
  entrance->nextTo(parkLot, "Parking Lot");
  
  mainAisle->nextTo(grains, "GRAINS");
  mainAisle->nextTo(dairy, "DAIRY");
  mainAisle->nextTo(poultry, "POULTRY");
  mainAisle->nextTo(produce, "PRODUCE");
  mainAisle->nextTo(entrance, "Entrance of Freddie's");
  
  //mainAisle->nextTo(kitchen, "Kitchen");//testing winning condition
  //kitchen->nextTo(mainAisle, "Fred");

  grains->nextTo(mainAisle, "Main Aisle");
  grains->nextTo(dairy, "DAIRY");

  dairy->nextTo(mainAisle, "Main Aisle");
  dairy->nextTo(poultry, "POULTRY");
  dairy->nextTo(grains, "GRAINS");

  poultry->nextTo(mainAisle, "Main Aisle");
  poultry->nextTo(produce, "PRODUCE");
  poultry->nextTo(dairy, "DAIRY");

  produce->nextTo(mainAisle, "Main Aisle");
  produce->nextTo(poultry, "POULTRY");

  Room* current = bedRoom; //start in bedroom
  char keyword[40];
  char input[40];
  while (true){
    if (current == kitchen){//winning condition
      if((find("White Bread",inventory) || find("Whole Wheat Bread", inventory) || find("Sourdough Bread", inventory)) &&
	 (find("Mozzarella Cheese", inventory) || find("Cheddar Cheese", inventory) || find("Parmesan Cheese", inventory)) &&
	 (find("Sliced Smoked Ham", inventory) || find("Sliced Smoked Beef", inventory)) &&
	 (find("Lettuce", inventory) || find("Spinach", inventory))){
	cout << "- - - " << endl;
	cout << "You assemble the carefully selected ingredients you so laboriously sought out to buy. The bread, vegetables, sliced meat, and cheese fall so effortlessly together as if they were meant to be together like this all along. You take a slow bite. Tears of deliciousness fill your twinkling eyes as you take another bite, then another, until the last bite is finally finished. It all went by so quickly. But you have more ingredients leftover on the counter. With lightning speed you make more sandwiches and gobble them down showing no signs of stopping. You feel an earthy rumble from somewhere deep within. It is your colon, telling you that it is ready to be released. You make a beeline for the bathroom, and blow up that toilet that was waiting for the moment to arrive all along." << endl << endl << "THE END" << endl;
	cout << "- - - " << endl;
	for (auto it = inventory->begin(); it != inventory->end(); it++){//prevent memory leak
          delete (*it);
        }
        delete inventory;
	return 0;
	}
      else{
	printRoom(inventory, current);
      }
    }
    else{
      printRoom(inventory, current); //print a description of the room
    }
    cin.get(keyword, 40);
    cin.clear();
    cin.ignore(999, '\n');
    if (strcmp(keyword, "GO") == 0){//if the keyword is GO
      bool found = false;
      cout << endl;
      cout << "Go Where? " << endl;
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
    }
    else if (strcmp(keyword, "DROP") == 0){
      cout << endl;
      dropItem(inventory, current);//dropItem method
    }
    else if (strcmp(keyword, "QUIT") == 0){//QUIT, must delete memory too
      cout << "Game Stopped." << endl;
      for (auto it = inventory->begin(); it != inventory->end(); it++){
	  delete (*it);
      }
      delete inventory;
      return 0;
    }
    else{
      cout << "Enter a valid keyword (\"GO\", \"INVENTORY\", \"GET\", \"DROP\", or \"QUIT\"). All words are case sensitive." << endl;
    }
  }
}

void printRoom(vector<Item*>* inventory, Room* current){//prints the description, items, and exits of a room
 vector<Item*> :: iterator it;
 cout << "- - -" << endl;
 cout <<current->getRoomName()<<endl;//get description
 cout <<  endl;
 cout << "ITEMS:" << endl;
 if(current->itemListSize() == 0){//if no items
    cout << "No Items." << endl;
  }
  else{
    vector<Item*>* itemList = current -> getItemList();//print items
    for(it = itemList->begin(); it != itemList->end(); it++){
      cout << "<" << (*it)->getItemName() << "> ";
    }
    cout << endl;
  }
 cout << endl;
 cout << "EXITS:" << endl;
 map<char*, Room*>* nextRooms = current->getNext();//show exits
 map<char*, Room*> :: iterator itr = nextRooms->begin();
 for (itr = nextRooms->begin(); itr != nextRooms->end(); itr++) {//print adjacent rooms
   cout << "<" << itr->first << "> ";
 }
 cout << endl;
 cout << "- - - " << endl;
}


void printInventory(vector<Item*>* inventory){//print out whatever is in vector pointer inventory
  vector<Item*>::iterator it;
  cout << "INVENTORY:" << endl;
  if (inventory->size() == 0){
    cout << "No Items." << endl;
  }
  else{
    for (it = inventory -> begin(); it != inventory -> end(); ++it) {
      cout << "<" << (*it)->getItemName() << "> ";
    }
  }
}

void dropItem(vector<Item*>* inventory, Room* current){//drop item into a room from inventory
  Item* item;
  vector<Item*>* roomItems = current -> getItemList();
  vector<Item*> :: iterator it;
  bool found = false;
  char* dropItem = new char();
  if(inventory->size() == 0){
    cout << "No Items in Inventory." << endl;
  }
  
  else{
    printInventory(inventory);
    cout << endl;
    cout << endl;
    cout << "Drop What?" << endl;
    cin.getline(dropItem, 40, '\n');
    for(it = inventory->begin(); it != inventory->end(); it++){
      if (strcmp((*it)->getItemName(), dropItem) == 0){//if matches, add to room and remove inventory
	current->addItem(*it);
	inventory->erase(it);
	found = true;
	cout << endl;
	cout << "Item Dropped." << endl;
	return;
      }
    }
    if (found == false){
      cout << "Invalid Item Name." << endl;
    }
  }
}

void getItem(vector<Item*>* inventory, Room* current){//pick up item from room
  vector<Item*> :: iterator it;
  char* getItem = new char();
  bool found = false;
  if(current->itemListSize() == 0){
    cout << "No Items in Room." << endl;
  }
  else{
    cout << "Get What?" << endl;
    cin.get(getItem, 40);//take input getItem
    cin.clear();
    cin.ignore(999, '\n');
    for(it = current->getItemList()->begin(); it != current->getItemList()->end(); it++){//search through itemList
      if (strcmp((*it)->getItemName(), getItem) == 0){//if there is a match, add to inventory delete from room
        inventory->push_back(*it);
        current->deleteItem(*it);
	found = true;
	cout << "Item Gotten." << endl;
	return;
      }
    }
    if (found == false) {
      cout << "Invalid Item Name." << endl;
    }
  }
}

bool find(char* item, vector<Item*>* inventory){
  vector<Item*>::iterator it;
  for (it = inventory -> begin(); it != inventory -> end(); ++it) {
    if(strcmp((*it)->getItemName(), item) == 0){
      return true;
    }
  }
  return false;
}
