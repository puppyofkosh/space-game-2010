#include "Idle.h"

#include "Game Class/GameClass.h"
#include "Space Object Class/SpaceObjectClass.h"

#include "Player Class/PlayerClass.h"

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

#include <math.h>

void idle()
{
	//game->idleTimer += game->timeForDraw;
	//if (game->idleTimer >= 1)//so we only call it 60fps
	//{
		game->idleTimer = 0;//reset the timer


		game->handleSpecialKeyboardInput(0, 0, 0);

		if (game->gameMode == game->SPACE)
		{
			game->player.update();

			game->backgroundStar.update();//update the background stars

			//Update the solar systems
			for (int i = 0; i < game->solarSystem.system.size(); i++)
			{
				game->solarSystem.system[i]->sun.update();
				for (int a = 0; a < game->solarSystem.system[i]->planet.size(); a++)
				{
					game->solarSystem.system[i]->planet[a]->update();
				}
			}

			game->hud.toggleEngine.update();
			game->hud.toggleMap.update();
			game->hud.landButton.update();
			
		}

		if (game->gameMode == game->PAUSE)
		{
			//game->pauseMenu.pauseMenuList.update();
			//game->pauseMenu.update();
		}
		if (game->gameMode == game->LAND)
		{
			//game->landMenu.choice.update();
			game->hud.landButton.update();//If we're landed and they press l, you take off
		}

		if  (game->activeList != NULL)
		{
			game->activeList->update();
		}
	//}
	glutPostRedisplay();
}