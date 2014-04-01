#pragma once

#include "../Space Object Class/SpaceObjectClass.h"

class Button: public SpaceObject
{
protected:
	bool previousKeyValue;//This is so the thruster/drive will toggle only when the key has been released
	
public:
	int keyValue;//The value of the key that will activate the action function if it is pressed

	void update();
	virtual void activate();//This is virtual because this function is overloaded in classes that inherit from
							//This one. When this is called in the update function, it will decide at runtime
							//Which one to call.



	Button();
};