#include "Logic.h"

Logic::Logic(){

}


Logic::~Logic(){

}

unsigned int Logic::addTask(Item itemToBeAdded){
	int addedItemId = _logicSchedule.addItem(itemToBeAdded);
	return addedItemId;
}
/*
int Logic::editTask(string partToEdit, unsigned int lineIndexToBeEdited){

}

int Logic::deleteAndAddEditedItem(unsigned int lineIndexToBeEdited, Item editedItemToBeAdded){
	deleteTask(lineIndexToBeEdited);
	addTask(editedItemToBeAdded);
}

Item Logic::deleteTask(unsigned int lineIndexToBeDeleted){
	unsigned int itemIdToBeDeleted;
	if (isValidLineIndex(lineIndexToBeDeleted)){
		itemIdToBeDeleted = getItemIdFromLineIndex(lineIndexToBeDeleted);
		Item deletedItem = _logicSchedule.deleteItem(itemIdToBeDeleted);
		return deletedItem;//Delete successful
	}
	else{
		Item failedDelete;
		failedDelete.setItemID(-1);
		return failedDelete;//Delete failed
	}
}
*/
/*
int Logic::searchTask(string phraseToSearch){
	vector<Item> searchedItems;
	unsigned int lineIndex;
	int scheduleSize = getScheduleSize();
	for (lineIndex = 0; lineIndex < scheduleSize; lineIndex++){
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

Item Logic::assignPriority(Item item, char priorityType){
	item.setPriority(priorityType);
	return item;
}

int Logic::assignPriorityToNewTask(char priorityType){
	unsigned int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	Item itemToBeAssignedPriority = assignPriority(_logicSchedule.getSchedule()[lastLineIndexOfSchedule], priorityType);
	deleteAndAddEditedItem(lastLineIndexOfSchedule, itemToBeAssignedPriority);
	return 1;
}

int Logic::assignPriorityToExistingTask(char priorityType, unsigned int lineIndex){
	Item itemToBeAssignedPriority = assignPriority(_logicSchedule.getSchedule()[lineIndex], priorityType);
	deleteAndAddEditedItem(lineIndex, itemToBeAssignedPriority);
	return 1;
}

Item Logic::assignLabel(Item item, char labelType){
	item.setLabel(labelType);
	return item;
}

int Logic::assignLabelToNewTask(char labelType){
	unsigned int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	Item itemToBeAssignedLabel = assignLabel(_logicSchedule.getSchedule()[lastLineIndexOfSchedule], labelType);
	deleteAndAddEditedItem(lastLineIndexOfSchedule, itemToBeAssignedLabel);
	return 1;
}

int Logic::assignPriorityToExistingTask(char labelType, unsigned int lineIndex){
	Item itemToBeAssignedLabel = assignPriority(_logicSchedule.getSchedule()[lineIndex], labelType);
	deleteAndAddEditedItem(lineIndex, itemToBeAssignedLabel);
	return 1;
}

int Logic::changeView(){

}
int Logic::showHelpMenu(){

}

void Logic::assignSaveFolder(){

}
int Logic::readDataFromFile(char * fileName, vector<Item> itemVector){
	// Variable to denote successful processing of function
	int retCode = -1;

	ifstream infile(fileName, std::ios::_Nocreate);

	if (infile.is_open()) {
		vector<Item>::iterator iterItem;
		while (!infile.eof()) {
			for (iterItem = itemVector.begin(); iterItem != itemVector.end(); ++iterItem) {
				infile.get(*iterItem->setItemName);
				infile.get(*iterItem->setStartTime);
				infile.get(*iterItem->setEndTime);
				infile.get(*iterItem->setItemID);
				infile.get(*iterItem->setDescription);
				infile.get(*iterItem->setPriority);
				infile.get(*iterItem->setLabel);
				infile.get(*iterItem->setCompletion);
			}
		}
		infile.close();
		retCode = 0;
	}
	return retCode;
}

int Logic::writeDataOntoFile(char * fileName, vector<Item> itemVector) {
	// Variable to denote successful processing of function
	int retCode = -1;
	ofstream outfile(fileName);

	if (!outfile.bad()) {
		vector<Item>::iterator iterItem;

		for (iterItem = itemVector.begin(); iterItem != itemVector.end(); ++iterItem) {
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
*/
/*
bool Logic::isValidLineIndex(unsigned int lineIndexToBeChecked){
	if (getScheduleSize() > lineIndexToBeChecked){
		return true;
	}
	else{
		return false;
	}
}

unsigned int Logic::getItemIdFromLineIndex(int lineIndex){
	unsigned int Id = _logicSchedule.getSchedule()[lineIndex].getItemID;
	return Id;
}
*/
/*
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


unsigned int Logic::getScheduleSize(){
	return _logicSchedule.getSizeOfSchedule();
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
*/