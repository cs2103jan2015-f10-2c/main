//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "ParseInfo.h"

const string ParseInfo::MESSAGE_SUCCESS = "successful execution";
const string ParseInfo::TOKEN_BLANK = "";

ParseInfo::ParseInfo() {
	_mainCommand = TOKEN_BLANK;
	_index = INDEX_ZERO;
	_isValidInput = true;
}

ParseInfo::ParseInfo(string mainCommand, unsigned int index, Item item, bool isValidInput) {
	_mainCommand = mainCommand;
	_index = index;
	_item = item;
	_isValidInput = isValidInput;
}

ParseInfo::~ParseInfo() {}

string ParseInfo::setMainCommand(string text) {
	_mainCommand = text;
	return MESSAGE_SUCCESS;
}

string ParseInfo::setIndex(unsigned int index) {
	_index = index;
	return MESSAGE_SUCCESS;
}

string ParseInfo::setItem(Item item) {
	_item = item;
	return MESSAGE_SUCCESS;
}



string ParseInfo::setIsNotValidInput() {
	_isValidInput = false;
	return MESSAGE_SUCCESS;
}

string ParseInfo::getMainCommand() {
	return _mainCommand;
}

unsigned int ParseInfo::getIndex() {
	return _index;
}

Item ParseInfo::getItem() {
	return _item;
}

bool ParseInfo::hasValidInput() {
	return _isValidInput;
}

bool ParseInfo::hasMainCommand() {
	return !_mainCommand.empty();
}

bool ParseInfo::hasIndex() {
	return _index != 0;
}

bool ParseInfo::hasItem() {
	string itemName;
	itemName = _item.getItemName();

	return !itemName.empty();
}
