//Item Header file, function prototypes and variable declaration
#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

class Item {
 public://functions
  Item(char* itemName);  
  char* getItemName();
  virtual ~Item();
 private://variables
  char* itemName;
};
#endif
