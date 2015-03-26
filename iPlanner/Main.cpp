#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	iParser testParser;
	string testInput = "23 -date 10 Nov 2012, 6:30PM";
	testParser.executeEditParsing(testInput);
	
	/*iParser testParser;
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
	}*/
	return;
}