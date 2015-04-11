////@author A0105180W
#include "Log.h"

void Log::writeToLogFile(string stringToBeLogged) {

	ofstream writeFile("log.txt", ios::app);
	writeFile << stringToBeLogged << endl;

	writeFile.close();
}