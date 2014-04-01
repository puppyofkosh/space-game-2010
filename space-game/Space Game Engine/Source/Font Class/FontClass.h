#pragma once

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

#include <vector>
#include <string>

class Font
{
public:
	std::vector <GLuint> characters;//texture ID's of all the letters in the font
	std::string name;//name of the font

	float charWidth;//Width/height of the characters. They should all be the same.
	float charHeight;

	unsigned int VBOID;//Id of the vbo
	unsigned int texCoordID;

	void init(std::string fontName, std::string folder);
	void init (std::string fontName, std::string folder, float iCharWidth, float iCharHeight);

	void drawString (float xPosition, float yPosition, std::string text);
	void drawString (float xPosition, float yPosition, double num);

	Font();
};