#include "BackgroundStarClass.h"

#include "../Game Class/GameClass.h"

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

#include <iostream>
#include "../VBO/VBOExtend.h"

//Making a new class called BackgroundStar; (for the stars we will draw)
class BackgroundStar;

BackgroundStar::~BackgroundStar()
{
	std::cout << "Deleting background stars\n";
	glDeleteBuffersARB (1, &VBOID);
}