//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "userCommand.h"
#include <list>
#include <iostream>
using namespace std;

#ifndef IPLANNERPARSER_H_
#define IPLANNERPARSER_H_

class iPlannerParser {

private:
	list<userCommand> userCommandList;
	void splitUserInput(string userInput);

	static const string TOKEN_COMMAND;
	static const int INDEX_INVALID = -1;
	static const int INDEX_ZERO = 0;
	static const int INDEX_NEXT = 1;

	int findIndex(string userInput, string stringToFind, int startingIndex);
	string getSubstring(string userInput, int startIndex, int endIndex);
	void addToUserCommandList(userCommand tempUserCommand);

public:
	list<userCommand> main(string userInput);

	// getters for unit testing
	const int getFindIndex(string userInput, string stringToFind, int startingIndex);
	const string getGetSubstring(string userInput, int startIndex, int endIndex);

};

#endif