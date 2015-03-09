//	ParserTestDriver
//	Tutorial F10-2C
//	Coder:	Ng Chon Beng (A0111238U)

#include "..\iPlannerParser\iPlannerParser.h"

void main() {
	iPlannerParser myParser;
	list<userCommand> myUserCommand;
	string userInput;

	getline(cin, userInput);
	myUserCommand = myParser.main(userInput);

	list<userCommand>::iterator iter;
	for(iter = myUserCommand.begin(); iter != myUserCommand.end(); iter++) {
		cout << "Command: " << iter->getCommand() << endl
			<< "Text: " << iter->getText() << endl;
	}
}