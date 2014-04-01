#pragma once
#include <string>
#include <vector>

#include "ShipPartClass.h"
#include "../Cargo Class/CargoClass.h"

class Engine : public ShipPart
{
public:
	float force;//The force that it can provide

	float efficiency;//the amount of fuel used vs burned. The higher, the better

	Engine(std::string iName, float iValue, float iForce, float eEfficiency);
};


/*
OKAY IAN READ THIS

The idea here is that NOONE (even you) should be able to make new CargoItem classes. They should be private. Thus
the need of the friend class
*/
class CargoBay : public ShipPart
{
	
private:
	class CargoSpace//the cargo bay can have multiple types of cargo in it. An instance of this is one type of cargo  
	{

	public:
		int amount;//The amount of this specific item in the hold. e.g. you could have 10 pounds of gold
					//10 of silver, and a million rabbits or something

		Cargo::CargoItem* item;//The item being stored. This should point to an object in the "part" class under game
		
		CargoSpace(Cargo::CargoItem* i, int iAmount);
	};

public:
	int space;//total space it can hold
	int spaceLeft;//space left for more cargo


	std::vector<CargoSpace*> cargo;//all of the cargo in the bay

	void addCargo(Cargo::CargoItem* c, int iAmount);
	void removeCargo(Cargo::CargoItem* c);

	CargoBay(std::string iName, float iValue, int iSpace);
	~CargoBay();

	friend class ListItemSellCargoItem;//This needs access to the CargoSpace class
};