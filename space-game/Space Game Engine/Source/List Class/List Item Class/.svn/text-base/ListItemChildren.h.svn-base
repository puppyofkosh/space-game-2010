#pragma once

#include "../../Ship Part Class/ShipPartClass.h"
#include "ListItemClass.h"
#include "../../Ship Part Class/ShipPartChildren.h"
#include "../../Trade Mission Class/TradeMissionClass.h"
#include <string>

class ListItemQuit : public ListItem {public: void activate(); //Closes the game
					ListItemQuit (std::string label);};

class ListItemSave : public ListItem {public: void activate();	//saves the game
					ListItemSave (std::string label);};

					
class ListItemLoad : public ListItem {public: void activate();	//loads a game
					ListItemLoad (std::string label);};

					
class ListItemRefuel : public ListItem {public: void activate(); //refuels and charges the player's ship
					ListItemRefuel (std::string label);};

class ListItemRepair : public ListItem {public: void activate();	//Repairs ship
					ListItemRepair (std::string label);};

class ListItemTogglePartList : public ListItem {public: void activate();//Toggles whether the list of parts will
					ListItemTogglePartList (std::string label);};		//be displayed

class ListItemBuyShipPart : public ListItem	//Allows the player to buy a part
{
public: 
	ShipPart* part;//The part that is for sale

	void activate();
	ListItemBuyShipPart (std::string label, ShipPart* iPart);
	
};

class ListItemToggleSellCargoList : public ListItem {public: void activate();
					ListItemToggleSellCargoList (std::string label);};

class ListItemSellCargoItem: public ListItem 
{
public:
	CargoBay::CargoSpace* cargoSpace;

	void activate();
	ListItemSellCargoItem (std::string label, CargoBay::CargoSpace* iItem);
};

class ListItemTradeMission : public ListItem//starts a trade mission to some random planet from the current one
{
public:
	TradeMission mission;
	bool accepted;//Whether the player accepted the mission or not

	void activate();
	void setup();

	ListItemTradeMission (std::string label);
};