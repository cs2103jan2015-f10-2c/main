//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#ifndef HISTORY_H
#define HISTORY_H

#include <stack>
#include "Item.h"

class History {
private:
	stack <string> _commandStack;
	stack <Item> _itemStack;

public:
	string addCommand(string, Item);
	Item undoLastCommand();
};

#endif