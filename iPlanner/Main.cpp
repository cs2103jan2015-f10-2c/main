#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {



	/*string testInput[][3] = { { "Do CS2103", "1 Mar 2015 to 31 Apr 2015", "" },
	{ "Do LSM1301", "31 Mar", "10pm-11pm" } };
	string expectedCommand[] = { "add", "start", "end" };
	string expectedText[][3] = { { "Do CS2103", "1 3 2015 -1 -1", "31 4 2015 -1 -1" },
	{ "Do LSM1301", "31 3 -1 22 -1", "31 3 -1 23 -1" } };

	for (int i = 0; i < 2; i++) {
	vector<string> testVector;
	for (int j = 0; j < 3; j++) {
	{
	if (i == 0 && j == 2) {
	break;
	}
	else {
	string input = testInput[i][j];
	testVector.push_back(input);
	}
	}
	}
	testParser.checkAndSetTokenisedInformation(testVector);
	testParser.clearParseInfo();
	}*/


	iParser testParser;
	Logic testLogic;
	string userInput;
	list<COMMAND_AND_TEXT> parseInfo;

	testLogic.retrieveDirectoryFromTextFile();
	testLogic.readDataFromFile();

	cout << "command : ";
	while (getline(cin, userInput)){
		testLogic.initiateCommandAction(testParser, userInput);
		cout << "command : ";
	}


		return;
	}