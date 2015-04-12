//	@author A0111238U
//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng

#include "iParser.h"

const string iParser::COMMAND_ADD = "add";
const string iParser::COMMAND_DELETE = "delete";
const string iParser::COMMAND_DEL = "del";
const string iParser::COMMAND_CLEAR = "clear";
const string iParser::COMMAND_EDIT = "edit";
const string iParser::COMMAND_UNDO = "undo";
const string iParser::COMMAND_SORT = "sort";
const string iParser::COMMAND_SEARCH = "search";
const string iParser::COMMAND_VIEW = "view";
const string iParser::COMMAND_SAVE = "save";
const string iParser::COMMAND_DONE = "done";
const string iParser::COMMAND_UNDONE = "undone";
const string iParser::COMMAND_EXIT = "exit";

const string iParser::COMMAND_NAME = "name";
const string iParser::COMMAND_START = "start";
const string iParser::COMMAND_END = "end";
const string iParser::COMMAND_DESCRIPTION = "description";
const string iParser::COMMAND_PRIORITY = "priority";
const string iParser::COMMAND_REMOVE = "remove";
const string iParser::COMMAND_RMV = "rmv";

const string iParser::STRING_DATE = "date";
const string iParser::STRING_DUE = "due";
const string iParser::STRING_START = "start";
const string iParser::STRING_END = "end";
const string iParser::STRING_DESCRIPTION = "description";
const string iParser::STRING_DESC = "desc";
const string iParser::STRING_PRIORITY = "priority";
const string iParser::STRING_PRIORITY_P = "p";
const string iParser::STRING_ALL = "all";
const string iParser::STRING_NAME = "name";
const string iParser::STRING_UPDATE = "update";
const string iParser::STRING_DONE = "done";
const string iParser::STRING_UNDONE = "undone";
const string iParser::STRING_HIGH = "high";
const string iParser::STRING_MEDIUM = "medium";
const string iParser::STRING_MED = "med";
const string iParser::STRING_LOW = "low";
const string iParser::STRING_H = "h";
const string iParser::STRING_M = "m";
const string iParser::STRING_L = "l";

const string iParser::MODIFIER_NAME = "-name";
const string iParser::MODIFIER_DATE = "-date";
const string iParser::MODIFIER_DUE = "-due";
const string iParser::MODIFIER_START = "-start";
const string iParser::MODIFIER_END = "-end";
const string iParser::MODIFIER_DESCRIPTION = "-description";
const string iParser::MODIFIER_DESC = "-desc";
const string iParser::MODIFIER_LABEL = "-label";
const string iParser::MODIFIER_PRIORITY = "-priority";
const string iParser::MODIFIER_PRIORITY_P = "-p";
const string iParser::MODIFIER_REMOVE = "-remove";
const string iParser::MODIFIER_RMV = "-rmv";

const string iParser::STRING_DAYS[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
const string iParser::STRING_DAYS_SHORT_FORM[] = { "mon", "tue", "wed", "thur", "fri", "sat", "sun" };
const string iParser::STRING_MONTHS[] = { "january", "february", "march", "april", "may", "june",
"july", "august", "september", "october", "november", "december" };
const string iParser::STRING_MONTHS_SHORT_FORM[] = { "jan", "feb", "mar", "apr", "may", "jun",
"jul", "aug", "sep", "oct", "nov", "dec" };
const string iParser::STRING_MONTHS_IN_NUMBER[] { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };
const string iParser::STRING_TO = "to";
const string iParser::STRING_AM = "am";
const string iParser::STRING_PM = "pm";
const string iParser::STRING_HR = "hr";
const string iParser::STRING_DATE_INITIALISE = "-1 -1 -1";
const string iParser::STRING_TIME_INITIALISE = "-1 -1";
const string iParser::STRING_MINUTE_INITIALISE = "00";
const string iParser::STRING_DATE_TIME_REMOVE = "-2 -2 -2 -2 -2";
const string iParser::STRING_BLANK = "";
const string iParser::STRING_NEGATIVE_ONE = "-1";
const char iParser::CHAR_SPACE = ' ';
const char iParser::CHAR_TAB = '\t';
const char iParser::CHAR_COMMA = ',';
const char iParser::CHAR_OBLIQUE = '/';
const char iParser::CHAR_HYPHEN = '-';
const char iParser::CHAR_COLON = ':';
const char iParser::CHAR_PLUS = '+';

const string iParser::MESSAGE_SUCCESS = "success";
const string iParser::MESSAGE_FAILURE = "failure";
const string iParser::MESSAGE_INVALID = "invalid";
const string iParser::MESSAGE_INVALID_INPUT = "Invalid input";
const string iParser::MESSAGE_INVALID_COMMAND = "Invalid command";
const string iParser::MESSAGE_INVALID_MODIFIER = "Invalid modifier";
const string iParser::MESSAGE_INVALID_SORT = "Invalid sort";
const string iParser::MESSAGE_INVALID_REMOVE = "Invalid remove";
const string iParser::MESSAGE_INVALID_VIEW = "Invalid view";
const string iParser::MESSAGE_INVALID_PRIORITY = "Invalid priority";
const string iParser::MESSAGE_INVALID_DATE_TIME = "Invalid date and time";
const string iParser::MESSAGE_INVALID_ADD_ITEM = "Unable to use \'name\' modifier when using \'add\' command";
const string iParser::MESSAGE_INVALID_NUMBER_OF_ITEM_MODIFIER = "Unable to use \'name\' modifier more than once";
const string iParser::MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER = "Unable to use multiple date time modifiers";
const string iParser::MESSAGE_INVALID_NUMBER_OF_DESCRIPTION_MODIFIER = "Unable to use \'description\' modifier more than once";
const string iParser::MESSAGE_INVALID_NUMBER_OF_PRIORITY_MODIFIER = "Unable to use \'priority\' modifier more than once";
const string iParser::MESSAGE_INVALID_NUMBER_OF_REMOVE_MODIFIER = "Unable to use \'remove\' modifier more than once";

const unsigned int iParser::SIZE_OF_STRING_TO = 2;
const unsigned int iParser::SIZE_OF_STRING_HYPHEN = 1;
const unsigned int iParser::MAX_SIZE_OF_STRING_HOURS = 2;
const unsigned int iParser::MIN_SIZE_OF_STRING_HOURS = 1;
const unsigned int iParser::SIZE_OF_STRING_MINUTES = 2;
const unsigned int iParser::MIN_SIZE_OF_STRING_WITH_SUFFIX = 3;
const unsigned int iParser::NUMBER_OF_DAYS = 7;
const unsigned int iParser::NUMBER_OF_MONTHS = 12;
const unsigned int iParser::NUMBER_OF_HOURS = 12;
const unsigned int iParser::HOURS_ZERO = 0;
const unsigned int iParser::HOURS_ONE_PM = 1;
const unsigned int iParser::HOURS_ELEVEN_PM = 11;

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
	string command = retrieveCommandOrModifier(userInput);
	string textWithoutCommand = removeFirstStringToken(userInput);

	if (command == COMMAND_ADD) {
		executeAddParsing(textWithoutCommand);
	} else if (command == COMMAND_DELETE || command == COMMAND_DEL) {
		executeCommandAndTextParsing(COMMAND_DELETE, textWithoutCommand);
	} else if (command == COMMAND_CLEAR) {
		executeSingularCommandParsing(COMMAND_CLEAR, userInput);
	} else if (command == COMMAND_EDIT) {
		executeEditParsing(textWithoutCommand);
	} else if (command == COMMAND_UNDO) {
		executeSingularCommandParsing(COMMAND_UNDO, userInput);
	} else if (command == COMMAND_SORT) {
		executeSortParsing(textWithoutCommand);
	} else if (command == COMMAND_SEARCH) {
		executeCommandAndTextParsing(COMMAND_SEARCH, textWithoutCommand);
	} else if (command == COMMAND_VIEW) {
		executeViewParsing(textWithoutCommand);
	} else if (command == COMMAND_SAVE) {
		executeCommandAndTextParsing(COMMAND_SAVE, textWithoutCommand);
	} else if (command == COMMAND_DONE) {
		executeCommandAndTextParsing(COMMAND_DONE, textWithoutCommand);
	} else if (command == COMMAND_UNDONE) {
		executeCommandAndTextParsing(COMMAND_UNDONE, textWithoutCommand);
	} else if (command == COMMAND_EXIT) {
		executeSingularCommandParsing(COMMAND_EXIT, userInput);
	} else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_COMMAND);
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeAddParsing(string text) {
	if (text == STRING_BLANK) {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
		return MESSAGE_FAILURE;
	}

	try {
		vector<string> tokenisedInformation = tokeniseText(text);
		string itemName = tokenisedInformation[INDEX_START];
		setParseInfo(COMMAND_ADD, itemName);
		if (tokenisedInformation.size() > 1) {
			checkAndSetTokenisedInformation(tokenisedInformation, COMMAND_ADD);
		}
	} catch (string& exceptionMessage) {
		clearParseInfo();
		setParseInfo(MESSAGE_INVALID, exceptionMessage);
		return MESSAGE_FAILURE;
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeEditParsing(string text) {
	if (text == STRING_BLANK) {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
		return MESSAGE_FAILURE;
	}

	try {
		vector<string> tokenisedInformation = tokeniseText(text);
		string indexToEdit = tokenisedInformation[INDEX_START];
		setParseInfo(COMMAND_EDIT, indexToEdit);
		if (tokenisedInformation.size() > 1) {
			checkAndSetTokenisedInformation(tokenisedInformation, COMMAND_EDIT);
		}
	} catch (string& exceptionMessage) {
		clearParseInfo();
		setParseInfo(MESSAGE_INVALID, exceptionMessage);
		return MESSAGE_FAILURE;
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeSortParsing(string sortType) {
	convertToLowerCase(sortType);

	if (sortType == STRING_DATE) {
		setParseInfo(COMMAND_SORT, STRING_DATE);
	} else if (sortType == STRING_NAME) {
		setParseInfo(COMMAND_SORT, STRING_NAME);
	} else if (sortType == STRING_PRIORITY || sortType == STRING_PRIORITY_P) {
		setParseInfo(COMMAND_SORT, STRING_PRIORITY);
	} else if (sortType == STRING_DONE) {
		setParseInfo(COMMAND_SORT, STRING_DONE);
	} else if (sortType == STRING_UPDATE) {
		setParseInfo(COMMAND_SORT, STRING_UPDATE);
	} else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_SORT);
		return MESSAGE_FAILURE;
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeViewParsing(string viewType) {
	convertToLowerCase(viewType);

	if (viewType == STRING_ALL) {
		setParseInfo(COMMAND_VIEW, STRING_ALL);
	} else if (viewType == STRING_DONE) {
		setParseInfo(COMMAND_VIEW, STRING_DONE);
	} else if (viewType == STRING_UNDONE) {
		setParseInfo(COMMAND_VIEW, STRING_UNDONE);
	} else if (viewType == STRING_PRIORITY || viewType == STRING_PRIORITY_P) {
		setParseInfo(COMMAND_VIEW, STRING_PRIORITY);
	} else if (viewType == STRING_HIGH || viewType == STRING_H) {
		setParseInfo(COMMAND_VIEW, STRING_HIGH);
	} else if (viewType == STRING_MEDIUM || viewType == STRING_MED || viewType == STRING_M) {
		setParseInfo(COMMAND_VIEW, STRING_MEDIUM);
	} else if (viewType == STRING_LOW || viewType == STRING_L) {
		setParseInfo(COMMAND_VIEW, STRING_PRIORITY);
	} else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_VIEW);
		return MESSAGE_FAILURE;
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeCommandAndTextParsing(const string commandType, string text) {
	if (text != STRING_BLANK) {
		convertToLowerCase(text);
		setParseInfo(commandType, text);
		return MESSAGE_SUCCESS;
	} else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
		return MESSAGE_FAILURE;
	}
}

string iParser::executeSingularCommandParsing(const string commandType, string userInput) {
	if (userInput == commandType) {
		setParseInfo(commandType);
		return MESSAGE_SUCCESS;
	} else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_COMMAND);
		return MESSAGE_FAILURE;
	}
}

string iParser::checkAndSetTokenisedInformation(vector<string>& tokenisedInformation, const string command) {
	assert(tokenisedInformation.size() > 1);

	bool hasItem = false;
	bool hasDateOrDue = false;
	bool hasStart = false;
	bool hasEnd = false;
	bool hasDescription = false;
	bool hasPriority = false;
	bool hasRemove = false;

	for (unsigned int index = 1; index < tokenisedInformation.size(); index++) {
		string singleInformation = tokenisedInformation[index];
		string modifier = retrieveCommandOrModifier(singleInformation);
		string textWithoutCommand = removeFirstStringToken(singleInformation);

		if (modifier == MODIFIER_NAME) {
			if (command == COMMAND_EDIT && !hasItem) {
				executeModifierAndTextParsing(COMMAND_NAME, textWithoutCommand);
				hasItem = true;
			} else {
				if (command == COMMAND_ADD) {
					throw MESSAGE_INVALID_ADD_ITEM;
				} else if (hasItem) {
					throw MESSAGE_INVALID_NUMBER_OF_ITEM_MODIFIER;
				}
			}
		} else if (modifier == MODIFIER_DATE) {
			if (!hasDateOrDue && !hasStart && !hasEnd) {
				executeDateTimeParsing(textWithoutCommand);
				hasDateOrDue = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
		} else if (modifier == MODIFIER_DUE) {
			if (!hasDateOrDue && !hasStart && !hasEnd) {
				setDateTime(textWithoutCommand, STRING_DUE);
				hasDateOrDue = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
		} else if (modifier == MODIFIER_START) {
			if (!hasDateOrDue && !hasStart) {
				setDateTime(textWithoutCommand, STRING_START);
				hasStart = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
		} else if (modifier == MODIFIER_END) {
			if (!hasDateOrDue && !hasEnd) {
				setDateTime(textWithoutCommand, STRING_END);
				hasEnd = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
		} else if (modifier == MODIFIER_DESCRIPTION || modifier == MODIFIER_DESC) {
			if (!hasDescription) {
				executeModifierAndTextParsing(COMMAND_DESCRIPTION, textWithoutCommand);
				hasDescription = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DESCRIPTION_MODIFIER;
			}
		} else if (modifier == MODIFIER_PRIORITY || modifier == MODIFIER_PRIORITY_P) {
			if (!hasPriority) {
				executePriorityParsing(textWithoutCommand);
				hasPriority = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_PRIORITY_MODIFIER;
			}
		} else if (modifier == MODIFIER_REMOVE || modifier == MODIFIER_RMV) {
			if (command == COMMAND_EDIT && !hasItem && !hasDateOrDue && !hasStart && !hasEnd && !hasDescription) {
				if (!hasRemove) {
					executeRemoveParsing(textWithoutCommand);
					hasRemove = true;
				} else {
					throw MESSAGE_INVALID_NUMBER_OF_REMOVE_MODIFIER;
				}
			} else if (command == COMMAND_ADD) {
				throw MESSAGE_INVALID_ADD_ITEM;
			}
		} else {
			throw MESSAGE_INVALID_MODIFIER;
		}
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeDateTimeParsing(const string dateTimeString) {
	if (dateTimeString == STRING_BLANK) {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	if (hasStartEndDateTime(dateTimeString)) {
		splitAndSetStartEndDateTime(dateTimeString);
	} else {
		setDateTime(dateTimeString, STRING_DATE);
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeModifierAndTextParsing(const string ModifierType, string text) {
	assert(ModifierType != STRING_BLANK);

	if (text != STRING_BLANK) {
		setParseInfo(ModifierType, text);
		return MESSAGE_SUCCESS;
	} else {
		throw MESSAGE_INVALID_INPUT;
	}
}

string iParser::executePriorityParsing(string priorityType) {
	convertToLowerCase(priorityType);

	if (priorityType == STRING_HIGH || priorityType == STRING_H) {
		setParseInfo(STRING_PRIORITY, STRING_HIGH);
	} else if (priorityType == STRING_MEDIUM || priorityType == STRING_MED || priorityType == STRING_M) {
		setParseInfo(STRING_PRIORITY, STRING_MEDIUM);
	} else if (priorityType == STRING_LOW || priorityType == STRING_L) {
		setParseInfo(STRING_PRIORITY, STRING_LOW);
	} else {
		throw MESSAGE_INVALID_PRIORITY;
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeRemoveParsing(string textToRemove) {
	assert(textToRemove != STRING_BLANK);

	convertToLowerCase(textToRemove);

	if (textToRemove == STRING_DATE) {
		setParseInfo(COMMAND_START, STRING_DATE_TIME_REMOVE);
		setParseInfo(COMMAND_END, STRING_DATE_TIME_REMOVE);
	} else if (textToRemove == STRING_START) {
		setParseInfo(COMMAND_START, STRING_DATE_TIME_REMOVE);
	} else if (textToRemove == STRING_END) {
		setParseInfo(COMMAND_END, STRING_DATE_TIME_REMOVE);
	} else if (textToRemove == STRING_DESCRIPTION || textToRemove == STRING_DESC) {
		setParseInfo(COMMAND_DESCRIPTION, STRING_BLANK);
	} else if (textToRemove == STRING_PRIORITY || textToRemove == STRING_PRIORITY_P) {
		setParseInfo(COMMAND_PRIORITY, STRING_BLANK);
	} else {
		throw MESSAGE_INVALID_REMOVE;
	}

	return MESSAGE_SUCCESS;
}


string iParser::retrieveCommandOrModifier(string userInput) {
	unsigned int endIndex = userInput.find_first_of(" \t");
	string command = userInput.substr(INDEX_START, endIndex);
	convertToLowerCase(command);
	return command;
}

vector<string> iParser::tokeniseText(const string text) {
	assert(text != STRING_BLANK);
	vector<string> tokenisedInformation;
	unsigned int startIndexForText = 0;
	unsigned int endIndexForText = 0;
	unsigned int startIndexForModifier = 0;
	unsigned int endIndexForModifier = 0;

	while (startIndexForModifier != INDEX_INVALID) {
		string tokenisedText;
		startIndexForModifier = text.find_first_of("-", endIndexForModifier);
		endIndexForModifier = text.find_first_of(" \t", startIndexForModifier);

		if (startIndexForModifier == INDEX_INVALID) {
			tokenisedText = text.substr(startIndexForText);
			trimText(tokenisedText);
			tokenisedInformation.push_back(tokenisedText);
		} else {
			string modifier = text.substr(startIndexForModifier, endIndexForModifier - startIndexForModifier);

			if (isModifier(modifier)) {
				endIndexForText = startIndexForModifier;
				tokenisedText = text.substr(startIndexForText, endIndexForText - startIndexForText);
				trimText(tokenisedText);
				if (tokenisedText == STRING_BLANK) {
					throw MESSAGE_INVALID_INPUT;
				}
				tokenisedInformation.push_back(tokenisedText);
				startIndexForText = endIndexForText;
			}
		}
	}

	return tokenisedInformation;
}

string iParser::removeFirstStringToken(string userInput) {
	unsigned int startIndex = userInput.find_first_of(" \t");
	string text;

	if (startIndex != INDEX_INVALID) {
		text = userInput.substr(++startIndex);
		return text;
	} else {
		return STRING_BLANK;
	}
}

string iParser::removeConsecutiveWhiteSpace(string& text) {
	unsigned int index;

	if (text == STRING_BLANK) {
		return MESSAGE_SUCCESS;
	}

	for (index = 0; index < text.length() - 1; index++) {
		if (isWhiteSpace(text[index]) && isWhiteSpace(text[index + 1])) {
			text.erase(index + 1, 1);
			index--;
		}
	}

	return MESSAGE_SUCCESS;
}

string iParser::removeWhiteSpace(string& text) {
	assert(text != STRING_BLANK);
	unsigned int index;

	for (index = 0; index < text.length(); index++) {
		if (isWhiteSpace(text[index])) {
			text.erase(index, 1);
			index--;
		}
	}

	return MESSAGE_SUCCESS;
}

string iParser::convertToLowerCase(string& text) {
	unsigned int index;
	unsigned int endIndex = text.length();

	for (index = 0; index < endIndex; index++) {
		text[index] = tolower(text[index]);
	}

	return MESSAGE_SUCCESS;
}

string iParser::trimText(string& text) {
	text = trimFront(text);
	text = trimBack(text);
	return MESSAGE_SUCCESS;
}

string iParser::trimFront(string text) {
	unsigned int startIndex = 0;

	while (startIndex < text.length() && (text[startIndex] == ' ' || text[startIndex] == '\t')) {
		startIndex++;
	}

	return text.substr(startIndex);
}

string iParser::trimBack(string text) {
	unsigned int endIndex = text.length();

	while (endIndex > 0 && (text[endIndex - 1] == ' ' || text[endIndex - 1] == '\t')) {
		endIndex--;
	}

	return text.substr(INDEX_START, endIndex);
}

bool iParser::hasStartEndDateTime(string dateTimeString) {
	unsigned int seperatorToIndex = dateTimeString.find(STRING_TO);
	unsigned int seperatorHyphenIndex = dateTimeString.find(CHAR_HYPHEN);

	if ((seperatorToIndex != INDEX_INVALID && seperatorHyphenIndex == INDEX_INVALID) ||
		(seperatorToIndex == INDEX_INVALID && seperatorHyphenIndex != INDEX_INVALID)) {
		return true;
	}

	return false;
}

string iParser::setDateTime(string dateTimeString, const string modifierType) {
	assert(dateTimeString != STRING_BLANK);
	assert(modifierType != STRING_BLANK);
	unsigned int numberOfCommas = retrieveCount(dateTimeString, CHAR_COMMA);

	if (dateTimeString == STRING_BLANK || numberOfCommas > 1) {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	string commandType;
	if (modifierType == STRING_DATE || modifierType == STRING_START) {
		commandType = COMMAND_START;
	} else if (modifierType == STRING_DUE || modifierType == STRING_END) {
		commandType = COMMAND_END;
	} else {
		throw MESSAGE_INVALID_INPUT;
	}

	if (numberOfCommas == 0) {
		string dateTimeToSet = STRING_BLANK;
		if (isValidDate(dateTimeString, dateTimeToSet)) {
			dateTimeToSet = dateTimeToSet + CHAR_SPACE + STRING_TIME_INITIALISE;
			setParseInfo(commandType, dateTimeToSet);
		} else if (isValidTime(dateTimeString, dateTimeToSet)) {
			dateTimeToSet = STRING_DATE_INITIALISE + CHAR_SPACE + dateTimeToSet;
			setParseInfo(commandType, dateTimeToSet);
		} else {
			throw MESSAGE_INVALID_DATE_TIME;
		}
	} else {
		splitAndSetDateTime(dateTimeString, commandType);
	}

	return MESSAGE_SUCCESS;
}

string iParser::splitAndSetDateTime(string dateTimeString, const string commandType) {
	assert(dateTimeString != STRING_BLANK);
	assert(commandType != STRING_BLANK);
	unsigned int startIndex = 0;
	unsigned int endIndex = dateTimeString.find_first_of(",");

	if (endIndex == dateTimeString.size() - 1) {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	string firstHalfOfDateTime = dateTimeString.substr(startIndex, endIndex + startIndex);
	startIndex = endIndex + 1;
	string secondHalfOfDateTime = dateTimeString.substr(startIndex);

	string dateTime = STRING_BLANK;
	string dateToSet = STRING_BLANK;
	string timeToSet = STRING_BLANK;

	if (isValidDate(firstHalfOfDateTime, dateToSet) && isValidTime(secondHalfOfDateTime, timeToSet)) {
		dateTime = dateToSet + CHAR_SPACE + timeToSet;
	} else if (isValidDate(secondHalfOfDateTime, dateToSet) && isValidTime(firstHalfOfDateTime, timeToSet)) {
		dateTime = dateToSet + CHAR_SPACE + timeToSet;
	} else {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	if (hasNoDayButHasTime(dateTime)) {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	setParseInfo(commandType, dateTime);

	return MESSAGE_SUCCESS;
}

string iParser::splitAndSetStartEndDateTime(const string dateTimeString) {
	assert(dateTimeString != STRING_BLANK);

	unsigned int numberOfCommas = retrieveCount(dateTimeString, CHAR_COMMA);

	if (numberOfCommas == 0) {
		splitAndSetNoCommaStartEndDateTime(dateTimeString);
	} else if (numberOfCommas == 1) {
		splitAndSetOneCommaStartEndDateTime(dateTimeString);
	} else if (numberOfCommas == 2) {
		splitAndSetTwoCommaStartEndDateTime(dateTimeString);
	} else {
		throw MESSAGE_INVALID_DATE_TIME;
	}
	return MESSAGE_SUCCESS;
}

string iParser::splitAndSetNoCommaStartEndDateTime(const string dateTimeString) {
	assert(dateTimeString != STRING_BLANK);

	unsigned int seperatorToIndex = dateTimeString.find(STRING_TO);
	unsigned int seperatorHyphenIndex = dateTimeString.find(CHAR_HYPHEN);
	string startDateTimeString = STRING_BLANK;
	string endDateTimeString = STRING_BLANK;

	if (seperatorToIndex != INDEX_INVALID) {
		startDateTimeString = dateTimeString.substr(INDEX_START, seperatorToIndex);
		endDateTimeString = dateTimeString.substr(seperatorToIndex + SIZE_OF_STRING_TO);
	} else if (seperatorHyphenIndex != INDEX_INVALID) {
		startDateTimeString = dateTimeString.substr(INDEX_START, seperatorHyphenIndex);
		endDateTimeString = dateTimeString.substr(seperatorHyphenIndex + SIZE_OF_STRING_HYPHEN);
	} else {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	string startInfo = STRING_BLANK;
	string endInfo = STRING_BLANK;
	if (isValidDate(startDateTimeString, startInfo) && isValidDate(endDateTimeString, endInfo)) {
		startInfo = startInfo + CHAR_SPACE + STRING_TIME_INITIALISE;
		endInfo = endInfo + CHAR_SPACE + STRING_TIME_INITIALISE;
	} else if (isValidTime(startDateTimeString, startInfo) && isValidTime(endDateTimeString, endInfo)) {
		startInfo = STRING_DATE_INITIALISE + CHAR_SPACE + startInfo;
		endInfo = STRING_DATE_INITIALISE + CHAR_SPACE + endInfo;
	} else {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	setParseInfo(COMMAND_START, startInfo);
	setParseInfo(COMMAND_END, endInfo);

	return MESSAGE_SUCCESS;
}
string iParser::splitAndSetOneCommaStartEndDateTime(const string dateTimeString) {
	assert(dateTimeString != STRING_BLANK);

	unsigned int seperatorToIndex = dateTimeString.find(STRING_TO);
	unsigned int seperatorHyphenIndex = dateTimeString.find(CHAR_HYPHEN);
	unsigned int commaIndex = dateTimeString.find_first_of(",");
	unsigned int seperatorIndex = INDEX_INVALID;
	unsigned int seperatorSize = 0;

	if (seperatorToIndex != INDEX_INVALID && seperatorHyphenIndex == INDEX_INVALID) {
		seperatorIndex = seperatorToIndex;
		seperatorSize = SIZE_OF_STRING_TO;
	} else if (seperatorToIndex == INDEX_INVALID && seperatorHyphenIndex != INDEX_INVALID) {
		seperatorIndex = seperatorHyphenIndex;
		seperatorSize = SIZE_OF_STRING_HYPHEN;
	} else {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	string startDateTimeString = STRING_BLANK;
	string endDateTimeString = STRING_BLANK;
	string fixedDateTimeString = STRING_BLANK;
	if (commaIndex < seperatorIndex) {
		fixedDateTimeString = dateTimeString.substr(INDEX_START, commaIndex);
		startDateTimeString = dateTimeString.substr(commaIndex + 1, seperatorIndex - commaIndex - 1);
		endDateTimeString = dateTimeString.substr(seperatorIndex + seperatorSize);
	} else {
		startDateTimeString = dateTimeString.substr(INDEX_START, seperatorIndex);
		unsigned int startIndexForEndDateTime = seperatorIndex + seperatorSize;
		endDateTimeString = dateTimeString.substr(startIndexForEndDateTime + 1, commaIndex - startIndexForEndDateTime - 1);
		fixedDateTimeString = dateTimeString.substr(commaIndex + 1);
	}

	string dateToSet = STRING_BLANK;
	if (isValidTime(fixedDateTimeString, dateToSet)) {
		throw MESSAGE_INVALID_DATE_TIME;
	} else if (isValidDate(fixedDateTimeString, dateToSet)) {
		string startTimeToSet = STRING_BLANK;
		string endTimeToSet = STRING_BLANK;

		if (isValidTime(startDateTimeString, startTimeToSet) && isValidTime(endDateTimeString, endTimeToSet)) {
			string startDateTime = dateToSet + CHAR_SPACE + startTimeToSet;
			string endDateTime = dateToSet + CHAR_SPACE + endTimeToSet;

			if (hasNoDayButHasTime(startDateTime)) {
				throw MESSAGE_INVALID_DATE_TIME;
			}

			setParseInfo(COMMAND_START, startDateTime);
			setParseInfo(COMMAND_END, endDateTime);
		} else {
			throw MESSAGE_INVALID_DATE_TIME;
		}
	} else {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	return MESSAGE_SUCCESS;
}

string iParser::splitAndSetTwoCommaStartEndDateTime(const string dateTimeString) {
	assert(dateTimeString != STRING_BLANK);

	unsigned int seperatorToIndex = dateTimeString.find(STRING_TO);
	unsigned int seperatorHyphenIndex = dateTimeString.find(CHAR_HYPHEN);
	unsigned int commaFirst = dateTimeString.find_first_of(",");
	unsigned int commaSecond = dateTimeString.find_first_of(",", commaFirst + 1);
	unsigned int seperatorIndex = INDEX_INVALID;
	unsigned int seperatorSize = 0;

	if (seperatorToIndex != INDEX_INVALID && seperatorHyphenIndex == INDEX_INVALID) {
		seperatorIndex = seperatorToIndex;
		seperatorSize = SIZE_OF_STRING_TO;
	} else if (seperatorToIndex == INDEX_INVALID && seperatorHyphenIndex != INDEX_INVALID) {
		seperatorIndex = seperatorHyphenIndex;
		seperatorSize = SIZE_OF_STRING_HYPHEN;
	} else {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	if (!(commaFirst < seperatorIndex && seperatorIndex < commaSecond)) {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	string startDateTimeString = dateTimeString.substr(INDEX_START, seperatorIndex);
	string endDateTimeString = dateTimeString.substr(seperatorIndex + seperatorSize);

	splitAndSetDateTime(startDateTimeString, COMMAND_START);
	splitAndSetDateTime(endDateTimeString, COMMAND_END);

	return MESSAGE_SUCCESS;
}


bool iParser::isValidDate(string dateString, string& dateToBeSet) {
	assert(dateString != STRING_BLANK);
	trimText(dateString);

	try {
		const unsigned int numberOfObliques = retrieveCount(dateString, CHAR_OBLIQUE);
		if (numberOfObliques > 2 || numberOfObliques < 0) {
			return false;
		} else if (numberOfObliques > 0) {
			dateToBeSet = splitAndSetObliqueDateInformation(dateString, numberOfObliques);
		} else {
			unsigned int numberOfSpaces = retrieveCount(dateString, CHAR_SPACE);
			if (numberOfSpaces > 2 || numberOfSpaces < 0) {
				return false;
			} else {
				dateToBeSet = splitAndSetSpaceDateInformation(dateString, numberOfSpaces);
			}
		}
	} catch (bool& booleanException) {
		return booleanException;
	}

	return true;
}

bool iParser::isValidTime(string timeString, string& timeToBeSet) {
	assert(timeString != STRING_BLANK);

	removeWhiteSpace(timeString);

	string suffix = STRING_BLANK;
	if (hasTimePeriodSuffix(timeString)) {
		unsigned int startIndex = 0;
		unsigned int endIndex = timeString.size() - 2;

		suffix = timeString.substr(endIndex);
		convertToLowerCase(suffix);
		timeString = timeString.substr(startIndex, endIndex);
	}

	try{
		timeToBeSet = splitAndSetTimeString(timeString, suffix);
	} catch (bool& booleanException) {
		return booleanException;
	}

	return true;
}

string iParser::splitAndSetObliqueDateInformation(string dateString, const unsigned int numberOfObliques) {
	assert(dateString != STRING_BLANK);
	assert(numberOfObliques > 0 && numberOfObliques <= 2);
	string day = STRING_NEGATIVE_ONE;
	string month = STRING_NEGATIVE_ONE;
	string year = STRING_NEGATIVE_ONE;
	unsigned int startIndex = 0;
	unsigned int endIndex = 0;

	removeWhiteSpace(dateString);

	endIndex = dateString.find_first_of("/");
	if (endIndex == dateString.size() - 1) {
		throw false;
	}

	day = dateString.substr(startIndex, endIndex - startIndex);
	if (!areDigits(day)) {
		throw false;
	}

	startIndex = endIndex + 1;

	if (numberOfObliques == 1) {
		month = dateString.substr(startIndex);
	} else if (numberOfObliques == 2) {
		endIndex = dateString.find_first_of("/", startIndex);
		if (endIndex == dateString.size() - 1) {
			throw false;
		}

		month = dateString.substr(startIndex, endIndex - startIndex);
		startIndex = endIndex + 1;
		year = dateString.substr(startIndex);
		if (!areDigits(year)) {
			throw false;
		}
	}

	if (!areDigits(month)) {
		throw false;
	}

	ostringstream output;
	output << year << CHAR_SPACE << month << CHAR_SPACE << day;

	return output.str();
}

string iParser::splitAndSetSpaceDateInformation(string dateString, const unsigned int numberOfSpaces) {
	assert(dateString != STRING_BLANK);
	assert(numberOfSpaces >= 0 && numberOfSpaces <= 2);
	string day = STRING_NEGATIVE_ONE;
	string month = STRING_NEGATIVE_ONE;
	string year = STRING_NEGATIVE_ONE;
	unsigned int keywordIndex = INDEX_INVALID;

	if (numberOfSpaces == 0) {
		if (isDay(dateString)) {
			day = setDay(dateString);
		} else {
			throw false;
		}
	} else {
		unsigned int startIndex = 0;
		unsigned int endIndex = 0;

		endIndex = dateString.find_first_of(" ");
		day = dateString.substr(startIndex, endIndex - startIndex);

		if (!areDigits(day)) {
			throw false;
		}
		startIndex = endIndex + 1;

		string tempMonth;
		if (numberOfSpaces == 1) {
			tempMonth = dateString.substr(startIndex);
			if (isMonth(tempMonth)) {
				month = setMonth(tempMonth);
			} else {
				throw false;
			}
		} else if (numberOfSpaces == 2) {
			endIndex = dateString.find_first_of(" ", startIndex);
			tempMonth = dateString.substr(startIndex, endIndex - startIndex);
			if (isMonth(tempMonth)) {
				month = setMonth(tempMonth);
			} else {
				throw false;
			}
			startIndex = endIndex + 1;
			year = dateString.substr(startIndex);
			if (!areDigits(year)) {
				throw false;
			}
		}
	}

	ostringstream output;
	output << year << CHAR_SPACE << month << CHAR_SPACE << day;

	return output.str();
}

string iParser::splitAndSetTimeString(string timeString, const string suffix) {
	assert(timeString != STRING_BLANK);
	const unsigned int numberOfColons = retrieveCount(timeString, CHAR_COLON);
	string output;

	if (numberOfColons == 0) {
		output = splitAndSetNoColonTimeString(timeString, suffix);
	} else if (numberOfColons == 1) {
		output = splitAndSetColonTimeString(timeString, suffix);
	} else {
		throw false;
	}

	return output;
}

string iParser::splitAndSetColonTimeString(string timeString, const string suffix) {
	assert(timeString != STRING_BLANK);
	string hour = STRING_NEGATIVE_ONE;
	string minute = STRING_NEGATIVE_ONE;
	unsigned int startIndex = 0;
	unsigned int endIndex = 0;

	endIndex = timeString.find_first_of(":");
	if (endIndex == timeString.size() - 1) {
		throw false;
	}
	hour = timeString.substr(startIndex, endIndex - startIndex);
	startIndex = endIndex + 1;
	minute = timeString.substr(startIndex);

	if (suffix == STRING_PM) {
		hour = addTwelveToHours(hour);
	}

	if (!isAppropriateTime(hour, minute, suffix)) {
		throw false;
	}

	ostringstream output;
	output << hour << CHAR_SPACE << minute;

	return output.str();
}

string iParser::splitAndSetNoColonTimeString(string timeString, const string suffix) {
	assert(timeString != STRING_BLANK);

	if (suffix != STRING_AM && suffix != STRING_PM && suffix != STRING_HR) {
		throw false;
	}

	string hour = STRING_NEGATIVE_ONE;
	string minute = STRING_NEGATIVE_ONE;
	unsigned int numberOfDigits = timeString.length();

	if ((numberOfDigits == 1 || numberOfDigits == 2) &&
		(suffix == STRING_AM || suffix == STRING_PM)) {
		hour = timeString;
		minute = STRING_MINUTE_INITIALISE;
	} else if (numberOfDigits == 3 &&
		(suffix == STRING_AM || suffix == STRING_PM)) {
		hour = timeString.substr(INDEX_START, 1);
		minute = timeString.substr(1);
	} else if (numberOfDigits == 4) {
		hour = timeString.substr(INDEX_START, 2);
		minute = timeString.substr(2);
	} else {
		throw false;
	}

	if (suffix == STRING_PM) {
		hour = addTwelveToHours(hour);
	}

	if (!isAppropriateTime(hour, minute, suffix)) {
		throw false;
	}

	ostringstream output;
	output << hour << CHAR_SPACE << minute;

	return output.str();
}

bool iParser::isDay(string dayString) {
	assert(dayString != STRING_BLANK);
	unsigned int index;

	convertToLowerCase(dayString);
	for (index = 0; index < NUMBER_OF_DAYS; index++) {
		if (dayString == STRING_DAYS[index] || dayString == STRING_DAYS_SHORT_FORM[index]) {
			return true;
		}
	}

	return false;
}

string iParser::setDay(string dayString) {
	assert(dayString != STRING_BLANK);
	unsigned int index;
	string output = STRING_BLANK;

	convertToLowerCase(dayString);
	for (index = 0; index < NUMBER_OF_DAYS; index++) {
		if (dayString == STRING_DAYS[index] || dayString == STRING_DAYS_SHORT_FORM[index]) {
			output = STRING_DAYS[index];
		}
	}

	return output;
}

bool iParser::isMonth(string monthString) {
	assert(monthString != STRING_BLANK);
	unsigned int index;

	convertToLowerCase(monthString);
	for (index = 0; index < NUMBER_OF_MONTHS; index++) {
		if (monthString == STRING_MONTHS[index] || monthString == STRING_MONTHS_SHORT_FORM[index]) {
			return true;
		}
	}

	return false;
}

string iParser::setMonth(string monthString) {
	assert(monthString != STRING_BLANK);
	unsigned int index;

	convertToLowerCase(monthString);
	for (index = 0; index < NUMBER_OF_MONTHS; index++) {
		if (monthString == STRING_MONTHS[index] || monthString == STRING_MONTHS_SHORT_FORM[index]) {
			ostringstream output;
			index++;
			output << index;
			return output.str();
		}
	}

	return STRING_BLANK;
}

bool iParser::hasTimePeriodSuffix(const string timeString) {
	assert(timeString != STRING_BLANK);
	if (timeString.size() < MIN_SIZE_OF_STRING_WITH_SUFFIX) {
		return false;
	}

	unsigned int secondLastCharacterIndex = timeString.size() - 2;
	string suffix = timeString.substr(secondLastCharacterIndex);

	convertToLowerCase(suffix);

	if (suffix == STRING_AM || suffix == STRING_PM || suffix == STRING_HR) {
		return true;
	} else {
		return false;
	}
}

string iParser::addTwelveToHours(const string hourString) {
	assert(hourString != STRING_BLANK);
	ostringstream output;

	if (areDigits(hourString)) {
		int hourInInt = stoi(hourString);
		if (hourInInt == HOURS_ZERO) {
			throw false;
		} else if (hourInInt >= HOURS_ONE_PM && hourInInt <= HOURS_ELEVEN_PM) {
			hourInInt += 12;
		}
		output << hourInInt;
	} else {
		throw false;
	}

	return output.str();
}

bool iParser::isAppropriateAMHour(const string hourString) {
	assert(hourString != STRING_BLANK);

	if (areDigits(hourString)) {
		int hourInInt = stoi(hourString);
		if (hourInInt > NUMBER_OF_HOURS) {
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

bool iParser::isAppropriateTime(const string hour, const string minute, const string suffix) {
	assert(hour != STRING_BLANK);
	assert(minute != STRING_BLANK);
	bool isValid = true;

	if (!areDigits(hour) || !areDigits(minute)) {
		isValid = false;
	}

	if (isValid && (minute.size() != SIZE_OF_STRING_MINUTES ||
		hour.size() < MIN_SIZE_OF_STRING_HOURS || hour.size() > MAX_SIZE_OF_STRING_HOURS)) {
		isValid = false;
	}

	if (isValid && suffix == STRING_AM && !isAppropriateAMHour(hour)) {
		isValid = false;
	}

	return isValid;
}

bool iParser::hasNoDayButHasTime(const string dateTimeString) {
	assert(dateTimeString != STRING_BLANK);

	unsigned int startOfDayIndex = dateTimeString.find_first_of(" ");
	startOfDayIndex = dateTimeString.find_first_of(" ", startOfDayIndex + 1);
	unsigned int startOfTimeIndex = dateTimeString.find_first_of(" ", startOfDayIndex + 1);

	startOfDayIndex++;
	startOfTimeIndex++;

	string day = dateTimeString.substr(startOfDayIndex, startOfTimeIndex - startOfDayIndex - 1);
	string time = dateTimeString.substr(startOfTimeIndex);

	if (day == STRING_NEGATIVE_ONE && time != STRING_TIME_INITIALISE) {
		return true;
	} else {
		return false;
	}
}

bool iParser::isModifier(string modifier) {
	assert(modifier != STRING_BLANK);
	convertToLowerCase(modifier);

	return (modifier == MODIFIER_NAME || modifier == MODIFIER_DATE ||
		modifier == MODIFIER_DUE || modifier == MODIFIER_START ||
		modifier == MODIFIER_END || modifier == MODIFIER_DESCRIPTION ||
		modifier == MODIFIER_DESC || modifier == MODIFIER_LABEL ||
		modifier == MODIFIER_PRIORITY || modifier == MODIFIER_PRIORITY_P ||
		modifier == MODIFIER_REMOVE || modifier == MODIFIER_RMV);
}

bool iParser::areDigits(const string text) {
	assert(text != STRING_BLANK);
	unsigned int index;

	for (index = 0; index < text.size(); index++) {
		if (!isdigit(text[index])) {
			return false;
		}
	}

	return true;
}

bool iParser::isWhiteSpace(const char character) {
	return (character == CHAR_SPACE || character == CHAR_TAB);
}

unsigned int iParser::retrieveCount(string text, const char character) {
	assert(text != STRING_BLANK);
	unsigned int count = 0;
	unsigned int index;

	for (index = 0; index < text.size(); index++) {
		if (text[index] == character) {
			count++;
		}
	}

	return count;
}

list<COMMAND_AND_TEXT> iParser::getParseInfo() {
	return _parseInfo;
}

string iParser::setParseInfo(string command, string text) {
	assert(command != STRING_BLANK);
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