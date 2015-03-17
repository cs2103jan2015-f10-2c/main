#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;
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
	}
	
	return;
}