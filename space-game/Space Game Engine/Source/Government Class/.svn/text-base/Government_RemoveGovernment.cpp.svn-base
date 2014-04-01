#include "GovernmentClass.h"

void Government::removeGovernment(int p)
{
	if (p > 0 && p < gov.size()-1)
	{
		delete gov[p];
		gov.erase (gov.begin() + p);
	}
}
void Government::removeGovernment(Government::Gov *p)
{
	for (int i = 0; i < gov.size(); i++)
	{
		if (gov[i] == p)
		{
			removeGovernment (i);
			return;
		}
	}
}