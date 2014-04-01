#include "PauseMenuClass.h"

#include "../Game Class/GameClass.h"

void PauseMenu::update()
{
	if (game->keyboard[int('q')] == true)	//if you press q while the game is paused
	{
		exit(0);											//Close the game
	}
	else if (game->keyboard[int('s')] == true)	//if you press s while the game is paused
	{
		game->pauseMenu.saveGame();											//save the game
	}
	else if (game->keyboard[int('l')] == true)	//if you press l while the game is paused
	{
		game->pauseMenu.loadGame();											//load the saved game
	}
}