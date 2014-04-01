#pragma once

#include "../Space Object Class/SpaceObjectClass.h"
#include "../Ship Part Class/ShipPartChildren.h"


#ifndef SHIP

#define SHIP
class Ship: public SpaceObject	//this contains all the info about ships, engine, speed, etc. 
{
private:
	//These two have to be private. Messing with them could cause the program to crash. Please use the set/gets
	//if you need data from them
	Engine* engine;//not to be screwed with
	CargoBay* cargoBay;
public:
	
	


	//Accelerations. When the player moves the ship, this is what is changed.
	double xAcceleration;
	double yAcceleration;

	enum ToggleEngine {DRIVE, THRUSTERS};//The types of engines they can use
	ToggleEngine toggleEngine;

	float maxFuel;//The tank's fuel capacity
	float fuel;//The amount of fuel this ship has left

	float mass;//Mass of the ship

	float hull;//The amount of hitpoints the hull has left
	float maxHull;//The maximum hitpts the hull can have
	Ship()
	{
		fuel = 0;
		xAcceleration = 0;
		yAcceleration = 0;
		engine = NULL;
		cargoBay = NULL;
	}
	~Ship()
	{
		if (engine != NULL)
			delete engine;
		if (cargoBay != NULL)
			delete cargoBay;
	}
	//encapsulating the cargo bay and engines...woot
	void setCargoBay(CargoBay* newBay);
	void setEngine (Engine* newEngine);
	Engine* getEngine();
	CargoBay* getCargoBay();
};

#endif