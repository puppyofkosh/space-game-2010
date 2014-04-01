#include "LandMenuClass.h"
#include "../List Class/List Item Class/ListItemChildren.h"

#include "../Game Class/GameClass.h"

#include <sstream>
#include <string>
#include <Time.h>

void LandMenu::setup()
{
	std::string temp;
	std::string temp2;
	std::stringstream out;

	displayPartList = false;//We will not display the part list (by default)
	availableParts.clear(true);

	displayCargoList = false;//or the cargo list
	sellableCargo.clear (true);

	for (int i = 0; i < choice.item.size(); i++)
	{
		choice.item[i]->setup();//most have an empty setup function but some (like the trade button) need it
	}
	

	//We set up the list of parts for sale that will be displayed should the user want to  buy one
	for (int i = 0; i < game->player.closest->partForSale.size(); i++)
	{
		out << game->player.closest->partForSale[i]->value;
		temp = out.str() + " space bucks - ";//Set the price into a string
		out.str("");//clear the buffer
			
		//set the item to be the price and the name of the item.
		availableParts.add (new ListItemBuyShipPart (temp + game->player.closest->partForSale[i]->name,
													game->player.closest->partForSale[i]));			
	}
	availableParts.add (new ListItemTogglePartList ("Go back"));//A way to get back to the prev
	
	for (int i = 0; i < game->player.ship.getCargoBay()->cargo.size(); i++)
	{
		//The value * amount, giving the total value of all of that type of cargo
		out << game->player.ship.getCargoBay()->cargo[i]->item->value * game->player.ship.getCargoBay()->cargo[i]->amount;
		temp2 = game->player.ship.getCargoBay()->cargo[i]->item->name;
		temp = temp2 + " " + out.str() + " space bucks - ";
		out.str("");

		sellableCargo.add (new ListItemSellCargoItem (temp, game->player.ship.getCargoBay()->cargo[i]));
	}
	sellableCargo.add (new ListItemTogglePartList("Go back"));
	
}