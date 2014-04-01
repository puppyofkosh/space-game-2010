#include "SpaceObjectClass.h"
#include "../Game Class/GameClass.h"

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

#include "../TGAImage.h"

#include <iostream>

void SpaceObject::init(char* textureFile, bool useAlpha)// a width and height need to be loaded before this is called.
{

	alpha = useAlpha;

	texID = game->loadTexture (textureFile);
	glBindTexture (GL_TEXTURE_2D, texID);
	
	glGetTexLevelParameterfv (GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);//we get the dimensions of the image
	glGetTexLevelParameterfv (GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);  

	float vData[] = {-width/2, -height/2, 0, width/2, -height/2, 0, width/2, height/2, 0, -width/2, height/2, 0};
	memcpy (vertices, vData, 12*sizeof(float));

	GLfloat textureCoords[] = {0, 0,		//basically to bind the texture to the object. No changes necessary.
							   1, 0,
							   1, 1,
						       0, 1};

	

	glGenBuffersARB (1, &texCoordID);
	glBindBufferARB (GL_ARRAY_BUFFER_ARB, texCoordID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof (textureCoords), textureCoords, GL_DYNAMIC_DRAW_ARB); 
	//glBufferSubDataARB (GL_ARRAY_BUFFER_ARB, 0, sizeof(textureCoords), textureCoords);

	//We set up the VBO here.
	glGenBuffersARB (1, &VBOID);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, VBOID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof(vertices), vertices, GL_DYNAMIC_DRAW_ARB);
	//glBufferSubDataARB (GL_ARRAY_BUFFER_ARB, 0, sizeof(vertices), vertices); //vertices ended

	//Set up the trueX/trueY position variables
	trueX = xPos-game->screenWidth/2;
	trueY = yPos-game->screenHeight/2;
}