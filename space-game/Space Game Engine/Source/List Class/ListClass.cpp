#include "ListClass.h"

class List;

List::List()
{
	selectedSpot = -1;
	item.resize(0);
}

List::~List()
{
		for (int i = 0; i < item.size(); i++)
		{
			delete item[i];
		}
	
}
