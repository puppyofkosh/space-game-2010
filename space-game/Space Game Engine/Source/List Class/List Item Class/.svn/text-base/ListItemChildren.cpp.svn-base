#include "ListItemChildren.h"
#include "../../Game Class/GameClass.h"
#include "../../Trade Mission Class/TradeMissionClass.h"
#include <sstream>
#include <Time.h>

class ListItemQuit;
void ListItemQuit::activate() { exit(0); }
ListItemQuit::ListItemQuit(std::string label) {
	text = label;
	ListItem();
}

class ListItemSave;
void ListItemSave::activate(){ game->pauseMenu.saveGame();}
ListItemSave::ListItemSave (std::string label) 
{
	text = label;
	ListItem();
}

class ListItemLoad;
void ListItemLoad::activate () {game->pauseMenu.loadGame();}
ListItemLoad::ListItemLoad(std::string label) 
{
	text = label; 
	ListItem();
}

class ListItemRefuel;
void ListItemRefuel::activate () 
{
	if (game->fuelPrice * (game->player.ship.maxFuel - game->player.ship.fuel) > game->player.money 
																				&& game->player.money > 0)
	{
		std::cout << "You dont have enough money to fill the tank, but we'll give you as much as you can afford\n";
		game->player.ship.fuel += game->player.money/game->fuelPrice;
		game->player.money = 0;
	}
	else if (game->player.money > 0)
	{
		game->player.money -= game->fuelPrice * (game->player.ship.maxFuel - game->player.ship.fuel);
		game->player.ship.fuel =  game->player.ship.maxFuel;
	}
}

ListItemRefuel::ListItemRefuel(std::string label) 
{
	text = label;
	ListItem();
}

class ListItemRepair;
void ListItemRepair::activate()
{
	game->player.ship.hull = game->player.ship.maxHull;
}
ListItemRepair::ListItemRepair(std::string label) 
{
	text = label;
	ListItem();
}

class ListItemTogglePartList;
void ListItemTogglePartList::activate()
{
	if (game->landMenu.displayPartList)
	{
		game->activeList = &game->landMenu.choice;
	}
	else
	{
		game->activeList = &game->landMenu.availableParts;
	}
	game->landMenu.displayPartList = !game->landMenu.displayPartList;
}
ListItemTogglePartList::ListItemTogglePartList(std::string label) 
{
	ListItem();
	text = label;
}

class ListItemBuyShipPart;
void ListItemBuyShipPart::activate()
{
	if (part != NULL)
	{
		if (game->player.money >= part->value)
		{
			if (part->getPart() == part->ENGINE)//If the part being bought is an engine
			{
				game->player.ship.setEngine ((Engine*)part);
			}
			if (part->getPart() == part->CARGO_BAY)
			{
				game->player.ship.setCargoBay ((CargoBay*)part);
			}
			game->player.money -= part->value;//the player has to pay for their shiny new part...
		}
		else//They cannot afford the part
		{
			game->message = "You're too poor to afford this part";
			std::cout << "You're too poor to afford this part\n";
		}
	}
}
ListItemBuyShipPart::ListItemBuyShipPart(std::string label, ShipPart *iPart)
{
	text = label;
	part = iPart;
	ListItem();
}

ListItemToggleSellCargoList::ListItemToggleSellCargoList(std::string label)
{
	text = label;
	ListItem();
}
void ListItemToggleSellCargoList::activate()
{
	if (game->landMenu.displayCargoList)
	{
		game->activeList = &game->landMenu.choice;
	}
	else
	{
		game->activeList = &game->landMenu.sellableCargo;
	}
	game->landMenu.displayCargoList = !game->landMenu.displayCargoList;
}

ListItemSellCargoItem::ListItemSellCargoItem(std::string label, CargoBay::CargoSpace* iItem)
{
	text = label;
	cargoSpace = iItem;
	ListItem();
}

void ListItemSellCargoItem::activate()
{
	game->player.money += cargoSpace->amount*cargoSpace->item->value;//The just sold it, give em some cash
	game->player.ship.getCargoBay()->removeCargo (cargoSpace->item);//Remove the cargo from the ship

	game->landMenu.sellableCargo.remove (this);//remove it from the list, as it has been sold.
}

class ListItemTradeMission;
ListItemTradeMission::ListItemTradeMission(std::string label)
{
	ListItem();
	text = label;
	accepted = false;
}
void ListItemTradeMission::setup()
{
	std::stringstream out;
	int pay;

	if (game->player.tradeMission == NULL && game->player.ship.getCargoBay()->spaceLeft > 0)
		//if they don't already have a trade mission and do have space
	{
		shouldDraw = true;
		
		//set up a mission to a random planet.
		srand(time(NULL));

		//properties of the trade mission
		int randSystem = rand()%game->solarSystem.system.size();
		int randPlanet = rand()%game->solarSystem.system[randSystem]->planet.size();
		int randCargo = rand()%game->cargo.item.size();
		Planet* endPlanet = game->solarSystem.system[randSystem]->planet[randPlanet];
		mission.setMission (game->player.landed, endPlanet, game->player.ship.getCargoBay()->spaceLeft, 
																			game->cargo.item[randCargo]);
		pay = mission.payment;
		out << pay;

		//Let them start a trade mission...
		text = "Take " + game->cargo.item[randCargo]->name + " to planet" + endPlanet->name + 
				" for " + out.str() + " space bucks";
	}
	else if (game->player.tradeMission != NULL && 
			game->player.tradeMission->destination == game->player.landed)//If the planet they're landed on is the
																			//delivery spot
	{
		pay = game->player.tradeMission->payment;
		out.str("");
		out << pay;
		shouldDraw = true;
		//We want them to have the option to drop off the cargo and get paid
		text = "Drop off cargo for " + out.str() + " space bucks";
	}
	else
	{
		shouldDraw = false;//If they have a trading mission (to a planet other than this one), don't draw it
	}

}
void ListItemTradeMission::activate()
{
	//if they don't have a mission, we set one up (and if their cargo bay ain't full)
	if (game->player.tradeMission == NULL && game->player.ship.getCargoBay()->spaceLeft > 0)
	{
		accepted = true;
		game->player.setTradeMission (&mission);//This will copy the data bout this mission to the player
	}
	//if they have a mission and they are on the planet where it is to be completed
	else if (game->player.tradeMission != NULL && game->player.tradeMission->destination == game->player.landed)
	{
		game->player.ship.getCargoBay()->removeCargo (game->player.tradeMission->cargoType);
		game->player.money += game->player.tradeMission->payment;//pay them
		game->player.setTradeMission (NULL);//This'll just delete the tradeMission...right? Yeah it will.
		accepted = false;
	}
}
