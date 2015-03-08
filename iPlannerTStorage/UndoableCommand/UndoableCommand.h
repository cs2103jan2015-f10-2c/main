//	Temporary Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Lee Joon Fai, A0108462J

#ifndef UNDOABLE_COMMAND_H
#define UNDOABLE_COMMAND_H

#include <string>

using namespace std;

class UndoableCommand {
public:
	virtual string executeCommand();
	virtual string undoCommand();
};

#endif