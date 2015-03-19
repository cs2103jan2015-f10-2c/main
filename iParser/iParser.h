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
#include <sstream>
#include <assert.h>
using namespace std;

#ifndef IPARSER_H_
#define IPARSER_H_

struct COMMAND_AND_TEXT {
	string command;
	string text;
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
	static const string COMMAND_EXIT;
	static const string COMMAND_INVALID;

	static const string MODIFIER_START;
	static const string MODIFIER_END;
	static const string MODIFIER_DESCRIPTION;

	//static const string TOKEN_COMMAND;
	//static const string TOKEN_SPACE;
	//static const string TOKEN_OBLIQUE;
	static const string STRING_BLANK;

	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_INVALID_INDEX;
	static const string MESSAGE_TERMINATE;

	//static const int LENGTH_VALID;
	//static const int DIGIT_OF_TIME;
	//static const int DIGIT_THREE;
	//static const int DIGIT_FOUR;

	//static const int INDEX_ZERO;
	static const int INDEX_ONE;
	static const int INDEX_INVALID;
	static const int INDEX_START;
	//static const int INDEX_NEXT;
	//static const int INDEX_AFTER_TOKEN_COMMAND;

	enum CommandType {
		ADD, DELETE, EDIT, UNDO, SORT, SEARCH, VIEW, EXIT, INVALID
	};

	// main functions to be executed in public method parse
	string executeParsing(string);

	// helper functions to main functions
	string retrieveCommand(string);
	CommandType determineCommandType(string);
	string removeCommand(string);

	// commandType functions
	string executeAddParsing(string);
	string executeDeleteParsing(string);

	// string manipulation functions
	unsigned int findWhiteSpace(string);
	string trimText(string&);
	string trimFront(string);
	string trimBack(string);

	// boolean functions
	//bool isValidLength(string userInput);
	bool isDigit(string text);

	// setters and getters
	list<COMMAND_AND_TEXT> getParseInfo();
	string setInformation(string, string);
	
	// assertion
	void checkString(string);

	// misc functions
	void showError(string text);

	/*
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
	*/
public:
	iParser();
	~iParser();

	// main function used to parse information to Logic
	list<COMMAND_AND_TEXT> parse(string Input);
};

#endif