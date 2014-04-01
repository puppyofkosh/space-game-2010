#include "FontClass.h"

class Font;

Font::Font()
{
	characters.resize (256);//256 characters.

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i] = 0;//We start by setting everything to 0 for error checking purposes later.
	}
}