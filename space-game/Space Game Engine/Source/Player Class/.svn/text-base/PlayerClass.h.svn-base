#include "../Ship Class/ShipClass.h"
#include "../Planet Class/PlanetClass.h"
#include "../Trade Mission Class/TradeMissionClass.h"
#include "../Government Class/GovernmentClass.h"

#ifndef PLAYER //Allows this to be included multiple times

#define PLAYER
class Player
{
public:

	Government::Gov* government;//The player's government

	float destinationXPos;//Where the player's destination is set at.
	float destinationYPos;

	TradeMission* tradeMission;//This must be deleted!

	Ship ship;		//Do not call ship.update!!!
	
	Planet* closest;//The closest planet
	float closestPlanetDistance;//Distance from the closest planet

	Planet* landed;//What planet the player is landed on.

	float money;//Amount of money the player has

	void update();
	void setTradeMission (TradeMission* t);

	Player()
	{
		destinationXPos = 0;//Somewhere the player cannot see em
		destinationYPos = 0;
		tradeMission = NULL;
	}
	~Player()
	{
		delete tradeMission;
	}
};

#endif