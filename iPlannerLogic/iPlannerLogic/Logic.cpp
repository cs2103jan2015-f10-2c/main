#include "Logic.h"

Logic::Logic(){

}


Logic::~Logic(){

}

int Logic::addTask(Item itemToBeAdded){
	_logicSchedule.addItem(itemToBeAdded);
}
int Logic::editTask(){

}

int Logic::deleteAndAddEditedItem(unsigned int lineIndexToBeEdited, Item editedItemToBeAdded){
	deleteTask(lineIndexToBeEdited);
	addTask(editedItemToBeAdded);
}

int Logic::deleteTask(unsigned int lineIndexToBeDeleted){
	if (getScheduleSize() > lineIndexToBeDeleted){
		unsigned int itemIdToBeDeleted = getItemIdFromLineIndex(lineIndexToBeDeleted);
		_logicSchedule.deleteItem(itemIdToBeDeleted);
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
			searchedItems.push_back(_logicSchedule.getSchedule()[lineIndex]);
		}
	}
}
bool Logic::isFound(int lineIndex, string& phraseToSearch){
	unsigned int phraseFoundFromItemName = _logicSchedule.getSchedule()[lineIndex].getItemName.find(phraseToSearch);
	unsigned int phraseFoundFromItemDescription = _logicSchedule.getSchedule()[lineIndex].getDescription.find(phraseToSearch);
	if (phraseFoundFromItemName>-1 || phraseFoundFromItemDescription> -1){
		return true;
	}
	else{
		return false;
	}
}

int Logic::sortTask(){

}

Item Logic::assignTiming(Item item, string timingType, DateTime datetime){
	if (timingType == "start"){
		item.setStartTime(datetime);
	}
	else if (timingType == "due" || timingType == "end"){
		item.setEndTime(datetime);
	}
	return item;
}

int Logic::assignTimingToNewTask(string timingType, DateTime datetime){
	unsigned int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	Item itemToBeAssignedTiming = assignTiming(_logicSchedule.getSchedule()[lastLineIndexOfSchedule], timingType, datetime); 
	deleteAndAddEditedItem(lastLineIndexOfSchedule, itemToBeAssignedTiming);
	return 1;
}

int Logic::assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex){
	Item itemToBeAssignedTiming = assignTiming(_logicSchedule.getSchedule()[lineIndex], timingType, datetime);
	deleteAndAddEditedItem(lineIndex, itemToBeAssignedTiming);
	return 1;
}

int Logic::assignPriority(){

}
int Logic::assignLabel(){

}
int Logic::changeView(){

}
int Logic::showHelpMenu(){

}

void Logic::assignSaveFolder(){

}
int Logic::readDataFromFile(char * fileName, vector<Item> itemVector){
  
}

int Logic::writeDataOntoFile(char * fileName,vector<Item> itemVector) {
	// Variable to denote successful processing of function
	int retCode = -1;
	ofstream outfile(fileName);

	if (!outfile.bad()) {
    vector<Item>::iterator iterItem;
    
    for( iterItem = itemVector.begin(); iterItem != itemVector.end(); ++iterItem) {
      outfile << *iterItem->getItemName << endl;
      outfile << *iterItem->getStartTime << endl;
      outfile << *iterItem->getEndTime << endl;
      outfile << *iterItem->getItemID << endl;
      outfile << *iterItem->getDescription << endl;
      outfile << *iterItem->getPriority << endl;
      outfile << *iterItem->getLabel << endl;
      outfile << *iterItem->getCompletion << endl;
    }
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
	unsigned int Id = _logicSchedule.getSchedule()[lineIndex].getItemID;
	return Id;
}

unsigned int Logic::getScheduleSize(){
	return _logicSchedule.getSchedule().size();
}

DateTime Logic::setDateTime(int year, int month, int day, int hour, int minute){
	DateTime datetime;
	if (datetime.isValidYearRange(year) && datetime.isValidMonthRange(month) && datetime.isValidDate(day, month, year)
		&& datetime.isValidHourRange(hour) && datetime.isValidMinuteRange(minute)){
		datetime.setYear(year);
		datetime.setMonth(month);
		datetime.setDay(day);
		datetime.setHour(hour);
		datetime.setMinute(minute);
	}
	return datetime;
}

DateTime Logic::setDateTime(int year, int month, int day){
	DateTime datetime;
	if (datetime.isValidYearRange(year) && datetime.isValidMonthRange(month) && datetime.isValidDate(day, month, year)){
		datetime.setYear(year);
		datetime.setMonth(month);
		datetime.setDay(day);
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
