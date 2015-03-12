#include "Logic.h"

const string Logic::MESSAGE_SUCCESS = "execution success";
const string Logic::MESSAGE_INVALID_INPUT = "invalid input";
const string Logic::COMMAND_ADD = "add";
const string Logic::COMMAND_DELETE = "del";
const string Logic::COMMAND_EDIT = "edit";
const string Logic::COMMAND_EXIT = "exit";

char Logic::buffer[300];
const string Logic::ASSIGNED_PRIORITY = "Priority : %c ";
const string Logic::ASSIGNED_LABEL = "Label : %c ";
const string Logic::ASSIGNED_START_TIME = "Start Time : %i/%i/%i %i:%i";
const string Logic::ASSIGNED_END_TIME = "End Time : %i/%i/%i %i:%i";
const string Logic::ASSIGNED_NAME = "Item Name : %s";
const string Logic::ASSIGNED_DESCRIPTION = "Item Description : %s";



Logic::Logic() {
	_nextItemID = 1;
	//failure in add,delete,add function will return an item with ID = 0
}

Logic::~Logic() {}

void Logic::printSchedule(){
	vector<Item> retrievedSchedule = getSchedule();
	for (int lineNumber = 0; lineNumber < getScheduleSize(); lineNumber++){
		printItem(getItemFromLineIndex(lineNumber));
		if (lineNumber != getScheduleSize() - 1){
			cout << endl;
		}
	}
}

void Logic::printItem(Item itemToBePrinted){
	printAssignedName(itemToBePrinted);
	printAssignedStartTime(itemToBePrinted);
	printAssignedEndTime(itemToBePrinted);
	printAssignedDescription(itemToBePrinted);
	printAssignedPriority(itemToBePrinted);
	printAssignedLabel(itemToBePrinted);
}
void Logic::printAssignedPriority(Item itemToBePrinted){
	sprintf_s(buffer, ASSIGNED_PRIORITY.c_str(), itemToBePrinted.getPriority());
	cout << buffer;
}

void Logic::printAssignedLabel(Item itemToBePrinted){
	sprintf_s(buffer, ASSIGNED_LABEL.c_str(), itemToBePrinted.getLabel());
	cout << buffer;
}

void Logic::printAssignedStartTime(Item itemToBePrinted){
	sprintf_s(buffer, ASSIGNED_START_TIME.c_str(), itemToBePrinted.getStartTime().getDay(), itemToBePrinted.getStartTime().getMonth(), itemToBePrinted.getStartTime().getYear(), itemToBePrinted.getStartTime().getHour(), itemToBePrinted.getStartTime().getMinute());
	cout << buffer;
}
void Logic::printAssignedEndTime(Item itemToBePrinted){
	sprintf_s(buffer, ASSIGNED_END_TIME.c_str(), itemToBePrinted.getEndTime().getDay(), itemToBePrinted.getEndTime().getMonth(), itemToBePrinted.getEndTime().getYear(), itemToBePrinted.getEndTime().getHour(), itemToBePrinted.getEndTime().getMinute());
	cout << buffer;
}

void Logic::printAssignedName(Item itemToBePrinted){
	sprintf_s(buffer, ASSIGNED_NAME.c_str(), itemToBePrinted.getItemName());
	cout << buffer;
}
void Logic::printAssignedDescription(Item itemToBePrinted){
	sprintf_s(buffer, ASSIGNED_DESCRIPTION.c_str(), itemToBePrinted.getDescription());
	cout << buffer;
}

unsigned int Logic::addTask(Item itemToBeAdded){
	unsigned int addedItemID = DEFAULT_ITEM_ID;
	if (isValidItem(itemToBeAdded)) {
			itemToBeAdded.setItemID(_nextItemID);
			_nextItemID++;
			addedItemID = _logicSchedule.addItem(itemToBeAdded);
	}
	return addedItemID;
}

unsigned int Logic::addTaskForEdition(Item itemToBeAdded){
	unsigned int addedItemID = DEFAULT_ITEM_ID;
	if (isValidItem(itemToBeAdded)) {
		addedItemID = _logicSchedule.addItem(itemToBeAdded);
	}
	return addedItemID;
}
/*
int Logic::editTask(string partToEdit, unsigned int lineIndexToBeEdited){

}
*/


bool Logic::isValidItem(Item itemToBeChecked){
	return true;
	/*ItemVerification itemVerifier(itemToBeChecked, _nextItemID);
	if (itemVerifier.isValidItem()) {
		return true;
	} else {
		return false;
	}*/
}

Item Logic::deleteTask(unsigned int lineIndexToBeDeleted){
	unsigned int itemIDToBeDeleted;
	if (isValidLineIndex(lineIndexToBeDeleted)){
		itemIDToBeDeleted = getItemIDFromLineIndex(lineIndexToBeDeleted);
		Item deletedItem = _logicSchedule.deleteItem(itemIDToBeDeleted);
		return deletedItem;//Delete successful
	}
	else{
		Item failedDelete;
		failedDelete.setItemID(DEFAULT_ITEM_ID);
		return failedDelete;//Delete failed
	}
}


unsigned int Logic::getItemIDFromLineIndex(unsigned int lineIndex){
	vector<Item> retrievedSchedule = getSchedule();
	unsigned int id = retrievedSchedule[lineIndex-1].getItemID();
	return id;
}

vector<Item> Logic::getSchedule(){
	return _logicSchedule.retrieveSchedule();
}

bool Logic::isValidLineIndex(unsigned int lineIndexToBeChecked){
	if (getScheduleSize() > lineIndexToBeChecked){
		return true;
	}
	else{
		return false;
	}
}
unsigned int Logic::getScheduleSize(){
	return _logicSchedule.getSizeOfSchedule();
}

Item Logic::deleteAndAddEditedItem(unsigned int lineIndexToBeEdited, Item editedItemToBeAdded){
	deleteTask(lineIndexToBeEdited);
	addTaskForEdition(editedItemToBeAdded);
	return editedItemToBeAdded;
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


Item Logic::assignTimingToNewTask(string timingType, DateTime dateTime){
	int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	if (timingType == "start"){
		_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setStartTime(dateTime);
	}
	else if (timingType == "end"){
		_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setEndTime(dateTime);
	}
	return _logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule];
}

Item Logic::assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex){
	if (timingType == "start"){
		_logicSchedule.retrieveSchedule()[lineIndex - 1].setStartTime(datetime);
	}
	else if (timingType == "end"){
		_logicSchedule.retrieveSchedule()[lineIndex - 1].setEndTime(datetime);
	}
	return _logicSchedule.retrieveSchedule()[lineIndex - 1];

}

Item Logic::assignPriority(Item item, char priorityType){
	item.setPriority(priorityType);
	return item;
}

Item Logic::assignPriorityToNewTask(char priorityType){
	int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setPriority(priorityType);
	return _logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule];
}

Item Logic::assignPriorityToExistingTask(char priorityType, unsigned int lineIndex){
	_logicSchedule.retrieveSchedule()[lineIndex-1].setPriority(priorityType);
	return _logicSchedule.retrieveSchedule()[lineIndex-1];
}

Item Logic::assignLabel(Item item, char labelType){
	item.setLabel(labelType);
	return item;
}
Item Logic::assignLabelToNewTask(char labelType){
	int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setLabel(labelType);
	return _logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule];
}

Item Logic::assignLabelToExistingTask(char labelType, unsigned int lineIndex){
	_logicSchedule.retrieveSchedule()[lineIndex - 1].setLabel(labelType);
	return _logicSchedule.retrieveSchedule()[lineIndex - 1];
}

string Logic::processedCommand(ParseInfo parseInfoToBeProcessed){
	return parseInfoToBeProcessed.getMainCommand();
}
unsigned int Logic::processedLineIndex(ParseInfo parseInfoToBeProcessed){
	return parseInfoToBeProcessed.getIndex();
}
Item Logic::processedItem(ParseInfo parseInfoToBeProcessed){
	return parseInfoToBeProcessed.getItem();
}


int Logic::editTask(string command, Item itemToBeEdited, unsigned int lineIndexToBeEdited){
	if (command == "priority"){
		char priorityToBeAssigned = itemToBeEdited.getPriority();
		assignPriorityToExistingTask(priorityToBeAssigned, lineIndexToBeEdited);
	}
	else if (command == "label"){
		char labelToBeAssigned = itemToBeEdited.getLabel();
		assignLabelToExistingTask(labelToBeAssigned, lineIndexToBeEdited);
	}
	else if (command == "start"){
		DateTime startTimeToBeAssigned = itemToBeEdited.getStartTime();
		assignTimingToExistingTask("start", startTimeToBeAssigned, lineIndexToBeEdited);

	}
	else if (command == "end" || command == "due"){
		DateTime endTimeToBeAssigned = itemToBeEdited.getEndTime();
		assignTimingToExistingTask("end", endTimeToBeAssigned, lineIndexToBeEdited);
	}
	return 1;
}




vector<Item> Logic::searchTask(string phraseToSearch){
	vector<Item> searchedItems;
	Item foundItem;
	unsigned int lineIndex;
	unsigned int itemID;
	unsigned int scheduleSize = getScheduleSize();
	for (lineIndex = 0; lineIndex < scheduleSize; lineIndex++){
		if (isFound(lineIndex, phraseToSearch)){
			foundItem = getItemFromLineIndex(lineIndex);
			searchedItems.push_back(foundItem);
		}
	}
	return searchedItems;
}

bool Logic::isFound(int lineIndex, string& phraseToSearch){
	Item itemFromLogicSchedule;
	itemFromLogicSchedule = getItemFromLineIndex(lineIndex);
	unsigned int phraseFoundFromItemName;
	unsigned int phraseFoundFromItemDescription;
	phraseFoundFromItemName = itemFromLogicSchedule.getItemName().find(phraseToSearch);
	if (phraseFoundFromItemName != string::npos) {
		return true;
	}
	phraseFoundFromItemDescription = itemFromLogicSchedule.getDescription().find(phraseToSearch);
	if (phraseFoundFromItemDescription != string::npos) {
		return true;
	}
	return false;
}

Item Logic::getItemFromLineIndex(unsigned int lineIndex) {
	Item itemToBeReturned;
	itemToBeReturned.setItemID(getSchedule()[lineIndex].getItemID());
	itemToBeReturned.setItemName(getSchedule()[lineIndex].getItemName());
	itemToBeReturned.setLabel(getSchedule()[lineIndex].getLabel());
	itemToBeReturned.setDescription(getSchedule()[lineIndex].getDescription());
	itemToBeReturned.setStartTime(getSchedule()[lineIndex].getStartTime());
	itemToBeReturned.setEndTime(getSchedule()[lineIndex].getEndTime());
	itemToBeReturned.setPriority(getSchedule()[lineIndex].getPriority());
	itemToBeReturned.setCompletion(getSchedule()[lineIndex].getCompletion());
	return itemToBeReturned;
}



int Logic::readDataFromFile(char * fileName) {
	// Variable to denote successful processing of function
	int retCode = -1;

	ifstream infile(fileName, std::ios::_Nocreate);
	string line;
	//Number of lines in Text File
	int fileLength = 1;  
	if (infile.is_open()) {

		while (!infile.eof()) {
			Item readItem;
			DateTime readTime;
			int tempInt;
			// Total Number of Lines for each Item = 16
			if (fileLength % 16 == 1) {
				getline(infile, line);
				readItem.setItemName(line);
			}
			else if (fileLength % 16 == 2) {
				for (int i = 0; i < 5; i++) {
					char buffer[256];
					infile.getline(buffer, 256);
					tempInt = atoi(buffer);
					if (i = 0) {
						readTime.setDay(tempInt);
					}
					else if (i = 1) {
						readTime.setMonth(tempInt);
					}
					else if (i = 2) {
						readTime.setYear(tempInt);
					}
					else if (i = 3) {
						readTime.setHour(tempInt);
					}
					else {
						readTime.setMinute(tempInt);
					}
					fileLength+=5;
				}
				readItem.setStartTime(readTime);
			}
			else if (fileLength % 16 == 7) {
				for (int i = 0; i < 5; i++) {
					char buffer[256];
					infile.getline(buffer, 256);
					tempInt = atoi(buffer);
					if (i = 0) {
						readTime.setDay(tempInt);
					}
					else if (i = 1) {
						readTime.setMonth(tempInt);
					}
					else if (i = 2) {
						readTime.setYear(tempInt);
					}
					else if (i = 3) {
						readTime.setHour(tempInt);
					}
					else {
						readTime.setMinute(tempInt);
					}
					fileLength += 5;
				}
				readItem.setEndTime(readTime);
			}
			else if (fileLength % 16 == 12) {
				char buffer[256];
				infile.getline(buffer, 256);
				tempInt = atoi(buffer);
				readItem.setItemID(tempInt);
				fileLength++;
			}
			else if (fileLength % 16 == 13) {
				getline(infile, line);
				readItem.setDescription(line);
				fileLength++;
			}
			else if (fileLength % 16 == 14) {
				char tempChar;
				infile.get(tempChar);
				readItem.setPriority(tempChar);
				fileLength++;
			}
			else if (fileLength % 16 == 15) {
				char tempChar;
				infile.get(tempChar);
				readItem.setLabel(tempChar);
				fileLength++;
			}
			else if (fileLength % 16 == 0) {
				getline(infile, line);
				if (line.compare("true")) {
					readItem.setCompletion(true);
				}
				else {
					readItem.setCompletion(false);
				}
				fileLength++;
			}
			_logicSchedule.addItem(readItem);

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
			outfile << iterItem->getItemName() << endl;

			DateTime tempObj1;
			tempObj1 = iterItem->getStartTime();
			outfile << tempObj1.getDay() << endl;
			outfile << tempObj1.getMonth() << endl;
			outfile << tempObj1.getYear() << endl;
			outfile << tempObj1.getHour() << endl;
			outfile << tempObj1.getMinute() << endl;

			DateTime tempObj2;
			tempObj2 = iterItem->getEndTime();
			outfile << tempObj2.getDay() << endl;
			outfile << tempObj2.getMonth() << endl;
			outfile << tempObj2.getYear() << endl;
			outfile << tempObj2.getHour() << endl;
			outfile << tempObj2.getMinute() << endl;

			outfile << iterItem->getItemID() << endl;

			string temp = iterItem->getDescription();
			if (temp.size() != 0) {
				outfile << iterItem->getDescription() << endl;
			}
			else {
				outfile << endl;
			}
			if (iterItem->getPriority()) {
				outfile << iterItem->getPriority() << endl;
			}
			else {
				outfile << endl;
			}
			if (iterItem->getLabel()) {
				outfile << iterItem->getLabel() << endl;
			}
			else {
				outfile << endl;
			}
			if (iterItem->getCompletion()) {
				outfile << iterItem->getCompletion() << endl;
			}
			else {
				outfile << false << endl;
			}

		}
		outfile.close();
		retCode = 0;
	}

	return retCode;
}

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
/*
int Logic::sortTask(){

}


int Logic::changeView(){

}

int Logic::showHelpMenu(){

}
*/
/*
void Logic::assignSaveFolder(){

}
*/