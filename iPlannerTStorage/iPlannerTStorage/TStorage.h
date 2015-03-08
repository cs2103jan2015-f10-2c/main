//	Temporary Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Lee Joon Fai, A0108462J

#ifndef TSTORAGE_H_
#define TSTORAGE_H_

#include <string>
#include <stack>
#include <vector>
#include "..\..\iPlannerPStorage\Item\Item.h"
#include "..\CommandAdd\CommandAdd.h"
#include "..\CommandDelete\CommandDelete.h"
#include "..\CommandEdit\CommandEdit.h"
using namespace std;

class TStorage {

private:
	stack<UndoableCommand> _commandStack;
	vector<Item> _itemVector;

public:
	bool initialiseItemVector();
	void executeCommand(UndoableCommand command);
	void undoLastCommand();
};

#endif