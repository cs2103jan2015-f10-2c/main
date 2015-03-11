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
	ParseInfo parseInfo;
	tokeniseToParts(userInput);
	if (!areValidCommands()) {
		
	}

	cout << displayTokens();
	cout << "Valid Commands: " << boolalpha << _parseInfo.getIsValidInput() << endl;

	parseInfo = _parseInfo;
	return parseInfo;
}

// 1. seperate the userInput into "::"
// 2. seperate each userInput into command and text
// 3. pushes to _tokens list
string iParser::tokeniseToParts(string userInput) {
	int start = INDEX_ZERO;
	int end = INDEX_ZERO;
	
	if (!isValidLength(userInput)) {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	while (end != INDEX_INVALID) {
		string individualCommandLine;
		start = findIndex(userInput, TOKEN_COMMAND, end);
		end = findIndex(userInput, TOKEN_COMMAND, start + INDEX_NEXT);
		individualCommandLine = retrieveSubstring(userInput, start, end);
		setToken(individualCommandLine);
	}

	return MESSAGE_SUCCESS;
}

bool iParser::areValidCommands() {
	bool isValid = true;
	list<COMMAND_AND_TEXT>::iterator iter;
	
	for (iter = _tokens.begin(); isValid && iter != _tokens.end(); iter++) {
		string command = iter->command;
		if (isCommand(command)) {
			if (isMainCommand(command)) {
				if (!_parseInfo.getHasMainCommand()) {
					_parseInfo.setMainCommand(command);
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
	
	// if any of the tokenised user inputs are not valid
	// ParseInfo passed to iLogic will be invalid information
	if (!isValid) {
		_parseInfo.setIsNotValidInput();
	}

	return isValid;
}


int iParser::findIndex(string userInput, string stringToFind, int startIndex) {
	int returnIndex;

	returnIndex = userInput.find(stringToFind, startIndex);

	return returnIndex;
}


string iParser::retrieveSubstring(string userInput, int startIndex, int endIndex) {
	string substring;

	substring = userInput.substr(startIndex, endIndex - startIndex);

	return substring;
}

string iParser::trimText(string& text) {
	text = trimFront(text);
	text = trimBack(text);

	return MESSAGE_SUCCESS;
}

string iParser::trimFront(string text) {
	int startIndex = INDEX_ZERO;

	while (text[startIndex] == ' ' || text[startIndex] == '\t') {
		startIndex++;
	}

	return text.substr(startIndex);
}

string iParser::trimBack(string text) {
	int endIndex = text.length() - INDEX_NEXT;

	while (text[endIndex] == ' ' || text[endIndex] == '\t') {
		endIndex--;
	}

	return text.substr(INDEX_ZERO, endIndex + INDEX_NEXT);
}

bool iParser::isCommand(string command) {
	bool isValid = false;

	if (command == COMMAND_ADD || command == COMMAND_DELETE || command == COMMAND_EDIT ||
		command == COMMAND_START || command == COMMAND_END || command == COMMAND_DESC) {
		isValid = true;
	}

	return isValid;
}

bool iParser::isMainCommand(string command) {
	bool isValid = false;

	if (command == COMMAND_ADD || command == COMMAND_DELETE || command == COMMAND_EDIT) {
		isValid = true;
	}

	return isValid;
}

bool iParser::isValidLength(string userInput) {
	return userInput.length() >= 2;
}

string iParser::setToken(string singleInput) {
	COMMAND_AND_TEXT line;
	int start = INDEX_ZERO;
	int end = INDEX_ZERO;

	end = findIndex(singleInput, TOKEN_SPACE, start);
	line.command = retrieveSubstring(singleInput, INDEX_AFTER_TOKEN_COMMAND, end);
	if (end != INDEX_INVALID) {
		line.text = retrieveSubstring(singleInput, end + INDEX_NEXT);
	}
	trimText(line.text);
	setTokenToList(line);

	return MESSAGE_SUCCESS;
}

string iParser::setTokenToList(COMMAND_AND_TEXT token) {
	_tokens.push_back(token);
	return MESSAGE_SUCCESS;
}

bool iParser::hasTokens() {
	return !_tokens.empty();
}

string iParser::displayTokens() {
	list<COMMAND_AND_TEXT>::iterator iter;
	ostringstream output;

	for (iter = _tokens.begin(); iter != _tokens.end(); iter++) {
		output << "Command: \"" << iter->command << " Text: \"" << iter->text << "\"" << endl;
	}

	return output.str();
}