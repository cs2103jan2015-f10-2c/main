//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include <string>
#include <list>
#include <iostream>
#include "..\iStorage\Item.h"

#ifndef PARSEINFO_H_
#define PARSEINFO_H_

struct COMMAND_AND_TEXT {
	string command;
	string text;
};


class ParseInfo {
private:
	string _command;
	unsigned int _index;
	Item _item;
	list<COMMAND_AND_TEXT> _tokens;
	bool _isValidInput;
	bool _hasCommand;

	static const string MESSAGE_SUCCESS;
	static const string TOKEN_BLANK;
	static const int INDEX_ZERO = 0;
	
public:
	ParseInfo();
	~ParseInfo();

	// setters
	string setCommand(string text);
	string setIndex(unsigned int index);
	string setItem(Item item);
	string setTokens(COMMAND_AND_TEXT token);
	string setIsNotValidInput();
	string setHasCommand();

	//getters
	string getCommand();
	unsigned int getIndex();
	Item getItem();
	list<COMMAND_AND_TEXT> getTokens();
	bool getIsValidInput();
	bool getHasCommand();
	bool getHasIndex();
	bool getHasItem();
	bool getHasTokens();
};

#endif