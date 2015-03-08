#include "..\iPlannerParser\iPlannerParser.h"

void main() {
	iPlannerParser myParser;
	string userInput;
	getline(cin, userInput);
	myParser.main(userInput);
}