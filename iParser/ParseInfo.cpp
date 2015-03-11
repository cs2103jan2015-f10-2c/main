//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "ParseInfo.h"

const string ParseInfo::MESSAGE_SUCCESS = "successful execution";
const string ParseInfo::TOKEN_BLANK = "";

ParseInfo::ParseInfo() {
	_command = TOKEN_BLANK;
	_index = INDEX_ZERO;	
	_isValidInput = true;
	_hasCommand = false;
}

ParseInfo::~ParseInfo() {}

string ParseInfo::setCommand(string text) {
	_command = text;
	setHasCommand();
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

string ParseInfo::setTokens(COMMAND_AND_TEXT token) {
	_tokens.push_back(token);
	return MESSAGE_SUCCESS;
}

string ParseInfo::setIsNotValidInput() {
	_isValidInput = false;
	return MESSAGE_SUCCESS;
}

string ParseInfo::setHasCommand() {
	_hasCommand = true;
	return MESSAGE_SUCCESS;
}

string ParseInfo::getCommand() {
	return _command;
}

unsigned int ParseInfo::getIndex() {
	return _index;
}

Item ParseInfo::getItem() {
	return _item;
}

list<COMMAND_AND_TEXT> ParseInfo::getTokens() {
	return _tokens;
}

bool ParseInfo::getIsValidInput() {
	return _isValidInput;
}

bool ParseInfo::getHasCommand() {
	return _hasCommand;
}

bool ParseInfo::getHasIndex() {
	return _index != 0;
}

bool ParseInfo::getHasItem() {
	string itemName;
	itemName = _item.getItemName();

	return !itemName.empty();
}

bool ParseInfo::getHasTokens() {
	return !_tokens.empty();
}

