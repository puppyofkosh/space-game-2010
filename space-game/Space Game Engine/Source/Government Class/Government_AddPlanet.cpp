#include "GovernmentClass.h"

void Government::Gov::addPlanet(Planet* p)
{
	planet.push_back (p);
	power += 25;
}