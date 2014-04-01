#pragma once

#include <string>
#include <vector>

#include "../Planet Class/PlanetClass.h"
#include "../Star Class/StarClass.h"

class SolarSystem	//The class solar system contains...
{


public:
	
	class System
	{
	public:
		std::string name;	//The name of the Planet
		std::vector<Planet*> planet;	//And some other planet thing...
		Star sun;	//And the sun.

		~System();
	};

	std::vector<System*> system;

	~SolarSystem();
};