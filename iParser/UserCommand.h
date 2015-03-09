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

	userCommand();
	~userCommand();
	userCommand(string singleInput);

	// setters
	void setCommand(string singleInput);
	void setText(string singleInput);

	// getters
	string getCommand();
	string getText();

	int findIndex(string singleInput, string stringToFind);
	string getSubstring(string singleInput, int start, int end = INDEX_DEFAULT);

};

#endif