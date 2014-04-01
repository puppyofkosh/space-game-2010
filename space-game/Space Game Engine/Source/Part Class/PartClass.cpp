#include "PartClass.h"
#include <iostream>

class Part;
Part::~Part()
{
	std::cout << "Deallocating Part data\n";
	for (int i = 0; i < engine.size(); i++)
	{
		if (engine[i] != NULL)
			delete engine[i];

		engine[i] = NULL;
	}

	for (int i = 0; i < cargoBay.size(); i++)
	{
		
		if (cargoBay[i] != NULL)
			delete cargoBay[i];

		cargoBay[i] = NULL;
	}
}