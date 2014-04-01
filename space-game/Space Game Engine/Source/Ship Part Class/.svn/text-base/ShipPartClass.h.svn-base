#pragma once

#include <string>

class ShipPart
{
public:
	enum partType {ENGINE, CARGO_BAY};	//Just don't mess with this stuff outside the constructor
protected:	
	partType type;//This should never be modified, except in the constructor. Doing so may cause the program
					//TO CRASH
					//kthxbai

public:
	std::string name;//name of the engine
	float value;//How much it can be bought/sold for

	partType getPart();




};