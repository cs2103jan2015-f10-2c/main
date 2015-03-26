#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	iParser testParser;
	Logic testLogic;
	string userInput;
	list<COMMAND_AND_TEXT> parseInfo;

	testLogic.retrieveDirectoryFromTextFile();
	testLogic.readDataFromFile();

	cout << "command : ";
	while (getline(cin, userInput)){
		cout << userInput << endl;
	testLogic.initiateCommandAction(testParser, userInput);
		cout << "command : ";
	}

	
	return;
}