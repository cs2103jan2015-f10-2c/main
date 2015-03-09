#include "Logic.h"

Logic::Logic(){

}


Logic::~Logic(){

}

int Logic::addTask(Item itemToBeAdded){
	logicSchedule.addItem(itemToBeAdded);
}
int Logic::editTask(){

}
int Logic::deleteTask(unsigned int lineIndexToBeDeleted){
	if (getScheduleSize() > lineIndexToBeDeleted){
		unsigned int itemIdToBeDeleted = getItemIdFromLineIndex(lineIndexToBeDeleted);
		logicSchedule.deleteItem(itemIdToBeDeleted);
		return 1;//Delete successful
	}
	else{
		return 0;//Delete failed
	}
}
int Logic::searchTask(string phraseToSearch){
	vector<Item> searchedItems;
	for (int lineIndex = 0; lineIndex < getScheduleSize(); lineIndex++){
		if (isFound(lineIndex, phraseToSearch)){
			searchedItems.push_back(logicSchedule.getSchedule()[lineIndex]);
		}
	}
}
bool Logic::isFound(int lineIndex, string& phraseToSearch){
	if (logicSchedule.getSchedule()[lineIndex].getItemName.find(phraseToSearch)>-1 || logicSchedule.getSchedule()[lineIndex].getDescription.find(phraseToSearch) > -1){
		return true;
	}
	else{
		return false;
	}
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
		outfile << setItem << endl << setDateTime << endl;
		outfile.close();
		retCode = 0;
	}

	return retCode;
}


void Logic::printItemVector(vector<Item> itemVector){
	for (int lineIndex = 0; lineIndex < itemVector.size(); lineIndex++){
		printItem(itemVector[lineIndex]);
		if (lineIndex < itemVector.size() - 1){
			cout << endl;
		}
	}
	return;
}

void Logic::printItem(Item item){
	cout << item.getItemName() << '\t';
	cout << item.getDescription() << '\t';
	//cout << item.getStartTime() << '\t';   Need print function for DateTime
	//cout << item.getEndTime() << '\t';
	cout << item.getLabel() << '\t';
	cout << item.getPriority();
	return;
}

unsigned int Logic::getItemIdFromLineIndex(int lineIndex){
	unsigned int Id = logicSchedule.getSchedule()[lineIndex].getItemID;
	return Id;
}

unsigned int Logic::getScheduleSize(){
	return logicSchedule.getSchedule().size();
}

DateTime Logic::setDateTime(int year, int month, int day, int hour, int minute){
	DateTime datetime;
	if (datetime.isValidYearRange(year) && datetime.isValidMonthRange(month) && datetime.isValidDate(day,month,year)
		&& datetime.isValidHourRange(hour) && datetime.isValidMinuteRange(minute)){
		datetime.setYear(year);
		datetime.setMonth(month);
		datetime.setDay(day);
		datetime.setHour(hour);
		datetime.setMinute(minute);
	}
	return datetime;
}

Item Logic::setItem(string itemName, DateTime startTime, DateTime endTime, string description, char priority, char label, bool isCompleted){
	Item item;

	item.setItemName(itemName);
  item.setStartTime(startTime);
  item.setEndTime(endTime);
	item.setDescription(description);
	item.setPriority(priority);
	item.setLabel(label);
	item.setCompletion(isCompleted);
	
  return item;
}
