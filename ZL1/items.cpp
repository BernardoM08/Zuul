#include <iostream>
#include <cstring>
#include <map>

#include "items.h"

using namespace std;

Items::Items()
{

}

//getters
char* Items::getName()
{
  return name;
}

int Items::getID()
{
  return id;
}

//setters
void Items::setName(char* name2)
{
  name = name2;
}

void Items::setID(int id2)
{
  id = id2;
}
