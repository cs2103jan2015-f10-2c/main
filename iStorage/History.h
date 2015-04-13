//author A0105180W
//	Permanent Storage
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#ifndef HISTORY_H
#define HISTORY_H

#include <stack>
#include "..\iPlanner Log\Log.h"
#include "Item.h"

class History {
private:
	Log _historyLogger;

	static const string COMMAND_ADD;
	static const string COMMAND_DELETE;
	static const string COMMAND_REPLACE;
	static const string COMMAND_CLEAR;
	static const string RESET_COMPLETION;
	static const string ERROR_ADD;
	static const string ERROR_EMPTYSTACKS;
	
	static const string ERROR_INVALIDCOMMAND;

	static const string LOG_CONSTRUCTHISTORY;
	static const string LOG_DESTRUCTHISTORY;
	static const string LOG_ITEMCOMMAND;
	static const string LOG_CLEARCOMMAND;
	static const string LOG_UNDOITEM;
	static const string LOG_UNDOCLEAR;
	static const string LOG_RESETHISTORY;

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
	//	Pre:	Nil
	//	Post:	Pops the top item in the command stack and the item stack
	bool removeUndoneCommand();

	//	Resets the schedule; empties all stack
	//	Pre:	Nil
	//	Post:	All stacks are emptied; confirmation string returned
	string reset();
};

#endif;