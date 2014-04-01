#pragma once

#ifndef SPACE_OBJECT//This is all to prevent errors incase this file is #included multiple times.

#define SPACE_OBJECT
class SpaceObject
{
public:
	float xPos;//x,y position (top left)
	float yPos;

	float width;//dimensions of the quad
	float height;

	float xSpeed;//Only for space objects, how fast the object is moving in the x direction
	float ySpeed;
	float trueX;//the "true" x position, rather than relative to the player's position
	float trueY;

	float vertices[12];//Holds the vertex data. [4 vertices * 3 points per vert  = 12]
	unsigned int VBOID; //The id number of the vbo
	unsigned int texID;//The ID number of the actual texture.
	unsigned int texCoordID; //The ID of the vbo that the texture is rendered on.
	
	float rotation;//How much to object is rotated.

	bool alpha;

	void init(char* textureFile, bool useAlpha);//initializes the vbos and starting position
	void draw();//call in display
	void update();//Call in idle function
	

	SpaceObject()
	{
		rotation = 0;
		xPos = 0;
		yPos = 0;
		width = 0;
		height = 0;
		VBOID = 0;

		xSpeed = 0;
		ySpeed = 0;
		trueX = 0;
		trueY = 0;

		alpha = false;
	}
	~SpaceObject();
};

#endif