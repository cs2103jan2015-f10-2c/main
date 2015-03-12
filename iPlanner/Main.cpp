#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;

	iParser testParser;
	Logic testLogic;
	ParseInfo testParseInfo;
	getline(cin, input);
	testParseInfo = testParser.parse(input);
	cout << "ItemName Added : " << testParseInfo.getItem().getItemName() << endl;
	testLogic.initiateCommandAction(testParseInfo);
	
	getline(cin, input);
	cout << "second input" << input << endl;
	testParseInfo = testParser.parse(input);
	cout << "ItemName Added : " << testParseInfo.getItem().getItemName() << endl;
	testLogic.initiateCommandAction(testParseInfo);
	/*while (testParseInfo.getMainCommand() != "exit"){
		getline(cin, input);
		testParseInfo = testParser.parse(input);
		cout << testParseInfo.getItem().getItemName() << endl;
		testLogic.initiateCommandAction(testParseInfo);
	}*/
	return;
}