//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

/*
===================================================================================================
NOTES TO DEVELOPERS
- _mainCommands: add / del / edit / exit
- if _isValidInput is false, user input is definitely wrong
  e.g. there is no _mainCommand
===================================================================================================
*/

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
	string _mainCommand;
	unsigned int _index;
	Item _item;
	list<COMMAND_AND_TEXT> _tokens;
	bool _isValidInput;

	static const string MESSAGE_SUCCESS;
	static const string TOKEN_BLANK;
	static const int INDEX_ZERO = 0;
	
public:
	ParseInfo();
	~ParseInfo();

	// setters
	string setMainCommand(string text);
	string setIndex(unsigned int index);
	string setItem(Item item);
	string setTokens(COMMAND_AND_TEXT token);
	string setIsNotValidInput();

	//getters
	string getMainCommand();
	unsigned int getIndex();
	Item getItem();
	list<COMMAND_AND_TEXT> getTokens();
	bool getHasMainCommand();
	bool getHasIndex();
	bool getHasItem();
	bool getHasTokens();
	bool getIsValidInput();
};

#endif