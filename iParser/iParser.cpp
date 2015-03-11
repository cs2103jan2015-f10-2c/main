//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "iParser.h"

const string iParser::COMMAND_ADD = "add";
const string iParser::COMMAND_DELETE = "del";
const string iParser::COMMAND_EDIT = "edit";
const string iParser::COMMAND_START = "start";
const string iParser::COMMAND_END = "end";
const string iParser::COMMAND_DESC = "desc";
const string iParser::TOKEN_COMMAND = "::";
const string iParser::TOKEN_SPACE = " ";
const string iParser::TOKEN_BLANK = "";
const string iParser::MESSAGE_SUCCESS = "successful execution";
const string iParser::MESSAGE_INVALID = "invalid input";
const string iParser::COMMAND_BLANK = "";

iParser::iParser() {}

iParser::~iParser() {}

ParseInfo iParser::parse(string userInput) {
	tokeniseToCommands(userInput);
	
	if (!areValidCommands()) {
		_ParseInfo.setIsNotValidInput();
	}

	return _ParseInfo;
}

string iParser::tokeniseToCommands(string userInput) {
	int start = INDEX_ZERO;
	int end = INDEX_ZERO;
	
	while (end != INDEX_INVALID) {
		string individualCommandLine;
		start = findIndex(userInput, TOKEN_COMMAND, end);
		end = findIndex(userInput, TOKEN_COMMAND, start + INDEX_NEXT);
		individualCommandLine = retrieveSubstring(userInput, start, end);
		setToken(individualCommandLine);
	}
	displayTokens();

	return MESSAGE_SUCCESS;
}

bool iParser::areValidCommands() {
	bool isValid = true;
	list<COMMAND_AND_TEXT>& tokens = _ParseInfo.getTokens();
	list<COMMAND_AND_TEXT>::iterator iter;
	
	for (iter = tokens.begin(); iter != tokens.end(); iter++) {
		string command = iter->command;
		if (isCommand(command)) {
			if (isRequiredCommand(command)) {
				if (!_ParseInfo.getHasCommand()) {
					retrieveCommand(command);
				}
				else {
					isValid = false;
				}
			}
		}
		else {
			isValid = false;
		}
	}

	return isValid;
}

string iParser::retrieveCommand(string command) {
	_ParseInfo.setCommand(command);
	_ParseInfo.setHasCommand();

	return MESSAGE_SUCCESS;
}

int iParser::findIndex(string userInput, string stringToFind, int startingIndex) {
	int returnIndex;

	returnIndex = userInput.find(stringToFind, startingIndex);

	return returnIndex;
}


string iParser::retrieveSubstring(string userInput, int startIndex, int endIndex) {
	string substring;

	substring = userInput.substr(startIndex, endIndex - startIndex);

	return substring;
}

bool iParser::isCommand(string command) {
	bool isValid = false;

	if (command == COMMAND_ADD || command == COMMAND_DELETE || command == COMMAND_EDIT ||
		command == COMMAND_START || command == COMMAND_END || command == COMMAND_DESC) {
		isValid = true;
	}

	return isValid;
}

bool iParser::isRequiredCommand(string command) {
	bool isValid = false;

	if (command == COMMAND_ADD || command == COMMAND_DELETE || command == COMMAND_EDIT) {
		isValid = true;
	}

	return isValid;
}

string iParser::setCommand(string command) {
	return MESSAGE_SUCCESS;
}

string iParser::setIndex(int index) {
	return MESSAGE_SUCCESS;
}

string iParser::setItem(string userInput) {
	return MESSAGE_SUCCESS;
}

string iParser::setToken(string text) {
	COMMAND_AND_TEXT line;
	int start = INDEX_ZERO;
	int end = INDEX_ZERO;

	end = findIndex(text, TOKEN_SPACE, start);
	line.command = retrieveSubstring(text, INDEX_AFTER_TOKEN_COMMAND, end);
	if (end != INDEX_INVALID) {
		line.text = retrieveSubstring(text, end + INDEX_NEXT);
	}

	_ParseInfo.setTokens(line);

	return MESSAGE_SUCCESS;
}

void iParser::displayTokens() {
	list<COMMAND_AND_TEXT>::iterator iter;
	list<COMMAND_AND_TEXT>& tokens = _ParseInfo.getTokens();
	
	for (iter = tokens.begin(); iter != tokens.end(); iter++) {
		cout << "Command: " << iter->command << endl
			<< "Text: " << iter->text << endl;
	}
}