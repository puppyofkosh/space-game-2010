#pragma once
#include <vector>

#include "../Ship Part Class/ShipPartChildren.h"

using std::vector;


//This class holds ALL OF THE POSSIBLE parts your ship can ever get.
class Part
{
public:
	vector<Engine*> engine;
	vector<CargoBay*> cargoBay;

	~Part();
};