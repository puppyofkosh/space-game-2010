#include "KeyboardInput.h"

#include "Game Class/GameClass.h"

#include <iostream>

void keyboardIn (unsigned char key, int x, int y)//gets the ascii value of the key and the x,y coordinates of the mouse when
										//The key was pressed
{
	if (game->gameMode == game->SPACE)//If the ship is flying around(Space Mode), the game is not paused, etc
	{
		game->handleKeyboardInput(key, x, y);	//Get keyboard Input
	}

	//escape key checker
	if (key == 27)//if escape is pressed... 
	{
		if (game->gameMode == game->SPACE)	//and you are in space mode
		{
			game->activeList = &game->pauseMenu.pauseMenuList;
			game->gameMode = game->PAUSE;	//Go to Pause mode
		}
		else//Otherwise we just go into space mode.
		{
			game->gameMode = game->SPACE;
		}
	}
		
	game->keyboard[int(key)] = true;
}

void keyboardUp (unsigned char key, int x, int y)
{
	game->keyboard[int(key)] = false;
}