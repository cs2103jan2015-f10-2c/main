//@author A0105180W
//	Schedule
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "History.h"

const string History::COMMAND_ADD = "ADD";
const string History::COMMAND_DELETE = "DELETE";
const string History::COMMAND_REPLACE = "REPLACE";
const string History::COMMAND_CLEAR = "CLEAR";
const string History::ERROR_ADD = "ERROR: Command and Item were not recorded.";
const string History::ERROR_EMPTYSTACKS = "ERROR: Undo has reached its limit.";
const string History::RESET_COMPLETION = "Reset completed.";

const string History::ERROR_INVALIDCOMMAND = "HISTORY::Invalid Command";

const string History::LOG_CONSTRUCTHISTORY = "HISTORY::ConstructHistory";
const string History::LOG_DESTRUCTHISTORY = "HISTORY::DestructHistory";
const string History::LOG_ITEMCOMMAND = "HISTORY::AddItemCommand";
const string History::LOG_CLEARCOMMAND = "HISTORY::AddClearCommand";
const string History::LOG_UNDOITEM = "HISTORY::UndoItemCommand";
const string History::LOG_UNDOCLEAR = "HISTORY::UndoClearCommand";
const string History::LOG_RESETHISTORY = "HISTORY::Reset\n";

//	Default Constructor
History::History() {
	_historyLogger.writeToLogFile(LOG_CONSTRUCTHISTORY);
}

//	Default Destructor
History::~History() {
	_historyLogger.writeToLogFile(LOG_DESTRUCTHISTORY);
}

//	Returns true if command is add, delete, or replace
bool History::isNormalHistoryCommand(string command) {
	try {
		if (command == COMMAND_ADD || command == COMMAND_DELETE || command == COMMAND_REPLACE) {
			return true;
		} else if (command != COMMAND_CLEAR) {
			throw ERROR_INVALIDCOMMAND;
		}
	}
	catch (string err_msg) {
		cerr << err_msg << endl;
	}
	assert(command != COMMAND_ADD);
	assert(command != COMMAND_DELETE);
	assert(command != COMMAND_REPLACE);

	return false;
}

bool History::isClearCommand(string command) {
	try {
		if (command == COMMAND_CLEAR) {
			return true;
		} else if (command != COMMAND_ADD && command != COMMAND_DELETE && command != COMMAND_REPLACE) {
			throw ERROR_INVALIDCOMMAND;
		}
	}
	catch (string err_msg) {
		cerr << err_msg << endl;
	}
	assert(command != COMMAND_CLEAR);

	return false;
}

//	Returns true if command stack is not empty
bool History::isValidUndoCall() {
	if (_commandStack.empty()) {
		return false;
	}
	
	assert(_commandStack.top() == COMMAND_ADD || _commandStack.top() == COMMAND_CLEAR || _commandStack.top() == COMMAND_REPLACE || _commandStack.top() == COMMAND_DELETE);

	return true;
}

//	Adds commands that modifies storage information (add, delete, edit)
string History::addCommand(string command, Item item) {
	if (isNormalHistoryCommand(command)) {
		_commandStack.push(command);
		_itemStack.push(item);

		assert(!_commandStack.empty());
		assert(!_itemStack.empty());

		_historyLogger.writeToLogFile(LOG_ITEMCOMMAND + command);
		return (command + item.displayItemFullDetails());
	}

	_historyLogger.writeToLogFile(LOG_ITEMCOMMAND + ERROR_ADD);
	return ERROR_ADD;
}

//	Adds clear command that cleared an entire schedule
string History::addClearCommand(vector<Item> clearedSchedule) {
	_commandStack.push(COMMAND_CLEAR);
	_scheduleStack.push(clearedSchedule);

	assert(!_commandStack.empty());
	assert(!_scheduleStack.empty());

	_historyLogger.writeToLogFile(LOG_CLEARCOMMAND);
	return COMMAND_CLEAR;
}

//	Removes commands from the item and command stack; returns item and command (both via reference)
string History::undoLastCommand(string& command, Item& latestItem, vector<Item>& lastestClearedSchedule) {
	try{
		if (isValidUndoCall()) {
			assert(!_commandStack.empty());
			command = _commandStack.top();

			if (isNormalHistoryCommand(command)) {
				assert(command == COMMAND_ADD || command == COMMAND_DELETE || command == COMMAND_REPLACE);
				assert(!_itemStack.empty());
				latestItem = _itemStack.top();
				removeUndoneCommand();

				_historyLogger.writeToLogFile(LOG_UNDOITEM + command);
				return (command + "\n" + latestItem.displayItemFullDetails());
			} else if (isClearCommand(command)) {
				assert(command == COMMAND_CLEAR);
				assert(!_scheduleStack.empty());
				lastestClearedSchedule = _scheduleStack.top();
				_commandStack.pop();
				_scheduleStack.pop();

				_historyLogger.writeToLogFile(LOG_UNDOCLEAR + command);
				return command;
			} else {
				throw ERROR_INVALIDCOMMAND;
			}
		}
	}
	catch (string err_msg) {
		cerr << err_msg << endl;
	}

	_historyLogger.writeToLogFile(LOG_UNDOITEM + ERROR_EMPTYSTACKS);
	return ERROR_EMPTYSTACKS;
}

bool History::removeUndoneCommand() {
	bool commandCompleted = false;

	assert(!_commandStack.empty());
	assert(!_itemStack.empty());
	_commandStack.pop();
	_itemStack.pop();
	commandCompleted = true;

	return commandCompleted;
}

string History::reset() {
	while (!_scheduleStack.empty()) {
		_scheduleStack.pop();
	}

	while (!_commandStack.empty()) {
		_commandStack.pop();
	}

	while (!_itemStack.empty()) {
		_itemStack.pop();
	}

	assert(_commandStack.empty());
	assert(_itemStack.empty());
	assert(_scheduleStack.empty());

	_historyLogger.writeToLogFile(LOG_RESETHISTORY);
	return RESET_COMPLETION;
}