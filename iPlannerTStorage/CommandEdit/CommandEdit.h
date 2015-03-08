//	Temporary Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Lee Joon Fai, A0108462J

#ifndef COMMAND_EDIT_H
#define COMMAND_EDIT_H

#include <string>
#include "..\UndoableCommand\UndoableCommand.h"

using namespace std;

class CommandEdit : UndoableCommand {
public:
	string executeCommand();
	string undoCommand();
};

#endif