//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

/*
===================================================================================================
NOTES TO DEVELOPERS
- iParser takes in a string and returns ParseInfo class to iLogic
- iParser splits string into individual fragments which is then assigned to the attributes in
  ParseInfo class
- Note that iParser does not do the validity check and only assigns to attributes
  (validity check is done in iLogic)
===================================================================================================
*/

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include "ParseInfo.h"
using namespace std;

#ifndef IPARSER_H_
#define IPARSER_H_

class iParser {

private:
	ParseInfo _parseInfo;
	list<string> _inputs;

	enum CommandType {
		ADD, DELETE, EDIT, START, END, DESCRIPTION, LABEL,
		PRIORITY, UNDO, SORT, SEARCH, EXIT, INVALID
	};

	static const string COMMAND_ADD;
	static const string COMMAND_DELETE;
	static const string COMMAND_EDIT;
	static const string COMMAND_START;
	static const string COMMAND_END;
	static const string COMMAND_DESCRIPTION;
	static const string COMMAND_EXIT;

	static const string TOKEN_COMMAND;
	static const string TOKEN_SPACE;
	static const string TOKEN_OBLIQUE;
	static const string TOKEN_BLANK;

	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_INVALID;
	static const string MESSAGE_TERMINATE;

	static const int LENGTH_VALID = 2;
	static const int DIGIT_OF_TIME = 2;
	static const int DIGIT_THREE = 3;
	static const int DIGIT_FOUR = 4;

	static const int INDEX_ZERO = 0;
	static const int INDEX_ONE = 1;
	static const int INDEX_INVALID = -1;
	static const int INDEX_NEXT = 1;
	static const int INDEX_AFTER_TOKEN_COMMAND = 2;

	// main functions to be executed in public method parse 
	string splitInput(string userInput);
	string setInformation();

	// input retrieval and categorisation
	string setInputs(string individualInputs);
	string retrieveCommand(string userInput);
	string retrieveText(string userInput);
	CommandType determineCommandType(string command);

	// commandType functions
	string setAddItemName(string text, Item& item);
	string setDeleteIndex(string text, Item& item);
	string setEditIndex(string text, Item& item);
	string setStartDateTime(string text, Item& item);
	string setEndDateTime(string text, Item& item);
	string setDescription(string text, Item& item);
	string setExit(string text);

	// helper functions assisting commandType functions
	string addIndex(string text);
	string splitAndSetDateTime(string text, Item& item, string command);
	int retrieveYear(string text);
	int retrieveMonth(string text);
	int retrieveDay(string text);
	int retrieveHour(string text);
	int retrieveMinute(string text);
	string setEditString(string text);

	// string manipulation functions
	int findIndex(string userInput, string stringToFind, int startIndex = INDEX_ZERO);
	string retrieveSubstring(string userInput, int startIndex, int endIndex = INDEX_INVALID);
	string trimText(string& text);
	string trimFront(string text);
	string trimBack(string text);
	int convertToDigit(string text);

	// boolean functions
	bool isValidLength(string userInput);
	bool isDigit(string text);

	// Misc functions
	string displayInputs();
	string displayParseInfo();
	void showError(string text);	

public:
	iParser();
	~iParser();

	// main function used to parse information to Logic
	ParseInfo parse(string Input);
};

#endif