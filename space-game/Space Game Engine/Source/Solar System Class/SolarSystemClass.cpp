#include "SolarSystemClass.h"
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

class SolarSystem;

SolarSystem::~SolarSystem()
{
	for (int i = 0; i < system.size(); i++)
	{
		delete system[i];
	}
}

SolarSystem::System::~System()
{
	for (int i = 0; i < planet.size(); i++)
	{
		delete planet[i];
	}
}