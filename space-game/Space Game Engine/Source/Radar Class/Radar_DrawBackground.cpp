#include "RadarClass.h"

#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#endif

#include "../VBO/VBOExtend.h"


//#include "../TGAImage.h"
void Radar::drawBackground()
{

	glColor3f(1, 1, 1);

	glMatrixMode (GL_MODELVIEW);
	glEnable (GL_TEXTURE_2D);//needed to render the texture

	glEnable (GL_BLEND);//This eliminates the black background
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();//save the current matrix
	
		glTranslatef ((xCenter), (yCenter), 0);//the center of the background for the radar will be the center of the radar
		
		glRotatef (rotation, 0, 0, 1);//Now we rotate the matrix so it looks like the OBJECT has been rotated
	
		//Enable ClientStates
		glEnableClientState( GL_VERTEX_ARRAY );
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		//Activate arrays
		glBindBufferARB( GL_ARRAY_BUFFER_ARB, backgroundVBOID);
		glVertexPointer( 3, GL_FLOAT, 0, 0 );

		//vbo to hold the texture
		glBindBufferARB( GL_ARRAY_BUFFER_ARB, backgroundTextureCoordVBOID);
		//Activate texture
		glBindTexture( GL_TEXTURE_2D, backgroundTexID);
		//Assign array
		glTexCoordPointer( 2, GL_FLOAT, 0, 0 );

		glDrawArrays (GL_QUADS, 0, 12);//Render it

		//Clear ClientState
		glDisableClientState( GL_VERTEX_ARRAY );
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );

	glPopMatrix();//bring us back to the saved matrix. This makes it appear as if the object just rendered has moved.

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}