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

#ifndef IPARSER_H
#define IPARSER_H

struct COMMAND_AND_TEXT {
	string command;
	string text;
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
	static const string COMMAND_UNDONE;
	static const string COMMAND_EXIT;

	// used to set as command for logic to intepret
	static const string COMMAND_NAME;
	static const string COMMAND_START;
	static const string COMMAND_END;
	static const string COMMAND_DESCRIPTION;
	static const string COMMAND_PRIORITY;
	static const string COMMAND_REMOVE;
	static const string COMMAND_RMV;

	// used to identify string in UserInput
	static const string STRING_DATE;
	static const string STRING_DUE;
	static const string STRING_START;
	static const string STRING_END;
	static const string STRING_DESCRIPTION;
	static const string STRING_DESC;
	static const string STRING_PRIORITY;
	static const string STRING_PRIORITY_P;
	static const string STRING_ALL;
	static const string STRING_UPDATE;
	static const string STRING_NAME;
	static const string STRING_DONE;
	static const string STRING_UNDONE;
	static const string STRING_HIGH;
	static const string STRING_MEDIUM;
	static const string STRING_MED;
	static const string STRING_LOW;
	static const string STRING_H;
	static const string STRING_M;
	static const string STRING_L;

	// used to identify modifier in UserInput
	static const string MODIFIER_NAME;
	static const string MODIFIER_DATE;
	static const string MODIFIER_DUE;
	static const string MODIFIER_START;
	static const string MODIFIER_END;
	static const string MODIFIER_DESCRIPTION;
	static const string MODIFIER_DESC;
	static const string MODIFIER_LABEL;
	static const string MODIFIER_PRIORITY;
	static const string MODIFIER_PRIORITY_P;
	static const string MODIFIER_REMOVE;
	static const string MODIFIER_RMV;

	// used for date time functions and checks
	static const string STRING_DAYS[];
	static const string STRING_DAYS_SHORT_FORM[];
	static const string STRING_MONTHS[];
	static const string STRING_MONTHS_SHORT_FORM[];
	static const string STRING_MONTHS_IN_NUMBER[];
	static const string STRING_TO;
	static const string STRING_AM;
	static const string STRING_PM;
	static const string STRING_HR;
	static const string STRING_DATE_INITIALISE;
	static const string STRING_TIME_INITIALISE;
	static const string STRING_MINUTE_INITIALISE;
	static const string STRING_BLANK;
	static const string STRING_NEGATIVE_ONE;

	static const char CHAR_SPACE;
	static const char CHAR_TAB;
	static const char CHAR_COMMA;
	static const char CHAR_OBLIQUE;
	static const char CHAR_HYPHEN;
	static const char CHAR_COLON;
	static const char CHAR_PLUS;

	// used for string return type as well as for setting _parseInfo list's text
	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_FAILURE;
	static const string MESSAGE_INVALID;
	static const string MESSAGE_INVALID_INPUT;
	static const string MESSAGE_INVALID_COMMAND;
	static const string MESSAGE_INVALID_MODIFIER;
	static const string MESSAGE_INVALID_SORT;
	static const string MESSAGE_INVALID_VIEW;
	static const string MESSAGE_INVALID_REMOVE;
	static const string MESSAGE_INVALID_PRIORITY;
	static const string MESSAGE_INVALID_DATE_TIME;
	static const string MESSAGE_INVALID_ADD_ITEM;
	static const string MESSAGE_INVALID_NUMBER_OF_ITEM;
	static const string MESSAGE_INVALID_NUMBER_OF_DATE_TIME_MODIFIER;
	static const string MESSAGE_INVALID_NUMBER_OF_REMOVE;

	// used to avoid magic numbers
	static const unsigned int SIZE_OF_STRING_TO;
	static const unsigned int SIZE_OF_STRING_HYPHEN;
	static const unsigned int MAX_SIZE_OF_STRING_HOURS;
	static const unsigned int MIN_SIZE_OF_STRING_HOURS;
	static const unsigned int SIZE_OF_STRING_MINUTES;
	static const unsigned int MIN_SIZE_OF_STRING_WITH_SUFFIX;
	static const unsigned int NUMBER_OF_DAYS;
	static const unsigned int NUMBER_OF_MONTHS;
	static const unsigned int NUMBER_OF_HOURS;
	static const unsigned int HOURS_ZERO;
	static const unsigned int HOURS_ONE_PM;
	static const unsigned int HOURS_ELEVEN_PM;

	static const unsigned int INDEX_START;
	static const unsigned int INDEX_INVALID;

	// =====================
	// main parsing function
	// =====================
	// Pre:		userInput passed to function as string
	// Post:	sets command and text to _parseInfo list based on user's command
	//			clears _parseInfo list and sets list as invalid if any invalid input is detected
	string executeParsing(string); // unit test

	// ===============================
	// functions within executeParsing
	// ===============================

	// Pre:		commandType is "add"
	// Post:	sets itemName and any modifiers along with their respective information to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text or invalid date time input is detected
	string executeAddParsing(string); 
	// Pre:		commandType is "edit"
	// Post:	sets indexToEdit and any modifiers along with their respective information to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text or invalid date time input is detected
	string executeEditParsing(string);
	// Pre:		
	// Post:	
	string executeSortParsing(string);
	// Pre:		
	// Post:	
	string executeViewParsing(string);
	// Pre:		commandType is "delete", "del", "search", "save", "done" or "undone"
	// Post:	sets text or index to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text is detected
	string executeCommandAndTextParsing(const string, string);
	// Pre:		commandType is "clear", "undo" or "exit"
	// Post:	sets command and text/index to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text is detected
	string executeSingularCommandParsing(const string, string);
	
	// ================
	// helper functions
	// ================

	//Pre:		vector with tokenised information has more than one string passed to function
	//Post:		determines the modifiers available in vector and executes the respective modifiers
	//			if any modifiers cannot be determined or if sub functions throw an exception, this function will stop it's execution
	string checkAndSetTokenisedInformation(vector<string>&, const string);
	// Pre:		ModifierType is "item", "date", "due", "start", "end", "description", "desc" or "priority"
	// Post:	sets modifier and text to _parseInfo list
	//			clears _parseInfo list and sets list as invalid if blank text is detected
	string executeModifierAndTextParsing(const string, string);
	// Pre:		nil
	// Post:	determines whether dateTime string is a single dateTime or a ranged dateTime and executes
	//			respective dateTime parsing
	//			if dateTime is not valid, invalid date time message will be thrown as exception
	string executeDateTimeParsing(const string);
	// Pre:		
	// Post:	
	string executePriorityParsing(string);
	// Pre:		ModifierType "remove" is called
	// Post:	sets the parts to be removed to _parseInfo list
	string executeRemoveParsing(string);

	// =============================
	// string manipulation functions
	// =============================
	// Pre:		nil
	// Post:	retrieves the first word from userInput string
	string retrieveCommandOrModifier(string);
	// Pre:		nil
	// Post:	tokenises userInput into commands and modifiers along with their respective texts that follow after
	vector<string> tokeniseText(const string);
	// Pre:		nil
	// Post:	returns a string with the first word from the text removed
	string removeFirstStringToken(string); 
	// Pre:		nil
	// Post:	if a whitespace character is detected within referenced string,
	//			any whitespace characters in the next index will be removed
	string removeConsecutiveWhiteSpace(string&);
	// Pre:		nil
	// Post:	removes all whitespace characters detected within the referenced string
	string removeWhiteSpace(string&);
	// Pre:		nil
	// Post:	converts all alphabet characters in the referenced string to lower case alphabets
	string convertToLowerCase(string&); 
	// Pre:		nil
	// Post:	trims text by removing whitespace characters at the front and back of the referenced string until
	//			the first non-whitespace character
	string trimText(string&);
	// Pre:		nil
	// Post:	trims text by removing whitespace characters at the front of the string until
	//			the first non-whitespace character
	string trimFront(string); 
	// Pre:		nil
	// Post:	trims text by removing whitespace characters at the back of the string until
	//			the first non-whitespace character
	string trimBack(string); 

	// ===================
	// date time functions
	// ===================
	// Pre:		nil
	// Post:	returns true if "to" or "-" are found
	//			else, returns false
	bool hasStartEndDateTime(string);
	// Pre:		nil
	// Post:	determines the dateTime which user inputs and sets dateTime information to _parseInfo
	//			if invalid dateTime is input, invalid input message will be thrown as exception
	string setDateTime(string, const string);
	// Pre:		one comma detected in dateTime string
	// Post:	determines the dateTime which user inputs and sets start OR end dateTime to _parseInfo
	//			if invalid dateTime is input, invalid input message will be thrown as exception
	string splitAndSetDateTime(string, const string);
	// Pre:		hasStartEndDateTime is true
	// Post:	determines the dateTime range which user inputs and sets start AND end dateTime to _parseInfo
	//			if invalid dateTime range is input, invalid input message will be thrown as exception
	string splitAndSetStartEndDateTime(const string);
	// Pre:		startEndDateTime has no commas detected
	// Post:	determines the dateTime range which user inputs and sets start AND end dateTime to _parseInfo
	//			the range may be [date to date] or [time to time] range
	//			if invalid dateTime range is input, invalid input message will be thrown as exception
	string splitAndSetNoCommaStartEndDateTime(const string);
	// Pre:		startEndDateTime has 1 comma detected
	// Post:	determines the dateTime range which user inputs and sets start AND end dateTime to _parseInfo
	//			the range may be [date, time to time] or [time to time, date] range
	//			if invalid dateTime range is input, invalid input message will be thrown as exception
	string splitAndSetOneCommaStartEndDateTime(const string);
	// Pre:		startEndDateTime has 2 commas detected
	// Post:	determines the dateTime range which user inputs and sets start AND end dateTime to _parseInfo
	//			the range may be [date, time to date, time], [time, date to time, date],
	//			[date, time to time, date] or [time, date to date, time] range
	//			if invalid dateTime range is input, invalid input message will be thrown as exception
	string splitAndSetTwoCommaStartEndDateTime(const string);
	// Pre:		nil
	// Post:	if date is valid, set date to _parseInfo and return true
	bool isValidDate(string, string&);
	// Pre:		nil
	// Post:	if time is valid, set time to _parseInfo and return true
	bool isValidTime(string, string&);
	// Pre:		date userInput contains '/'	
	// Post:	if date is valid, set time to _parseInfo and return true
	//			else, false will be thrown as exception for isValidDate to catch
	string splitAndSetObliqueDateInformation(string, const unsigned int);
	// Pre:		date userInput does not contain '/'	
	// Post:	if date is valid, set time to _parseInfo and return true
	//			else, false will be thrown as exception for isValidDate to catch
	string splitAndSetSpaceDateInformation(string, const unsigned int);
	// Pre:		nil
	// Post:	determines if time string has colon or not and executes the respective time string functiions
	//			if time string is invalid, false will be thrown as exception for isValidTime to catch
	string splitAndSetTimeString(string, const string);
	// Pre:		time userInput does contains ':'	
	// Post:	if time is valid, set time to _parseInfo and return true
	//			else, false will be thrown as exception for isValidTime to catch
	string splitAndSetColonTimeString(string, const string);
	// Pre:		time userInput does does not contain ':'	
	// Post:	if time is valid, set time to _parseInfo and return true
	//			else, false will be thrown as exception for isValidTime to catch
	string splitAndSetNoColonTimeString(string, const string);
	// Pre:		nil	
	// Post:	if day string is a valid day, return true
	bool isDay(string);
	// Pre:		isDay is true	
	// Post:	sets the day with alphabetical string
	string setDay(string);
	// Pre:		nil	
	// Post:	if month string is a valid month, return true
	bool isMonth(string); 
	// Pre:		isMonth is true	
	// Post:	sets the month with digit string
	string setMonth(string);
	// Pre:		nil
	// Post:	returns true if time string contains 'am', 'pm' or 'hr'
	bool hasTimePeriodSuffix(const string);
	// Pre:		hasTimePeriodSuffix is true, suffix is 'pm'	
	// Post:	if time is between 1~11, it will be added by 12 and be returned as a string
	string addTwelveToHours(const string); 
	// Pre:		nil
	// Post:	returns true if suffix is AM and hour falls between 1~12
	bool isAppropriateAMHour(const string);
	// Pre:		nil
	// Post:	returns true if hour and minute strings are valid
	bool isAppropriateTime(const string, const string, const string);
	// Pre:		nil
	// Post:	returns true if day is not detected while time is available
	bool hasNoDayButHasTime(const string);

	// =================
	// boolean functions
	// =================

	// Pre:		nil
	// Post:	returns boolean of whether string is a modifier keyword
	bool isModifier(string);
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