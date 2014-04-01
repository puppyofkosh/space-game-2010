//THIS IS TO CONVERT THE SPECIAL GLUT INPUT (Upkey, downkey, leftkey, rightkey etc) into my version of that
//input. Unfortunately, glut's key numbers do not go in order, for example
//GLUT_KEY_F1 = 1
//GLUT_KEY_UP = 101 or something
//This makes them go in order, so 
//KEY_UP will be 13


#ifndef CONVERT_SPECIAL_KEYBOARD_INPUT

#define CONVERT_SPECIAL_KEYBOARD_INPUT
class ConvertSpecialKeyboardInput
{
public:

	unsigned int F1_KEY;
	unsigned int F2_KEY;
	unsigned int F3_KEY;
	unsigned int F4_KEY;
	unsigned int F5_KEY;
	unsigned int F6_KEY;
	unsigned int F7_KEY;
	unsigned int F8_KEY;
	unsigned int F9_KEY;
	unsigned int F10_KEY;
	unsigned int F11_KEY;
	unsigned int F12_KEY;
	unsigned int UP_KEY;
	unsigned int DOWN_KEY;
	unsigned int LEFT_KEY;
	unsigned int RIGHT_KEY;
	unsigned int PAGE_UP_KEY;
	unsigned int PAGE_DOWN_KEY;
	unsigned int HOME_KEY;
	unsigned int END_KEY;
	unsigned int INSERT_KEY;

	int convertFromGlutKey(int glutKey);//returns the converted key FROM what glut gave you
	int convertToGlutKey(unsigned int key);//Returns the equivalent of what glut would give you
	void init();//initiates all values.

};
#endif