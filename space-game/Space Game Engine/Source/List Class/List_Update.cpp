#include "ListClass.h"
#include "../Game Class/GameClass.h"

#include <iostream>

void List::update()
{

	if (prevReturnKey == true && game->keyboard[13] == false && selectedSpot > -1 && selectedSpot < item.size())//If the return key was pressed...
	{
		item[selectedSpot]->activate();
	}

	if ( selectedSpot < 0)
	{
		if (item.size() > 0)
		{
			selectedSpot = 0;
		}
	}

	if (prevUpKey == true && game->specialKeyboard[game->convertKeys.UP_KEY - 1] == false)
	{
		if (selectedSpot == 0)//If it's not the first item
		{
			selectedSpot = item.size()-1;
		}
		else
		{
			//Move it down 1
			selectedSpot -= 1;
		}
	}

	if (prevDownKey == true && game->specialKeyboard[game->convertKeys.DOWN_KEY - 1] == false)
	{
		if (selectedSpot == item.size() - 1)//if its the last item, select the first selectable item
		{
			selectedSpot = 0;
		}
		else
		{
			//Move it up one if it can be selected
			selectedSpot += 1;
		}
	}

	
	prevUpKey = game->specialKeyboard[game->convertKeys.UP_KEY - 1];
	prevDownKey = game->specialKeyboard[game->convertKeys.DOWN_KEY - 1];
	prevReturnKey = game->keyboard[13];

}