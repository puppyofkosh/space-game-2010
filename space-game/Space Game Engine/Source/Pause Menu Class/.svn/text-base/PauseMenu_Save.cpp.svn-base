/*
 *  PauseMenu_Save.cpp
 *  Space Game Engine
 *
 *  Created by Alex Nesta on 8/30/10.
 *  Copyright 2010 Holy Cross High School. All rights reserved.
 *
 */

#include "../Game Class/GameClass.h"

#include <fstream>
#include <iostream>
void PauseMenu::saveGame()
{
	using std::endl;

	std::ofstream outfile;
	
	outfile.open("SaveGame.ini", std::ios::out);
	
	outfile << "X Position Of Ship" << endl << game->player.ship.xPos  << std::endl;
	outfile << "True X Position Of Ship" << endl << game->player.ship.trueX  << std::endl;

	outfile << "Y Position Of Ship" << endl << game->player.ship.yPos  << std::endl;
	outfile << " True Y Position Of Ship" << endl << game->player.ship.trueY  << std::endl;
	
	outfile << "X Speed Of Ship" << endl << game->player.ship.xSpeed  << std::endl;
	outfile << "Y Speed Of Ship" << endl << game->player.ship.ySpeed  << std::endl;
	
	outfile << "Rotation Of Ship" << endl << game->player.ship.rotation  << std::endl;

	outfile << "X Acceleration of the ship" << endl << game->player.ship.xAcceleration << endl;
	outfile << "Y Acceleration of the ship" << endl << game->player.ship.yAcceleration << endl;
	
	outfile.close();
	std::cout << "File Saved!" << endl;
}
