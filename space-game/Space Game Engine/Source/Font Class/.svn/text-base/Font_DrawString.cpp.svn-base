#include "FontClass.h"

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
#include <iostream>
#include <sstream>

#include "../Game Class/GameClass.h"

void Font::drawString (float xPosition, float yPosition, std::string text)
{
	glMatrixMode (GL_MODELVIEW);
	glEnable (GL_TEXTURE_2D);//needed to render the texture

	glEnable (GL_BLEND);//This eliminates the black background
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float xOffset = 0;//Everytime a character is drawn, the next must be drawn NEXT to it, not in the same spot

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == '\n')
		{
			yPosition += charHeight;
			xOffset = 0;
		}
		if (xPosition + xOffset >= game->screenWidth-charWidth)//if the text is gonna go off the screen
		{
			xOffset = 0;
			yPosition += charHeight;
		}
		if (characters[int(text[i])] != 0)//If the image has been loaded
		{
			glPushMatrix();//save the current matrix
			
				glTranslatef ((xPosition + xOffset), (yPosition), 0);

				//Enable ClientStates
				glEnableClientState( GL_VERTEX_ARRAY );
				glEnableClientState( GL_TEXTURE_COORD_ARRAY );
				//Activate arrays
				glBindBufferARB( GL_ARRAY_BUFFER_ARB, VBOID);
				glVertexPointer( 3, GL_FLOAT, 0, 0 );

				//vbo to hold the texture
				glBindBufferARB( GL_ARRAY_BUFFER_ARB, texCoordID);
				//Activate texture
				glBindTexture( GL_TEXTURE_2D, characters[int(text[i])]);//texture it with the character being drawn's texture
				//Assign array
				glTexCoordPointer( 2, GL_FLOAT, 0, 0 );

				glDrawArrays (GL_QUADS, 0, 12);//Render it

				//Clear ClientState
				glDisableClientState( GL_VERTEX_ARRAY );
				glDisableClientState( GL_TEXTURE_COORD_ARRAY );

				xOffset += charWidth;

			glPopMatrix();//bring us back to the saved matrix. This makes it appear as if the object just rendered has moved.
		}
	}

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void Font::drawString (float xPosition, float yPosition, double num)
{
	std::stringstream out;
	out << num;
	std::string text = out.str();

	glMatrixMode (GL_MODELVIEW);
	glEnable (GL_TEXTURE_2D);//needed to render the texture

	glEnable (GL_BLEND);//This eliminates the black background
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float xOffset = 0;//Everytime a character is drawn, the next must be drawn NEXT to it, not in the same spot

	for (int i = 0; i < text.size(); i++)
	{

		if (text[i] == '\n')
		{
			yPosition += charHeight;
			xOffset = 0;
		}
		if (xPosition + xOffset >= game->screenWidth-charWidth)//if the text is gonna go off the screen
		{
			xOffset = 0;
			yPosition += charHeight;
		}
		if (characters[int(text[i])] != 0)//If the image has been loaded
		{
			glPushMatrix();//save the current matrix
			
				glTranslatef ((xPosition + xOffset), (yPosition), 0);

				//Enable ClientStates
				glEnableClientState( GL_VERTEX_ARRAY );
				glEnableClientState( GL_TEXTURE_COORD_ARRAY );
				//Activate arrays
				glBindBufferARB( GL_ARRAY_BUFFER_ARB, VBOID);
				glVertexPointer( 3, GL_FLOAT, 0, 0 );

				//vbo to hold the texture
				glBindBufferARB( GL_ARRAY_BUFFER_ARB, texCoordID);
				//Activate texture
				glBindTexture( GL_TEXTURE_2D, characters[int(text[i])]);//texture it with the character being drawn's texture
				//Assign array
				glTexCoordPointer( 2, GL_FLOAT, 0, 0 );

				glDrawArrays (GL_QUADS, 0, 12);//Render it

				//Clear ClientState
				glDisableClientState( GL_VERTEX_ARRAY );
				glDisableClientState( GL_TEXTURE_COORD_ARRAY );

				xOffset += charWidth;

			glPopMatrix();//bring us back to the saved matrix. This makes it appear as if the object just rendered has moved.
		}
	}

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}