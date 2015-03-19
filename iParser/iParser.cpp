//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "iParser.h"

const string iParser::COMMAND_ADD = "add";
const string iParser::COMMAND_DELETE_ONE = "del";
const string iParser::COMMAND_DELETE_TWO = "delete";
const string iParser::COMMAND_EDIT = "edit";
const string iParser::COMMAND_UNDO = "undo";
const string iParser::COMMAND_SORT = "sort";
const string iParser::COMMAND_SEARCH = "search";
const string iParser::COMMAND_VIEW = "view";
const string iParser::COMMAND_EXIT = "exit";
const string iParser::COMMAND_INVALID = "invalid";
const string iParser::MODIFIER_START = "start";
const string iParser::MODIFIER_END = "end";
const string iParser::MODIFIER_DESCRIPTION = "desc";
//const string iParser::TOKEN_COMMAND = "::";
//const string iParser::TOKEN_SPACE = " ";
//const string iParser::TOKEN_OBLIQUE = "/";
const string iParser::STRING_BLANK = "";
const string iParser::MESSAGE_SUCCESS = "success";
const string iParser::MESSAGE_INVALID_INDEX = "Invalid index";
const string iParser::MESSAGE_TERMINATE = "error encountered.Press any button to terminate programme...";

const int iParser::INDEX_INVALID = -1;
const int iParser::INDEX_ONE = 1;
const int iParser::INDEX_START = 0;

iParser::iParser() {}

iParser::~iParser() {}

list<COMMAND_AND_TEXT> iParser::parse(string userInput) {
	checkString(userInput);
	executeParsing(userInput);
	return _parseInfo;
}

string iParser::executeParsing(string userInput) {
	string command = retrieveCommand(userInput);
	CommandType commandType = determineCommandType(command);
	string textWithoutCommand = removeCommand(userInput);

	switch (commandType) {
	case ADD:
		executeAddParsing(textWithoutCommand);
		break;
	case DELETE:
		executeDeleteParsing(textWithoutCommand);
		break;
	case EDIT:
		break;
	case UNDO:
		break;
	case SORT:
		break;
	case SEARCH:
		break;
	case VIEW:
		break;
	case EXIT:
		break;
	case INVALID:
	default:
		showError(MESSAGE_TERMINATE);
		getchar();
		exit(EXIT_FAILURE);
	}

	return MESSAGE_SUCCESS;
}

string iParser::retrieveCommand(string userInput) {
	trimText(userInput);
	unsigned int endIndex = userInput.find_first_of(" \t");
	string command = userInput.substr(INDEX_START, endIndex);
	return command;
}

iParser::CommandType iParser::determineCommandType(string command) {
	if (command == COMMAND_ADD) {
		return CommandType::ADD;
	}
	else if (command == COMMAND_DELETE_ONE || command == COMMAND_DELETE_TWO) {
		return CommandType::DELETE;
	}
	else if (command == COMMAND_EDIT) {
		return CommandType::EDIT;
	}
	else if (command == COMMAND_UNDO) {
		return CommandType::UNDO;
	}
	else if (command == COMMAND_SORT) {
		return CommandType::SORT;
	}
	else if (command == COMMAND_SEARCH) {
		return CommandType::SEARCH;
	}
	else if (command == COMMAND_VIEW) {
		return CommandType::VIEW;
	}
	else if (command == COMMAND_EXIT) {
		return CommandType::EXIT;
	}
	else {
		return CommandType::INVALID;
	}
}

string iParser::removeCommand(string userInput) {
	unsigned int startIndex = userInput.find_first_of(" \t");
	string text;

	if (startIndex != INDEX_INVALID) {
		text = userInput.substr(startIndex + INDEX_ONE);
	}
	else {
		return STRING_BLANK;
	}
	trimText(text);
	
	return text;
}

string iParser::executeAddParsing(string text) {
	COMMAND_AND_TEXT information;
	setInformation(COMMAND_ADD, text);
	return MESSAGE_SUCCESS;
}

string iParser::executeDeleteParsing(string text) {
	COMMAND_AND_TEXT information;
	if (isDigit(text)) {
		setInformation(COMMAND_DELETE_TWO, text);
	}
	else {
		//setInformation(COMMAND_INVALID, MESSAGE_INVALID_INDEX);
		setInformation(COMMAND_DELETE_TWO, text);

	}
	return MESSAGE_SUCCESS;
}

string iParser::trimText(string& text) {
	text = trimFront(text);
	text = trimBack(text);
	return MESSAGE_SUCCESS;
}

string iParser::trimFront(string text) {
	unsigned int startIndex = INDEX_START;
	while (startIndex < text.length() && (text[startIndex] == ' ' || text[startIndex] == '\t')) {
		startIndex++;
	}

	return text.substr(startIndex);
}

string iParser::trimBack(string text) {
	unsigned int endIndex = text.length();
	while (endIndex > INDEX_START && (text[endIndex - INDEX_ONE] == ' ' || text[endIndex - INDEX_ONE] == '\t')) {
		endIndex--;
	}

	return text.substr(INDEX_START, endIndex);
}

//isDigit FAULTY!!!!!!!!!!!!!!!!!!!!!!!
//CB!!!!!!!!!!!!!!!!!!
//CHECK AGAIN!!!!!!
bool iParser::isDigit(string text) {
	bool isValid = true;
	unsigned int index;
	unsigned int textSize = text.size();
	for (index = INDEX_START; isValid && index < textSize; index++) {
		if (!(text[index] >= '0' && text[index] <= '9')) {
			isValid = false;
		}
	}

	return isValid;
}

list<COMMAND_AND_TEXT> iParser::getParseInfo() {
	return _parseInfo;
}

string iParser::setInformation(string command, string text) {
	COMMAND_AND_TEXT information;
	information.command = command;
	information.text = text;
	_parseInfo.push_back(information);
	return MESSAGE_SUCCESS;
}

void iParser::checkString(string string) {
	assert(string[INDEX_START] != NULL);
	assert(string != "");
}

void iParser::showError(string text) {
	cout << text;
}

/*
// splits inputs to fragments seperated by "::"
string iParser::splitInput(string userInput) {
	if (!isValidLength(userInput)) {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	int start = INDEX_ZERO;
	int end = INDEX_ZERO;
	while (end != INDEX_INVALID) {
		string individualInput;
		start = findIndex(userInput, TOKEN_COMMAND, end);
		end = findIndex(userInput, TOKEN_COMMAND, start + INDEX_AFTER_TOKEN_COMMAND);//
		if (start != INDEX_INVALID) {
			individualInput = retrieveSubstring(userInput, start, end);
			setInputs(individualInput);
		}
		else {
			_parseInfo.setIsNotValidInput();
			return MESSAGE_INVALID;
		}
	}

	return MESSAGE_SUCCESS;
}


string iParser::setInformation() {
	if (!_parseInfo.hasValidInput()) {
		return MESSAGE_INVALID;
	}
	
	list<string>::iterator iter;
	Item tempItem;

	for (iter = _inputs.begin(); _parseInfo.hasValidInput() && iter != _inputs.end(); iter++) {
		CommandType commandType;
		string userInput;
		string command;
		string text;
		
		userInput = *iter;
		command = retrieveCommand(userInput);
		commandType = determineCommandType(command);
		text = retrieveText(userInput);

		switch (commandType) {
		case ADD:
			setAddItemName(text, tempItem);
			break;
		case DELETE:
			setDeleteIndex(text, tempItem);
			break;
		case EDIT:
			setEditIndex(text, tempItem);
			break;
		case START:
			setStartDateTime(text, tempItem);
			break;
		case END:
			setEndDateTime(text, tempItem);
			break;
		case DESCRIPTION:
			setDescription(text, tempItem);
			break;
		case EXIT:
			setExit(text);
			break;
		case INVALID:
			_parseInfo.setIsNotValidInput();
			return MESSAGE_INVALID;
		default:
			showError(MESSAGE_TERMINATE);
			getchar();
			exit(EXIT_FAILURE);
		}
		_parseInfo.setItem(tempItem);
	}

	return MESSAGE_SUCCESS;
}

string iParser::setInputs(string individualInputs) {
	_inputs.push_back(individualInputs);

	return MESSAGE_SUCCESS;
}

string iParser::retrieveCommand(string userInput) {
	string command;
	int start = INDEX_AFTER_TOKEN_COMMAND;
	int end = INDEX_ZERO;

	end = findIndex(userInput, TOKEN_SPACE, start);
	command = retrieveSubstring(userInput, start, end);

	return command;
}

string iParser::retrieveText(string userInput) {
	string text;
	int start;

	start = findIndex(userInput, TOKEN_SPACE);
	if (start != INDEX_INVALID) {
		text = retrieveSubstring(userInput, start);
		trimText(text);
	}
	else {
		return TOKEN_BLANK;
	}

	return text;
}

string iParser::setAddItemName(string text, Item& item) {
	if (text != TOKEN_BLANK && !_parseInfo.hasMainCommand()) {
		_parseInfo.setMainCommand(COMMAND_ADD);
		item.setItemName(text);
	}
	else {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	return MESSAGE_SUCCESS;
}

string iParser::setDeleteIndex(string text, Item& item) {
	if (text != TOKEN_BLANK && !_parseInfo.hasMainCommand() && isDigit(text)) {
		_parseInfo.setMainCommand(COMMAND_DELETE);
		addIndex(text);
	}
	else {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	return MESSAGE_SUCCESS;
}

string iParser::setEditIndex(string text, Item& item) {
	if (text != TOKEN_BLANK && !_parseInfo.hasMainCommand() && isDigit(text)) {
		_parseInfo.setMainCommand(COMMAND_EDIT);
		addIndex(text);
	}
	else {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	return MESSAGE_SUCCESS;
}

string iParser::setStartDateTime(string text, Item& item) {
	if (text != TOKEN_BLANK) {
		splitAndSetDateTime(text, item, COMMAND_START);
	}
	else {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	return MESSAGE_SUCCESS;

}

string iParser::setEndDateTime(string text, Item& item) {
	if (text != TOKEN_BLANK) {
		splitAndSetDateTime(text, item, COMMAND_END);
	}
	else {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	return MESSAGE_SUCCESS;

}

string iParser::setDescription(string text, Item& item) {
	if (text != TOKEN_BLANK) {
		item.setDescription(text);
		_parseInfo.setEditString(COMMAND_DESCRIPTION);
	}
	else {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	return MESSAGE_SUCCESS;
}

string iParser::setExit(string text) {
	if (text == TOKEN_BLANK && !_parseInfo.hasMainCommand()) {
		_parseInfo.setMainCommand(COMMAND_EXIT);
	}
	else {
		_parseInfo.setIsNotValidInput();
		return MESSAGE_INVALID;
	}

	return MESSAGE_SUCCESS;
}

string iParser::addIndex(string text) {
	int index;
	index = convertToDigit(text);
	_parseInfo.setIndex(index);

	return MESSAGE_SUCCESS;
}

// returns index where stringToFind is found
int iParser::findIndex(string userInput, string stringToFind, int startIndex) {
	int returnIndex;

	returnIndex = userInput.find(stringToFind, startIndex);

	return returnIndex;
}

string iParser::trimText(string& text) {
	text = trimFront(text);
	text = trimBack(text);

	return MESSAGE_SUCCESS;
}

string iParser::trimFront(string text) {
	unsigned int startIndex = INDEX_ZERO;

	while (startIndex < text.length() && (text[startIndex] == ' ' || text[startIndex] == '\t')) {
		startIndex++;
	}

	return text.substr(startIndex);
}

string iParser::trimBack(string text) {
	int endIndex = text.length();

	while (endIndex > INDEX_ZERO && (text[endIndex-INDEX_ONE] == ' ' || text[endIndex-INDEX_ONE] == '\t')) {
		endIndex--;
	}

	return text.substr(INDEX_ZERO, endIndex);
}

int iParser::convertToDigit(string text) {
	int digit;
	istringstream convert(text);
	convert >> digit;
	
	return digit;
}

// assume DateTime to be DD/MM/YY_HHMM
string iParser::splitAndSetDateTime(string text, Item& item, string command) {
	int year = retrieveYear(text);
	int month = retrieveMonth(text);
	int day = retrieveDay(text);
	int hour = retrieveHour(text);
	int minute = retrieveMinute(text);

	DateTime dateTime(year, month, day, hour, minute);
	if (command == COMMAND_START) {
		item.setStartTime(dateTime);
		_parseInfo.setEditString(COMMAND_START);
	}
	else if (command == COMMAND_END) {
		item.setEndTime(dateTime);
		_parseInfo.setEditString(COMMAND_END);
	}

	return MESSAGE_SUCCESS;
}

int iParser::retrieveYear(string text) {
	int year;
	string stringToConvert;
	int start;

	start = findIndex(text, TOKEN_OBLIQUE);
	start = findIndex(text, TOKEN_OBLIQUE, ++start);
	stringToConvert = retrieveSubstring(text, ++start);
	istringstream convert(stringToConvert);
	convert >> year;

	return year;
}

int iParser::retrieveMonth(string text) {
	int month;
	string stringToConvert;
	int start;

	start = findIndex(text, TOKEN_OBLIQUE);
	stringToConvert = retrieveSubstring(text, ++start);
	istringstream convert(stringToConvert);
	convert >> month;

	return month;
}

int iParser::retrieveDay(string text) {
	int day;
	string stringToConvert;
	int start = INDEX_ZERO;

	stringToConvert = retrieveSubstring(text, start);
	istringstream convert(stringToConvert);
	convert >> day;

	return day;
}

int iParser::retrieveHour(string text) {
	int hour;
	string stringToConvert;
	int start;

	start = findIndex(text, TOKEN_SPACE);
	stringToConvert = retrieveSubstring(text, ++start);
	trimText(stringToConvert);
	if (stringToConvert.size() == DIGIT_THREE) {
		stringToConvert = stringToConvert[INDEX_ZERO];
	}
	else {
		stringToConvert = retrieveSubstring(stringToConvert, INDEX_ZERO, DIGIT_OF_TIME);
	}
	istringstream convert(stringToConvert);
	convert >> hour;
	
	return hour;
}

int iParser::retrieveMinute(string text) {
	int minute;
	string stringToConvert;
	int start;

	start = findIndex(text, TOKEN_SPACE);
	stringToConvert = retrieveSubstring(text, ++start);
	trimText(stringToConvert);
	if (stringToConvert.size() == DIGIT_THREE) {
		stringToConvert = retrieveSubstring(stringToConvert, INDEX_ONE);
	}
	else {
		stringToConvert = retrieveSubstring(stringToConvert, DIGIT_OF_TIME);
	}
	istringstream convert(stringToConvert);
	convert >> minute;

	return minute;
}

string iParser::setEditString(string text) {
	if (_parseInfo.hasMainCommand()) {
		if (_parseInfo.getMainCommand() == COMMAND_EDIT) {
			_parseInfo.setEditString(text);
			return MESSAGE_SUCCESS;
		}
	}

	return MESSAGE_INVALID;
}

bool iParser::isValidLength(string userInput) {
	return userInput.length() >= LENGTH_VALID;
}

bool iParser::isDigit(string text) {
	bool isValid = true;
	int index;
	int textSize = text.size();

	for (index = INDEX_ZERO; isValid && index < textSize; index++) {
		if (!(text[index] >= '0' && text[index] <= '9')) {
			isValid = false;
		}
	}

	return isValid;
}

string iParser::displayInputs() {
	list<string>::iterator iter;
	ostringstream output;
	int index = INDEX_ONE;

	for (iter = _inputs.begin(); iter != _inputs.end(); index++, iter++) {
		output << "Line " << index << ": " << *iter << endl;
	}

	return output.str();
}

string iParser::displayParseInfo() {
	ostringstream output;

	output << "Valid input: " << boolalpha << _parseInfo.hasValidInput() << endl
		<< "Main Command: " << _parseInfo.getMainCommand() << endl
		<< "Edit String: " << _parseInfo.getEditString() << endl
		<< "Index: " << _parseInfo.getIndex() << endl
		<< _parseInfo.getItem().displayItemForUser();

	return output.str();
}


*/