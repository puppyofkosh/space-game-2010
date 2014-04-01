#include "RadarClass.h"

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



void Radar::initBackground(char* textureFile)// a width and height need to be loaded before this is called.
{
	backgroundAlpha = true;

	backgroundTexID = game->loadTexture (textureFile);
	glBindTexture (GL_TEXTURE_2D, backgroundTexID);
	
	glGetTexLevelParameterfv (GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &radarWidth);//we get the dimensions of the image
	glGetTexLevelParameterfv (GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &radarHeight);  

	float vData[] = {-radarWidth/2, -radarHeight/2, 0, radarWidth/2, -radarHeight/2, 0, radarWidth/2, radarHeight/2, 0, -radarWidth/2, radarHeight/2, 0};
	memcpy (backgroundVertices, vData, 12*sizeof(float));

	GLfloat textureCoords[] = {0, 0,		//basically to bind the texture to the object. No changes necessary.
							   1, 0,
							   1, 1,
						       0, 1};

	
	//bind the texture coords to a vbo
	glGenBuffersARB (1, &backgroundTextureCoordVBOID);
	glBindBufferARB (GL_ARRAY_BUFFER_ARB, backgroundTextureCoordVBOID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof (textureCoords), textureCoords, GL_DYNAMIC_DRAW_ARB); 
	//glBufferSubDataARB (GL_ARRAY_BUFFER_ARB, 0, sizeof(textureCoords), textureCoords);

	//bind the quad to a vbo
	glGenBuffersARB (1, &backgroundVBOID);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, backgroundVBOID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof(backgroundVertices), backgroundVertices, GL_DYNAMIC_DRAW_ARB);
	//glBufferSubDataARB (GL_ARRAY_BUFFER_ARB, 0, sizeof(vertices), vertices); //vertices ended
}

void Radar::initBackground(char *textureFile, bool useAlpha, float iWidth, float iHeight)
{
	backgroundTexID = game->loadTexture (textureFile);
	glBindTexture (GL_TEXTURE_2D, backgroundTexID);
	
	radarWidth = iWidth;
	radarHeight = iHeight;
	backgroundAlpha = useAlpha;

	float vData[] = {-radarWidth/2, -radarHeight/2, 0, radarWidth/2, -radarHeight/2, 0, radarWidth/2, radarHeight/2, 0, -radarWidth/2, radarHeight/2, 0};
	memcpy (backgroundVertices, vData, 12*sizeof(float));

	GLfloat textureCoords[] = {0, 0,		//basically to bind the texture to the object. No changes necessary.
							   1, 0,
							   1, 1,
						       0, 1};

	//bind the texture coords to a vbo
	glGenBuffersARB (1, &backgroundTextureCoordVBOID);
	glBindBufferARB (GL_ARRAY_BUFFER_ARB, backgroundTextureCoordVBOID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof (textureCoords), textureCoords, GL_DYNAMIC_DRAW_ARB); 
	//glBufferSubDataARB (GL_ARRAY_BUFFER_ARB, 0, sizeof(textureCoords), textureCoords);

	//bind the quad to a vbo
	glGenBuffersARB (1, &backgroundVBOID);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, backgroundVBOID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof(backgroundVertices), backgroundVertices, GL_DYNAMIC_DRAW_ARB);
	//glBufferSubDataARB (GL_ARRAY_BUFFER_ARB, 0, sizeof(vertices), vertices); //vertices ended
}