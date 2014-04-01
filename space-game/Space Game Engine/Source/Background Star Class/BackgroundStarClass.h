#ifndef BACKGROUND_STAR

#include <vector>

#define BACKGROUND_STAR
class BackgroundStar
{
	class StarClassTemp
	{
	public:
		float xPos;
		float yPos;
		float zPos;
	};

public:
	//coordinates that the star has
	std::vector <StarClassTemp> star;

	unsigned int VBOID;//Weird VBO stuff that only Ian really understands.

	//Initialize, draw, and update the stars on the screen.
	void init(int number);//create the specified amount of background stars
	void draw();
	void update();

	~BackgroundStar();
};
#endif