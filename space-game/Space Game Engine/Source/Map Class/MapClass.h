#pragma once

#include "../Radar Class/RadarClass.h"

class Map : public Radar
{
private:
	void drawElement(float x, float y, float r, float g, float b);
public:
	void draw();

	bool isActive;//Whether or not the map is up.
};