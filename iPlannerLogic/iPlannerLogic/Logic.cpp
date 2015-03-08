#include "Logic.h"

Logic::Logic()
{
}


Logic::~Logic()
{
}

int Logic::addTask(){
}
int Logic::editTask(){
}
int Logic::deleteTask(){

}
int Logic::searchTask(){

}
int Logic::sortTask(){

}
int Logic::assignTiming(){
}
int Logic::assignPriority(){

}
int Logic::assignLabel(){

}
int Logic::changeView(){

}
int Logic::showHelpMenu(){

}

void Logic::addToTStorage(){

}
void Logic::addToPStorage(){

}
void Logic::deleteFromPStorage(){

}
void Logic::editPStorage(){

}

void Logic::assignSaveFolder(){

}
void Logic::readDataFromFile(){

}
int Logic::writeDataOntoFile(char * fileName) {
	// Variable to denote successful processing of function
	int retCode = -1;
	ofstream outfile(fileName);

	if (!outfile.bad()) {

		outfile << _taskName << endl;
		outfile.close();
		retCode = 0;
	}

	return retCode;
}
