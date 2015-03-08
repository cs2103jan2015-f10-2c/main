//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include <string>
using namespace std;

#ifndef IPLANNERPARSER_H_
#define IPLANNERPARSER_H_

class iPlannerParser {
private:
	enum CommandType {
		ADD, DELETE, EDIT, UNDO, CLEAR, SEARCH, SORT, RECUR, EXIT
	};
	
	// add class Item
	
	static string STRING_BLANK;

	static string readCommand(string userInput);
	static bool isBlank(string userInput);

	static string setItemName();
	static string setItemDate();
	static string setItemTime();
	static string setItemDescription();


public:
	static void main(string userInput);

};

#endif