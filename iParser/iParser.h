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

#include <string>
#include <list>
#include "ParseInfo.h"
using namespace std;

#ifndef IPARSER_H_
#define IPARSER_H_

class iParser {

private:
	ParseInfo _ParseInfo;

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
	static const int INDEX_INVALID = -1;
	static const int INDEX_NEXT = 1;
	static const int INDEX_AFTER_TOKEN_COMMAND = 2;

	string tokeniseToParts(string userInput);
	bool areValidCommands();
	string retrieveCommand(string command);

	int findIndex(string userInput, string stringToFind, int startingIndex);
	string retrieveSubstring(string userInput, int startIndex, int endIndex = INDEX_INVALID);

	bool isCommand(string command);
	bool isRequiredCommand(string command);

	// getters
	string getCommand();
	int getIndex();

	//setters
	string setCommand(string command);
	string setIndex(int index);
	string setItem(string userInput);
	string setToken(string userInput);

	void displayTokens();

public:
	iParser();
	~iParser();

	ParseInfo parse(string Input);
};

#endif