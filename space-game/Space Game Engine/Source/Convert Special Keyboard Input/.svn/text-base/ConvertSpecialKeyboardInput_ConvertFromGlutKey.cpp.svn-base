#include "ConvertSpecialKeyboardInputClass.h"

#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

//////////////////////////////////////////
//NOTE!!
//This changes the names of the keys!
//GLUT_KEY_F1 now equals F1_KEY
//See this function for the complete list
//////////////////////////////////////////

int ConvertSpecialKeyboardInput::convertFromGlutKey(int glutKey)
{

	//will return -1 if init has not yet been called
	if (F2_KEY != 2)
	{
		return -1;
	}

	switch (glutKey)
	{
	case GLUT_KEY_F1:
		return F1_KEY;
		break;
	case GLUT_KEY_F2:
		return F2_KEY;
		break;
	case GLUT_KEY_F3:
		return F3_KEY;
		break;
	case GLUT_KEY_F4:
		return F4_KEY;
		break;
	case GLUT_KEY_F5:
		return F5_KEY;
		break;
	case GLUT_KEY_F6:
		return F6_KEY;
		break;
	case GLUT_KEY_F7:
		return F7_KEY;
		break;
	case GLUT_KEY_F8:
		return F8_KEY;
		break;
	case GLUT_KEY_F9:
		return F9_KEY;
		break;
	case GLUT_KEY_F10:
		return F10_KEY;
		break;
	case GLUT_KEY_F11:
		return F11_KEY;
		break;
	case GLUT_KEY_F12:
		return F12_KEY;
		break;
	case GLUT_KEY_LEFT:
		return LEFT_KEY;
		break;
	case GLUT_KEY_RIGHT:
		return RIGHT_KEY;
		break;
	case GLUT_KEY_UP:
		return UP_KEY;
		break;
	case GLUT_KEY_DOWN:
		return DOWN_KEY;
		break;
	case GLUT_KEY_PAGE_UP:
		return PAGE_UP_KEY;
		break;
	case GLUT_KEY_PAGE_DOWN:
		return PAGE_DOWN_KEY;
		break;
	case GLUT_KEY_HOME:
		return HOME_KEY;
		break;
	case GLUT_KEY_END:
		return END_KEY;
		break;
	case GLUT_KEY_INSERT:
		return INSERT_KEY;
		break;
	default:
		return 0;//Not found
		break;
	};



	return 0;
}
