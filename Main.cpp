#include  <iostream>
#include <cstring>
#include <vector>
#include ""
using namespace std;

void addMedia(vector<Room*>*);
void Inventory(vector<Item*>*);
void deleteMedia(vector<Room*>*);

int main(){
  vector<Room*>* RoomList = new vector<Room*>(); //create a vector pointer of media pointers
  vector<Item*>* ItemList = new vector<Item*>();
  
  char keyword[40];
  bool stillPlaying = true;
  cout << "TITLE" << endl;
  cout << "DESCRIPTION" << endl;
  while (stillPlaying == true){
    cout << "Type in a keyword (\"GO\",\"HELP\", \"INVENTORY\", \"GET\", \"DROP\", or \"QUIT\"):"<<endl;
    cin >> keyword; //put input into char array keyword
    cin.ignore();
    if (strcmp(keyword, "GO") == 0){//if the input is ADD
      cout << endl; //formatting
      go(RoomList); //addMedia function that reads vector pointer
      cout << endl;
    }
    else if (strcmp(keyword, "INVENTORY") == 0){//Similar to above
      cout << endl;
      searchMedia(mediaList);
      cout << endl;
    }
    else if (strcmp(keyword, "GET") == 0){
      cout << endl;
      deleteMedia(mediaList);
      cout << endl;
    }
    else if (strcmp(keyword, "DROP"){
	cout << endl;
	dropItem();
    }
    else if (strcmp(keyword, "HELP") == ){
      cout << endl;
      "Type
    }
    else if (strcmp(keyword, "QUIT") == 0){//if quit, boolean is false so program will stop
      cout << "Have a nice day!" << endl;
      stillPlaying = false;
    }
    else{//if not a valid keyword
      cout << "Make sure the keyword is capitalized." << endl;
    }
  }
  return 0;
}

void addMedia(vector<Media*>* mediaList){//user inputs information into mediavoid addMedia(vector<Media*>*);
  void searchMedia(vector<Media*>*);
  void deleteMedia(vector<Media*>*);

  int main(){
    vector<Media*>* mediaList = new vector<Media*>(); //create a vector pointer of media pointers
    char keyword[40];
    bool stillPlaying = true;
    while (stillPlaying == true){
      cout << "Type in a keyword (\"ADD\", \"SEARCH\",\"DELETE\", or \"QUIT\"):"<<endl;
      cin >> keyword; //put input into char array keyword
      cin.ignore();
      if (strcmp(keyword, "ADD") == 0){//if the input is ADD
	cout << endl; //formatting
	addMedia(mediaList); //addMedia function that reads vector pointer
	cout << endl;
      }
      else if (strcmp(keyword, "SEARCH") == 0){//Similar to above
	cout << endl;
	searchMedia(mediaList);
	cout << endl;
      }
      else if (strcmp(keyword, "DELETE") == 0){
	cout << endl;
	deleteMedia(mediaList);
	cout << endl;
      }
      else if (strcmp(keyword, "QUIT") == 0){//if quit, boolean is false so program will stop
	cout << "Have a nice day!" << endl;
	stillPlaying = false;
      }
      else{//if not a valid keyword
	cout << "Make sure the keyword is capitalized." << endl;
      }
    }
    return 0;
  }

  void addMedia(vector<Media*>* mediaList){//user inputs information into media
