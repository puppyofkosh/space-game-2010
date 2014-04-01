#pragma once

#include "../List Class/ListClass.h"

class LandMenu
{
public:
	List choice;//The choices the player has in the land menu

	int tradeMissionPlace;//Where in the "choice" array the option to start a trade mission is.

	List availableParts;//The parts you can buy from the planet you are landed on
	bool displayPartList;//Whether or not to show the parts

	List sellableCargo;//All the cargo the player has that can be sold
	bool displayCargoList;

	void setup();//called every time the player lands.
	
	LandMenu()
	{
		displayPartList = false;
		displayCargoList = false;
	}
};