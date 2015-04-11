#include "Log.h"

void Log::writeToLogFile(string stringToBeLogged) {

	logData.push_back(stringToBeLogged);

	ofstream writeFile("log.txt", ios::app);
	writeFile << stringToBeLogged << endl;

	writeFile.close();
}