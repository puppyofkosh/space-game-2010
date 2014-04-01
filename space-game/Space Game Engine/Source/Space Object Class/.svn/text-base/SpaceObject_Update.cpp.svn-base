#include "SpaceObjectClass.h"

#include "../Game Class/GameClass.h"

void SpaceObject::update()
{
	//make sure the rotation stays between 0 and 360 (degrees)
	if (rotation > 360)
	{
		rotation -= 360;
	}
	if (rotation < 0)
	{
		rotation += 360;
	}

	//Move the object however much the ship has moved in the last frame
	xPos -= game->player.ship.xSpeed * game->timeForDraw/game->msForFrame;
	yPos -= game->player.ship.ySpeed * game->timeForDraw/game->msForFrame;

	trueX += xSpeed;
	trueY += ySpeed;
}