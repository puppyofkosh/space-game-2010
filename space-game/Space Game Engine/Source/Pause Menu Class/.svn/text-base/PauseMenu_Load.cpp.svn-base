/*
 *  PauseMenu_Load.cpp
 *  Space Game Engine
 *
 *  Created by Alex Nesta on 8/30/10.
 *  Copyright 2010 Holy Cross High School. All rights reserved.
 *
 */

#include "../Game Class/GameClass.h"
#include <fstream>
#include <string>
#include <iostream>

void PauseMenu::loadGame()
{
	std::ifstream infile;
	
	infile.open("SaveGame.ini", std::ios::in);
	
	std::string line;
	
	int count = 1;

	float oldTrueX = game->player.ship.trueX;
	float oldTrueY = game->player.ship.trueY;
	
	if(infile.is_open())
	{
		while(!infile.eof())
		{
			getline(infile, line);
			if(count == 2)
				game->player.ship.xPos = atof(line.c_str());
			if(count == 4)
				game->player.ship.trueX = atof(line.c_str());

			
			else if(count == 6)
				game->player.ship.yPos = atof(line.c_str());
			else if(count == 8)
				game->player.ship.trueY = atof(line.c_str());
			
			
			else if(count == 10)
				game->player.ship.xSpeed = atof(line.c_str());
			else if(count == 12)
				game->player.ship.ySpeed = atof(line.c_str());
			
			
			else if(count == 14)
				game->player.ship.rotation = atoi(line.c_str());

			else if (count == 16)
				game->player.ship.xAcceleration = atof (line.c_str());
			else if (count == 18)
				game->player.ship.yAcceleration = atof (line.c_str());
			
			count++;
		}
		
		infile.close();
		std::cout<<"File Loaded" << std::endl;

		
		//We now send all objects back to their original positions
		for (int i = 0; i < game->solarSystem.system.size(); i++)
		{
			game->solarSystem.system[i]->sun.xPos += oldTrueX;//Set the positions of the object back to it's original
			game->solarSystem.system[i]->sun.yPos += oldTrueY;

			game->solarSystem.system[i]->sun.xPos -= game->player.ship.trueX;//Now make it the position it was in the save
			game->solarSystem.system[i]->sun.yPos -= game->player.ship.trueY;
			for (int a = 0; a < game->solarSystem.system[i]->planet.size(); a++)
			{
				game->solarSystem.system[i]->planet[a]->xPos += oldTrueX;
				game->solarSystem.system[i]->planet[a]->yPos += oldTrueY;

				game->solarSystem.system[i]->planet[a]->xPos -= game->player.ship.trueX;
				game->solarSystem.system[i]->planet[a]->yPos -= game->player.ship.trueY;

			}
		}


		game->player.update();
	}
	else
	{
		std::cout<<"Load Failed!";
	}


}
