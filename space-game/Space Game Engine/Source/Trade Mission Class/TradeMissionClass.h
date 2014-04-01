#pragma once

#include "../Planet Class/PlanetClass.h"
#include "../Cargo Class/CargoClass.h"



class TradeMission
{
public:
	Planet* source;//Where the trade mission was assigned/accepted
	Planet* destination;//Where the cargo is "destined" to go
	Cargo::CargoItem* cargoType;//The type of cargo being moved
	int payment;//The payment the player will get for this mission
	float distance;//The distance from the first planet to the second
	int amount;//The amount of cargo being transported
	bool isCompleted;//Whether or not the trade mission has been completed.

	void setMission(Planet* start, Planet* end, int iAmount, Cargo::CargoItem* type);//Make a new trade mission to wherever the specified planet is...
};