#include "ButtonClass.h"
#include "../Game Class/GameClass.h"

#include <iostream>

void Button::update()
{
	//If the key has been released (but was pressed previously) then we call activate
	if (game->keyboard[keyValue] == false && previousKeyValue == true)
	{
		this->activate();//Will call the "activate" function for whichever class update is called from.
	}

	previousKeyValue = game->keyboard[keyValue];
}