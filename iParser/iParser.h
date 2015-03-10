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
	static const string MESSAGE_SUCCESS;
	static const int INDEX_INVALID = -1;
	static const int INDEX_ZERO = 0;
	static const int INDEX_NEXT = 1;

	// Splits user input amongst the token "::"
	// Pre: nil
	// Post: one user input returned
	string splitUserInput(string userInput);

	// Pre: string to find and start index required
	// Post: returns index where the string to find is found
	int findIndex(string userInput, string stringToFind, int startingIndex);

	// Pre: start and end index required
	// Post: returns substring between start and end index
	string getSubstring(string userInput, int startIndex, int endIndex);

	// Pre: userCommand class defined
	// Post:adds to private attribute
	string addToUserCommandList(userCommand tempUserCommand);

public:
	list<userCommand> parse(string userInput);

	// getters for unit testing
	const int getFindIndex(string userInput, string stringToFind, int startingIndex);
	const string getGetSubstring(string userInput, int startIndex, int endIndex);

};

#endif