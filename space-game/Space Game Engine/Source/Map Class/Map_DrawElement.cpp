#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#define NO_VBOS
#endif
#ifdef _WIN32
#include <windows.h> // these two header files are needed to compile a program in OpenGL with GLUT
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif
#ifdef __linux__
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#define NO_VBOS
#endif 

#include "../VBO/VBOExtend.h"
#include "../Game Class/GameClass.h"

#include "MapClass.h"

void Map::drawElement (float x, float y, float r, float g, float b)
{
	//DRAW THE PLAYER's RADAR OBJECT//
	glPushMatrix();//save the current matrix
	
		glColor3f (r, g, b);
		glTranslatef ((x), (y), 0);//
		glScalef (2, 2, 1);
	
		//Enable ClientStates
		glEnableClientState( GL_VERTEX_ARRAY );
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		//Activate arrays
		glBindBufferARB( GL_ARRAY_BUFFER_ARB, VBOID);
		glVertexPointer( 3, GL_FLOAT, 0, 0 );

		//vbo to hold the texture
		glBindBufferARB( GL_ARRAY_BUFFER_ARB, texCoordID);
		//Activate texture
		glBindTexture( GL_TEXTURE_2D, texID);
		//Assign array
		glTexCoordPointer( 2, GL_FLOAT, 0, 0 );

		glDrawArrays (GL_QUADS, 0, 12);//Render it

		//Clear ClientState
		glDisableClientState( GL_VERTEX_ARRAY );
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );

	glPopMatrix();//bring us back to the saved matrix. This makes it appear as if the object just rendered has moved.

}