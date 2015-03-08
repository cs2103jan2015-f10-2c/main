//	Temporary Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Lee Joon Fai, A0108462J

#ifndef COMMAND_DELETE_H
#define COMMAND_DELETE_H

#include <string>
#include "..\UndoableCommand\UndoableCommand.h"

using namespace std;

class CommandDelete : UndoableCommand {
public:
	string executeCommand();
	string undoCommand();
};

#endif