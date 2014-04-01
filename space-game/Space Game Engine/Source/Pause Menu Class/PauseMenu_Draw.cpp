/*
 *  PauseMenu_Draw.cpp
 *  Space Game Engine
 *
 *  Created by Alex Nesta on 8/30/10.
 *  Copyright 2010 Holy Cross High School. All rights reserved.
 *
 */

#include "../Game Class/GameClass.h"


void PauseMenu::draw(){

	game->arial10.drawString (0, 20, "Welcome To the Pause Menu :D");
	game->arial10.drawString (0, 40, "You can press 'S' to save");
	game->arial10.drawString (0, 60, "You can press 'L' to load");
	game->arial10.drawString (0, 80, "You can press 'Q' to quit");
	


}