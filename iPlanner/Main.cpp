#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;
	Logic testLogic;
	string directory;
	string filename;
	/*cout << "Save Directory : ";
	getline(cin, directory);
	cout << "file name : ";
	getline(cin, filename);
	
	testLogic.changeSavingDirectory(directory);
	testLogic.changeSavingFileName(filename);
	*/
	testLogic.readDataFromFile(testLogic.retrieveDirectoryFromTextFile());
	cout << "Command: ";
	while (getline(cin, input)) {
		testLogic.initiateCommandAction(input);
		cout << "Command : ";
		testLogic.writeDataOntoFile(testLogic.getDirectoryAndFileName());
	}
	
	return;
}