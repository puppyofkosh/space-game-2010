#include "Display.h"
#include "Game Class/GameClass.h"
#include "Space Object Class/SpaceObjectClass.h"

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

#include <sstream>
#include <string>

#include "VBO/VBOExtend.h"
#include "TGAImage.h"
#include "Trade Mission Class/TradeMissionClass.h"

#include <iostream>
#include <math.h>


void display()//render everything
{
	using std::endl;

	int fps = game->getFramerate();	//Get the framerate and Display it in the Console.
	if (fps != -1)//getFramerate returns the framerate every second. Otherwise returns -1
	{
		std::cout << "The current fps is " << fps << std::endl;
	}
	//print the speed of the ship
	//std::cout << "The player's speed in the x direction is " << abs (game->player.ship.xSpeed) << std::endl;
	//std::cout << "The player's speed in the y direction is " << abs (game->player.ship.ySpeed) << std::endl;

	//std::cout << "It took " << game->timeForDraw << " ms to draw that frame" << std::endl;

	game->newTimeForDraw = glutGet(GLUT_ELAPSED_TIME);

	//game->limitFramerate();//limits the framerate

	glClear(GL_COLOR_BUFFER_BIT);
	//Make the BackGround Black. We are in space after all :P
	glClearColor (0, 0, 0, 0); 
	glColor3f (1, 1, 1); //Make the drawing color white for the stars. Are all of these white color calls really necssary?

	game->arial10.drawString (game->screenWidth - 300, game->arial10.charHeight, game->message);

	if (game->gameMode == game->SPACE)	//If you are in Space Mode,
	{
		game->backgroundStar.draw();//Draw our background stars

		//Draw the solar system.
		
		for (int i = 0; i < game->solarSystem.system.size(); i++)
		{
			game->solarSystem.system[i]->sun.draw();	//Draw the sun
			for (int a = 0; a < game->solarSystem.system[i]->planet.size(); a++)	//Draw all the planets
			{
				game->solarSystem.system[i]->planet[a]->draw();
			}
		}

		game->player.ship.draw();//Draw the player's ship
		//If this planet is the closest to the player, then we draw a little message
		if (game->player.closest != NULL)
		{
			game->arial10.drawString(game->player.closest->xPos, game->player.closest->yPos, "Land here folks");
		}
		
		if (game->map.isActive == false)//only draw the hud if the map is not being displayed
		{
			game->hud.draw();	//Draw the HUD

		}
		if (game->map.isActive == true)	//If the map is "active"
		{
			game->map.drawBackground();			//Draw the Background of the Map
			game->map.draw();					//Draw the Objects on the Map
		}



	}	

	else if (game->gameMode == game->PAUSE)
	{
		game->pauseMenu.pauseMenuList.draw();

		//game->pauseMenu.draw();
	}
	
	//if in land mode
	else if (game->gameMode == game->LAND && game->player.landed != NULL)
	{
				//Draw the player's fuel
		std::stringstream out;
		out << (int)game->player.ship.fuel;
		game->arial10.drawString (5, game->screenHeight - 100, "Fuel: " + out.str());
		out.str("");//Clear it

		out << (int)game->player.money;
		game->arial10.drawString (5, game->screenHeight - 90, "Space Bucks: " + out.str());
		out.str("");//Clear it

		out << 100 * (game->player.ship.hull/game->player.ship.maxHull);
		game->arial10.drawString (5, game->screenHeight - 80, "Hull Percentage: " + out.str());
		out.str("");//Clear it

		

		game->arial10.drawString (900, 10, game->player.landed->name);
		game->landMenu.choice.draw();

		//print the type of engine the player currently has
		game->arial10.drawString (450, 500, "You have " + game->player.ship.getEngine()->name);

		//print the name of the govt. controlling the planet
		game->arial10.drawString (800, 200, "You are on a " + game->player.landed->controllingGovernment->name + " controlled planet");


		if (game->landMenu.displayPartList)
		{
			game->landMenu.availableParts.draw();
		}/*
		if (game->landMenu.displayCargoList)
		{
			game->landMenu.sellableCargo.draw();
		}*/
		if (game->activeList != NULL)
			game->activeList->draw();
	}

	game->player.closest = NULL;//Reset it.
	glFlush();	//Flush to prevent garbage
	glutSwapBuffers();	//Swap Buffers for smooth animations.

	game->timeForDraw = glutGet(GLUT_ELAPSED_TIME) - game->newTimeForDraw;

	//std::cout << glGetError() << std::endl;//check for errors. This is a slow function, only call when needed
}