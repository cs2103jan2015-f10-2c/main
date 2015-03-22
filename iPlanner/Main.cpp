#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	iParser testParser;
	Logic testLogic;
	string userInput;
	list<COMMAND_AND_TEXT> parseInfo;
	COMMAND_AND_TEXT commandAndText;
	commandAndText.command = "add";
	commandAndText.text = "Youngbin";
	parseInfo.push_back(commandAndText);
	commandAndText.command = "description";
	commandAndText.text = "HAHA";
	parseInfo.push_back(commandAndText);
	
	//getline(cin, userInput);
	//parseInfo = testParser.parse(userInput);
	
	testLogic.addTask(parseInfo);
	//while (getline(cin, userInput)){
	//	testLogic.initiateCommandAction(testParser, userInput);
	//	cout << "command : ";
//	}
	

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