/*
 *  PauseMenuClass.h
 *  Space Game Engine
 *
 *  Created by Alex Nesta on 8/30/10.
 *  Copyright 2010 Holy Cross High School. All rights reserved.
 *
 */
#pragma once

#include "../List Class/ListClass.h"

class PauseMenu 
{
public:
	List pauseMenuList;//The list of options in the pause menu

	void draw();
	void update();

//private:
	void saveGame();
	void loadGame();
	
};