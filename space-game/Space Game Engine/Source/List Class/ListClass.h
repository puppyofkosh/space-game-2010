#pragma once

#include <vector>
#include "List Item Class/ListItemClass.h"

#include <string>

class List
{
public:

	//ListItem* selected;//the currently selected item
	int selectedSpot;//Where the selected item is in the array

	std::vector <ListItem*> item;	//all of the items in the list

	float xPos;//Starting position of the menu
	float yPos;

	void draw();
	void update();
	void init (float xStart, float yStart);
	void clear(bool deleteContents);//Delete all members
	void add(ListItem* i);//Adds a list item to the array.
	void remove (ListItem* a);//remove the specified item
	void remove (int place);//remove the item in the specified place

	bool prevUpKey;//The previous values of the keys so we can see if the key has been pressed and released.
	bool prevDownKey;
	bool prevReturnKey;

	List();
	~List();
};