#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room
{
 public: //function prototypes
  Room();
  //getters
  char* getDesc();
  map<int, char*>* getDir();
  int getID();
  int getItem();
  //setters
  void setDesc(char*);
  void setDir(map<int, char*>);
  void setID(int);
  void setItem(int);
 private: //private variables
  char* desc;
  map<int, char*> dir;
  int id;
  int item;
};
#endif
