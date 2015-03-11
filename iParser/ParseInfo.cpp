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

string ParseInfo::setTokens(COMMAND_AND_TEXT token) {
	_tokens.push_back(token);
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

list<COMMAND_AND_TEXT> ParseInfo::getTokens() {
	return _tokens;
}

bool ParseInfo::getIsValidInput() {
	return _isValidInput;
}

bool ParseInfo::getHasMainCommand() {
	return !_mainCommand.empty();
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

