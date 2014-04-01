#include "ConvertSpecialKeyboardInputClass.h"

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif


//////////////////////////////////////////
//NOTE!!
//This changes the names of the keys!
//GLUT_KEY_F1 now equals F1_KEY
//See this function for the complete list
//////////////////////////////////////////

int ConvertSpecialKeyboardInput::convertToGlutKey(unsigned int key)
{

	if (F2_KEY != 2)//Constructor has not been called, return -1
	{
		return -1;
	}

	if (key == F1_KEY)
		return GLUT_KEY_F1;
	
	if (key == F2_KEY)
		return GLUT_KEY_F2;
		
	if (key == F3_KEY)
		return GLUT_KEY_F3;
		
	if (key == F4_KEY)
		return GLUT_KEY_F4;
		
	if (key == F5_KEY)
		return GLUT_KEY_F5;
		
	if (key == F6_KEY)
		return GLUT_KEY_F6;
		
	if (key == F7_KEY)
		return GLUT_KEY_F7;
		
	if (key == F8_KEY)
		return GLUT_KEY_F8;
		
	if (key == F9_KEY)
		return GLUT_KEY_F9;
		
	if (key == F10_KEY)
		return GLUT_KEY_F10;
		
	if (key == F11_KEY)
		return GLUT_KEY_F11;
		
	if (key == F12_KEY)
		return GLUT_KEY_F12;
		
	if (key == LEFT_KEY)
		return GLUT_KEY_LEFT;
		
	if (key == RIGHT_KEY)
		return GLUT_KEY_RIGHT;
		
	if (key == UP_KEY)
		return GLUT_KEY_UP;
		
	if (key == DOWN_KEY)
		return GLUT_KEY_DOWN;
		
	if (key == PAGE_UP_KEY)
		return GLUT_KEY_PAGE_UP;
		
	if (key == PAGE_DOWN_KEY)
		return GLUT_KEY_PAGE_DOWN;
		
	if (key == HOME_KEY)
		return GLUT_KEY_HOME;
		
	if (key == END_KEY)
		return GLUT_KEY_END;
		
	if (key == INSERT_KEY)
		return GLUT_KEY_INSERT;


	else
		return 0;//No clue what they sent.
		

}