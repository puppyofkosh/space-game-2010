
#include "RadarClass.h"

#include <stdlib.h>
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
#include "../Game Class/GameClass.h"

void Radar::draw()
{

	int xPosition;//For each different ship displayed on the radar.
	int yPosition;

//	float divisorX = (20880 - game->screenWidth)/xCenter;
//	float divisorY = (12608-game->screenHeight)/yCenter;

	float divisorX = (50000 - game->screenWidth)/xCenter;
	float divisorY = (50000-game->screenHeight)/yCenter;


	//glMatrixMode (GL_MODELVIEW);
	//glEnable (GL_TEXTURE_2D);//needed to render the texture

	//glEnable (GL_BLEND);//This eliminates the black background
//	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	xPos = ((game->screenWidth/2) - game->screenWidth)/divisorX + xCenter;//We draw the player ship in the center of the radar display
	yPos = ((game->screenHeight/2) - game->screenHeight)/divisorY + yCenter;
	xPos -= (-(game->screenWidth/2))/divisorX;//This is to make it match up with the player's position on the radar
	yPos -= (-(game->screenHeight/2))/divisorY;


	glEnable (GL_TEXTURE_2D);

	glEnable (GL_BLEND);//This eliminates the black background
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//DRAW THE PLAYER's RADAR OBJECT//
	glPushMatrix();//save the current matrix
		glColor3f (0, 0, 1);
		glTranslatef ((xPos), (yPos), 0);//
		
		//glRotatef (rotation, 0, 0, 1);//Now we rotate the matrix so it looks like the OBJECT has been rotated
	
		//Enable ClientStates
		glEnableClientState( GL_VERTEX_ARRAY );
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		//Activate arrays
		glBindBufferARB( GL_ARRAY_BUFFER_ARB, VBOID);
		glVertexPointer( 3, GL_FLOAT, 0, 0 );

		//vbo to hold the texture
		glBindBufferARB( GL_ARRAY_BUFFER_ARB, texCoordID);
		//Activate texture
		glBindTexture( GL_TEXTURE_2D, texID);
		//Assign array
		glTexCoordPointer( 2, GL_FLOAT, 0, 0 );

		glDrawArrays (GL_QUADS, 0, 12);//Render it

		//Clear ClientState
		glDisableClientState( GL_VERTEX_ARRAY );
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );

	glPopMatrix();//bring us back to the saved matrix. This makes it appear as if the object just rendered has moved.
	glDisable (GL_BLEND);
	glDisable (GL_TEXTURE_2D);

	//Now we draw all of the planets in green.
	for (int i = 0; i < game->solarSystem.system.size(); i++)
	{
		
			//Draw the star radar objects in the solar system
			xPosition = (game->solarSystem.system[i]->sun.xPos - game->screenWidth)/divisorX + xCenter;
			yPosition = (game->solarSystem.system[i]->sun.yPos - game->screenHeight)/divisorY + yCenter;
			xPosition -= (-(game->screenWidth/2))/divisorX;//This is to make it match up with the player's position on the radar
			yPosition -= (-(game->screenHeight/2))/divisorY;



			//Make sure it's within the radar display
			if (yPosition > game->screenHeight-radarHeight && xPosition > game->screenWidth-radarWidth)
			{

				//Draw the name of the planet
				glColor3f (1, 1, 1);
				game->arial10.drawString (xPosition - 10, yPosition + 10, game->solarSystem.system[i]->name);

				glEnable (GL_TEXTURE_2D);

				glEnable (GL_BLEND);//This eliminates the black background
				glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

				glPushMatrix();//save the current matrix
				
					glTranslatef ((xPosition), (yPosition), 0);//Move the camera to the position at where we'll draw it
					glColor3f (1, 1, 0);//Make it yellow
					
					glRotatef (rotation, 0, 0, 1);//Now we rotate the matrix so it looks like the OBJECT has been rotated
				
					//Enable ClientStates
					glEnableClientState( GL_VERTEX_ARRAY );
					glEnableClientState( GL_TEXTURE_COORD_ARRAY );
					//Activate arrays
					glBindBufferARB( GL_ARRAY_BUFFER_ARB, VBOID);
					glVertexPointer( 3, GL_FLOAT, 0, 0 );

					//vbo to hold the texture
					glBindBufferARB( GL_ARRAY_BUFFER_ARB, texCoordID);
					//Activate texture
					glBindTexture( GL_TEXTURE_2D, texID);
					//Assign array
					glTexCoordPointer( 2, GL_FLOAT, 0, 0 );

					glDrawArrays (GL_QUADS, 0, 12);//Render it

					//Clear ClientState
					glDisableClientState( GL_VERTEX_ARRAY );
					glDisableClientState( GL_TEXTURE_COORD_ARRAY );

				glPopMatrix();//bring us back to the saved matrix. This makes it appear as if the object just rendered has moved.
				glDisable (GL_BLEND);
				glDisable (GL_TEXTURE_2D);
			}		

		//Draw the planet's radar objects
		for (int a = 0; a < game->solarSystem.system[i]->planet.size(); a++)
		{
			xPosition = (game->solarSystem.system[i]->planet[a]->xPos - game->screenWidth)/divisorX + xCenter;
			yPosition = (game->solarSystem.system[i]->planet[a]->yPos - game->screenHeight)/divisorY + yCenter;
			xPosition -= (-(game->screenWidth/2))/divisorX;//This is to make it match up with the player's position on the radar
			yPosition -= (-(game->screenHeight/2))/divisorY;

			//Make sure it's within the radar display
			if (yPosition > game->screenHeight-radarHeight && xPosition > game->screenWidth-radarWidth)
			{

				//Draw the planet's name
				glColor3f (1, 1, 1);
				game->arial10.drawString (xPosition - 10, yPosition + 10, game->solarSystem.system[i]->planet[a]->name);

				glEnable (GL_TEXTURE_2D);

				glEnable (GL_BLEND);//This eliminates the black background
				glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

				glPushMatrix();//save the current matrix
				
					glTranslatef ((xPosition), (yPosition), 0);//Move the camera to the position at where we'll draw it
					glColor3f (0, 1, 0);
					
					glRotatef (rotation, 0, 0, 1);//Now we rotate the matrix so it looks like the OBJECT has been rotated
				
					//Enable ClientStates
					glEnableClientState( GL_VERTEX_ARRAY );
					glEnableClientState( GL_TEXTURE_COORD_ARRAY );
					//Activate arrays
					glBindBufferARB( GL_ARRAY_BUFFER_ARB, VBOID);
					glVertexPointer( 3, GL_FLOAT, 0, 0 );

					//vbo to hold the texture
					glBindBufferARB( GL_ARRAY_BUFFER_ARB, texCoordID);
					//Activate texture
					glBindTexture( GL_TEXTURE_2D, texID);
					//Assign array
					glTexCoordPointer( 2, GL_FLOAT, 0, 0 );

					glDrawArrays (GL_QUADS, 0, 12);//Render it

					//Clear ClientState
					glDisableClientState( GL_VERTEX_ARRAY );
					glDisableClientState( GL_TEXTURE_COORD_ARRAY );

				glPopMatrix();//bring us back to the saved matrix. This makes it appear as if the object just rendered has moved.
				glDisable (GL_BLEND);
				glDisable (GL_TEXTURE_2D);
			}
		}
	}

	glColor3f (1, 1, 1);//set the colour back to black
	//glDisable(GL_BLEND);
	//glDisable(GL_TEXTURE_2D);
}
/*
void Radar::draw()
{
	float divisorX = (20880 - game->screenWidth)/xCenter;
	float divisorY = (12608-game->screenHeight)/yCenter;

	glEnable (GL_TEXTURE_2D);

	xPos = ((game->screenWidth/2) - game->screenWidth)/divisorX + xCenter;//We draw the player ship in the center of the radar display
	yPos = ((game->screenHeight/2) - game->screenHeight)/divisorY + yCenter;
	xPos -= (-(game->screenWidth/2))/divisorX;//This is to make it match up with the player's position on the radar
	yPos -= (-(game->screenHeight/2))/divisorY;

	glPushMatrix();
		glTranslatef (640, 512, 0);

		glEnableClientState (GL_VERTEX_ARRAY);
		glEnableClientState (GL_TEXTURE_COORD_ARRAY);

		glBindBufferARB (GL_ARRAY_BUFFER_ARB, VBOID);
		glVertexPointer (3, GL_FLOAT, 0, 0);

		glBindBufferARB (GL_ARRAY_BUFFER_ARB, texCoordID);
		glBindTexture (GL_TEXTURE_2D, texID);
		glTexCoordPointer (2, GL_FLOAT,  0, 0);

		glDrawArrays (GL_QUADS, 0, 12);

		glDisableClientState (GL_VERTEX_ARRAY);
		glDisableClientState (GL_TEXTURE_COORD_ARRAY);

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}*/