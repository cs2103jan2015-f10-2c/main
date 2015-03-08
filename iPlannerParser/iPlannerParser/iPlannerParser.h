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
	string findSubstring(string userInput, int startIndex, int endIndex);

public:
	list<userCommand> main(string userInput);

};

#endif