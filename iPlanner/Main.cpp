//@author A0116229J
#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	
	Logic testLogic;
	string userInput;
	list<COMMAND_AND_TEXT> parseInfo;

	testLogic.retrieveBasicInformationFromTextFile();
	testLogic.readDataFromFile();
	testLogic.sortTask();

	cout << "command : ";
	while (getline(cin, userInput)){
	testLogic.initiateCommandAction(userInput);
	cout << "command : ";
	}

	return;
}