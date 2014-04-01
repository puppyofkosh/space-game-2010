#include "ListClass.h"

void List::remove(ListItem* a)
{
	for (int i = 0; i < item.size(); i++)
	{
		if (item[i] == a)
		{
			remove (i);
		}
	}
}
void List::remove(int place)
{
	delete item[place];
	item.erase (item.begin() + place);
}