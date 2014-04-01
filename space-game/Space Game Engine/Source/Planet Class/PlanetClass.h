#pragma once

#include "../Space Object Class/SpaceObjectClass.h"
#include "../Ship Part Class/ShipPartClass.h"
#include "../Government Class/GovernmentClass.h"

#include <string>
#include <vector>

class Planet : public SpaceObject
{
public:

	float rotationSpeed;//How fast the planet rotates.

	std::string name;//The name of the planet.
	bool canLand;//Whether or not the player can land

	std::vector<ShipPart*> partForSale;//All of the available parts for sale

	Government::Gov* controllingGovernment;//The government that's in control

	Planet();

	void update();//updates the rotation, and position of the planet
};