#include "../Game Class/GameClass.h"

#include "BackgroundStarClass.h"

#include "../VBO/VBOExtend.h"

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif
#ifdef __linux__
#include <GL/glext.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#endif
#ifdef _WIN32
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#endif



void BackgroundStar::draw()
{
	//glMatrixMode (GL_MODELVIEW);

	glColor3f (1, 1, 1);	//Set the color of the stars to white

	for (int i = 0; i < star.size(); i++)
	{
		glPushMatrix();//save the current matrix

			glTranslatef ((star[i].xPos), (star[i].yPos), 0);//Move the drawing position to the X and Y position of your screen. 
											//xPos and yPos are declared in BackGroundStar_Init.cpp
			//Enable ClientStates
			glEnableClientState( GL_VERTEX_ARRAY );
			//Activate arrays
			glBindBufferARB( GL_ARRAY_BUFFER_ARB, VBOID);
			glVertexPointer( 3, GL_FLOAT, 0, 0 );

			glDrawArrays (GL_POINTS, 0, 1);//Render the star, 3 points.

			//Clear ClientState
			glDisableClientState( GL_VERTEX_ARRAY );

		glPopMatrix();//bring us back to the saved matrix. This makes it appear as if the object just rendered has moved.
	}
	glColor3f (1, 1, 1); //Set the color to white again.
}