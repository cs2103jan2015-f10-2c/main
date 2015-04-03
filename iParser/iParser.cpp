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
const string iParser::COMMAND_EXIT = "exit";

const string iParser::COMMAND_ITEM = "item";
const string iParser::COMMAND_START = "start";
const string iParser::COMMAND_END = "end";
const string iParser::COMMAND_DESCRIPTION = "description";
const string iParser::COMMAND_PRIORITY = "priority";

const string iParser::MODIFIER_DATE = "date";
const string iParser::MODIFIER_DUE = "due";
const string iParser::MODIFIER_START = "start";
const string iParser::MODIFIER_END = "end";

const string iParser::STRING_ITEM = "-item";
const string iParser::STRING_DATE = "-date";
const string iParser::STRING_DUE = "-due";
const string iParser::STRING_START = "-start";
const string iParser::STRING_END = "-end";
const string iParser::STRING_DESCRIPTION = "-description";
const string iParser::STRING_DESC = "-desc";
const string iParser::STRING_LABEL = "-label";
const string iParser::STRING_PRIORITY = "-priority";
const string iParser::STRING_PRIORITY_EXCLAMATION = "-!";

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
const string iParser::STRING_BLANK = "";
const string iParser::STRING_ZERO = "0";
const string iParser::STRING_NEGATIVE_ONE = "-1";
const char iParser::CHAR_SPACE = ' ';
const char iParser::CHAR_TAB = '\t';
const char iParser::CHAR_COMMA = ',';
const char iParser::CHAR_OBLIQUE = '/';
const char iParser::CHAR_HYPHEN = '-';
const char iParser::CHAR_COLON = ':';

const string iParser::MESSAGE_SUCCESS = "success";
const string iParser::MESSAGE_FAILURE = "failure";
const string iParser::MESSAGE_INVALID = "invalid";
const string iParser::MESSAGE_INVALID_INPUT = "Invalid input";
const string iParser::MESSAGE_INVALID_COMMAND = "Invalid command";
const string iParser::MESSAGE_INVALID_DATE_TIME = "Invalid date and time";
const string iParser::MESSAGE_TERMINATE = "Error encountered.Press any button to terminate programme...";

const string iParser::MESSAGE_INVALID_ADD_ITEM = "Unable to use \'-item\' modifier when using \'add\' command";
const string iParser::MESSAGE_INVALID_NUMBER_OF_ITEM = "Unable to use \'-item\' modifier more than once";
const string iParser::MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER = "Unable to use multiple date time modifiers";

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
const unsigned int iParser::TYPE_START_END_DATE_AND_TIME = 1;
const unsigned int iParser::TYPE_START_END_DATE = 2;
const unsigned int iParser::TYPE_START_END_TIME = 3;

iParser::iParser() {}

iParser::~iParser() {}

list<COMMAND_AND_TEXT> iParser::parse(string userInput) {
	assert(userInput[0] != NULL);
	executeParsing(userInput);
	return _parseInfo;
}

string iParser::executeParsing(string userInput) {
	assert(userInput[0] != NULL);
	trimText(userInput);
	removeConsecutiveWhiteSpace(userInput);
	string command = retrieveCommandOrModifier(userInput);
	CommandType commandType = determineCommandType(command);
	string textWithoutCommand = removeFirstStringToken(userInput);

	switch (commandType) {
	case ADD:
		executeAddParsing(textWithoutCommand);
		break;
	case DELETE:
		executeCommandAndTextParsing(textWithoutCommand, COMMAND_DELETE);
		break;
	case CLEAR:
		executeCommandParsing(userInput, COMMAND_CLEAR);
		break;
	case EDIT:
		executeEditParsing(textWithoutCommand);
		break;
	case UNDO:
		executeCommandParsing(userInput, COMMAND_UNDO);
		break;
	case SORT:
		executeCommandAndTextParsing(textWithoutCommand, COMMAND_SORT);
		break;
	case SEARCH:
		executeCommandAndTextParsing(textWithoutCommand, COMMAND_SEARCH);
		break;
	case VIEW:
		executeCommandAndTextParsing(textWithoutCommand, COMMAND_VIEW);
		break;
	case SAVE:
		executeCommandAndTextParsing(textWithoutCommand, COMMAND_SAVE);
		break;
	case DONE:
		executeCommandAndTextParsing(textWithoutCommand, COMMAND_DONE);
		break;
	case EXIT:
		executeCommandParsing(userInput, COMMAND_EXIT);
		break;
	case INVALID_COMMAND:
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_COMMAND);
		break;
	default:
		exit(EXIT_FAILURE);
	}

	return MESSAGE_SUCCESS;
}

iParser::CommandType iParser::determineCommandType(string command) {
	if (command == COMMAND_ADD) {
		return CommandType::ADD;
	} else if (command == COMMAND_DELETE || command == COMMAND_DEL) {
		return CommandType::DELETE;
	} else if (command == COMMAND_EDIT) {
		return CommandType::EDIT;
	} else if (command == COMMAND_UNDO) {
		return CommandType::UNDO;
	} else if (command == COMMAND_SORT) {
		return CommandType::SORT;
	} else if (command == COMMAND_SEARCH) {
		return CommandType::SEARCH;
	} else if (command == COMMAND_VIEW) {
		return CommandType::VIEW;
	} else if (command == COMMAND_SAVE) {
		return CommandType::SAVE;
	} else if (command == COMMAND_DONE) {
		return CommandType::DONE;
	} else if (command == COMMAND_EXIT) {
		return CommandType::EXIT;
	} else {
		return CommandType::INVALID_COMMAND;
	}
}

iParser::ModifierType iParser::determineModifierType(string modifier) {
	if (modifier == STRING_ITEM) {
		return ModifierType::ITEM;
	} else if (modifier == STRING_DATE) {
		return ModifierType::DATE;
	} else if (modifier == STRING_DUE) {
		return ModifierType::DUE;
	} else if (modifier == STRING_START) {
		return ModifierType::START;
	} else if (modifier == STRING_END) {
		return ModifierType::END;
	} else if (modifier == STRING_DESCRIPTION || modifier == STRING_DESC) {
		return ModifierType::DESCRIPTION;
	} else if (modifier == STRING_PRIORITY || modifier == STRING_PRIORITY_EXCLAMATION) {
		return ModifierType::PRIORITY;
	} else
		return ModifierType::INVALID_MODIFIER;
}

string iParser::executeAddParsing(string text) {
	if (text == STRING_BLANK) {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
		return MESSAGE_FAILURE;
	}

	vector<string> tokenisedInformation = tokeniseText(text);
	try {
		string itemName = tokenisedInformation[INDEX_START];
		setParseInfo(COMMAND_ADD, itemName);
		if (tokenisedInformation.size() > 1) {
			checkAndSetTokenisedInformation(tokenisedInformation, COMMAND_ADD);
		}
	}
	catch (string& exceptionMessage) {
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

	vector<string> tokenisedInformation = tokeniseText(text);
	try {
		string indexToEdit = tokenisedInformation[INDEX_START];
		setParseInfo(COMMAND_EDIT, indexToEdit);
		if (tokenisedInformation.size() > 1) {
			checkAndSetTokenisedInformation(tokenisedInformation, COMMAND_EDIT);
		}
	}
	catch (string& exceptionMessage) {
		clearParseInfo();
		setParseInfo(MESSAGE_INVALID, exceptionMessage);
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

string iParser::executeCommandParsing(const string commandType, string userInput) {
	if (userInput == commandType) {
		setParseInfo(commandType);
		return MESSAGE_SUCCESS;
	} else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_COMMAND);
		return MESSAGE_FAILURE;
	}
}

string iParser::executeModifierAndTextParsing(const string ModifierType, string text) {
	if (text != STRING_BLANK) {
		convertToLowerCase(text);
		setParseInfo(ModifierType, text);
		return MESSAGE_SUCCESS;
	} else {
		throw MESSAGE_INVALID_INPUT;
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

	for (unsigned int index = 1; index < tokenisedInformation.size(); index++) {
		string singleInformation = tokenisedInformation[index];
		string modifier = retrieveCommandOrModifier(singleInformation);
		ModifierType modifierType = determineModifierType(modifier);
		string textWithoutCommand = removeFirstStringToken(singleInformation);

		switch (modifierType) {
		case ITEM:
			if (command == COMMAND_EDIT && !hasItem) {
				executeModifierAndTextParsing(COMMAND_ITEM, textWithoutCommand);
				hasItem = true;
			} else {
				if (command == COMMAND_ADD) {
					throw MESSAGE_INVALID_ADD_ITEM;
				} else if (hasItem) {
					throw MESSAGE_INVALID_NUMBER_OF_ITEM;
				}
			}
			break;
		case DATE:
			if (!hasDateOrDue && !hasStart && !hasEnd) {
				executeDateTimeParsing(textWithoutCommand, MODIFIER_DATE);
				hasDateOrDue = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
			break;
		case DUE:
			if (!hasDateOrDue && !hasStart && !hasEnd) {
				setDateTime(textWithoutCommand, MODIFIER_DUE);
				hasDateOrDue = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
			break;
		case START:
			if (!hasDateOrDue && !hasStart) {
				setDateTime(textWithoutCommand, MODIFIER_START);
				hasStart = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
			break;
		case END:
			if (!hasDateOrDue && !hasEnd) {
				setDateTime(textWithoutCommand, MODIFIER_END);
				hasEnd = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
			break;
		case DESCRIPTION:
			if (!hasDescription) {
				executeModifierAndTextParsing(COMMAND_DESCRIPTION, textWithoutCommand);
				hasDescription = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
			break;
		case PRIORITY:
			if (!hasPriority) {
				executeModifierAndTextParsing(COMMAND_PRIORITY, textWithoutCommand);
				hasPriority = true;
			} else {
				throw MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
			}
			break;
		default:
			throw MESSAGE_INVALID_INPUT;
		}
	}

	return MESSAGE_SUCCESS;
}

string iParser::executeDateTimeParsing(string dateTimeString, const string modifierType) {
	if (hasStartEndDateTime(dateTimeString)) {
		//splitAndSetStartEnd(dateTimeString);
	} else {
		setDateTime(dateTimeString, modifierType);
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
				tokenisedInformation.push_back(tokenisedText);
				startIndexForText = endIndexForText;
			}
		}
	}

	return tokenisedInformation;
}

string iParser::retrieveFirstStringToken(string text) {
	unsigned int endIndex = text.find_first_of(" \t");
	string firstString = text.substr(INDEX_START, endIndex);
	return firstString;
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
	assert(dateTimeString != STRING_BLANK);

	bool isValid = false;
	unsigned int seperatorToIndex = dateTimeString.find(STRING_TO);
	unsigned int seperatorHyphenIndex = dateTimeString.find(CHAR_HYPHEN);

	if ((seperatorToIndex != INDEX_INVALID && seperatorHyphenIndex == INDEX_INVALID) ||
		(seperatorToIndex == INDEX_INVALID && seperatorHyphenIndex != INDEX_INVALID)) {
		isValid = true;
	}

	return isValid;
}

string iParser::setDateTime(string dateTimeString, const string modifierType) {
	assert(modifierType != STRING_BLANK);
	unsigned int numberOfCommas = retrieveCount(dateTimeString, CHAR_COMMA);

	if (dateTimeString == STRING_BLANK || numberOfCommas > 1) {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	string commandType;
	if (modifierType == MODIFIER_DATE || modifierType == MODIFIER_START) {
		commandType = COMMAND_START;
	} else {
		commandType = COMMAND_END;
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
	} else {
		seperatorIndex = seperatorHyphenIndex;
		seperatorSize = SIZE_OF_STRING_HYPHEN;
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
	if (dateString == STRING_BLANK) {
		return false;
	}

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
	}
	catch (bool& booleanException) {
		return booleanException;
	}

	return true;
}

bool iParser::isValidTime(string timeString, string& timeToBeSet) {
	if (timeString == STRING_BLANK) {
		return false;
	}

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
	}
	catch (bool& booleanException) {
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
		bool hasDay = false;
		if (isDay(dateString)) {
			day = setDay(dateString);
			hasDay = true;
		}

		if (!hasDay) {
			if (isMonth(dateString)) {
				month = setMonth(dateString);
			} else {
				throw false;
			}
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

	if (!isAppropriateTiming(hour, minute, suffix)) {
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

	if (!isAppropriateTiming(hour, minute, suffix)) {
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

bool iParser::isAppropriateHour(const string hourString) {
	assert(hourString != STRING_BLANK);

	if (areDigits(hourString)) {
		int hourInInt = stoi(hourString);
		if (hourInInt > NUMBER_OF_HOURS) {
			return false;
		}
	} else {
		return false;
	}

	return true;
}

bool iParser::isAppropriateTiming(const string hour, const string minute, const string suffix) {
	bool isValid = true;

	if (!areDigits(hour) && !areDigits(minute)) {
		isValid = false;
	}
	
	if (isValid && minute.size() != SIZE_OF_STRING_MINUTES &&
		(hour.size() < MIN_SIZE_OF_STRING_HOURS || hour.size() > MAX_SIZE_OF_STRING_HOURS)) {
		isValid = false;
	}

	if (isValid && suffix == STRING_AM && !isAppropriateHour(hour)) {
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

	string day = dateTimeString.substr(startOfDayIndex, startOfTimeIndex - startOfDayIndex);
	string time = dateTimeString.substr(startOfTimeIndex);

	if (day == STRING_NEGATIVE_ONE && time != STRING_TIME_INITIALISE) {
		return true;
	} else return false;
}


bool iParser::isModifier(string modifier) {
	convertToLowerCase(modifier);

	return (modifier == STRING_ITEM || modifier == STRING_DATE ||
		modifier == STRING_DUE || modifier == STRING_START ||
		modifier == STRING_END || modifier == STRING_DESCRIPTION ||
		modifier == STRING_DESC || modifier == STRING_LABEL || modifier == STRING_PRIORITY);
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

void iParser::showParseInfo() {
	list<COMMAND_AND_TEXT>::iterator iter;
	int i = 0;

	for (iter = _parseInfo.begin(); iter != _parseInfo.end(); i++, iter++) {
		cout << "Command " << ": " << iter->command
			<< " Text: " << iter->text << endl;
	}
}