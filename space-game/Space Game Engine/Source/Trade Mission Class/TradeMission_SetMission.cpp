#include "TradeMissionClass.h"

#include <Math.h>
void TradeMission::setMission(Planet* start, Planet* end, int iAmount, Cargo::CargoItem* type)
{
	cargoType = type;
	amount = iAmount;
	source = start;
	destination = end;
	//calculate the distance between the two planets.
	distance = sqrt ((start->xPos - end->xPos)*(start->xPos - end->xPos) + (start->yPos - end->yPos)*(start->yPos - end->yPos));
	payment = distance * 0.1*amount;
	isCompleted = false;
}