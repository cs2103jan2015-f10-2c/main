//author A0112042E
//	Schedule
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "Schedule.h"

const string Schedule::COMMAND_ADD = "ADD";
const string Schedule::COMMAND_DELETE = "DELETE";
const string Schedule::COMMAND_REPLACE = "REPLACE";
const string Schedule::COMMAND_CLEAR = "CLEAR";
const string Schedule::ERROR_ADD = "ERROR: Command and Item were not recorded.";
const string Schedule::ERROR_EMPTYSTACKS = "ERROR: Undo has reached its limit.";
const string Schedule::LOG_ADDITEM = "STORAGE::AddItem";
const string Schedule::LOG_RETRIEVEITEM = "STORAGE::RetrieveItem";
const string Schedule::LOG_REPLACEITEM = "STORAGE::ReplaceItem";
const string Schedule::LOG_DELETEITEM = "STORAGE::DeleteItem";
const string Schedule::LOG_CONSTRUCTSCHEDULE = "STORAGE::ConstructSchedule";
const string Schedule::LOG_DESTRUCTSCHEDULE = "STORAGE::DestructSchedule";
const string Schedule::LOG_CLEAR = "STORAGE::ClearItems";
const string Schedule::LOG_UNDO = "STORAGE::UndoCommand";

//	Constructor
Schedule::Schedule() {
	_storageLogger.writeToLogFile(LOG_CONSTRUCTSCHEDULE);
}

//	Destructor
Schedule::~Schedule() {
	_storageLogger.writeToLogFile(LOG_DESTRUCTSCHEDULE);
}

//	Checks if an itemID matches the itemID of an item in a given vector cell
bool Schedule::isMatchingItemID(unsigned int vectorIndex, unsigned int itemID) {
	assert(itemID >= 0);
	assert(vectorIndex >= 0);
	
	if (_schedule[vectorIndex].getItemID() == itemID) {
		return true;
	}
	return false;
}

//	Checks if an item's priority matches that specified by the user
bool Schedule::isMatchingPriority(char itemPriority, char userPriority) {
	if (itemPriority == userPriority) {
		return true;
	}
	return false;
}

//	Checks if an item's label matches that specified by the user
bool Schedule::isMatchingLabel(char itemLabel, char userLabel) {
	if (itemLabel == userLabel) {
		return true;
	}
	return false;
}

//	Checks if an item's completion status matches that specified by the user
bool Schedule::isMatchingCompletionStatus(bool itemCompletion, bool userCompletion) {
	if (itemCompletion == userCompletion) {
		return true;
	}
	return false;
}

//	Checks if an item's time period matches that specified by the user
bool Schedule::isRelevantDateTime(DateTime itemStart, DateTime itemEnd, DateTime startTime, DateTime endTime) {
	if (itemStart.displayDateTime() == "" && itemEnd.displayDateTime() == "") {
		return false;
	} else if (itemStart.isAfter(endTime) && itemEnd.displayDateTime() == "") {
		return false;
	} else if (itemStart.isBefore(startTime) && itemEnd.displayDateTime() == "") {
		return false;
	} else if (itemStart.displayDateTime() == "" && itemEnd.isAfter(endTime)) {
		return false;
	} else if (itemStart.displayDateTime() == "" && itemEnd.isBefore(startTime)) {
		return false;
	} else if (itemStart.isBefore(startTime) && itemEnd.isBefore(startTime)) {
		return false;
	} else if (itemStart.isAfter(endTime) && itemEnd.isAfter(endTime)) {
		return false;
	} else {
		return true;
	}
}

//	Checks if an item's description and name has a user-specified keyword
bool Schedule::hasKeyword(string name, string description, string keyword) {
	if (lowerAllCase(name).find(lowerAllCase(keyword)) != string::npos) {
		return true;
	} else if (lowerAllCase(description).find(lowerAllCase(keyword)) != string::npos) {
		return true;
	} else {
		return false;
	}
}

//	Retrieves schedule vector index given itemID
unsigned int Schedule::findVectorIndexGivenItemID(unsigned int itemID) {
	unsigned int vectorIndex = 0;

	while (vectorIndex < _schedule.size() && !isMatchingItemID(vectorIndex, itemID)) {
		vectorIndex++;
	}

	return vectorIndex;
}

//	Retrieves item ID given display vector index
unsigned int Schedule::findItemIDGivenDisplayVectorIndex(unsigned int displayVectorIndex) {
	assert(displayVectorIndex >= 1);
	
	return _displaySchedule[displayVectorIndex - 1].getItemID();
}

//	Retrieves the size of the schedule
unsigned int Schedule::getSizeOfSchedule() {
	return _schedule.size();
}

//	Retrieves the size of the display schedule
unsigned int Schedule::getSizeOfDisplaySchedule() {
	return _displaySchedule.size();
}

//	Resets the display schedule to the schedule
unsigned int Schedule::resetDisplaySchedule() {
	_displaySchedule = _schedule;
	return getSizeOfDisplaySchedule();
}

//	Adds the item to the schedule, returns full details of the item (string)
string Schedule::addItem(Item* item) {
	_scheduleHistory.addCommand(COMMAND_ADD, *item);
	_schedule.push_back(*item);

	assert(_schedule.size() > 0);
	_storageLogger.writeToLogFile(LOG_ADDITEM);

	return _schedule.back().displayItemFullDetails();
}

//	Retrieves a copy of an existing item in the schedule give Item ID
Item Schedule::retrieveItemGivenItemID(unsigned int itemID) {
	assert(itemID >= 0);
	
	unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);
	return _schedule[vectorIndex];
}

//	Retrieves a copy of an existing item in the schedule given the item's display vector index
Item Schedule::retrieveItemGivenDisplayVectorIndex(unsigned int displayVectorIndex) {
	assert(displayVectorIndex >= 1);
	assert(_schedule.size() > 0);
	assert(_displaySchedule.size() > 0);
	unsigned int itemID = findItemIDGivenDisplayVectorIndex(displayVectorIndex);
	_storageLogger.writeToLogFile(LOG_RETRIEVEITEM);
	return retrieveItemGivenItemID(itemID);
}

//	Replaces an existing item in the schedule, returns full details of the item (string)
string Schedule::replaceItemGivenItemID(Item* replacementItem, unsigned int itemID) {
	assert(itemID >= 0);
	assert(_schedule.size() > 0);
	unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);

	_scheduleHistory.addCommand(COMMAND_REPLACE, _schedule[vectorIndex]);
	_schedule[vectorIndex] = *replacementItem;

	return _schedule[vectorIndex].displayItemFullDetails();
}

//	Replaces an existing item in the schedule given the item's display vector index
string Schedule::replaceItemGivenDisplayVectorIndex(Item* replacementItem, unsigned int displayVectorIndex) {
	assert(displayVectorIndex >= 1);
	assert(_schedule.size() > 0);
	assert(_displaySchedule.size() > 0);
	unsigned int itemID = findItemIDGivenDisplayVectorIndex(displayVectorIndex);
	_storageLogger.writeToLogFile(LOG_REPLACEITEM);
	return replaceItemGivenItemID(replacementItem, itemID);
}

//	Deletes an item from the schedule, returns full details of the item (string)
string Schedule::deleteItemGivenItemID(unsigned int itemID) {
	assert(itemID >= 0);
	assert(_schedule.size() > 0);
	unsigned int index = findVectorIndexGivenItemID(itemID);
	Item itemToBeDeleted = _schedule[index];

	_scheduleHistory.addCommand(COMMAND_DELETE, itemToBeDeleted);
	_schedule.erase(_schedule.begin() + index);

	return itemToBeDeleted.displayItemFullDetails();
}

//	Deletes an item from the schedule given item's display vector index
string Schedule::deleteItemGivenDisplayVectorIndex(unsigned int displayVectorIndex) {
	assert(displayVectorIndex >= 1);
	assert(_schedule.size() > 0);
	assert(_displaySchedule.size() > 0);
	unsigned int itemID = findItemIDGivenDisplayVectorIndex(displayVectorIndex);
	_storageLogger.writeToLogFile(LOG_DELETEITEM);
	return deleteItemGivenItemID(itemID);
}

//	Removes all items in the display schedule, from the schedule
string Schedule::clearDisplaySchedule() {
	unsigned int index = 1;

	_scheduleHistory.addClearCommand(_displaySchedule);

	while (getSizeOfDisplaySchedule() != 0) {
		unsigned int itemID = findItemIDGivenDisplayVectorIndex(index);
		unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);
		_schedule.erase(_schedule.begin() + vectorIndex);
		_displaySchedule.erase(_displaySchedule.begin());
	}
	
	assert(_displaySchedule.empty());

	_storageLogger.writeToLogFile(LOG_CLEAR);
	return COMMAND_CLEAR;
}

//	Undoes the last command that modified the schedule (add, replace, delete)
string Schedule::undoLastCommand() {
	Item latestItem;
	string command;
	vector <Item> latestClearedSchedule;

	string confirmation = _scheduleHistory.undoLastCommand(command, latestItem, latestClearedSchedule);

	if (confirmation == ERROR_EMPTYSTACKS) {
		return confirmation;
	} else if (command == COMMAND_ADD) {
		confirmation = undoAdd(latestItem);
	} else if (command == COMMAND_DELETE) {
		confirmation = undoDelete(latestItem);
	} else if (command == COMMAND_REPLACE) {
		confirmation = undoReplace(latestItem);
	} else if (command == COMMAND_CLEAR) {
		confirmation = undoClear(latestClearedSchedule);
	}

	return confirmation;
}

//	Undoes the last command that modified the schedule (add)
string Schedule::undoAdd(Item latestItem) {
	string confirmation = deleteItemGivenItemID(latestItem.getItemID());
	_scheduleHistory.removeUndoneCommand();

	_storageLogger.writeToLogFile(LOG_UNDO + COMMAND_ADD);
	return (COMMAND_ADD + confirmation);
}

//	Undoes the last command that modified the schedule (replace)
string Schedule::undoReplace(Item latestItem) {
	string confirmation = replaceItemGivenItemID(&latestItem, latestItem.getItemID());
	_scheduleHistory.removeUndoneCommand();

	_storageLogger.writeToLogFile(LOG_UNDO + COMMAND_REPLACE);
	return (COMMAND_REPLACE + confirmation);
}

//	Undoes the last command that modified the schedule (delete)
string Schedule::undoDelete(Item latestItem) {
	string confirmation = addItem(&latestItem);
	_scheduleHistory.removeUndoneCommand();

	_storageLogger.writeToLogFile(LOG_UNDO + COMMAND_DELETE);
	return (COMMAND_DELETE + confirmation);
}

//	Undoes the last command that cleared a schedule
string Schedule::undoClear(vector<Item> latestClearedSchedule) {
	unsigned int index;
	for (index = 0; index < latestClearedSchedule.size(); index++) {
		addItem(&(latestClearedSchedule[index]));
		_scheduleHistory.removeUndoneCommand();
	}

	_storageLogger.writeToLogFile(LOG_UNDO + COMMAND_CLEAR);
	return to_string(index);
}

string Schedule::resetHistory() {
	return _scheduleHistory.reset();
}

//	Retrieves the entire schedule
const vector<Item>& Schedule::retrieveSchedule() {
	return _schedule;
}

//	Retrieves the entire display schedule
const vector<Item>& Schedule::retrieveDisplaySchedule() {
	return _displaySchedule;
}

//	Checks if an item is earlier than another
bool Schedule::isEarlierThan(Item leftItem, Item rightItem) {
	string leftDateTime = "";
	string rightDateTime = "";

	if (leftItem.displayStartTime() != "") {
		leftDateTime = leftItem.displayStartTime();
	} else if (leftItem.displayEndTime() != "") {
		leftDateTime = leftItem.displayEndTime();
	}

	if (rightItem.displayStartTime() != "") {
		rightDateTime = rightItem.displayStartTime();
	} else if (rightItem.displayEndTime() != "") {
		rightDateTime = rightItem.displayEndTime();
	}

	return (leftDateTime < rightDateTime);
}

//	Sorts the display schedule by date, returns constant reference to sorted display schedule
const vector<Item>& Schedule::retrieveDisplayScheduleByDate() {
	stable_sort(_displaySchedule.begin(), _displaySchedule.end(), isEarlierThan);
	return retrieveDisplaySchedule();
}

// Convert entire string to lowercase
string Schedule::lowerAllCase(const string& uncovertedString) {
	string workingStringCopy = uncovertedString;

	transform(workingStringCopy.begin(), workingStringCopy.end(), workingStringCopy.begin(), tolower);

	return workingStringCopy;
}

//	Checks if an item's name is alphabetically smaller than another's
bool Schedule::isAlphabeticallySmallerThan(Item leftItem, Item rightItem) {
	string leftItemName = lowerAllCase(leftItem.getItemName());
	string rightItemName = lowerAllCase(rightItem.getItemName());

	return (leftItemName < rightItemName);
}

//	Sorts the display schedule by item name, returns constant reference to sorted display schedule
const vector<Item>& Schedule::retrieveDisplayScheduleByItemName() {
	stable_sort(_displaySchedule.begin(), _displaySchedule.end(), isAlphabeticallySmallerThan);
	return retrieveDisplaySchedule();
}

//	Checks if an item is of lower priority than another
bool Schedule::isLowerPriorityThan(Item leftItem, Item rightItem) {
	char leftItemPriority = leftItem.getPriority();
	char rightItemPriority = rightItem.getPriority();

	if (leftItemPriority == 'H') {
		leftItemPriority = '1';
	} else if (leftItemPriority == 'M') {
		leftItemPriority = '2';
	} else if (leftItemPriority == 'L') {
		leftItemPriority = '3';
	} else {
		leftItemPriority = '4';
	}

	if (rightItemPriority == 'H') {
		rightItemPriority = '1';
	} else if (rightItemPriority == 'M') {
		rightItemPriority = '2';
	} else if (rightItemPriority == 'L') {
		rightItemPriority = '3';
	} else {
		rightItemPriority = '4';
	}

	return (leftItemPriority < rightItemPriority);
}

//	Sorts the display schedule by priority, returns constant reference to sorted display schedule
const vector<Item>& Schedule::retrieveDisplayScheduleByPriority() {
	stable_sort(_displaySchedule.begin(), _displaySchedule.end(), isLowerPriorityThan);
	return retrieveDisplaySchedule();
}

//	Checks if an item is less completed than another (completed vs incomplete)
bool Schedule::isLessCompleteThan(Item leftItem, Item rightItem) {
	return (leftItem.getCompletion() < rightItem.getCompletion());
}

//	Sorts the display schedule by completion status (completed first), returns constant reference to sorted display schedule
const vector<Item>& Schedule::retrieveDisplayScheduleByCompletionStatus() {
	stable_sort(_displaySchedule.begin(), _displaySchedule.end(), isLessCompleteThan);
	return retrieveDisplaySchedule();
}

//	Checks if an items is updated later than another
bool Schedule::isUpdatedLaterThan(Item leftItem, Item rightItem) {
	return (leftItem.getLastUpdate() > rightItem.getLastUpdate());
}

//	Sorts the display schedule by last updated time
const vector<Item>& Schedule::retrieveDisplayScheduleByLastUpdate() {
	stable_sort(_displaySchedule.begin(), _displaySchedule.end(), isUpdatedLaterThan);
	return retrieveDisplaySchedule();
}

//	Filters the schedule by priority
const vector<Item>& Schedule::retrieveDisplayScheduleFilteredByPriority(char priority) {
	for (int index = 0; index < (int)_displaySchedule.size(); index++) {
		if (filterDisplayScheduleByPriority(index, priority)) {
			index--;
		}
	}

	return retrieveDisplaySchedule();
}

//	Filters the schedule by label
const vector<Item>& Schedule::retrieveDisplayScheduleFilteredByLabel(char label) {
	for (int index = 0; index < (int)_displaySchedule.size(); index++) {
		if (filterDisplayScheduleByLabel(index, label)) {
			index--;
		}
	}

	return retrieveDisplaySchedule();
}

//	Filters the schedule by completion status
const vector<Item>& Schedule::retrieveDisplayScheduleFilteredByCompletion(bool completionStatus) {
	for (int index = 0; index < (int)_displaySchedule.size(); index++) {
		if (filterDisplayScheduleByCompletion(index, completionStatus)) {
			index--;
		}
	}

	return retrieveDisplaySchedule();
}

//	Filters the schedule by keyword
const vector<Item>& Schedule::retrieveDisplayScheduleFilteredByKeyword(string keyword) {
	for (int index = 0; index < (int)_displaySchedule.size(); index++) {
		if (filterDisplayScheduleByKeyword(index, keyword)) {
			index--;
		}
	}

	return retrieveDisplaySchedule();
}

//	Filters the schedule by a user-specified time period
const vector<Item>& Schedule::retrieveDisplayScheduleFilteredByDateTime(DateTime startTime, DateTime endTime) {
	for (int index = 0; index < (int)_displaySchedule.size(); index++) {
		if (filterDisplayScheduleByDateTime(index, startTime, endTime)) {
			index--;
		}
	}

	return retrieveDisplaySchedule();
}

//	Checks given item in the schedule, and removes it if it does not have the user-specified priority
bool Schedule::filterDisplayScheduleByPriority(int index, char priority) {
	Item removedItem;

	if (!isMatchingPriority(_displaySchedule[index].getPriority(), priority)) {
		removedItem = _displaySchedule[index];

		_displaySchedule.erase(_displaySchedule.begin() + index);
		return true;
	}

	return false;
}

//	Checks given item in the schedule, and removes it if it does not have the user-specified label
bool Schedule::filterDisplayScheduleByLabel(int index, char label) {
	Item removedItem;

	if (!isMatchingLabel(_displaySchedule[index].getLabel(), label)) {
		removedItem = _displaySchedule[index];

		_displaySchedule.erase(_displaySchedule.begin() + index);
		return true;
	}

	return false;
}

//	Checks given item in the schedule, and removes it if it does not have the user-specified completion status
bool Schedule::filterDisplayScheduleByCompletion(int index, bool completionStatus) {
	Item removedItem;

	if (!isMatchingCompletionStatus(_displaySchedule[index].getCompletion(), completionStatus)) {
		removedItem = _displaySchedule[index];

		_displaySchedule.erase(_displaySchedule.begin() + index);
		return true;
	}

	return false;
}

//	Checks given item in the schedule, and removes it if it does not have the user-specified keyword
bool Schedule::filterDisplayScheduleByKeyword(int index, string keyword) {
	if (!hasKeyword(_displaySchedule[index].getItemName(), _displaySchedule[index].getDescription(), keyword)) {
		_displaySchedule.erase(_displaySchedule.begin() + index);
		return true;
	} else {
		return false;
	}
}

//	Checks given item in the schedule, and removes it if it does not coincide with the user-specified date and time period
bool Schedule::filterDisplayScheduleByDateTime(int index, DateTime startTime, DateTime endTime) {
	if (!isRelevantDateTime(_displaySchedule[index].getStartTime(), _displaySchedule[index].getEndTime(), startTime, endTime)) {
		_displaySchedule.erase(_displaySchedule.begin() + index);
		return true;
	} else {
		return false;
	}
}