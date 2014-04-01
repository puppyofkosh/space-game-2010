#include "PlayerClass.h"

void Player::setTradeMission(TradeMission *t)
{

	delete tradeMission;//get rid of the old one.
	tradeMission = NULL;
	if (t != NULL)
	{
		tradeMission = new TradeMission;
		tradeMission->setMission (t->source, t->destination, t->amount, t->cargoType);
		ship.getCargoBay()->addCargo (tradeMission->cargoType, tradeMission->amount);
		//so the radar will show where the planet is
		destinationXPos = tradeMission->destination->xPos + ship.trueX;
		destinationYPos = tradeMission->destination->yPos + ship.trueY;
	}
}