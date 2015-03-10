#include "Logic.h"

const string Logic::MESSAGE_SUCCESS = "execution success";
const string Logic::MESSAGE_INVALID_INPUT = "invalid input";
const string Logic::COMMAND_ADD = "add";
const string Logic::COMMAND_DELETE = "del";
const string Logic::COMMAND_EDIT = "edit";
const string Logic::COMMAND_EXIT = "exit";

Logic::Logic() {
	_nextItemID = 0;
}

Logic::~Logic() {}

string Logic::executeLogic() {
	string userInput;

	while (notExit(userInput)) {
		iParser myParser;
		list<userCommand> userCommandList;
		getline(cin, userInput);
		userCommandList = myParser.parse(userInput);
		executeCommand(userCommandList);	
		//showUserInput(userCommandList);
	}

	return MESSAGE_SUCCESS;
}

bool Logic::notExit(string userInput) {
	return userInput != COMMAND_EXIT;
}

string Logic::showUserInput(list<userCommand> userCommandList) {
	list<userCommand>::iterator iter;
	int i = 1; // refractor this in the future
	for (iter = userCommandList.begin(); iter != userCommandList.end(); i++, iter++) {
		cout << "Command " << i << ": " << iter->getCommand() << endl
			<< "Text " << i << ": " << iter->getText() << endl;
	}

	return MESSAGE_SUCCESS;
}

string Logic::executeCommand(list<userCommand> userCommandList) {
	list<userCommand>::iterator iter;

	for (iter = userCommandList.begin(); iter != userCommandList.end(); iter++) {
		if (!isValidCommand(iter->getCommand())) {
			return MESSAGE_INVALID_INPUT;
		}
	}
	return MESSAGE_SUCCESS;
}

bool Logic::isValidCommand(string userCommand) {
	bool isValid = false;

	if (userCommand == COMMAND_ADD || userCommand == COMMAND_DELETE ||
		userCommand == COMMAND_EDIT || userCommand == COMMAND_EXIT) {
		isValid = true;
	}

	return isValid;
}

unsigned int Logic::addTask(Item itemToBeAdded){
	unsigned int addedItemID = -1;
	if (isValidItem(itemToBeAdded)){
		addedItemID = _logicSchedule.addItem(itemToBeAdded);
		return addedItemID;
	}
	else return addedItemID;
}
/*
int Logic::editTask(string partToEdit, unsigned int lineIndexToBeEdited){

}
*/


bool Logic::isValidItem(Item itemToBeChecked){
	return true;
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
		failedDelete.setItemID(0);
		return failedDelete;//Delete failed
	}
}


unsigned int Logic::getItemIdFromLineIndex(int lineIndex){
	vector<Item> retrievedSchedule = _logicSchedule.retrieveSchedule();
	unsigned int Id = retrievedSchedule[lineIndex-1].getItemID();
	return Id;
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

int Logic::deleteAndAddEditedItem(unsigned int lineIndexToBeEdited, Item editedItemToBeAdded){
	deleteTask(lineIndexToBeEdited);
	addTask(editedItemToBeAdded);
	return 1;
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
	Item itemToBeAssignedTiming = getSchedule()[lastLineIndexOfSchedule];
	Item itemAfterTimingAssigned = assignTiming(itemToBeAssignedTiming, timingType,dateTime);
	//DELETE AND EDIT NEEDED!!!!!!!deleteAndAddEditedItem(lastLineIndexOfSchedule, itemAfterAssignedPriority);
	return itemAfterTimingAssigned;
}

Item Logic::assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex){
	Item itemToBeAssignedTiming = getSchedule()[lineIndex - 1];
	Item itemAfterTimingAssigned = assignTiming(itemToBeAssignedTiming, timingType,datetime);
	//DELETE AND EDIT NEEDED!!!!!!!deleteAndAddEditedItem(lastLineIndexOfSchedule, itemAfterAssignedPriority);
	return itemAfterTimingAssigned;
}

Item Logic::assignPriority(Item item, char priorityType){
	item.setPriority(priorityType);
	return item;
}

Item Logic::assignPriorityToNewTask(char priorityType){
	int lastLineIndexOfSchedule = getScheduleSize()-1;//new task will be at the very back of the schedule vector
	Item itemToBeAssignedPriority = getSchedule()[lastLineIndexOfSchedule];
	Item itemAfterPriorityAssigned = assignPriority(itemToBeAssignedPriority,priorityType);
	//DELETE AND EDIT NEEDED!!!!!!!deleteAndAddEditedItem(lastLineIndexOfSchedule, itemAfterAssignedPriority);
	return itemAfterPriorityAssigned;
}

Item Logic::assignPriorityToExistingTask(char priorityType, unsigned int lineIndex){
	Item itemToBeAssignedPriority = getSchedule()[lineIndex-1];
	Item itemAfterPriorityAssigned = assignPriority(itemToBeAssignedPriority, priorityType);
	//DELETE AND EDIT NEEDED!!!!!!!deleteAndAddEditedItem(lastLineIndexOfSchedule, itemAfterAssignedPriority);
	return itemAfterPriorityAssigned;
}

Item Logic::assignLabel(Item item, char labelType){
	item.setLabel(labelType);
	return item;
}
Item Logic::assignLabelToNewTask(char labelType){
	int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	Item itemToBeAssignedLabel = getSchedule()[lastLineIndexOfSchedule];
	Item itemAfterLabelAssigned = assignLabel(itemToBeAssignedLabel, labelType);
	//DELETE AND EDIT NEEDED!!!!!!!deleteAndAddEditedItem(lastLineIndexOfSchedule, itemAfterAssignedPriority);
	return itemAfterLabelAssigned;
}

Item Logic::assignLabelToExistingTask(char labelType, unsigned int lineIndex){
	Item itemToBeAssignedLabel = getSchedule()[lineIndex - 1];
	Item itemAfterLabelAssigned = assignLabel(itemToBeAssignedLabel, labelType);
	//DELETE AND EDIT NEEDED!!!!!!!deleteAndAddEditedItem(lastLineIndexOfSchedule, itemAfterAssignedPriority);
	return itemAfterLabelAssigned;
}
/*
int Logic::editTask(string partToEdit, unsigned int lineIndexToBeEdited){

}




int Logic::searchTask(string phraseToSearch){
	vector<Item> searchedItems;
	Item foundItem;
	unsigned int lineIndex;
	unsigned int itemID;
	unsigned int scheduleSize = getScheduleSize();
	for (lineIndex = 0; lineIndex < scheduleSize; lineIndex++){
		if (isFound(lineIndex, phraseToSearch)){
			itemID = getItemIdFromLineIndex(lineIndex);
			foundItem = getItem(itemID);
			searchedItems.push_back(foundItem);
		}
	}
}

bool Logic::isFound(int lineIndex, string& phraseToSearch){
	Item itemFromLogicSchedule;
	itemFromLogicSchedule = getItem(lineIndex);
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

int Logic::sortTask(){

}


int Logic::changeView(){

}

int Logic::showHelpMenu(){

}

void Logic::assignSaveFolder(){

}
*/
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

Item Logic::getItem(unsigned int itemID) {
	Item itemToBeReturned;
	itemToBeReturned = _logicSchedule.getItem(itemID);
}

unsigned int Logic::getItemIdFromLineIndex(int lineIndex){
	unsigned int Id = _logicSchedule.retrieveSchedule()[lineIndex].getItemID;
	return Id;
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
