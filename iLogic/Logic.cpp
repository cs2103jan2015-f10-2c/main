#include "Logic.h"

const string Logic::MESSAGE_SUCCESS = "execution success";

string Logic::readUserInput() {
	string userInput;

	while (userInput != "::exit") { // refractor this in the future
		iParser myParser;
		list<userCommand> userCommandList;
		getline(cin, userInput);
		userCommandList = myParser.parse(userInput);
		showUserInput(userCommandList);
	}

	return MESSAGE_SUCCESS;
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

Logic::Logic() {
	_nextItemID = 0;
}

Logic::~Logic() {}

/*
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

<<<<<<< HEAD

}
*/
=======
}


>>>>>>> 75ecd23d5ba36c7c428e7b829b72e548560dddc4
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

/*
unsigned int Logic::getItemIdFromLineIndex(int lineIndex){
	vector<Item> retrievedSchedule = _logicSchedule.retrieveSchedule();
	unsigned int Id = retrievedSchedule[lineIndex].getItemID();
	return Id;
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


int Logic::assignTimingToNewTask(string timingType, DateTime dateTime){
	unsigned int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	unsigned int lastLineItemID = getItemIdFromLineIndex(lastLineIndexOfSchedule);
	Item itemToBeAssignedTiming = assignTiming(itemToBeAssignedTiming, timingType, dateTime);
	deleteAndAddEditedItem(lastLineIndexOfSchedule, itemToBeAssignedTiming);
	return 1;
}

int Logic::assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex){
	Item itemToBeAssignedTiming = assignTiming(_logicSchedule.retrieveSchedule()[lineIndex], timingType, datetime);
	deleteAndAddEditedItem(lineIndex, itemToBeAssignedTiming);
	return 1;
}

Item Logic::assignPriority(Item item, char priorityType){
	item.setPriority(priorityType);
	return item;
}

int Logic::assignPriorityToNewTask(char priorityType){
	unsigned int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	Item itemToBeAssignedPriority = assignPriority(_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule], priorityType);
	deleteAndAddEditedItem(lastLineIndexOfSchedule, itemToBeAssignedPriority);
	return 1;
}

int Logic::assignPriorityToExistingTask(char priorityType, unsigned int lineIndex){
	Item itemToBeAssignedPriority = assignPriority(_logicSchedule.retrieveSchedule()[lineIndex], priorityType);
	deleteAndAddEditedItem(lineIndex, itemToBeAssignedPriority);
	return 1;
}

Item Logic::assignLabel(Item item, char labelType){
	item.setLabel(labelType);
	return item;
}

int Logic::assignLabelToNewTask(char labelType){
	unsigned int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
	Item itemToBeAssignedLabel = assignLabel(_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule], labelType);
	deleteAndAddEditedItem(lastLineIndexOfSchedule, itemToBeAssignedLabel);
	return 1;
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

int Logic::readDataFromFile(char * fileName, vector<Item> itemVector){
	// Variable to denote successful processing of function
	int retCode = -1;

	ifstream infile(fileName, std::ios::_Nocreate);

	if (infile.is_open()) {
		vector<Item>::iterator iterItem;
		while (!infile.eof()) {
			for (iterItem = itemVector.begin(); iterItem != itemVector.end(); ++iterItem) {
				infile.get(iterItem->getItemName);
				/*
				DateTime tempObj1 = iterItem->getStartTime();
				infile.get(tempObj1.getDay());
				infile.get(tempObj1.getMonth());
				infile.get(tempObj1.getYear());
				infile.get(tempObj1.getHour());
				infile.get(tempObj1.getMinute());
				
				infile.get(iterItem->getEndTime);
				/*DateTime tempObj2 = iterItem->getEndTime();
				infile.get(tempObj2).getDay());
				infile.get(tempObj2.getMonth());
				infile.get(tempObj2.getYear());
				infile.get(tempObj2.getHour());
				infile.get(tempObj2.getMinute());
<<<<<<< HEAD
			
=======
>>>>>>> 75ecd23d5ba36c7c428e7b829b72e548560dddc4
				infile.get(*iterItem->getStartTime);
				infile.get(*iterItem->getEndTime);
				infile.get(*iterItem->getItemID);
				infile.get(*iterItem->getDescription);
				infile.get(*iterItem->getPriority);
				infile.get(*iterItem->getLabel);
				infile.get(*iterItem->getCompletion);
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
			outfile << tempObj1.getDay();
			outfile << tempObj1.getMonth();
			outfile << tempObj1.getYear();
			outfile << tempObj1.getHour();
			outfile << tempObj1.getMinute();
			
			DateTime tempObj2;
			tempObj2 = iterItem->getEndTime();
			outfile << tempObj2.getDay();
			outfile << tempObj2.getMonth();
			outfile << tempObj2.getYear();
			outfile << tempObj2.getHour();
			outfile << tempObj2.getMinute();
			
			outfile << iterItem->getItemID() << endl;
			outfile << iterItem->getDescription() << endl;
			outfile << iterItem->getPriority() << endl;
			outfile << iterItem->getLabel() << endl;
			outfile << iterItem->getCompletion() << endl;
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
