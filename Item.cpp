#include <iostream>
#include "Item.h"

using namespace std;

//contructor
Item :: Item(char* newName) {
  this->itemName = newName;
}
//returns item's name, getter
char* Item :: getItemName() {
  return itemName;
}

Item :: ~Item(){
  delete[] itemName;
}
