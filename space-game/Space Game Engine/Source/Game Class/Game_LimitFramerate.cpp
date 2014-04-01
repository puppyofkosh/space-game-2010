#include "GameClass.h"

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include <iostream>

void Game::limitFramerate()
{
	     //check current time against last time
     //run empty while loop while this time is less than whatever framerate you want
     //then set the last time equal to current time
    
	int prevtime = 0;

	//curtime = glutGet (GLUT_ELAPSED_TIME);
	prevtime = glutGet (GLUT_ELAPSED_TIME);

	while (glutGet(GLUT_ELAPSED_TIME) - prevtime < 15);
}