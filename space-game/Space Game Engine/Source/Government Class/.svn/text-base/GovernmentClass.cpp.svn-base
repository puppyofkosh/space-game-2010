#include "GovernmentClass.h"

class Government;

Government::Government()
{
	gov.resize(0);
}
Government::~Government()
{
	for (int i = 0; i < gov.size(); i++)
	{
		delete gov[i];
	}
}

Government::Gov::Gov(std::string iName)
{
	name = iName;
}