#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;
	Logic testLogic;
	cout << "Command : ";
	while (getline(cin, input)) {
		cout << "input" << input << endl;
		testLogic.initiateCommandAction(input);
		cout << "Command : ";
	}
	return;
}