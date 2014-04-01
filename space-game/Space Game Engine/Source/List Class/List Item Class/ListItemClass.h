#pragma once

#include <string>
#include <iostream>

class ListItem
{
public:
	std::string text;

	bool canBeSelected;//Whether or not its an option on a menu or a piece of text.

	bool shouldDraw;//whether or not it should be drawn

	virtual void activate()
	{
		std::cout << "Button activated" << std::endl;
	}//What is called when this item is selected from the list

	virtual void setup()//This is called every time the button needs to be shown (ie, when the plr lands or something)
	{
		//leave it blank for most.
	}

	ListItem();
	ListItem (std::string label);
	ListItem (std::string label, bool isSelectable);
};
