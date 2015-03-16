#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;
	Logic testLogic;
	string directory;
	string filename;
	cout << "Save Directory : ";
	getline(cin, directory);
	cout << "file name : ";
	cin >> filename;
	testLogic.changeSavingDirectory(directory);
	testLogic.changeSavingFileName(filename);
	cout << "Command: ";
	while (getline(cin, input)) {
		testLogic.initiateCommandAction(input);
		cout << "Command : ";
	}
	testLogic.writeDataOntoFile(testLogic.getDirectoryAndFileName());
	return;
}