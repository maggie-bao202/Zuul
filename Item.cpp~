//Item.cpp file, functions accessable within Item class are here
#include <iostream>
#include "Item.h"

using namespace std;

Item :: Item(char* newName) {//constructor
  this->itemName = newName;
}

char* Item :: getItemName() {//return item name
  return itemName;
}

Item :: ~Item(){//destructor
  delete[] itemName;
}
