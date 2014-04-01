#include "PlanetClass.h"

#include "../Game Class/GameClass.h"

#include <iostream>

#include <math.h>
void Planet::update()
{

	//Check for the player distance to see if they can land
	//Check to see if the planet is in the screen, so we don't waste cpu time

	float playerDistance = -1;

	if (xPos < game->screenWidth && xPos > 0 && yPos < game->screenHeight && yPos > 0)
	{	//Determine the distance from the planet to the player.
		playerDistance = sqrt (abs(((game->player.ship.xPos - xPos)*(game->player.ship.xPos - xPos)) + ((game->player.ship.yPos - yPos)*(game->player.ship.yPos - yPos))));
	}
	if (playerDistance < 300 && playerDistance >= 0)
	{
		//If no closest planet has been selected or the current selected one is farther from this one
		if (game->player.closest == NULL || game->player.closestPlanetDistance > playerDistance)
		{
			//We set the closest planet to the player to be this one
			game->player.closestPlanetDistance = playerDistance;
			game->player.closest = this;
		}
	}

	rotation += rotationSpeed * game->timeForDraw/game->msForFrame;//So the planet spins using time based movement

	//make sure the rotation stays between 0 and 360 (degrees)
	if (rotation > 360)
	{
		rotation -= 360;
	}
	if (rotation < 0)
	{
		rotation += 360;
	}
	
	//update the position so when the player moves the planet appears to stay in the same place (scrolling effect)
	xPos -= game->player.ship.xSpeed * game->timeForDraw/game->msForFrame;
	yPos -= game->player.ship.ySpeed * game->timeForDraw/game->msForFrame;
}