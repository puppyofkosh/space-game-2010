#include "GovernmentClass.h"

void Government::Gov::removePlanet (int p)
{
	if (p > 0 && p < planet.size()-1)//make sure it actually exists 
	{
		planet.erase (planet.begin() + p);//remove the planet from the array. Deallocating it is a bad idea
										//as it still has to be used by the game and will be deallocated by the
										//solar system class
	}
}
void Government::Gov::removePlanet(Planet *p)
{
	for (int i = 0; i < planet.size(); i++)
	{
		if (planet[i] == p)
		{
			removePlanet (i);
			return;
		}
	}
}