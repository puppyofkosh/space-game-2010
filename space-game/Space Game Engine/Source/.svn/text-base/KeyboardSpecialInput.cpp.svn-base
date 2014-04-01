#include "KeyboardSpecialInput.h"

#include "Game Class/GameClass.h"

void keyboardSpecialIn(int key, int x, int y)
{
	/*if (game->gameMode == game->SPACE)//If the ship is not landed, the game is not paused etc
	{
		game->handleSpecialKeyboardInput(key, x, y);
	}*/

	int convertedKey = game->convertKeys.convertFromGlutKey(key);//Convert from the glut key to the game's
																//key definitions
	convertedKey --;//Since convertFromGlutKey returns a value 1-21 we need a value 0-20 (for the array)
	
	game->specialKeyboard[convertedKey] = true;
}

void keyboardSpecialUp(int key, int x, int y)
{
	int convertedKey = game->convertKeys.convertFromGlutKey(key);//Convert from the glut key to the game's
																//key definitions
	convertedKey --;//Since convertFromGlutKey returns a value 1-21 we need a value 0-20
	
	game->specialKeyboard[convertedKey] = false;
}