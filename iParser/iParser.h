//	@author A0111238U
//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng

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

#define TESTMODE
#ifndef TESTMODE
private:
#else
public:
#endif

	// =================
	// private attribute
	// =================

	list<COMMAND_AND_TEXT> _parseInfo;

	// =====================
	// Pre defined variables
	// =====================

	// used to identify commands in userInput and set as command for logic to intepret
	static const string COMMAND_ADD;
	static const string COMMAND_DELETE;
	static const string COMMAND_DEL;
	static const string COMMAND_CLEAR;
	static const string COMMAND_EDIT;
	static const string COMMAND_UNDO;
	static const string COMMAND_SORT;
	static const string COMMAND_SEARCH;
	static const string COMMAND_VIEW;
	static const string COMMAND_SAVE;
	static const string COMMAND_DONE;
	static const string COMMAND_EXIT;

	// used to set as command for logic to intepret
	static const string COMMAND_ITEM;
	static const string COMMAND_START;
	static const string COMMAND_END;
	static const string COMMAND_DESCRIPTION;
	static const string COMMAND_PRIORITY;

	// used to identify whether date time input is appointment or due date
	static const string MODIFIER_DATE;
	static const string MODIFIER_DUE;
	static const string MODIFIER_START;
	static const string MODIFIER_END;
	static const string MODIFIER_FROM;

	// used to identify modifiers in UserInput
	static const string STRING_ITEM;
	static const string STRING_DATE;
	static const string STRING_DUE;
	static const string STRING_START;
	static const string STRING_END;
	static const string STRING_FROM;
	static const string STRING_DESCRIPTION;
	static const string STRING_DESC;
	static const string STRING_LABEL;
	static const string STRING_PRIORITY;
	static const string STRING_PRIORITY_EXCLAMATION;

	// used for date time functions and checks
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

	// used for string return type as well as for setting _parseInfo list's text
	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_FAILURE;
	static const string MESSAGE_INVALID;
	static const string MESSAGE_INVALID_INPUT;
	static const string MESSAGE_INVALID_COMMAND;
	static const string MESSAGE_INVALID_ADD;
	static const string MESSAGE_INVALID_EDIT;
	static const string MESSAGE_INVALID_SAVE;
	static const string MESSAGE_INVALID_DATE_TIME;
	static const string MESSAGE_TERMINATE;

	// used to avoid magic numbers
	static const unsigned int MAX_NUMBER_OF_COMMAS;
	static const unsigned int MIN_SIZE_WITH_ABBREVIATION;
	static const unsigned int SIZE_DAYS;
	static const unsigned int SIZE_MONTHS;
	static const unsigned int SIZE_DATETIME_WHITESPACE;
	static const unsigned int HOURS_ZERO;
	static const unsigned int HOURS_ONE_PM;
	static const unsigned int HOURS_ELEVEN_PM;

	static const unsigned int INDEX_START;
	static const unsigned int INDEX_INVALID;
	static const unsigned int TYPE_START_END_DATE_AND_TIME;
	static const unsigned int TYPE_START_END_DATE;
	static const unsigned int TYPE_START_END_TIME;

	// =====================================
	// enumeration for command and modifiers
	// =====================================

	enum CommandType {
		ADD, DELETE, CLEAR, EDIT, UNDO, SORT, SEARCH, VIEW, SAVE, DONE, EXIT, INVALID_COMMAND
	};

	enum ModifierType {
		ITEM, DATE, DUE, START, END, FROM, DESCRIPTION, PRIORITY, INVALID_MODIFIER
	};

	// =====================
	// main parsing function
	// =====================
	// Pre:		userInput passed to function as string
	// Post:	sets command and text to _parseInfo list based on user's command
	//			clears _parseInfo list and sets list as invalid if any invalid input is detected
	string executeParsing(string); // unit test

	// ========================================
	// command / modifier determining functions
	// ========================================
	
	// Pre:		command retrieved passed to function
	// Post:	determines and returns the enum CommandType, returns INVALID_COMMAND if command does not match
	CommandType determineCommandType(string);
	// Pre:		modifiers retrieved passed to function
	// Post:	determines and returns the enum ModifierType, returns INVALID_MODIFIER if modifier does not match
	ModifierType determineModifierType(string);

	// ===============================
	// functions within executeParsing
	// ===============================

	// Pre:		commandType is "add"
	// Post:	sets itemName and any modifiers along with their respective information to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text or invalid date time input is detected
	string executeAddParsing(string); // unit test + improve =======================================================
	// Pre:		commandType is "edit"
	// Post:	sets indexToEdit and any modifiers along with their respective information to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text or invalid date time input is detected
	string executeEditParsing(string); // unit test + improve ======================================================
	// Pre:		commandType is "delete", "del", "sort", "search", "view", "save" or "done"
	// Post:	sets text or index to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text is detected
	string executeCommandAndTextParsing(const string, string);
	// Pre:		commandType is "delete", "del", "sort", "search", "view", "save" or "done"
	// Post:	sets command and text/index to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text is detected
	string executeCommandParsing(const string, string);
	// Pre:		ModifierType is "item", "date", "due", "start", "end", "from", "description", "desc" or "priority"
	// Post:	sets modifier and text to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text is detected
	string executeModifierAndTextParsing(const string, string);

	// ================
	// helper functions
	// ================

	string checkAndSetTokenisedInformation(vector<string>&, const string);
	string executeDateTimeParsing(string, const string);

	// =============================
	// string manipulation functions
	// =============================
	string retrieveCommandOrModifier(string);
	vector<string> tokeniseText(const string);
	string removeFirstStringToken(string); 
	string retrieveFirstStringToken(string); 
	string removeConsecutiveWhiteSpace(string&);
	string removeWhiteSpace(string&);
	string removeCharacter(string&, const char); 
	string convertToLowerCase(string&); 
	string trimText(string&);
	string trimFront(string); 
	string trimBack(string); 

	// ===================
	// date time functions
	// ===================
	string setDateTime(string, const string);
	string splitDateTime(string, const string);
	bool hasStartEnd(string, unsigned int&, unsigned int&);
	START_AND_END splitAndSetStartEnd(const string, const unsigned int, const unsigned int, unsigned int&);
	bool isValidDate(string, string&);
	bool isValidTime(string, string&);
	string splitAndSetObliqueDateInformation(string, const unsigned int);
	string splitAndSetSpaceDateInformation(string, const unsigned int);
	string splitAndSetTimeString(string, const string);
	string splitAndSetColonTimeString(string, const string);
	string splitAndSetNoColonTimeString(string, const string);
	bool isDay(string, unsigned int&);
	bool isDay(string);
	string setDay(string);
	bool isMonth(string); 
	string setMonth(string);
	bool hasTimePeriodAbbreviation(const string);
	string addTwelveToHours(const string); 

	// =================
	// boolean functions
	// =================

	// Pre:		nil
	// Post:	returns boolean of whether string is a modifier keyword
	bool isModifier(const string);
	// Pre:		nil
	// Post:	returns true if string contains only digits between 0 to 9
	//			returns false otherwise
	bool areDigits(const string);
	// Pre:		nil
	// Post:	returns true if character is either a space or tab
	//			returns false otherwise
	bool isWhiteSpace(const char);

	// =================
	// character counter
	// =================

	// Pre:		string to be checked and character to count passed to function
	// Post:	returns the unsigned int value of character to be counted within string
	unsigned int retrieveCount(string, const char); 

	// ===================
	// setters and getters
	// ===================

	// Pre:		nil
	// Post:	returns list of _parseInfo
	list<COMMAND_AND_TEXT> getParseInfo();
	// Pre:		non-blank command string passed to function
	// Post:	sets command and text (if applicable) to _parseInfo list
	string setParseInfo(string, string = "");
	// Pre:		nil
	// Post:	clears _parseInfo list
	string clearParseInfo();
	
	// ==============
	// misc functions
	// ==============

	// Pre:		nil
	// Post:	list of command and text displayed
	void showParseInfo();

public:
	iParser();
	~iParser();

	// ================================================
	// main function called by logic to parse userInput
	// ================================================

	// Pre:		nil
	// Post:	returns a list of a pair of string to logic for logic to interpret
	//			pair of string consist of command and text
	list<COMMAND_AND_TEXT> parse(string Input);
};

#endif