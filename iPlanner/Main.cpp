#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;
	Logic testLogic;
	while (getline(cin, input)) {
		iParser testParser;
		ParseInfo testParseInfo;

		
		testParseInfo = testParser.parse(input);

		cout << "Command : " << testParseInfo.getMainCommand() << endl;
		cout << "LineIndex : " << testParseInfo.getIndex() << endl;

		testLogic.initiateCommandAction(testParseInfo);
	}
	return;
}