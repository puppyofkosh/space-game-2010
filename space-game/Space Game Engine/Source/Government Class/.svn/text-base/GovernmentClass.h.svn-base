#pragma once

#include <string>
#include <vector>

class Planet;
class Government
{
public:
	class Gov
	{
	public:
		std::string name;//govt name.

		std::vector<Planet*> planet;//The planets controlled by this govt.

		//attributes that'll show up about the government
		int power;//How powerful the govt. is based on how many planets it owns.

		
		//COLORTHZ. This is the Government "color"
		float r;
		float g;
		float b;

		void addPlanet(Planet* p);//Add a planet to this government
		
		void removePlanet (Planet* p);//remove a planet from this govt's controlled planet
		void removePlanet (int p);

		Gov(std::string iName);

	};
	std::vector<Gov*> gov;
	~Government();
	Government();

	void removeGovernment(int p);
	void removeGovernment(Gov* p);
};