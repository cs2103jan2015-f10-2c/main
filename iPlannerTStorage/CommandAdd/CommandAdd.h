//	Temporary Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Lee Joon Fai, A0108462J

#ifndef COMMAND_ADD_H
#define COMMAND_ADD_H

#include <string>
#include "..\TStorageUndoableCommand\TStorageUndoableCommand.h"

using namespace std;

class CommandAdd : TStorageUndoableCommand {
public:
	string executeCommand();
	string undoCommand();
};
};

#endif