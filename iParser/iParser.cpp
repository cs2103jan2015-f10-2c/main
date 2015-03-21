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
const string iParser::COMMAND_SAVE = "save";
const string iParser::COMMAND_DONE = "done";
const string iParser::COMMAND_EXIT = "exit";

const string iParser::MODIFIER_START = "start";
const string iParser::MODIFIER_END = "end";
const string iParser::MODIFIER_DESCRIPTION = "description";

const string iParser::STRING_DESCRIPTION = "description";
const string iParser::STRING_DESCRIPTION_SHORT_FORM = "desc";
const string iParser::STRING_DATE = "date";
const string iParser::STRING_DAYS[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
const string iParser::STRING_DAYS_SHORT_FORM[] = { "mon", "tue", "wed", "thur", "fri", "sat", "sun" };
const string iParser::STRING_MONTHS[] = { "january" , "february", "march", "april", "may", "june",
										  "july", "august", "september", "october", "november", "december" };
const string iParser::STRING_MONTHS_SHORT_FORM[] = { "jan", "feb", "mar", "apr", "may", "jun",
													 "jul", "aug", "sep", "oct", "nov", "dec" };
const string iParser::STRING_MONTHS_IN_NUMBER[] { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };
const string iParser::STRING_BLANK = "";
const string iParser::STRING_NEGATIVE_ONE = "-1";
const char iParser::CHAR_SPACE = ' ';
const char iParser::CHAR_TAB = '\t';
const char iParser::CHAR_COMMA = ',';
const char iParser::CHAR_OBLIQUE = '/';
const char iParser::CHAR_HYPHEN = '-';

const string iParser::MESSAGE_SUCCESS = "success";
const string iParser::MESSAGE_FAILURE = "failure";
const string iParser::MESSAGE_INVALID = "invalid";
const string iParser::MESSAGE_INVALID_INPUT = "invalid input";
const string iParser::MESSAGE_INVALID_COMMAND = "invalid command";
const string iParser::MESSAGE_INVALID_ADD = "invalid text added";
const string iParser::MESSAGE_INVALID_EDIT = "invalid edit";
const string iParser::MESSAGE_INVALID_INDEX = "invalid index";
const string iParser::MESSAGE_INVALID_DATE = "invalid date input";
const string iParser::MESSAGE_INVALID_TIME = "invalid time input";
const string iParser::MESSAGE_TERMINATE = "error encountered.Press any button to terminate programme...";

const unsigned int iParser::SIZE_DAYS = 7;
const unsigned int iParser::SIZE_MONTHS = 12;

const unsigned int iParser::INDEX_ZERO = 0;
const unsigned int iParser::INDEX_ONE = 1;
const unsigned int iParser::INDEX_TWO = 2;
const unsigned int iParser::INDEX_THREE = 3;
const unsigned int iParser::INDEX_START = 0;
const unsigned int iParser::INDEX_INVALID = -1;

iParser::iParser() {}

iParser::~iParser() {}

list<COMMAND_AND_TEXT> iParser::parse(string userInput) {
	executeParsing(userInput);
	return _parseInfo;
}

string iParser::executeParsing(string userInput) {
	trimText(userInput);
	removeConsecutiveWhiteSpace(userInput);
	string command = retrieveCommand(userInput);
	CommandType commandType = determineCommandType(command);
	string textWithoutCommand = removeFirstStringToken(userInput);

	switch (commandType) {
	case ADD:
		executeAddParsing(textWithoutCommand);
		break;
	case DELETE:
		executeDeleteParsing(textWithoutCommand);
		break;
	case EDIT:
		executeEditParsing(textWithoutCommand);
		break;
	case UNDO:
		executeUndoParsing(userInput);
		break;
	case SORT:
		break;
	case SEARCH:
		executeSearchParsing(textWithoutCommand);
		break;
	case VIEW:
		break;
	case SAVE:
		break;
	case DONE:
		executeDoneParsing(textWithoutCommand);
		break;
	case EXIT:
		executeExitParsing(userInput);
		break;
	case INVALID:
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_COMMAND);
		break;
	default:
		showError(MESSAGE_TERMINATE);
		getchar();
		exit(EXIT_FAILURE);
	}

	return MESSAGE_SUCCESS;
}

string iParser::retrieveCommand(string userInput) {
	unsigned int endIndex = userInput.find_first_of(" \t");
	string command = userInput.substr(INDEX_START, endIndex);
	convertToLowerCase(command);
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
	else if (command == COMMAND_SAVE) {
		return CommandType::SAVE;
	}
	else if (command == COMMAND_DONE) {
		return CommandType::DONE;
	}
	else if (command == COMMAND_EXIT) {
		return CommandType::EXIT;
	}
	else {
		return CommandType::INVALID;
	}
}

string iParser::executeAddParsing(string text) {
	if (text == STRING_BLANK) {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
		return MESSAGE_FAILURE;
	}

	int numberOfCommas = retrieveCount(text, CHAR_COMMA);

	return MESSAGE_SUCCESS;
}

string iParser::executeDeleteParsing(string indexToDelete) {
	if (indexToDelete != STRING_BLANK && areDigits(indexToDelete)) {
		setParseInfo(COMMAND_DELETE_TWO, indexToDelete);
		return MESSAGE_SUCCESS;
	}
	else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INDEX);
		return MESSAGE_FAILURE;
	}
}

string iParser::executeEditParsing(string text) {
	string indexToEdit = retrieveFirstStringToken(text);
	string textToEdit = removeFirstStringToken(text);

	if (textToEdit != STRING_BLANK && areDigits(indexToEdit)) {
		setParseInfo(COMMAND_EDIT, indexToEdit);
		setParseInfo(MODIFIER_DESCRIPTION, textToEdit);
		return MESSAGE_SUCCESS;
	}
	else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INDEX);
		return MESSAGE_FAILURE;
	}
}

string iParser::executeUndoParsing(string userInput) {
	if (userInput == COMMAND_UNDO) {
		setParseInfo(COMMAND_UNDO);
		return MESSAGE_SUCCESS;
	}
	else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_COMMAND);
		return MESSAGE_FAILURE;
	}
}

string iParser::executeSearchParsing(string textToSearch) {
	if (textToSearch != STRING_BLANK) {
		setParseInfo(COMMAND_SEARCH, textToSearch);
		return MESSAGE_SUCCESS;
	}
	else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
		return MESSAGE_FAILURE;
	}
}

string iParser::executeDoneParsing(string indexToMarkAsDone) {
	if (indexToMarkAsDone != STRING_BLANK && areDigits(indexToMarkAsDone)) {
		setParseInfo(COMMAND_DONE, indexToMarkAsDone);
		return MESSAGE_SUCCESS;
	}
	else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INDEX);
		return MESSAGE_FAILURE;
	}
}

string iParser::executeExitParsing(string userInput) {
	if (userInput == COMMAND_EXIT) {
		setParseInfo(COMMAND_EXIT);
		return MESSAGE_SUCCESS;
	}
	else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_COMMAND);
		return MESSAGE_FAILURE;
	}	
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

string iParser::removeFirstStringToken(string userInput) {
	unsigned int startIndex = userInput.find_first_of(" \t");
	string text;

	if (startIndex != INDEX_INVALID) {
		text = userInput.substr(++startIndex);
	}
	else {
		return STRING_BLANK;
	}

	return text;
}

string iParser::retrieveFirstStringToken(string text) {
	unsigned int endIndex = text.find_first_of(" \t");
	string firstString = text.substr(INDEX_START, endIndex);
	return firstString;
}

string iParser::removeConsecutiveWhiteSpace(string& text) {
	unsigned int index;
	unsigned int endIndex = text.length();

	for (index = INDEX_START; index < endIndex - INDEX_ONE; index++) {
		if (isWhiteSpace(text[index]) && isWhiteSpace(text[index + INDEX_ONE])) {
			text.erase(index + INDEX_ONE, INDEX_ONE);
			index--;
		}
	}

	return MESSAGE_SUCCESS;
}

string iParser::convertToLowerCase(string& text) {
	unsigned int index;
	unsigned int endIndex = text.length();

	for (index = INDEX_START; index < endIndex; index++) {
		text[index] = tolower(text[index]);
	}

	return MESSAGE_SUCCESS;
}

bool iParser::areDigits(string text) {
	bool isValid = true;
	unsigned int index;

	for (index = INDEX_START; isValid && index < text.size(); index++) {
		if (!isdigit(text[index])) {
			isValid = false;
		}
	}

	return isValid;
}

bool iParser::isWhiteSpace(char character) {
	return (character == CHAR_SPACE || character == CHAR_TAB);
}

//string iParser::checkTokensAndSetParseInfo(const vector<string>& tokens) {
//	bool isValid = true;
//	
//	if (tokens.size() == 0) {
//		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
//		isValid = false;
//	}
//
//	unsigned int index;
//	bool hasDate = false;
//	bool hasTime = false;
//	for (index = INDEX_START; isValid && index < tokens.size(); index++) {
//		if (tokens[index] == STRING_BLANK) {
//			setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
//			isValid = false;
//		}
//	}
//
//	return MESSAGE_SUCCESS;
//}

string iParser::splitAndSetObliqueDateInformation(string date, unsigned int numberOfObliques) {
	assert(numberOfObliques > 0 && numberOfObliques <= 2);
	ostringstream output;
	string day = STRING_NEGATIVE_ONE;
	string month = STRING_NEGATIVE_ONE;
	string year = STRING_NEGATIVE_ONE;
	unsigned int startIndex = INDEX_START;
	unsigned int endIndex = INDEX_START;
	
	endIndex = date.find_first_of("/");
	day = date.substr(startIndex, endIndex - startIndex);
	startIndex = endIndex + INDEX_ONE;
	
	if (numberOfObliques == 1) {
		month = date.substr(startIndex);
	}
	else if (numberOfObliques == 2) {
		endIndex = date.find_first_of("/", startIndex);
		month = date.substr(startIndex, endIndex - startIndex);
		startIndex = endIndex + INDEX_ONE;
		year = date.substr(startIndex);
	}

	output << day << CHAR_SPACE << month << CHAR_SPACE << year;

	return output.str();
}

string iParser::splitAndSetSpaceDateInformation(string date, unsigned int numberOfSpaces) {
	assert(numberOfSpaces >= 0 && numberOfSpaces <= 2);
	ostringstream output;
	string day = STRING_NEGATIVE_ONE;
	string month = STRING_NEGATIVE_ONE;
	string year = STRING_NEGATIVE_ONE;
	unsigned int startIndex = INDEX_START;
	unsigned int endIndex = INDEX_START;
	unsigned int keywordIndex = INDEX_INVALID;

	if (numberOfSpaces == 0) {
		bool hasDay = false;
		if (isDay(date, keywordIndex)) {
			day = STRING_DAYS[keywordIndex];
			hasDay = true;
		}
		
		if (!hasDay) {
			if (isMonth(date, keywordIndex)) {
				month = STRING_MONTHS_IN_NUMBER[keywordIndex];
			}
		}
	}
	else {
		string tempMonth;
		endIndex = date.find_first_of(" ");
		day = date.substr(startIndex, endIndex - startIndex);
		startIndex = endIndex + INDEX_ONE;

		if (numberOfSpaces == 1) {
			tempMonth = date.substr(startIndex);
			if (isMonth(tempMonth, keywordIndex)) {
				month = STRING_MONTHS_IN_NUMBER[keywordIndex];
			}
		}
		else if (numberOfSpaces == 2) {
			endIndex = date.find_first_of(" ", startIndex);
			tempMonth = date.substr(startIndex, endIndex - startIndex);
			if (isMonth(tempMonth, keywordIndex)) {
				month = STRING_MONTHS_IN_NUMBER[keywordIndex];
			}
			startIndex = endIndex + INDEX_ONE;
			year = date.substr(startIndex);
		}
	}

	output << day << CHAR_SPACE << month << CHAR_SPACE << year;

	return output.str();
}

unsigned int iParser::retrieveCount(string text, char character) {
	unsigned int count = INDEX_START;
	unsigned int index;
	
	for (index = INDEX_START; index < text.size(); index++) {
		if (text[index] == character) {
			count++;
		}
	}

	return count;
}

bool iParser::isValidDate(string text, string& dateToBeSet) {
	unsigned int numberOfObliques = retrieveCount(text, CHAR_OBLIQUE);

	if (numberOfObliques > INDEX_TWO && numberOfObliques < INDEX_ZERO) {
		return false;
	}
	else if (numberOfObliques > INDEX_ZERO) {
		dateToBeSet = splitAndSetObliqueDateInformation(text, numberOfObliques);
	}
	else {
		unsigned int numberOfSpaces = retrieveCount(text, CHAR_SPACE);
		if (numberOfSpaces > INDEX_TWO && numberOfSpaces < INDEX_ZERO) {
			dateToBeSet = splitAndSetSpaceDateInformation(text, numberOfSpaces);
		}
	}

	return true;
}

bool iParser::isValidTime(string text, string& textToBeSet) {

	return true;
}

bool iParser::isDay(string day, unsigned int& indexToSet) {
	assert(indexToSet == INDEX_INVALID);
	unsigned int index;
	convertToLowerCase(day);
	for (index = INDEX_START; index < SIZE_DAYS; index++) {
		if (day == STRING_DAYS[index] || day == STRING_DAYS_SHORT_FORM[index]) {
			indexToSet = index;
			return true;
		}
	}
	return false;
}

bool iParser::isMonth(string month, unsigned int& indexToSet) {
	assert(indexToSet == INDEX_INVALID);
	unsigned int index;
	convertToLowerCase(month);
	for (index = INDEX_START; index < SIZE_MONTHS; index++) {
		if (month == STRING_MONTHS[index] || month == STRING_MONTHS_SHORT_FORM[index]) {
			indexToSet = index;
			return true;
		}
	}
	return false;
}

bool iParser::isValidDateString(string dateString) {
	assert(dateString != STRING_BLANK && dateString[INDEX_ZERO] != NULL);
	bool isValid = true;
	unsigned whiteSpaceCount = INDEX_ZERO;
	unsigned int index;

	for (index = INDEX_START; isValid && index < dateString.size(); index++) {
		if (dateString[index] == CHAR_SPACE) {
			whiteSpaceCount++;
		}
		if (!isdigit(dateString[index]) && dateString[index] != CHAR_HYPHEN && dateString[index] != CHAR_SPACE) {
			isValid = false;
		}
	}

	if (whiteSpaceCount != INDEX_TWO) {
		isValid = false;
	}

	return isValid;
}	

list<COMMAND_AND_TEXT> iParser::getParseInfo() {
	return _parseInfo;
}

string iParser::setParseInfo(string command, string text) {
	COMMAND_AND_TEXT information;
	information.command = command;
	information.text = text;
	_parseInfo.push_back(information);
	return MESSAGE_SUCCESS;
}

string iParser::clearParseInfo() {
	_parseInfo.clear();
	return MESSAGE_SUCCESS;
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