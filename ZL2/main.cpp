/*
map: https://www.youtube.com/watch?v=POYRev0zk2k

*/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <unistd.h>

#include "room.h"
#include "items.h"

using namespace std;

//functions
void initRoom(vector<Room*>* rooms);
void initItems(vector<Items*>* items);
void printRoom(vector<Room*>* rooms, vector<Items*>* items, int cR);
int move(vector<Room*>* rooms, int cR, char direction[]);


int main()
{
  vector<Room*> rooms;
  vector<Items*> items;
  vector<int> inv;
  char input[10];
  int cR = 1;
  initRoom(&rooms);
  initItems(&items);
  bool run = true;

  cout << "This is my Zuul Program" << endl;
  cout << "You have the commands: go, pickup, drop, inv, help, and quit" << endl;
  while (run == true)
    {
      cout << endl;
      printRoom(&rooms, &items, cR);
      cin >> input;
      if (strcmp(input, "go") == 0)
	{
	  cout << "Which Direction?" << endl;
	  cin >> input;
	  if (move(&rooms, cR, input) == 0)
	    {
	      cout << "There is nothing in that direction" << endl;
	    }
	  else
	    {
	      cR = move(&rooms, cR, input);
	    }
	}

      if (strcmp(input, "pickup") == 0)
	{
	  cout << "pickup" << endl;
	}

      if (strcmp(input, "drop") == 0)
	{
	  cout << "input" << endl;
	}

      if (strcmp(input, "inv") == 0)
	{
	  cout << "inv" << endl;
	}
      
      if (strcmp(input, "help") == 0)
	{
	  cout << "go     |  Allows you to leave your current room, into another connecting room." << endl;
	  cout << "pickup |  Allows you to pick up an item from your current room." << endl;
	  cout << "drop   |  Allows you to drop an item from your inventory." << endl;
	  cout << "inv    |  Allows you to check the items you have in your inventory." << endl;
	  cout << "quit   |  Allows you to quit the game." << endl;

	}

      if (strcmp(input, "quit") == 0)
	{
	  cout << "Thank you for playing" << endl;
	  run = false;
	}
    }
  
  return 0;
}

void printInv(vector<Items*>* items, vector<int> inv)
{
  vector<int>::iterator it;
  vector<Items*>:: iterator it2;
  
  
}

void initRoom(vector<Room*>* rooms)
{
  //exits
  char* north = (char*)("north");
  char* south = (char*)("south");
  char* east = (char*)("east");
  char* west = (char*)("west");
  map<int, char*> pass;

  Room* sPit = new Room();
  sPit->setDesc((char*)("You are inside the muddy mess of what had previously been a well-made pit trap. The slippery walls make it difficult to scale, but after a few attempts you are able to get back up to surface level. Your clothes look awful."));
  sPit->setID(1);
  sPit->setItem(0);
  pass.insert(pair<int, char*> (2, north));
  sPit->setDir(pass);
  rooms->push_back(sPit);
  pass.clear();

Room* glade = new Room();
  glade->setDesc((char*)("This area seems to be one of the glades in this forest. Bright rays of today's sunny skies shine through the large openings among the leaves. On the ground, dozens of different types and colors of flowers are starting to bloom. You pick up that it is nearing the beginning of spring."));
  glade->setID(2);
  glade->setItem(1);
  pass.insert(pair<int, char*> (1, south));
  pass.insert(pair<int, char*> (3, north));
  glade->setDir(pass);
  rooms->push_back(glade);
  pass.clear();

  Room* forestH = new Room();
  forestH->setDesc((char*)("This area looks like it leads to multiple different areas. The very faint rushing of a stream echoes from the west, but chirping of birds come from south and east. The north seems quiet."));
  forestH->setID(3);
  forestH->setItem(0);
  pass.insert(pair<int, char*> (2, south));
  pass.insert(pair<int, char*> (4, west));
  pass.insert(pair<int, char*> (7, north));
  pass.insert(pair<int, char*> (9, east));
  forestH->setDir(pass);
  rooms->push_back(forestH);
  pass.clear();

  Room* riverP = new Room();
  riverP->setDesc((char*)("The sound of the river's rushing comes to an easily audible level. There are cracked sticks upon the floor of the path, seemingly crushed by a large creature who passed by recently."));
  riverP->setID(4);
  riverP->setItem(0);
  pass.insert(pair<int, char*> (3, east));
  pass.insert(pair<int, char*> (5, west));
  riverP->setDir(pass);
  rooms->push_back(riverP);
  pass.clear();

  Room* riverS = new Room();
  riverS->setDesc((char*)("The suns seems to be even brighter now, as the light is reflecting off the river to the west of you. In the middle of the river, a large brown bear seems to be swimming in search of fish. It won't be back in it's den for a while."));
  riverS->setID(5);
  riverS->setItem(0);
  pass.insert(pair<int, char*> (4, east));
  pass.insert(pair<int, char*> (6, west));
  riverS->setDir(pass);
  rooms->push_back(riverS);
  pass.clear();

  Room* river = new Room();
  river->setDesc((char*)("You are now inside the river, swimming among the strong current. You notice some fish swimming down the current."));
  river->setID(6);
  river->setItem(2);
  pass.insert(pair<int, char*> (5, east));
  river->setDir(pass);
  rooms->push_back(river);
  pass.clear();

  Room* bearD = new Room();
  bearD->setDesc((char*)("This area is heavily covered in shade from the trees. You see an open cave to the north of you, where you can faintly hear a small yelp. After a few seconds of observing your surroundings, you realize that you are right outside the den of a bear."));
  bearD->setID(7);
  bearD->setItem(0);
  pass.insert(pair<int, char*> (3, south));
  pass.insert(pair<int, char*> (8, north));
  bearD->setDir(pass);
  rooms->push_back(bearD);
  pass.clear();

  Room* bear = new Room();
  bear->setDesc((char*)("The light is extremely low, with very little light reflecting from outside. While inside the cave, you see a small bear cub curled into a small ball"));
  bear->setID(8);
  bear->setItem(3);
  pass.insert(pair<int, char*> (7, south));
  bear->setDir(pass);
  rooms->push_back(bear);
  pass.clear();

  Room* glade2 = new Room();
  glade2->setDesc((char*)("This area seems to be similar to the first glade you entered, but towards the east, you see a path covered in thorny plants and branches."));
  glade2->setID(9);
  glade2->setItem(0);
  pass.insert(pair<int, char*> (3, west));
  pass.insert(pair<int, char*> (10, east));
  glade2->setDir(pass);
  rooms->push_back(glade2);
  pass.clear();

  Room* thornyP = new Room();
  thornyP->setDesc((char*)("You scratch yourself on the thorns on your way through the path. You hear a rustling sound from the north. There is an opening from the path coming from both the west and east directions."));
  thornyP->setID(10);
  thornyP->setItem(0);
  pass.insert(pair<int, char*> (9, west));
  pass.insert(pair<int, char*> (11, north));
  pass.insert(pair<int, char*> (12, east));
  thornyP->setDir(pass);
  rooms->push_back(thornyP);
  pass.clear();

  Room* humanWB = new Room();
  humanWB->setDesc((char*)("You see another person. As you get close, they invite you to their table. They offer to help you get out, and bring you back to their house."));
  humanWB->setID(11);
  humanWB->setItem(4);
  pass.insert(pair<int, char*> (10, south));
  humanWB->setDir(pass);
  rooms->push_back(humanWB);
  pass.clear();

  Room* slipH = new Room();
  slipH->setDesc((char*)("There is a faint amount of light shining through the many cracks between leaves. You find yourself at the top of a hill. Judging from the slipperiness and steepness, you probably won't be able to make it back up if you slide down. It's a one way trip. There seems to be a small opening to your east."));
  slipH->setID(12);
  slipH->setItem(0);
  pass.insert(pair<int, char*> (10, west));
  pass.insert(pair<int, char*> (13, east));
  pass.insert(pair<int, char*> (14, north));
  slipH->setDir(pass);
  rooms->push_back(slipH);
  pass.clear();

  Room* owl = new Room();
  owl->setDesc((char*)("After exploring for a little bit, you find a nest filled with sleeping owls. As you walk to get closer, you see the slit of one of the owls spring up and look at you. They spread their wings and scratch at you, forcing you to leave the nest"));
  owl->setID(13);
  owl->setItem(5);
  pass.insert(pair<int, char*> (12, west));
  owl->setDir(pass);
  rooms->push_back(owl);
  pass.clear();

  Room* brambleP = new Room();
  brambleP->setDesc((char*)("This path is similar to the thorny path you traveled in before, but in these ones, you notice that there are small blackberries attached to many of the thorned stems. Out of the opening to the west, you see a log cabin."));
  brambleP->setID(14);
  brambleP->setItem(6);
  pass.insert(pair<int, char*> (15, west));
  brambleP->setDir(pass);
  rooms->push_back(brambleP);
  pass.clear();

  Room* cabinL = new Room();
 cabinL->setDesc((char*)("From this log cabin, you see the opening towards a road. A surge of relief washes throughout your entire body, knowing that you'll be able to get out of this place."));
  cabinL->setID(15);
  cabinL->setItem(0);
  pass.insert(pair<int, char*> (14, east));
  cabinL->setDir(pass);
  rooms->push_back(cabinL);
  pass.clear();
}

void initItems(vector<Items*>* items)
{
  Items* flower = new Items();
  flower->setName((char*)("Flower"));
  flower->setID(1);
  items->push_back(flower);

  Items* fish = new Items();
  fish->setName((char*)("Fish"));
  fish->setID(2);
  items->push_back(fish);

  Items* bear = new Items();
  bear->setName((char*)("Bear Cub"));
  bear->setID(3);
  items->push_back(bear);

  Items* help = new Items();
  help->setName((char*)("Help From Stranger"));
  help->setID(4);
  items->push_back(help);

  Items* owl = new Items();
  owl->setName((char*)("Owl Feather"));
  owl->setID(5);
  items->push_back(owl);

  Items* berry = new Items();
  berry->setName((char*)("Blackberries"));
  berry->setID(6);
  items->push_back(berry);
}

void printRoom(vector<Room*>* rooms, vector<Items*>* items, int cR)
{
  vector<Room*>::iterator it;
  vector<Items*>::iterator it2;
  for (it = rooms->begin(); it != rooms->end(); it++)
    {
      if (cR == (*it)->getID())
	{
	  cout << (*it)->getDesc() << endl;
	  for (map<int, char*>::iterator it3 = (*it)->getDir()->begin(); it3 != (*it)->getDir()->end(); it3++)
	    {
	      cout << it3->second << " | ";
	    }
	  cout << endl;
	  for (it2 = items->begin(); it2 != items->end(); it2++)
	    {
	      if ((*it)->getItem() == (*it2)->getID())
		{
		  cout << (*it2)->getName() << endl;
		}
	    }
	  cout << endl;
	}
    }
}

int move(vector<Room*>* rooms, int cR, char direction[]) 
  {//moving to another room
    vector<Room*>::iterator it;
    for (it = rooms->begin(); it != rooms->end(); it++)
      {
        if (cR == (*it)->getID())
          {
            map<int, char*> exits;
            exits = *(*it) -> getDir();
            map<int, char*>::const_iterator it2;
            for (it2 = exits.begin(); it2 != exits.end(); ++it2)
              {
	        if (strcmp(it2->second, direction) == 0)
                  {
	            return it2->first;
	          }
              }
          }
      }
  return 0;
}
