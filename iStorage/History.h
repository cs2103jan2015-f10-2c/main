//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#ifndef HISTORY_H
#define HISTORY_H

#include <stack>
#include "Item.h"

class History {
private:
	static const string COMMAND_ADD;
	static const string COMMAND_DELETE;
	static const string COMMAND_REPLACE;
	static const string COMMAND_CLEAR;
	static const string ERROR_ADD;
	static const string ERROR_EMPTYSTACKS;

	stack <string> _commandStack;
	stack <vector <Item>> _scheduleStack;
	stack <Item> _itemStack;

	bool isNormalHistoryCommand(string);
	bool isClearCommand(string);
	bool isValidUndoCall();

public:
	//	Default Constructor
	History();

	//	Default Destructor
	~History();

	//	Adds commands that modifies storage information (add, delete, edit)
	//	Pre:	Valid item
	//	Post:	Command is added into the command stack; item is added into the item stack
	string addCommand(string, Item);

	//	Adds clear command that cleared an entire schedule
	//	Pre:	Valid schedule
	//	Post:	Clear command is added into the command stack; cleared schedule is added into the schedule stack
	string addClearCommand(vector<Item>);

	//	Removes commands from the item and command stack; returns item and command (both via reference)
	//	Pre:	Item and command stacks are not empty
	//	Post:	Command and Item are returned via reference; success/failure message is returned
	string undoLastCommand(string&, Item&, vector<Item>&);

	//	From the item and command stack, removes the undone command (that is re-added during execution of undo)
	bool removeUndoneCommand();
};

#endif;