#include "HUDClass.h"
#include "../Game Class/GameClass.h"

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
#include <sstream>

void HUD::draw()
{
	controlPanelBackground.draw();
	toggleEngine.draw();
	toggleMap.draw();

				
	//if there is a planet for the player to land on
	if (game->player.closest != NULL)
	{
		landButton.draw();
	}

	//Draw the player's fuel
	std::stringstream out;
	out << (int)game->player.ship.fuel;
	game->arial10.drawString (5, game->screenHeight - 100, "Fuel: " + out.str());
	out.str("");//Clear it

	//...money
	out << (int)game->player.money;
	game->arial10.drawString (5, game->screenHeight - 90, "Space Bucks: " + out.str());
	out.str("");//Clear it

	//Hull percentage
	out << 100 * (game->player.ship.hull/game->player.ship.maxHull);
	game->arial10.drawString (5, game->screenHeight - 80, "Hull Percentage: " + out.str());
	out.str("");//Clear it

	if (game->player.ship.toggleEngine == game->player.ship.THRUSTERS)//We draw whichever one is being used in red
	{
		glColor3f (1, 0, 0);
	}
	game->arial10.drawString (5, game->screenHeight - 400, "Thrusters");
	glColor3f (1, 1, 1);
	if (game->player.ship.toggleEngine == game->player.ship.DRIVE)
	{
		glColor3f (1, 0, 0);
	}
	game->arial10.drawString (5, game->screenHeight - 410, "Drive");
	glColor3f (1, 1, 1);

	//Printing all the cargo.
	int yPosition = game->screenHeight/2;//Where we draw this
	out << game->player.ship.getCargoBay()->spaceLeft;
	game->arial10.drawString (5, yPosition, out.str() + " tons of free space in cargo bay");
	out.str("");//Clear it
	yPosition += 10;
	for (int i = 0; i < game->player.ship.getCargoBay()->cargo.size(); i++)
	{
		std::string cargoName = game->player.ship.getCargoBay()->cargo[i]->item->name;
		out << game->player.ship.getCargoBay()->cargo[i]->amount;
		game->arial10.drawString (5, yPosition, out.str() + " tons of " + cargoName);
		out.str("");//Clear it
		yPosition += 10;
	}

	radar.drawBackground();
	radar.draw();
}