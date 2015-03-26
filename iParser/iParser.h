//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

/*
===================================================================================================
NOTES TO DEVELOPERS
===================================================================================================
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <cctype>
#include <assert.h>
using namespace std;

#ifndef IPARSER_H_
#define IPARSER_H_

struct COMMAND_AND_TEXT {
	string command;
	string text;
};

struct START_AND_END {
	string start;
	string end;
};

class iParser {
public:
	list<COMMAND_AND_TEXT> _parseInfo;

	static const string COMMAND_ADD;
	static const string COMMAND_DELETE_ONE;
	static const string COMMAND_DELETE_TWO;
	static const string COMMAND_EDIT;
	static const string COMMAND_UNDO;
	static const string COMMAND_SORT;
	static const string COMMAND_SEARCH;
	static const string COMMAND_VIEW;
	static const string COMMAND_SAVE;
	static const string COMMAND_DONE;
	static const string COMMAND_EXIT;

	static const string COMMAND_ITEM;
	static const string COMMAND_START;
	static const string COMMAND_END;
	static const string COMMAND_DESCRIPTION;
	static const string COMMAND_LABEL;
	static const string COMMAND_PRIORITY;

	static const string MODIFIER_DATE;
	static const string MODIFIER_DUE;

	static const string STRING_ITEM;
	static const string STRING_DATE;
	static const string STRING_DUE;
	static const string STRING_DESCRIPTION;
	static const string STRING_DESC;
	static const string STRING_LABEL;
	static const string STRING_PRIORITY;

	static const string STRING_DAYS[];
	static const string STRING_DAYS_SHORT_FORM[];
	static const string STRING_MONTHS[];
	static const string STRING_MONTHS_SHORT_FORM[];
	static const string STRING_MONTHS_IN_NUMBER[];
	static const string STRING_TO;
	static const string STRING_AM;
	static const string STRING_PM;
	static const string STRING_DATE_INITIALISE;
	static const string STRING_TIME_INITIALISE;
	static const string STRING_BLANK;
	static const string STRING_NEGATIVE_ONE;

	static const char CHAR_SPACE;
	static const char CHAR_TAB;
	static const char CHAR_COMMA;
	static const char CHAR_OBLIQUE;
	static const char CHAR_HYPHEN;
	static const char CHAR_COLON;

	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_FAILURE;
	static const string MESSAGE_INVALID;
	static const string MESSAGE_INVALID_INPUT;
	static const string MESSAGE_INVALID_COMMAND;
	static const string MESSAGE_INVALID_ADD;
	static const string MESSAGE_INVALID_EDIT;
	static const string MESSAGE_INVALID_INDEX;
	static const string MESSAGE_INVALID_SAVE;
	static const string MESSAGE_INVALID_DATE_TIME;
	static const string MESSAGE_TERMINATE;

	static const unsigned int MAX_NUMBER_OF_COMMAS;
	static const unsigned int MIN_SIZE_WITH_ABBREVIATION;
	static const unsigned int SIZE_DAYS;
	static const unsigned int SIZE_MONTHS;
	static const unsigned int SIZE_DATETIME_WHITESPACE;

	static const unsigned int INDEX_START;
	static const unsigned int INDEX_INVALID;
	static const unsigned int TYPE_START_END_DATE_AND_TIME;
	static const unsigned int TYPE_START_END_DATE;
	static const unsigned int TYPE_START_END_TIME;

	enum CommandType {
		ADD, DELETE, EDIT, UNDO, SORT, SEARCH, VIEW, SAVE, DONE, EXIT, INVALID_COMMAND
	};

	enum ModifierType {
		ITEMNAME, DATE, DUE, DESCRIPTION, LABEL, PRIORITY, INVALID_MODIFIER
	};

	// main functions to be executed in public method parse
	string executeParsing(string);

	// helper functions to main functions
	string retrieveCommandOrModifier(string); // unit tested
	CommandType determineCommandType(string);
	ModifierType determineModifierType(string);

	// commandType functions
	string executeAddParsing(string); // unit tested
	string executeDeleteParsing(string); // unit tested
	string executeEditParsing(string); // unit tested // to be improved
	string executeUndoParsing(string); // unit tested
	string executeSortParsing(string);
	string executeSearchParsing(string); // unit tested
	string executeViewParsing(string);
	string executeSaveParsing(string);
	string executeDoneParsing(string); // unit tested
	string executeExitParsing(string); // unit tested

	string checkAndSetTokenisedInformation(vector<string>&);
	string executeDateTimeParsing(string, const string);

	// string manipulation functions
	vector<string> tokeniseText(const string); // unit tested
	string trimText(string&); // unit tested
	string trimFront(string); // unit tested
	string trimBack(string); // unit tested
	string removeFirstStringToken(string);  // unit tested
	string retrieveFirstStringToken(string); // unit tested
	string removeConsecutiveWhiteSpace(string&); // unit tested
	string removeWhiteSpace(string&); // unit tested
	string removeCharacter(string&, const char); // unit tested
	string convertToLowerCase(string&); // unit tested
	bool areDigits(const string); // unit tested
	bool isWhiteSpace(const char); // unit tested

	// date time functions
	string setDateTime(string, const string);
	string splitDateTime(string, const string); // unit tested
	bool hasStartEnd(string, unsigned int&, unsigned int&); // unit tested
	START_AND_END splitAndSetStartEnd(const string, const unsigned int, const unsigned int, unsigned int&); // unit tested
	bool isValidDate(string, string&); // unit tested
	bool isValidTime(string, string&); // unit tested
	string splitAndSetObliqueDateInformation(string, const unsigned int); // unit tested
	string splitAndSetSpaceDateInformation(string, const unsigned int); // unit tested
	string splitAndSetTimeString(string, const string); // unit tested
	string splitAndSetColonTimeString(string, const string); // unit tested
	string splitAndSetNoColonTimeString(string, const string); // unit tested
	bool isDay(string, unsigned int&); //unit tested
	bool isDay(string); // unit tested
	bool isMonth(string, unsigned int&); //unit tested
	bool hasTimePeriodAbbreviation(const string); // unit tested
	string addTwelveToHours(const string); // unit tested

	// counters
	unsigned int retrieveCount(string, const char); // unit tested

	// setters and getters
	list<COMMAND_AND_TEXT> getParseInfo();
	string setParseInfo(string, string = "");
	string clearParseInfo();
	void showParseInfo();

	// misc functions
	void showError(string text);

public:
	iParser();
	~iParser();

	// main function used to parse information to Logic
	list<COMMAND_AND_TEXT> parse(string Input);
};

#endif