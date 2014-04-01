#include "GameClass.h"

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

void Game::handleSpecialKeyboardInput (int key, int x, int y)//Handles input for "fly around" mode
{
	float shipSpeed;
	if (player.ship.getEngine() != NULL)
	{
		shipSpeed = player.ship.getEngine()->force/player.ship.mass;//F = ma. a = f/m
	}
	else
	{
		shipSpeed = 0;
	}
	float fuelEfficiency = player.ship.getEngine()->efficiency;
	float shipRotationSpeed = 3;

	const double PI = 3.1415926535;//We need this b/c the sin function takes radians.

	/*switch (key)
	{
	case GLUT_KEY_UP:
		player.ship.xAcceleration = sin(player.ship.rotation*PI/180) * shipSpeed;//this is  so it moves forward relative to
																		  //the rotation of the ship
		player.ship.yAcceleration = -(cos (player.ship.rotation*PI/180)) * shipSpeed;

		player.ship.xSpeed += player.ship.xAcceleration;//Now we increment the x/y speeds
		player.ship.ySpeed += player.ship.yAcceleration;
		break;
	case GLUT_KEY_DOWN:
		player.ship.xAcceleration = sin(player.ship.rotation*PI/180) * shipSpeed;
		player.ship.yAcceleration = -(cos (player.ship.rotation*PI/180)) * shipSpeed;

		player.ship.xSpeed -= player.ship.xAcceleration;
		player.ship.ySpeed -= player.ship.yAcceleration;
		break;
	case GLUT_KEY_LEFT:
		player.ship.rotation -= shipRotationSpeed;//turn the ship
		break;

	case GLUT_KEY_RIGHT:
		player.ship.rotation += shipRotationSpeed;
		break;


	};*/

	if (gameMode == SPACE)
	{

		//Drive control
		if (player.ship.toggleEngine == player.ship.DRIVE)
		{
			//we subtract 1 because convertKeys will give a value of 1-21. We need a value between 0 and 20.
			if (specialKeyboard[convertKeys.UP_KEY - 1] == true && player.ship.fuel > 0 && specialKeyboard[convertKeys.DOWN_KEY - 1] == false)
			{		//if the up key is being pressed and they have enough fuel and the down key is not being pressed
			
				player.ship.xAcceleration = sin(player.ship.rotation*PI/180) * shipSpeed;//this is  so it moves forward relative to
																				  //the rotation of the ship
				player.ship.yAcceleration = -(cos (player.ship.rotation*PI/180)) * shipSpeed;

				player.ship.xSpeed += player.ship.xAcceleration * game->timeForDraw/game->msForFrame;//Now we increment the x/y speeds
				player.ship.ySpeed += player.ship.yAcceleration * game->timeForDraw/game->msForFrame;

				player.ship.fuel -= (1/fuelEfficiency)*game->timeForDraw/game->msForFrame;//Decrease the fuel in the player's tank
			}

			//If the down key is pressed and they have fuel
			if (specialKeyboard[convertKeys.DOWN_KEY - 1] == true && player.ship.fuel > 0 && specialKeyboard[convertKeys.UP_KEY - 1] == false)
			{		//if the down key is pressed but the upkey is not
				player.ship.xAcceleration = sin(player.ship.rotation*PI/180) * shipSpeed;
				player.ship.yAcceleration = -(cos (player.ship.rotation*PI/180)) * shipSpeed;

				player.ship.xSpeed -= player.ship.xAcceleration * game->timeForDraw/game->msForFrame;
				player.ship.ySpeed -= player.ship.yAcceleration * game->timeForDraw/game->msForFrame;

				player.ship.fuel -= (1/fuelEfficiency)*game->timeForDraw/game->msForFrame;//Decrease the fuel in the player's tank
			}
			//if both the up and down keys are being pressed, we stop the ship
			if (specialKeyboard[convertKeys.UP_KEY - 1] == true && specialKeyboard[convertKeys.DOWN_KEY - 1] == true && player.ship.fuel > 0)
			{
				player.ship.xSpeed = 0;//stop the ship
				player.ship.ySpeed = 0;
				player.ship.fuel --;
			}

			if (specialKeyboard[convertKeys.LEFT_KEY - 1] == true)
			{
				player.ship.rotation -= shipRotationSpeed * game->timeForDraw/game->msForFrame;//turn the ship
				//also uses time based movement
			}

			if (specialKeyboard[convertKeys.RIGHT_KEY - 1] == true)
			{
				player.ship.rotation += shipRotationSpeed * game->timeForDraw/game->msForFrame;
			}
		}

		//Thruster control
		else if (player.ship.toggleEngine == player.ship.THRUSTERS)
		{

			if (specialKeyboard[convertKeys.UP_KEY - 1] == true && player.ship.fuel > 0)
			{
				player.ship.xAcceleration += shipSpeed * game->timeForDraw/game->msForFrame;
				player.ship.yAcceleration += shipSpeed * game->timeForDraw/game->msForFrame;

				player.ship.fuel -= (1/fuelEfficiency)*game->timeForDraw/game->msForFrame;//Decrease the fuel in the player's tank
			}
					//If they press down (in thruster mode) and aren't going too slow, and have the fuel
			if (specialKeyboard[convertKeys.DOWN_KEY - 1] == true && player.ship.xAcceleration > -1 
																&& player.ship.yAcceleration > -1
																&& player.ship.fuel > 0)
			{
				player.ship.xAcceleration -= shipSpeed * game->timeForDraw/game->msForFrame;
				player.ship.yAcceleration -= shipSpeed * game->timeForDraw/game->msForFrame;

				player.ship.fuel -= (1/fuelEfficiency)*game->timeForDraw/game->msForFrame;//Decrease the fuel in the player's tank
			}
			if (specialKeyboard[convertKeys.LEFT_KEY - 1] == true && player.ship.fuel > 0)
			{

				player.ship.fuel -= 0.05*(1/fuelEfficiency)*game->timeForDraw/game->msForFrame;//Decrease the fuel in the tank

				player.ship.rotation -= shipRotationSpeed * game->timeForDraw/game->msForFrame;//turn the ship
			}

			if (specialKeyboard[convertKeys.RIGHT_KEY - 1] == true && player.ship.fuel > 0)
			{
				
				player.ship.fuel -= 0.05*(1/fuelEfficiency)*game->timeForDraw/game->msForFrame;//Decrease the fuel in the tank

				player.ship.rotation += shipRotationSpeed * game->timeForDraw/game->msForFrame;
			}
		}
	}

}