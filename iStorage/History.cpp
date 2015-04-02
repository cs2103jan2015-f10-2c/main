//	Schedule
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "History.h"

const string History::COMMAND_ADD = "ADD";
const string History::COMMAND_DELETE = "DELETE";
const string History::COMMAND_REPLACE = "REPLACE";
const string History::ERROR_ADD = "ERROR: Command and Item were not recorded.";
const string History::ERROR_EMPTYSTACKS = "ERROR: Undo has reached its limit.";

//	Default Constructor
History::History() {}

//	Default Destructor
History::~History() {}

bool History::isValidHistoryCommand(string command) {
	if (command == COMMAND_ADD || command == COMMAND_DELETE || command == COMMAND_REPLACE) {
		return true;
	}

	return false;
}

string History::addCommand(string command, Item item) {
	if (isValidHistoryCommand(command)) {
		_commandStack.push(command);
		_itemStack.push(item);

		return (command + item.displayItemFullDetails());
	}

	return ERROR_ADD;
}

bool History::isValidUndoCall() {
	if (_commandStack.empty() || _itemStack.empty()) {
		return false;
	}
	return true;
}

string History::undoLastCommand(string& command, Item& latestItem) {
	if (isValidUndoCall()) {
		return ERROR_EMPTYSTACKS;
	} else {
		command = _commandStack.top();
		_commandStack.pop();

		latestItem = _itemStack.top();
		_itemStack.pop();

		return (command + latestItem.displayItemFullDetails());
	}
}