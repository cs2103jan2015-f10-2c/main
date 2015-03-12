#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;
	getline(cin, input);
	iParser testParser;
	ParseInfo testParseInfo;
	testParseInfo =	testParser.parse(input);
}