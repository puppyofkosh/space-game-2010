#include "ShipClass.h"
#include <iostream>

class Ship;

void Ship::setCargoBay(CargoBay* newBay)
{				
	CargoBay* temp = new CargoBay (newBay->name, newBay->value, newBay->space);
	
	if (cargoBay == NULL)
		cargoBay = new CargoBay ("", 0, 0);

	if (cargoBay->space <= newBay->space)//if the new cargobay is bigger //than the old one, we save their stuff									
	{
		
	int limit = cargoBay->cargo.size();//To preserve my sanity.
													
		for (int i = 0; i < limit; i++)					
		{
			//save all of the player's cargo to the new cargo Bay
			temp->addCargo (cargoBay->cargo[i]->item, 
			cargoBay->cargo[i]->amount);
		}
	}

	if (cargoBay != NULL)
		delete cargoBay;//get rid of the old cargo bay

	//otherwise they lose it all, and get a smaller cargo bay. Oh well. Dumbass player
	cargoBay = temp;

}
void Ship::setEngine(Engine* newEngine)
{
	if (engine != NULL)
		delete engine;

	engine = new Engine (newEngine->name, newEngine->value, newEngine->force, newEngine->efficiency);
}
Engine* Ship::getEngine()
{
	return engine;
}
CargoBay* Ship::getCargoBay()
{
	return cargoBay;
}