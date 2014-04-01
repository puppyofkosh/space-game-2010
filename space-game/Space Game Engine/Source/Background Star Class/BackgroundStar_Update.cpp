#include "BackgroundStarClass.h"
#include "../Game Class/GameClass.h"

void BackgroundStar::update()
{
	for (int i = 0; i < star.size(); i++)
	{
		//Makes the stars move based on the speed of the ship and the star's "x psotion"
		star[i].xPos -= game->player.ship.xSpeed/star[i].zPos * game->timeForDraw/game->msForFrame;	
		star[i].yPos -= game->player.ship.ySpeed/star[i].zPos * game->timeForDraw/game->msForFrame;	///


		//To make the stars wrap around (so they are never "lost" offscreen)
		//This saves processing power and such. 
		//If the star position is larger than the screen width/height(off the screen), 
		//Then put it back in the beginning so it can actually be seen.
		if (star[i].xPos > game->screenWidth)	
		{
			star[i].xPos = 0;
		}
		if (star[i].xPos < 0)
		{
			star[i].xPos = game->screenWidth;
		}

		if (star[i].yPos > game->screenHeight)
		{
			star[i].yPos = 0;
		}
		if (star[i].yPos < 0)
		{
			star[i].yPos = game->screenHeight;
		}
	}
}