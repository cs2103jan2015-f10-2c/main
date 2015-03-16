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
	getline(cin, filename);
	
	testLogic.changeSavingDirectory(directory);
	testLogic.changeSavingFileName(filename);
	filename = testLogic.retrieveDirectoryFromTextFile();
	cout << "directory to be saved : " << filename << endl;

	cout << "Command: ";
	while (getline(cin, input)) {
		testLogic.initiateCommandAction(input);
		cout << "Command : ";
		testLogic.writeDataOntoFile(filename);
	}
	
	return;
}