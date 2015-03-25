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
const string iParser::STRING_TO = "to";
const string iParser::STRING_AM = "am";
const string iParser::STRING_PM = "pm";
const string iParser::STRING_DATE_INITIALISE = "-1 -1 -1";
const string iParser::STRING_TIME_INITIALISE = "-1 -1";
const string iParser::STRING_BLANK = "";
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
const string iParser::MESSAGE_INVALID_INPUT = "invalid input";
const string iParser::MESSAGE_INVALID_COMMAND = "invalid command";
const string iParser::MESSAGE_INVALID_ADD = "invalid text added";
const string iParser::MESSAGE_INVALID_EDIT = "invalid edit";
const string iParser::MESSAGE_INVALID_INDEX = "invalid index";
const string iParser::MESSAGE_INVALID_DATE_TIME = "invalid date and time";
const string iParser::MESSAGE_TERMINATE = "error encountered.Press any button to terminate programme...";

const unsigned int iParser::MAX_NUMBER_OF_COMMAS = 4;
const unsigned int iParser::MIN_SIZE_WITH_ABBREVIATION = 3;
const unsigned int iParser::SIZE_DAYS = 7;
const unsigned int iParser::SIZE_MONTHS = 12;
const unsigned int iParser::SIZE_DATETIME_WHITESPACE = 4;

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
	
	unsigned int numberOfCommas = retrieveCount(text, CHAR_COMMA);
	if (numberOfCommas >= 0 && numberOfCommas <= MAX_NUMBER_OF_COMMAS) {
		vector<string> tokenisedInformation = tokeniseText(text);
		try {
			checkAndSetTokenisedInformation(tokenisedInformation);
		}
		catch (string& exceptionMessage) {
			clearParseInfo();
			setParseInfo(MESSAGE_INVALID, exceptionMessage);
			return MESSAGE_FAILURE;
		}
	}
	else {
		setParseInfo(MESSAGE_INVALID, MESSAGE_INVALID_INPUT);
		return MESSAGE_FAILURE;
	}

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

// remember to SLAP this ==============================================================
string iParser::checkAndSetTokenisedInformation(vector<string>& tokenisedInformation) {
	if (tokenisedInformation.size() < 1 || tokenisedInformation[INDEX_START] == STRING_BLANK) {
		throw MESSAGE_INVALID_INPUT;
	}

	string description = tokenisedInformation[INDEX_START];
	setParseInfo(COMMAND_ADD, description);

	if (tokenisedInformation.size() == 1) {
		return MESSAGE_SUCCESS;
	}

	
	string startDate = STRING_DATE_INITIALISE;
	string endDate = STRING_DATE_INITIALISE;
	string startTime = STRING_TIME_INITIALISE;
	string endTime = STRING_TIME_INITIALISE;
	bool hasDate = false;
	bool hasTime = false;
	unsigned int dateTimeType = INDEX_INVALID;
	//bool hasLabel = false;
	//bool hasPriority = false;
	unsigned int index;

	for (index = INDEX_START+1; index < tokenisedInformation.size(); index++) {
		unsigned int seperatorPosition = INDEX_INVALID;
		unsigned int seperatorSize = INDEX_INVALID;
		string tokenisedString = tokenisedInformation[index];

		if ((!hasDate || !hasTime) && dateTimeType == INDEX_INVALID) {
			if (hasStartEnd(tokenisedString, seperatorPosition, seperatorSize)) {
				START_AND_END information;
				information = splitStartEnd(tokenisedString, seperatorPosition, seperatorSize, dateTimeType);

				if (dateTimeType == TYPE_START_END_DATE_AND_TIME || dateTimeType == TYPE_START_END_DATE) {
					startDate = information.start;
					endDate = information.end;
					hasDate = true;
				}
				else if (dateTimeType == TYPE_START_END_DATE_AND_TIME || dateTimeType == TYPE_START_END_TIME) {
					startTime = information.start;
					endTime = information.end;
					hasTime = true;
				}
			}
		}
		else {
			if (!hasDate && isValidDate(tokenisedString, startDate)) {
				hasDate = true;
			}
			else if (!hasTime && isValidTime(tokenisedString, startTime)) {
				hasTime = true;
			}
		}
	}
	
	string startInformation;
	string endInformation;
	if (dateTimeType != INDEX_INVALID) {
		startInformation = startDate + CHAR_SPACE + startTime;
		endInformation = endDate + CHAR_SPACE + endTime;
		setParseInfo(MODIFIER_START, startInformation);
		setParseInfo(MODIFIER_END, endInformation);
	}
	else if (hasDate && !hasTime) {
		startInformation = startDate + CHAR_SPACE + startTime;
		setParseInfo(MODIFIER_START, startInformation);
	}
	else if (hasTime && !hasDate) {
		endInformation = endDate + CHAR_SPACE + endTime;
		setParseInfo(MODIFIER_END, endInformation);
	}
	else {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	return MESSAGE_SUCCESS;
}
// remember to SLAP this ==============================================================

vector<string> iParser::tokeniseText(const string text) {
	vector<string> tokenisedInformation;
	unsigned int startIndex = INDEX_START;
	unsigned int endIndex = INDEX_START;

	while (endIndex != INDEX_INVALID) {
		endIndex = text.find_first_of(",", startIndex);
		string tokenisedString = text.substr(startIndex, endIndex - startIndex);
		trimText(tokenisedString);
		tokenisedInformation.push_back(tokenisedString);
		startIndex = endIndex + 1;
	}

	return tokenisedInformation;
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

	while (endIndex > INDEX_START && (text[endIndex - 1] == ' ' || text[endIndex - 1] == '\t')) {
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

	for (index = INDEX_START; index < endIndex - 1; index++) {
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
	unsigned int endIndex = text.length();

	for (index = INDEX_START; index < endIndex; index++) {
		if (isWhiteSpace(text[index])) {
			text.erase(index, 1);
			index--;
		}
	}

	return MESSAGE_SUCCESS;
}

string iParser::removeCharacter(string& text, const char character) {
	assert(text != STRING_BLANK);
	unsigned int index;
	unsigned int endIndex = text.length();

	for (index = INDEX_START; index < endIndex; index++) {
		if (text[index] == character) {
			text.erase(index, 1);
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

bool iParser::areDigits(const string text) {
	assert(text != STRING_BLANK);
	bool isValid = true;
	unsigned int index;

	for (index = INDEX_START; isValid && index < text.size(); index++) {
		if (!isdigit(text[index])) {
			isValid = false;
		}
	}

	return isValid;
}

bool iParser::isWhiteSpace(const char character) {
	return (character == CHAR_SPACE || character == CHAR_TAB);
}

bool iParser::hasStartEnd(string text, unsigned int& seperatorPosition, unsigned int& seperatorSize) {
	assert(text != STRING_BLANK);
	seperatorPosition = text.find(STRING_TO);
	if (seperatorPosition != INDEX_INVALID) {
		seperatorSize = STRING_TO.size();
		return true;
	}

	seperatorPosition = text.find(CHAR_HYPHEN);
	if (seperatorPosition != INDEX_INVALID) {
		seperatorSize = 1;
		return true;
	}

	return false;
}

// remember to SLAP this ==============================================================
START_AND_END iParser::splitStartEnd(const string text, const unsigned int seperatorPosition, const unsigned int seperatorSize, unsigned int& type) {
	assert(text != STRING_BLANK);
	START_AND_END information;
	string startInformation = STRING_BLANK;
	string endInformation = STRING_BLANK;
	string startDate = STRING_BLANK;
	string startTime = STRING_BLANK;
	string endDate = STRING_BLANK;
	string endTime = STRING_BLANK;
	bool hasStartEndDateAndTime = false;

	string start = text.substr(INDEX_START, seperatorPosition);
	string end = text.substr(seperatorPosition + seperatorSize);
	unsigned int numberOfCommasInStart = retrieveCount(start, CHAR_COMMA);
	unsigned int numberOfCommasInEnd = retrieveCount(start, CHAR_COMMA);

	if (numberOfCommasInStart > 1 || numberOfCommasInEnd > 1) {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	if (numberOfCommasInStart == 1) {
		unsigned int startIndex = INDEX_START;
		unsigned int endIndex = start.find_first_of(",");
		startDate = start.substr(startIndex, endIndex);
		startIndex = endIndex + 1;
		startTime = start.substr(startIndex);
		
		string startDateInformation;
		string startTimeInformation;
		if (isValidDate(startDate, startDateInformation) && isValidTime(startTime, startTimeInformation)) {
			start = startDateInformation + CHAR_SPACE + startTimeInformation;
			hasStartEndDateAndTime = true;
		}
		else {
			throw MESSAGE_INVALID_DATE_TIME;
		}
	}
		
	if (numberOfCommasInEnd == 1) {
		unsigned int startIndex = INDEX_START;
		unsigned int endIndex = end.find_first_of(",");
		endDate = end.substr(startIndex, endIndex);
		startIndex = endIndex + 1;
		endTime = end.substr(startIndex);
		
		string endDateInformation;
		string endTimeInformation;
		if (isValidDate(endDate, endDateInformation) && isValidTime(endTime, endTimeInformation)) {
			start = endDateInformation + CHAR_SPACE + endTimeInformation;
			hasStartEndDateAndTime = true;
		}
		else {
			throw MESSAGE_INVALID_DATE_TIME;
		}
	}
	
	if (hasStartEndDateAndTime) {
		type = TYPE_START_END_DATE_AND_TIME;
	}
	else if (isValidDate(start, startInformation) && isValidDate(end, endInformation)) {
		type = TYPE_START_END_DATE;
	}
	else if (isValidTime(start, startInformation) && isValidTime(end, endInformation)) {
		type = TYPE_START_END_TIME;
	}
	else {
		throw MESSAGE_INVALID_DATE_TIME;
	}

	information.start = startInformation;
	information.end = endInformation;

	return information;
}
// remember to SLAP this ==============================================================

bool iParser::isValidDate(string dateString, string& dateToBeSet) {
	if (dateString == STRING_BLANK) {
		return false;
	}

	trimText(dateString);

	try {
		const unsigned int numberOfObliques = retrieveCount(dateString, CHAR_OBLIQUE);
		if (numberOfObliques > 2 && numberOfObliques < 0) {
			return false;
		}
		else if (numberOfObliques > 0) {
			dateToBeSet = splitAndSetObliqueDateInformation(dateString, numberOfObliques);
		}
		else {
			unsigned int numberOfSpaces = retrieveCount(dateString, CHAR_SPACE);
			if (numberOfSpaces > 2 && numberOfSpaces < 0) {
				return false;
			}
			else {
				dateToBeSet = splitAndSetSpaceDateInformation(dateString, numberOfSpaces);
			}
		}
	}
	catch (exception& e) {
		return false;
	}

	return true;
}

bool iParser::isValidTime(string timeString, string& timeToBeSet) {
	if (timeString == STRING_BLANK) {
		return false;
	}
	
	removeWhiteSpace(timeString);

	string abbreviation = STRING_BLANK;
	if (hasTimePeriodAbbreviation(timeString)) {
		unsigned int startIndex = INDEX_START;
		unsigned int endIndex = timeString.size() - 2;

		abbreviation = timeString.substr(endIndex);
		timeString = timeString.substr(startIndex, endIndex);
		convertToLowerCase(abbreviation);
	}
	
	try{
		timeToBeSet = splitAndSetTimeString(timeString, abbreviation);
	}
	catch (exception& e) {
		return false;
	}

	return true;
}

string iParser::splitAndSetObliqueDateInformation(string date, const unsigned int numberOfObliques) {
	assert(date != STRING_BLANK);
	assert(numberOfObliques > 0 && numberOfObliques <= 2);
	string day = STRING_NEGATIVE_ONE;
	string month = STRING_NEGATIVE_ONE;
	string year = STRING_NEGATIVE_ONE;
	unsigned int startIndex = INDEX_START;
	unsigned int endIndex = INDEX_START;

	endIndex = date.find_first_of("/");
	day = date.substr(startIndex, endIndex - startIndex);
	if (!areDigits(day)) {
		throw exception("invalid day");
	}
	startIndex = ++endIndex;

	if (numberOfObliques == 1) {
		month = date.substr(startIndex);
	}
	else if (numberOfObliques == 2) {
		endIndex = date.find_first_of("/", startIndex);
		month = date.substr(startIndex, endIndex - startIndex);
		startIndex = ++endIndex;
		year = date.substr(startIndex);
		if (!areDigits(year)) {
			throw exception("invalid year");
		}
	}

	if (!areDigits(month)) {
		throw exception("invalid month");
	}

	ostringstream output;
	output << day << CHAR_SPACE << month << CHAR_SPACE << year;

	return output.str();
}

string iParser::splitAndSetSpaceDateInformation(string date, const unsigned int numberOfSpaces) {
	assert(date != STRING_BLANK);
	assert(numberOfSpaces >= 0 && numberOfSpaces <= 2);
	string day = STRING_NEGATIVE_ONE;
	string month = STRING_NEGATIVE_ONE;
	string year = STRING_NEGATIVE_ONE;
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
			else {
				throw exception("invalid keyword");
			}
		}
	}
	else {
		unsigned int startIndex = INDEX_START;
		unsigned int endIndex = INDEX_START;

		string tempMonth;
		endIndex = date.find_first_of(" ");
		day = date.substr(startIndex, endIndex - startIndex);
		if (!areDigits(day)) {
			throw exception("invalid day");
		}
		startIndex = ++endIndex;

		if (numberOfSpaces == 1) {
			tempMonth = date.substr(startIndex);
			if (isMonth(tempMonth, keywordIndex)) {
				month = STRING_MONTHS_IN_NUMBER[keywordIndex];
			}
			else {
				throw exception("invalid month");
			}
		}
		else if (numberOfSpaces == 2) {
			endIndex = date.find_first_of(" ", startIndex);
			tempMonth = date.substr(startIndex, endIndex - startIndex);
			if (isMonth(tempMonth, keywordIndex)) {
				month = STRING_MONTHS_IN_NUMBER[keywordIndex];
			}
			else {
				throw exception("invalid month");
			}
			startIndex = ++endIndex;
			year = date.substr(startIndex);
			if (!areDigits(year)) {
				throw exception("invalid year");
			}
		}
	}

	ostringstream output;
	output << day << CHAR_SPACE << month << CHAR_SPACE << year;

	return output.str();
}

string iParser::splitAndSetTimeString(string timeString, const string abbreviation) {
	assert(timeString != STRING_BLANK);
	const unsigned int numberOfColons = retrieveCount(timeString, CHAR_COLON);
	string output;

	if (numberOfColons == 0) {
		output = splitAndSetNoColonTimeString(timeString, abbreviation);
	}
	else if (numberOfColons == 1) {
		output = splitAndSetColonTimeString(timeString, abbreviation);
	}
	else {
		throw exception("invalid time");
	}
	
	return output;
}

string iParser::splitAndSetColonTimeString(string timeString, const string abbreviation) {
	assert(timeString != STRING_BLANK);
	string hour = STRING_NEGATIVE_ONE;
	string minute = STRING_NEGATIVE_ONE;
	unsigned int startIndex = INDEX_START;
	unsigned int endIndex = INDEX_START;

	endIndex = timeString.find_first_of(":");
	hour = timeString.substr(startIndex, endIndex - startIndex);
	startIndex = endIndex + 1;
	minute = timeString.substr(startIndex);

	if (abbreviation == STRING_PM) {
		hour = addTwelveToHours(hour);
	}

	if (!areDigits(hour) || !areDigits(minute)) {
		throw exception("invalid time");
	}

	ostringstream output;
	output << hour << CHAR_SPACE << minute;

	return output.str();
}

string iParser::splitAndSetNoColonTimeString(string timeString, const string abbreviation) {
	assert(timeString != STRING_BLANK);
	string hour = STRING_NEGATIVE_ONE;
	string minute = STRING_NEGATIVE_ONE;
	unsigned int numberOfDigits = timeString.length();
	bool hasAbbreviation = !abbreviation.empty();

	if (numberOfDigits == 1 || numberOfDigits == 2) {
		hour = timeString;
	}
	else if (numberOfDigits == 3) {
		hour = timeString.substr(INDEX_START, 1);
		minute = timeString.substr(1);
		if (!areDigits(minute)) {
			throw exception("invalid minute");
		}
	}
	else if (numberOfDigits == 4) {
		hour = timeString.substr(INDEX_START, 2);
		minute = timeString.substr(2);
		if (!areDigits(minute)) {
			throw exception("invalid minute");
		}
	}

	if (hasAbbreviation) {
		if (abbreviation == STRING_PM) {
			hour = addTwelveToHours(hour);
		}
	}

	if (!areDigits(hour)) {
		throw exception("invalid hour");
	}

	ostringstream output;
	output << hour << CHAR_SPACE << minute;

	return output.str();
}

bool iParser::isValidDateTimeString(const string dateTimeString) {
	assert(dateTimeString != STRING_BLANK);
	unsigned whiteSpaceCount = retrieveCount(dateTimeString, CHAR_SPACE);
	if (whiteSpaceCount != SIZE_DATETIME_WHITESPACE) {
		return false;
	}

	bool isValid = true;
	unsigned int endIndex = dateTimeString.find_first_of(" ");
	string day = dateTimeString.substr(INDEX_START, endIndex);

	if (!isDay(day)) {
		unsigned int index;
		for (index = INDEX_START; isValid && index < dateTimeString.size(); index++) {
			if (dateTimeString[index] != CHAR_SPACE &&
				dateTimeString[index] != CHAR_HYPHEN &&
				!isdigit(dateTimeString[index])) {
				isValid = false;
			}
		}
	}

	unsigned int index;
	for (index = endIndex; isValid && index < dateTimeString.size(); index++) {
		if (dateTimeString[index] != CHAR_SPACE &&
			dateTimeString[index] != CHAR_HYPHEN &&
			!isdigit(dateTimeString[index])) {
			isValid = false;
		}
	}

	return isValid;
}

bool iParser::isDay(string day, unsigned int& indexToSet) {
	assert(day != STRING_BLANK);
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

bool iParser::isDay(string day) {
	assert(day != STRING_BLANK);
	
	unsigned int index;
	convertToLowerCase(day);
	for (index = INDEX_START; index < SIZE_DAYS; index++) {
		if (day == STRING_DAYS[index] || day == STRING_DAYS_SHORT_FORM[index]) {
			return true;
		}
	}
	return false;
}

bool iParser::isMonth(string month, unsigned int& indexToSet) {
	assert(month != STRING_BLANK);
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

bool iParser::hasTimePeriodAbbreviation(const string timeString) {
	assert(timeString != STRING_BLANK);
	if (timeString.size() < MIN_SIZE_WITH_ABBREVIATION) {
		return false;
	}

	unsigned int secondLastCharacterIndex = timeString.size() - 2;
	string abbreviation = timeString.substr(secondLastCharacterIndex);
	
	convertToLowerCase(abbreviation);

	if (abbreviation == STRING_AM || abbreviation == STRING_PM) {
		return true;
	}
	else {
		return false;
	}
}

string iParser::addTwelveToHours(const string hour) {
	assert(hour != STRING_BLANK);
	ostringstream output;

	if (areDigits(hour)) {
		int hourInInt = stoi(hour);
		hourInInt += 12;
		output << hourInInt;
	}
	else {
		output << STRING_NEGATIVE_ONE;
	}

	return output.str();
}

unsigned int iParser::retrieveCount(string text, const char character) {
	assert(text != STRING_BLANK);
	unsigned int count = INDEX_START;
	unsigned int index;

	for (index = INDEX_START; index < text.size(); index++) {
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
	int i = INDEX_START;

	for (iter = _parseInfo.begin(); iter != _parseInfo.end(); i++, iter++) {
		cout << "Line " << i << ": " << "\"" << iter->command << "\"" << "\"" << iter->text << "\"" << endl;
	}
}

void iParser::showError(string text) {
	cout << text;
}