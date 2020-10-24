#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <cstring>

using namespace std;

class Items
{
 public: //public function prototypes
  Items();
  //getters
  char* getName();
  int getID();
  //setters
  void setName(char*);
  void setID(int);
 private: //private varaibles
  char* name;
  int id;
};

#endif
