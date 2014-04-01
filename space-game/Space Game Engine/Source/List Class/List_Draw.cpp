#include "ListClass.h"
#include "../Game Class/GameClass.h"

void List::draw()
{
	float tempX = xPos;
	float tempY = yPos;

	if (item.size() > 0)
	{
		for (int i = 0; i < item.size(); i++)
		{
			if (item[i] != NULL && item[i]->shouldDraw == true)
			{
				if (/*selected == item[i]*/selectedSpot == i)//If the item is selected we will have it spaced out, so it sticks out
				{
					glColor3f (1, 0, 0);
					game->arial10.drawString (tempX, tempY, item[i]->text);
					glColor3f (1, 1, 1);
				}
				else//Otherwise, draw it normally
				{	
					game->arial10.drawString (tempX, tempY, item[i]->text);
				}
				tempY += game->arial10.charHeight;//Move to next line
			}
		}
	}
}