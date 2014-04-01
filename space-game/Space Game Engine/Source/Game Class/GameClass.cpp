//GameClass.cpp is located in the folder "Game Class"
//GameClass.h is also located in "Game Class"
//Since they are in the same folder, we do not need to have
//include "Game Class/GameClass.h"
//whereas in main.cpp, we do.
#include "GameClass.h"
#include <vector>
#include <iostream>
#include <fstream>

#include "../Space Object Class/SpaceObjectClass.h"


Game::~Game()
{
	/*player.ship.cleanup();
	backgroundStar.cleanup();
	for (int i = 0; i < solarSystem.size(); i++)
	{
		solarSystem[i].sun.cleanup();
		for (int a = 0; a < solarSystem[i].planet.size(); a++)
		{
			solarSystem[i].planet[a].cleanup();
		}
	}
	solarSystem.erase (solarSystem.begin(), solarSystem.end());*/
}


Game::Game()
{
	frame = 0;
	timePassed = 0;
	fps = 0;
	timebase = 0;
	idleTimer = 0;
	timeForDraw = 0;
	message = "";

	player.closest = NULL;
	player.closestPlanetDistance = -1;

	map.isActive = false;

	for (int i = 0; i < sizeof(keyboard)*sizeof(bool); i++)
	{
		keyboard[i] = false;
	}
	for (int i = 0; i < sizeof(specialKeyboard)*sizeof(bool); i++)
	{
		specialKeyboard[i] = false;
	}
}

//class GameClass;
Game * game;
