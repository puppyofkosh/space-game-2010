#include "GameClass.h"
#include <string>

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

/*void Game::drawString(float x, float y, void *font, std::string s)
{
	glRasterPos3f(x, y, 0); // sets the point for text at (x, y)

	for (int i = 0; i < s.length (); i++) // this goes through all characters of the apstring
	{
		glutBitmapCharacter (font, s[i]); // now, they are printed, one by one, to the window
	}
}*/