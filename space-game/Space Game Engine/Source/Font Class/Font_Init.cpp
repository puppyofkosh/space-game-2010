#include "FontClass.h"

#include <fstream>
#include <sstream>
#include <iostream>

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

void Font::init(std::string fontName, std::string folder)
{
	name = fontName;

	std::fstream infile;
	std::stringstream out;

	std::string folderToOpen;


	for (int i = 0; i < characters.size(); i++)
	{
		folderToOpen = folder;
		folderToOpen += '/';
		folderToOpen += name;

		out << i;
		folderToOpen += out.str();
		folderToOpen += ".tga";

		infile.open (folderToOpen.c_str(), std::ios::in);
		
		if (infile.is_open())
		{
			std::cout << "loading" << folderToOpen << std::endl;
			characters[i] = game->loadTexture ((char*)folderToOpen.c_str());
			glBindTexture (GL_TEXTURE_2D, characters[i]);
		}
		infile.close();
		out.str(std::string());//clear the string
	}
	
	
	glGetTexLevelParameterfv (GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &charWidth);//we get the dimensions of the image
	glGetTexLevelParameterfv (GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &charHeight);  

	float vertices[] = {-charWidth/2, -charHeight/2, 0, charWidth/2, -charHeight/2, 0, charWidth/2, charHeight/2, 0, -charWidth/2, charHeight/2, 0};

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
}

void Font::init (std::string fontName, std::string folder, float iCharWidth, float iCharHeight)
{
	name = fontName;

	charWidth = iCharWidth;
	charHeight = iCharHeight;

	std::fstream infile;
	std::stringstream out;

	std::string folderToOpen;

	for (int i = 0; i < characters.size(); i++)
	{
		folderToOpen = folder;
		folderToOpen += '/';
		folderToOpen += name;

		out << i;
		folderToOpen += out.str();
		folderToOpen += ".tga";

		infile.open (folderToOpen.c_str(), std::ios::in);
		
		if (infile.is_open())
		{
			std::cout << "loading" << folderToOpen << std::endl;
			characters[i] = game->loadTexture ((char*)folderToOpen.c_str());
			glBindTexture (GL_TEXTURE_2D, characters[i]);
		}
		infile.close();
		out.str(std::string());//clear the string
	}
	
	float vertices[] = {-charWidth/2, -charHeight/2, 0, charWidth/2, -charHeight/2, 0, charWidth/2, charHeight/2, 0, -charWidth/2, charHeight/2, 0};

	GLfloat textureCoords[] = {0, 0,		//basically to bind the texture to the object. No changes necessary.
							   1, 0,
							   1, 1,
						       0, 1};

	

	glGenBuffersARB (1, &texCoordID);
	glBindBufferARB (GL_ARRAY_BUFFER_ARB, texCoordID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof (textureCoords), textureCoords, GL_DYNAMIC_DRAW_ARB); 

	//We set up the VBO here.
	glGenBuffersARB (1, &VBOID);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, VBOID);
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, sizeof(vertices), vertices, GL_DYNAMIC_DRAW_ARB);
}