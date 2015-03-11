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

struct COMMAND_AND_TEXT {
	string command;
	string text;
};

class iParser {

	// used for private method unit testing
	#ifndef TESTMODE 
	private: 
	#else 
	public:
	#endif
	// used for private method unit testing

	ParseInfo _parseInfo;
	list<COMMAND_AND_TEXT> _tokens;

	static const string COMMAND_ADD;
	static const string COMMAND_DELETE;
	static const string COMMAND_EDIT;
	static const string COMMAND_START;
	static const string COMMAND_END;
	static const string COMMAND_DESC;
	static const string COMMAND_BLANK;

	static const string TOKEN_COMMAND;
	static const string TOKEN_SPACE;
	static const string TOKEN_BLANK;

	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_INVALID;

	static const int INDEX_ZERO = 0;
	static const int INDEX_ONE = 1;
	static const int INDEX_INVALID = -1;
	static const int INDEX_NEXT = 1;
	static const int INDEX_AFTER_TOKEN_COMMAND = 2;

	// main methods to be executed in public method parse 
	string tokeniseToParts(string userInput);
	bool areValidCommands();

	// helper functions to assist main methods
	int findIndex(string userInput, string stringToFind, int startIndex);
	string retrieveSubstring(string userInput, int startIndex, int endIndex = INDEX_INVALID);
	string trimText(string& text);
	string trimFront(string text);
	string trimBack(string text);

	// boolean functions to assist main methods
	bool isCommand(string command);
	bool isMainCommand(string command);
	bool isValidLength(string userInput);

	// Methods for _tokens
	string setToken(string singleInput);
	string setTokenToList(COMMAND_AND_TEXT token);
	bool hasTokens();
	string displayTokens();

public:
	iParser();
	~iParser();

	ParseInfo parse(string Input);
};

#endif