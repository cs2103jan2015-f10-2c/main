#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;
	Logic testLogic;
	cout << "Command: ";
	while (getline(cin, input)) {
		iParser testParser;
		ParseInfo testParseInfo;	
		testParseInfo = testParser.parse(input);
		testLogic.initiateCommandAction(testParseInfo);
		cout << "Command: ";
	}
	return;
}