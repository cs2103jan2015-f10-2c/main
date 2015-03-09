//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "iPlannerParser.h"

const string iPlannerParser::TOKEN_COMMAND = "::";

list<userCommand> iPlannerParser::main(string userInput) {
	splitUserInput(userInput);
	return userCommandList;
}

void iPlannerParser::splitUserInput(string userInput) {
	int startIndex = INDEX_ZERO;
	int endIndex = INDEX_ZERO;

	while(endIndex != INDEX_INVALID) {
		string splittedUserCommand;
		startIndex = findIndex(userInput,TOKEN_COMMAND, endIndex);
		endIndex = findIndex(userInput,TOKEN_COMMAND, startIndex+INDEX_NEXT);
		splittedUserCommand = getSubstring(userInput, startIndex, endIndex);
		userCommand tempUserCommand(splittedUserCommand);
		addToUserCommandList(tempUserCommand);
	}
}

int iPlannerParser::findIndex(string userInput, string stringToFind, int startingIndex) {
	int returnIndex;

	returnIndex = userInput.find(stringToFind, startingIndex);

	return returnIndex;
}

string iPlannerParser::getSubstring(string userInput, int startIndex, int endIndex) {
	string substring;

	substring = userInput.substr(startIndex, endIndex - startIndex);

	return substring;
}

void iPlannerParser::addToUserCommandList(userCommand tempUserCommand) {
	userCommandList.push_back(tempUserCommand);
}

const int iPlannerParser::getFindIndex(string userInput, string stringToFind, int startingIndex) {
	return findIndex(userInput, stringToFind, startingIndex);
}

const string iPlannerParser::getGetSubstring(string userInput, int startIndex, int endIndex) {
	return getSubstring(userInput, startIndex, endIndex);
}