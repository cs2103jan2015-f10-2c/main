#include "..\iLogic\Logic.h"
#include "..\iParser\iParser.h"

void main() {
	string input;
	Logic testLogic;
	cout << "Command: ";
	while (getline(cin, input)) {
		testLogic.initiateCommandAction(input);
		cout << "Command : ";
	}
	return;
}