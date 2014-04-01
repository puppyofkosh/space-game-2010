#include "ButtonClassChildren.h"
#include "../Game Class/GameClass.h"
#include "../List Class/List Item Class/ListItemChildren.h"

#include <iostream>
#include <sstream>
#include <string>

class ToggleEngine;
void ToggleEngine::activate()
{

	if (game->player.ship.toggleEngine == game->player.ship.THRUSTERS)
	{
		game->player.ship.toggleEngine = game->player.ship.DRIVE;
	}
	//if they want to switch to thruster mode, and aren't going too fast.
	else if (game->player.ship.toggleEngine == game->player.ship.DRIVE 
			&& abs(game->player.ship.xSpeed) < game->speedThresholdThruster 
			&& abs(game->player.ship.ySpeed) < game->speedThresholdThruster)
	{
		game->player.ship.toggleEngine = game->player.ship.THRUSTERS;
	}
}

class ToggleButton;
void ToggleMap::activate()
{
	//toggle the map.
	game->map.isActive = !game->map.isActive;
}

class LandButton;
void LandButton::activate()
{

	if (game->gameMode == game->LAND)//if they are landed, we take off
	{
		game->player.landed = NULL;
		game->gameMode = game->SPACE;

		//We clean up the array of items for sale
		game->landMenu.availableParts.clear(true);
	}
	else if (game->player.closest != NULL)//If they arent landed and are near a planet
	{
		game->player.landed = game->player.closest;//They will land on the closest planet
		game->gameMode = game->LAND;//The player is landed
		
		game->landMenu.setup();

		game->activeList = &game->landMenu.choice;
	}
}