#include "ListItemClass.h"

class ListItem;

ListItem::ListItem()
{
	canBeSelected = false;
	shouldDraw = true;
}

ListItem::ListItem(std::string label)
{
	canBeSelected = false;
	text = label;
	shouldDraw = true;
}

ListItem::ListItem (std::string label, bool isSelectable)
{
	text = label;
	canBeSelected = isSelectable;
	shouldDraw = true;
}