#include <stdlib.h>//for rand() and srand()

#include "BackgroundStarClass.h"
#include "../Game Class/GameClass.h"

#include "../VBO/VBOExtend.h"

#include <time.h>//For random seed

void BackgroundStar::init(int number)
{
	star.resize(number);
	for (int i = 0; i < star.size(); i++)
	{
		star[i].xPos = rand()%game->screenWidth;	//make X position of the stars random relative to screen size
		star[i].yPos = rand()%game->screenHeight;	//make Y position of the stars random relative to screen size
		star[i].zPos = (rand()%10) + 1;				//make Z position of the stars random between 0 and 10
	}
	float vData[] = {0, 0, 0, 0, 5, 0, 1, 5, 0, 1, 0, 0};//We will move the camera to position them, so all stars can have vertices at 0, 0, 0

	//We set up the VBO here.
	glGenBuffersARB (1, &VBOID);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, VBOID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof(vData), vData, GL_DYNAMIC_DRAW_ARB);

}
