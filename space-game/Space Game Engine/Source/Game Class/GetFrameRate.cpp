#include "GameClass.h"

float Game::getFramerate()
{
	frame++;
	timePassed=glutGet(GLUT_ELAPSED_TIME);
	
	if (timePassed - timebase > 1000) {
		fps = frame*1000.0/(timePassed-timebase);
	 	timebase = timePassed;		
		frame = 0;
		return fps;
	}

	return -1;//Will return framerate once per second, otherwise, return -1
}