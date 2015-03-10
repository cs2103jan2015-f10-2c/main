//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "userCommand.h"
#include <list>
#include <iostream>
using namespace std;

#ifndef IPARSER_H_
#define IPARSER_H_

class iParser {

private:
	list<userCommand> userCommandList;

	static const string TOKEN_COMMAND;
	static const int INDEX_INVALID = -1;
	static const int INDEX_ZERO = 0;
	static const int INDEX_NEXT = 1;

	void splitUserInput(string userInput);
	int findIndex(string userInput, string stringToFind, int startingIndex);
	string getSubstring(string userInput, int startIndex, int endIndex);
	void addToUserCommandList(userCommand tempUserCommand);

public:
	list<userCommand> parse(string userInput);

	// getters for unit testing
	const int getFindIndex(string userInput, string stringToFind, int startingIndex);
	const string getGetSubstring(string userInput, int startIndex, int endIndex);

};

#endif