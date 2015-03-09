//	ParserTestDriver
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "..\iPlannerParser\iPlannerParser.h"

void main() {
	iPlannerParser myParser;
	string userInput;
	getline(cin, userInput);
	myParser.main(userInput);
}