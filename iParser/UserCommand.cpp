//	userCommandClass
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "userCommand.h"

const string userCommand::TOKEN_COMMAND = "::";
const string userCommand::TOKEN_SPACE = " ";
const int userCommand::INDEX_START_OF_COMMAND = 2;
const int userCommand::INDEX_START_OF_TEXT = 1;
const int userCommand::INDEX_DEFAULT = -1;

userCommand::userCommand() {
	_command = "";
	_text = "";
}

userCommand::~userCommand() {
	_command = "";
	_text = "";
}

userCommand::userCommand(string singleInput) {
	setCommand(singleInput);
	setText(singleInput);
}

void userCommand::setCommand(string singleInput) {
	int start;
	int end;
	string command;

	start = findIndex(singleInput, TOKEN_COMMAND);
	start = start + INDEX_START_OF_COMMAND;
	end = findIndex(singleInput, TOKEN_SPACE);
	command = getSubstring(singleInput, start, end);

	_command = command;
}

void userCommand::setText(string singleInput) {
	int start;
	int end;
	string text;

	start = findIndex(singleInput, TOKEN_SPACE);
	start = start + INDEX_START_OF_TEXT;
	text = getSubstring(singleInput, start);

	_text = text;
}

string userCommand::getCommand() {
	return _command;
}

string userCommand::getText() {
	return _text;
}

int userCommand::findIndex(string singleInput, string stringToFind) {
	return singleInput.find(stringToFind);
}

string userCommand::getSubstring(string singleInput, int start, int end) {
	string substring;

	if (end != INDEX_DEFAULT) {
		substring = singleInput.substr(start, end - start);
	}
	else {
		substring = singleInput.substr(start);
	}

	return substring;
}