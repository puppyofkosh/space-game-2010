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

#include "SpaceObjectClass.h"
#include "../VBO/VBOExtend.h"

#include <iostream>

//class SpaceObject;

SpaceObject::~SpaceObject()
{
	std::cout << "Deleting Object...\n";
	glDeleteBuffersARB (1, &VBOID);
	glDeleteBuffersARB (1, &texCoordID);
	glDeleteTextures (1, &texID);
}