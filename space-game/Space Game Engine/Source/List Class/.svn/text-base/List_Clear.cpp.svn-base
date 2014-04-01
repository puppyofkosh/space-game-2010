#include "ListClass.h"

void List::clear(bool deleteContents)//Will resize the array to 0 and if deleteContents = true, it will delete
{										//Everything in the array
	if (deleteContents)
	{
		for (int i = 0; i < item.size(); i++)
		{
			delete item[i];
		}
	}
	item.resize(0);
}