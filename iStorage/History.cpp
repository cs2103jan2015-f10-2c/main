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

//	Default Constructor
History::History() {}

//	Default Destructor
History::~History() {}

//	Returns true if command is add, delete, or replace
bool History::isNormalHistoryCommand(string command) {
	if (command == COMMAND_ADD || command == COMMAND_DELETE || command == COMMAND_REPLACE) {
		return true;
	}

	return false;
}

bool History::isClearCommand(string command) {
	if (command == COMMAND_CLEAR) {
		return true;
	}

	return false;
}

//	Returns true if command and item stacks are both not empty
bool History::isValidUndoCall() {
	if (_commandStack.empty()) {
		return false;
	}
	return true;
}

//	Adds commands that modifies storage information (add, delete, edit)
string History::addCommand(string command, Item item) {
	if (isNormalHistoryCommand(command)) {
		_commandStack.push(command);
		_itemStack.push(item);

		return (command + item.displayItemFullDetails());
	}

	return ERROR_ADD;
}

//	Adds clear command that cleared an entire schedule
string History::addClearCommand(vector<Item> clearedSchedule) {
	_commandStack.push(COMMAND_CLEAR);
	_scheduleStack.push(clearedSchedule);

	return COMMAND_CLEAR;
}

//	Removes commands from the item and command stack; returns item and command (both via reference)
string History::undoLastCommand(string& command, Item& latestItem, vector<Item>& lastestClearedSchedule) {
	if (isValidUndoCall()) {
		command = _commandStack.top();

		if (isNormalHistoryCommand(command)) {
			latestItem = _itemStack.top();
			removeUndoneCommand();
		} else if (isClearCommand(command)) {
			lastestClearedSchedule = _scheduleStack.top();
			_commandStack.pop();
			_scheduleStack.pop();
		}

		return (command + "\n" + latestItem.displayItemFullDetails());
	}

	return ERROR_EMPTYSTACKS;
}

bool History::removeUndoneCommand() {
	bool commandCompleted = false;

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

	return RESET_COMPLETION;
}