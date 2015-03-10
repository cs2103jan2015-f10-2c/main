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

userCommand::~userCommand() {}

userCommand::userCommand(string input) {
	setCommand(input);
	setText(input);
}

void userCommand::setCommand(string input) {
	int start;
	int end;
	string command;

	start = findIndex(input, TOKEN_COMMAND);
	start = start + INDEX_START_OF_COMMAND;
	end = findIndex(input, TOKEN_SPACE);
	command = getSubstring(input, start, end);

	_command = command;
}

void userCommand::setText(string input) {
	int start;
	int end;
	string text;

	start = findIndex(input, TOKEN_SPACE);
	start = start + INDEX_START_OF_TEXT;
	text = getSubstring(input, start);

	_text = text;
}

string userCommand::getCommand() {
	return _command;
}

string userCommand::getText() {
	return _text;
}

int userCommand::findIndex(string input, string stringToFind) {
	return input.find(stringToFind);
}

string userCommand::getSubstring(string input, int start, int end) {
	string substring;

	if (end != INDEX_DEFAULT) {
		substring = input.substr(start, end - start);
	}
	else {
		substring = input.substr(start);
	}

	return substring;
}