#include "GameClass.h"
#include <Time.h>

void Game::initObjects()
{

	activeList = NULL;
	
	//Position the ship in the center.
	player.ship.xPos = screenWidth/2;
	player.ship.yPos = screenHeight/2;

	convertKeys.init();//setup the key converter from glut

	srand(time(NULL));//seed the randomizer
	
	game->backgroundStar.init(100);//initialize the background stars
}