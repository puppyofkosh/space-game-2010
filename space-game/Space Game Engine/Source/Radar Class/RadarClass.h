#pragma once

#include "../Space Object Class/SpaceObjectClass.h"

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

class Radar : public SpaceObject
{
public:
	//Where the center of the radar will be
	float xCenter;
	float yCenter;

	float radarWidth;//width/height of the radar dsiplay
	float radarHeight;

	bool backgroundAlpha;//Whether or not the background uses alpha.

	GLuint backgroundTexID;//Texture ID of the background image
	GLuint backgroundVBOID;//The id of the background quad
	GLuint backgroundTextureCoordVBOID;//Texture coordinates of the background image
	float backgroundVertices[12];//coordinates of the background image


	void draw();
	void initBackground(char* textureFile);//Initializes the background image for the radar.
											//Alpha is on by default and the width/height are the image's
											//width and height

	void initBackground(char* textureFile, bool useAlpha, float width, float height);//if you want to specify the
																					//width and height and alpha
	void drawBackground();
};