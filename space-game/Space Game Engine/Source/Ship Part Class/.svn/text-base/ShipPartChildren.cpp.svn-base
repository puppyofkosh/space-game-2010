#include "ShipPartChildren.h"
#include <iostream>

class Engine;
Engine::Engine(std::string iName, float iValue, float iForce, float eEfficiency)
{
	name = iName;
	value = iValue;
	force = iForce;
	efficiency = eEfficiency;

	type = ENGINE;//We set it's type to be an engine
}

class CargoBay;
CargoBay::CargoBay(std::string iName, float iValue, int iSpace)
{
	name = iName;
	value = iValue;
	space = iSpace;
	spaceLeft = iSpace;

	type = CARGO_BAY;//set it up to be a cargo bay
}
CargoBay::~CargoBay()
{
	std::cout << "Freeing cargo bay data\n";
	for (int i = 0; i < cargo.size(); i++)
	{
		if (cargo[i] != NULL)//if it hasn't already been freed then free it
		{
			delete cargo[i];
		}
		cargo[i] = NULL;
	}
}
void CargoBay::addCargo(Cargo::CargoItem *c, int iAmount)
{
	
	if (iAmount <= spaceLeft)//We can only fit so much cargo into the bay
	{
		for (int i = 0; i < cargo.size(); i++)
		{
			if (cargo[i]->item == c)//if this type of cargo is already in the bay
			{
				//we just add to it
				cargo[i]->amount += iAmount;
				return;
			}
		}
	
		cargo.push_back (new CargoSpace (c, iAmount));//Add a new item to the array...
		spaceLeft -= iAmount;//There is now less space in the cargo bay for usage
		return;
	}

}
void CargoBay::removeCargo(Cargo::CargoItem* c)
{
	int placeToDelete = -1;
	for (int i = 0; i < cargo.size(); i++)
	{
		if (cargo[i]->item == c)
		{
			placeToDelete = i;
		}
	}
	if (placeToDelete == -1)//If the cargo was never there to begin with
		return;

	else
	{
		spaceLeft += cargo[placeToDelete]->amount;//By removing this cargo, we free up some space int the bay...
		delete cargo[placeToDelete];//deallocate it
		cargo[placeToDelete] = NULL;
		cargo.erase (cargo.begin() + placeToDelete);//remove it from the array.
	}

}
CargoBay::CargoSpace::CargoSpace(Cargo::CargoItem* i, int iAmount)
{
	item = i;
	amount = iAmount;
}
