#include <iostream>
#include <cstring>
#include <map>

#include "room.h"

using namespace std;

Room::Room()
{
  
}

//getters
char* Room::getDesc()
{
  return desc;
}

map<int, char*>* Room::getDir()
{
  return &dir;
}

int Room::getID()
{
  return id;
}

int Room::getItem()
{
  return item;
}

//setters
void Room::setDesc(char* desc2)
{
  desc = desc2;
}

void Room::setDir(map<int, char*> dir2)
{
  dir = dir2;
}

void Room::setID(int id2)
{
  id = id2;
}

void Room::setItem(int item2)
{
  item = item2;
}


