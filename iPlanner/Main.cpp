#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	iParser testParser;
	Logic testLogic;
	string userInput;
	list<COMMAND_AND_TEXT> parseInfo;
	cout << "command : ";
	while (getline(cin, userInput)){
		cout << userInput << endl;
	testLogic.initiateCommandAction(testParser, userInput);
		cout << "command : ";
	}
	

	/*string input;
	Logic testLogic;
	string directory;
	string filename;

	testLogic.retrieveDirectoryFromTextFile();
	testLogic.readDataFromFile();
	
	cout << "Command: ";
	while (getline(cin, input)) {
		testLogic.initiateCommandAction(input);
		cout << "Command : ";
		testLogic.writeDataOntoFile();
	}*/
	
	return;
}