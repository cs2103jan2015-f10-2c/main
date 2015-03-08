//	Temporary Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Lee Joon Fai, A0108462J

#ifndef T_STORAGE_UNDOABLE_COMMAND_H
#define T_STORAGE_UNDOABLE_COMMAND_H

#include <string>

using namespace std;

class TStorageUndoableCommand {
public:
	virtual string executeCommand();
	virtual string undoCommand();
};



class CommandDelete : TStorageUndoableCommand {
public:
	string executeCommand();
	string undoCommand();
};

class CommandEdit : TStorageUndoableCommand {
public:
	string executeCommand();
	string undoCommand();
};

#endif