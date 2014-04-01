//#pragma once

#include "PlayerClass.h"

#include "../Game Class/GameClass.h"

#include <iostream>
#include <math.h>

void Player::update()
{

	ship.trueX += ship.xSpeed * game->timeForDraw/game->msForFrame;//We update the truex and truey position of the player
	ship.trueY += ship.ySpeed * game->timeForDraw/game->msForFrame;

	//std::cout << "Your true x position is" << ship.trueX << std::endl;
	//std::cout << "Your true y position is" << ship.trueY << std::endl;

	const double PI = 3.1415926535;

	if (ship.rotation > 360)
	{
		ship.rotation -= 360;
	}
	if (ship.rotation < 0)
	{
		ship.rotation += 360;
	}



	//If they're in thruster mode...use a different movement scheme.
	if (ship.toggleEngine == ship.THRUSTERS)
	{
		//time based movement takes affect...
		ship.xSpeed = sin(ship.rotation*PI/180) * ship.xAcceleration;
		ship.ySpeed = -cos(ship.rotation*PI/180) * ship.yAcceleration;
	}

	//Speed limiter for thruster mode
	if (ship.toggleEngine == ship.THRUSTERS)
	{
		if (abs(ship.xAcceleration) > game->speedThresholdThruster)
		{
			if (ship.xAcceleration < 0)
			{
				ship.xAcceleration = -game->speedThresholdThruster;
			}
			else
			{
				ship.xAcceleration = game->speedThresholdThruster;
			}
		}
		if (abs(ship.yAcceleration) > game->speedThresholdThruster)
		{
			if (ship.yAcceleration < 0)
			{
				ship.yAcceleration = -game->speedThresholdThruster;
			}
			else
			{
				ship.yAcceleration = game->speedThresholdThruster;
			}
		}
	}
	

	//Speed limiter for drive mode
	if (ship.toggleEngine == ship.DRIVE)
	{
		if (abs(ship.xSpeed) > game->speedThresholdDrive)
		{
			//Keep the ships speed at the top rate, but no faster.
			if (ship.xSpeed < 0)
			{
				ship.xSpeed = -game->speedThresholdDrive;
			}
			//Make sure they keep going in the same direction
			else
			{
				ship.xSpeed = game->speedThresholdDrive;
			}
		}
		if (abs(ship.ySpeed) > game->speedThresholdDrive)
		{
			//Keep the ships speed at the top rate, but no faster.
			if (ship.ySpeed < 0)
			{
				ship.ySpeed = -game->speedThresholdDrive;
			}
			//Make sure they keep going in the same direction
			else
			{
				ship.ySpeed = game->speedThresholdDrive;
			}
		}
	}
}