//	userCommandClass
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include <string>
using namespace std;

#ifndef USERCOMMAND_H_
#define USERCOMMAND_H_

class userCommand {
private:
	string _command;
	string _text;

public:
	static const string TOKEN_COMMAND;
	static const string TOKEN_SPACE;
	static const int INDEX_START_OF_COMMAND;
	static const int INDEX_START_OF_TEXT;
	static const int INDEX_DEFAULT;

	// constructor and destructor
	userCommand();
	~userCommand();
	userCommand(string input);

	// setters
	// pre: userInput split into command and text
	// post: sets the respective command and text to private attributes
	void setCommand(string input);
	void setText(string input);

	// getters
	string getCommand();
	string getText();

	// Pre: string to find and start index required
	// Post: returns index where the string to find is found
	int findIndex(string input, string stringToFind);

	// Pre: start and end index required
	// Post: returns substring between start and end index
	string getSubstring(string input, int start, int end = INDEX_DEFAULT);

};

#endif