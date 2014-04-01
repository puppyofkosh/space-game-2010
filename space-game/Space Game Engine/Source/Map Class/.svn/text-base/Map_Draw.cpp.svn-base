#include "MapClass.h"

#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#define NO_VBOS
#endif
#ifdef _WIN32
#include <windows.h> // these two header files are needed to compile a program in OpenGL with GLUT
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif
#ifdef __linux__
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#define NO_VBOS
#endif 

#include "../VBO/VBOExtend.h"
#include "../Game Class/GameClass.h"

#include <iostream>
void Map::draw()
{
	int xPosition;//For each different ship displayed on the radar.
	int yPosition;

	float divisorX = (game->sectorWidth/2 - game->screenWidth)/xCenter;//sets the accuracy of the map (aka the zoom)
	float divisorY = (game->sectorHeight/2 - game->screenHeight)/yCenter;

	glEnable (GL_TEXTURE_2D);//needed to render the texture

	glEnable (GL_BLEND);//This eliminates the black background
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	xPosition = ((game->player.ship.trueX) - game->screenWidth)/divisorX + xCenter;//We draw the player ship in the center of the radar display
	yPosition = ((game->player.ship.trueY) - game->screenHeight)/divisorY + yCenter;
	xPosition -= (-(game->screenWidth/2))/divisorX;//This is to make it match up with the player's position on the radar
	yPosition -= (-(game->screenHeight/2))/divisorY;

	drawElement (xPosition, yPosition, 0, 0, 1);//Draw the player

	xPosition = ((game->player.destinationXPos) - game->screenWidth)/divisorX + xCenter;//We draw the player ship in the center of the radar display
	yPosition = ((game->player.destinationYPos) - game->screenHeight)/divisorY + yCenter;
	xPosition -= (-(game->screenWidth/2))/divisorX;//This is to make it match up with the player's position on the radar
	yPosition -= (-(game->screenHeight/2))/divisorY;

	drawElement (xPosition, yPosition, 1, 0, 0);

	
	//Draw all the stars in yellow
	for (int i = 0; i < game->solarSystem.system.size(); i++)
	{
		xPosition = ((game->solarSystem.system[i]->sun.xPos + game->player.ship.trueX - game->screenWidth) - game->screenWidth)/divisorX + xCenter;//We draw the player ship in the center of the radar display
		yPosition = (game->solarSystem.system[i]->sun.yPos + game->player.ship.trueY - game->screenHeight)/divisorY + yCenter;
		xPosition -= (-(game->screenWidth/2))/divisorX;//This is to make it match up with the player's position on the radar
		yPosition -= (-(game->screenHeight/2))/divisorY;
		
		float rGov = game->solarSystem.system[i]->planet[0]->controllingGovernment->r;
		float gGov = game->solarSystem.system[i]->planet[0]->controllingGovernment->g;
		float bGov = game->solarSystem.system[i]->planet[0]->controllingGovernment->b;
		
		/*for (int a = 0; a < game->government.gov.size(); a++)
		{
			if (game->solarSystem.system[i]->planet[0]->controllingGovernment == game->government.gov[a])
			{
				if (a == 0)
				{
					r = 1;
					g = 0;
					b = 0;
				}
				if (a == 1)
				{
					r = 0;
					g = 1;
					b = 0;
				}
				if (a == 2)
				{
					r = 0;
					g = 0;
					b = 1;
				}
				if (a == 3)
				{
					r = 1;
					g = 1;
					b = 0;
				}
				if (a == 4)
				{
					r = 1;
					g = 0;
					b = 1;
				}
				if (a == 5)
				{
					r = 0;
					g = 1;
					b = 1;
				}

			}
		}*/
		drawElement (xPosition, yPosition, rGov, gGov, bGov);//Draw the star in whatever color the controlling govt. is
	}

	glColor3f (0, 0, 0);//set the colour back to black
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}