#include "CargoClass.h"
#include <iostream>
#include <string>

class Cargo;

Cargo::~Cargo()
{
	std::cout << "Deallocating cargo data\n";
	for (int i = 0; i < item.size(); i++)
	{
		if (item[i] != NULL)
			delete item[i];

		item[i] = NULL;
	}
}
Cargo::CargoItem::CargoItem(double iValue, std::string iName)
{
	if (iValue > 0)
	{
		value = iValue;
	}
	name = iName;
}
void Cargo::addCargoItem(std::string iName, int iValue)
{
	item.push_back (new CargoItem (iValue, iName));//Add a new item to the array...
	return;
}
