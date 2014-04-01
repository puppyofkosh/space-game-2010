#pragma once

#include <vector>

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

#include "../Space Object Class/SpaceObjectClass.h"//Dependency problems...so you need this.
#include "../Player Class/PlayerClass.h"
#include "../Background Star Class/BackgroundStarClass.h"
#include "../Convert Special Keyboard Input/ConvertSpecialKeyboardInputClass.h"
#include "../Solar System Class/SolarSystemClass.h"
#include "../Radar Class/RadarClass.h"
#include "../HUD Class/HUDClass.h"
#include "../Map Class/MapClass.h"
#include "../Pause Menu Class/PauseMenuClass.h"
#include "../Font Class/FontClass.h"
#include "../List Class/ListClass.h"
#include "../Land Menu Class/LandMenuClass.h"
#include "../Part Class/PartClass.h"
#include "../Cargo Class/CargoClass.h"
#include "../Government Class/GovernmentClass.h"


#ifndef GAME//prevents errors should this file be included multiple times.

#define GAME
class Game
{
public:
	enum GameMode {SPACE, LAND, PAUSE, MAP};
	GameMode gameMode;
	int screenWidth;//resolution
	int screenHeight;

	std::string message;//This will be drawn no matter what in the top right hand corner of the screen.

	int msForFrame;//The amount of time it took (optimally) to draw a frame with the frame limiter on

	Font arial10;

	HUD hud;//Contains the radar display, as well as the main control panel

	Map map;

	Part part;//all the available parts

	List* activeList;//The list that will be updated.

	float sectorWidth;//The dimensions a sector will be.  50,000 is an ok number...
	float sectorHeight;

	float speedThresholdDrive;//speed the player can go using the drive before they deccelerate
	float speedThresholdThruster;//Maximum speed the player can go using thrusters

	double fuelPrice;//The price for one unit of fuel

	BackgroundStar backgroundStar;//background stars that scroll

	SolarSystem solarSystem;//Solar systems which contain a sun and planets

	Player player;//player class, contains data about the player and his/her ship
	
	Government government;//The governments in the game

	PauseMenu pauseMenu;//When the player pauses the game
	LandMenu landMenu;//When the player lands, we use this

	Cargo cargo;//All of the possible types of cargo...fish, beans, titanium alloys...

	int timeForDraw;//time it takes to draw last frame
	int newTimeForDraw;
	int idleTimer;//Timer 'til idle function is called

	ConvertSpecialKeyboardInput convertKeys;//Converts input for "special" keys

	void setup(int argc, char** argv);//Setup glut, opengl etc
	void startGame();//Begins the game (glutMainLoop())
	GLuint loadTexture (char* TexName);//loads a tga file then sets it up as a texture
	void limitFramerate();//Keeps the framerate at a certain rate.
	float getFramerate();//returns the framerate every second. OTHERWISE RETURNS -1
	void initObjects();//Initialize objects. The stars, keyboard conversion stuff, etc.
	void generateUniverse();//Will randomly generate the solar systems

	void handleKeyboardInput(unsigned char key, int x, int y);
	void handleSpecialKeyboardInput (int key, int x, int y);

	//void drawString (float x, float y, void *font, std::string s);//makes string drawing easier

	bool keyboard[256];//This contains whether or not a key is up or down. For example keyboard[97] = true
						//if the letter 'a' is pressed because it has an ascii value of 97.
	bool specialKeyboard[21];//there are only 21 "special" keys.

	~Game();

	Game();

private:

	

	int frame;//These are used by the framerate counter.
	int timePassed;
	float fps;
	int timebase;


};
extern Game * game;

#endif
