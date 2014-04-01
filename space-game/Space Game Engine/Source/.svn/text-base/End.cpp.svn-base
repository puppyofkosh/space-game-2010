#include "End.h"
#include "Game Class/GameClass.h"

#include <iostream>
#include <fstream>

#include "VBO/VBOExtend.h"

void end()
{
	delete game;

	#ifdef _WIN32
		_CrtDumpMemoryLeaks();//when in debug mode, this will show all leaked memory in the output from debug box.
	#endif
}