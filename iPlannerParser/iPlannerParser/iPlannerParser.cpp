//	Parser
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "iPlannerParser.h"

string iPlannerParser::STRING_BLANK = "";

void iPlannerParser::main(string userInput) {
	if(isBlank(userInput)) {
		return;
	}

	return;
}

bool iPlannerParser::isBlank(string userInput) {
	return userInput == STRING_BLANK;
}

void main() {

}