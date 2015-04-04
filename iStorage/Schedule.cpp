//	Schedule
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "Schedule.h"

const string Schedule::COMMAND_ADD = "ADD";
const string Schedule::COMMAND_DELETE = "DELETE";
const string Schedule::COMMAND_REPLACE = "REPLACE";
const string Schedule::ERROR_ADD = "ERROR: Command and Item were not recorded.";
const string Schedule::ERROR_EMPTYSTACKS = "ERROR: Undo has reached its limit.";

//	Constructor
Schedule::Schedule() {}

//	Destructor
Schedule::~Schedule() {}

//	Checks if an itemID matches the itemID of an item in a given vector cell
bool Schedule::isMatchingItemID(unsigned int vectorIndex, unsigned int itemID) {
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
	if (itemStart.isAfter(endTime) || itemEnd.isBefore(startTime)) {
		return false;
	} else {
		return true;
	}
}

bool Schedule::hasKeyword(string name, string description, string keyword) {
	if (name.find(keyword) != string::npos) {
		return true;
	} else if (description.find(keyword) != string::npos) {
		return true;
	} else {
		return false;
	}
}

//	Retrieves schedule vector index given itemID
unsigned int Schedule::findVectorIndexGivenItemID(unsigned int itemID) {
	unsigned int vectorIndex = 0;

	while (vectorIndex <= _schedule.size() && !isMatchingItemID(vectorIndex, itemID)) {
		vectorIndex++;
	}

	return vectorIndex;
}

//	Retrieves item ID given display vector index
unsigned int Schedule::findItemIDGivenDisplayVectorIndex(unsigned int displayVectorIndex) {
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

	return _schedule.back().displayItemFullDetails();
}

//	Retrieves a copy of an existing item in the schedule give Item ID
Item Schedule::retrieveItemGivenItemID(unsigned int itemID) {
	unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);
	return _schedule[vectorIndex];
}

//	Retrieves a copy of an existing item in the schedule given the item's display vector index
Item Schedule::retrieveItemGivenDisplayVectorIndex(unsigned int displayVectorIndex) {
	unsigned int itemID = findItemIDGivenDisplayVectorIndex(displayVectorIndex);
	return retrieveItemGivenItemID(itemID);
}

//	Replaces an existing item in the schedule, returns full details of the item (string)
string Schedule::replaceItemGivenItemID(Item* replacementItem, unsigned int itemID) {
	unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);

	_scheduleHistory.addCommand(COMMAND_REPLACE, _schedule[vectorIndex]);
	_schedule[vectorIndex] = *replacementItem;

	return _schedule[vectorIndex].displayItemFullDetails();
}

//	Replaces an existing item in the schedule given the item's display vector index
string Schedule::replaceItemGivenDisplayVectorIndex(Item* replacementItem, unsigned int displayVectorIndex) {
	unsigned int itemID = findItemIDGivenDisplayVectorIndex(displayVectorIndex);
	return replaceItemGivenItemID(replacementItem, itemID);
}

//	Deletes an item from the schedule, returns full details of the item (string)
string Schedule::deleteItemGivenItemID(unsigned int itemID) {
	unsigned int index = findVectorIndexGivenItemID(itemID);
	Item itemToBeDeleted = _schedule[index];

	_scheduleHistory.addCommand(COMMAND_DELETE, itemToBeDeleted);
	_schedule.erase(_schedule.begin() + index);

	return itemToBeDeleted.displayItemFullDetails();
}

//	Deletes an item from the schedule given item's display vector index
string Schedule::deleteItemGivenDisplayVectorIndex(unsigned int displayVectorIndex) {
	unsigned int itemID = findItemIDGivenDisplayVectorIndex(displayVectorIndex);
	return deleteItemGivenItemID(itemID);
}

//	Undoes the last command that modified the schedule (add, replace, delete)
string Schedule::undoLastCommand() {
	Item latestItem;
	string command;
	string confirmation = _scheduleHistory.undoLastCommand(command, latestItem);

	if (confirmation == ERROR_EMPTYSTACKS) {
		return confirmation;
	} else if (command == COMMAND_ADD) {
		confirmation = undoAdd(latestItem);
	} else if (command == COMMAND_DELETE) {
		confirmation = undoDelete(latestItem);
	} else if (command == COMMAND_REPLACE) {
		confirmation = undoReplace(latestItem);
	}

	return confirmation;
}

//	Undoes the last command that modified the schedule (add)
string Schedule::undoAdd(Item latestItem) {
	string confirmation = deleteItemGivenItemID(latestItem.getItemID());
	_scheduleHistory.removeUndoneCommand();

	return (COMMAND_ADD + confirmation);
}

//	Undoes the last command that modified the schedule (replace)
string Schedule::undoReplace(Item latestItem) {
	string confirmation = replaceItemGivenItemID(&latestItem, latestItem.getItemID());
	_scheduleHistory.removeUndoneCommand();

	return (COMMAND_REPLACE + confirmation);
}

//	Undoes the last command that modified the schedule (delete)
string Schedule::undoDelete(Item latestItem) {
	string confirmation = addItem(&latestItem);
	_scheduleHistory.removeUndoneCommand();

	return (COMMAND_DELETE + confirmation);
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

bool Schedule::isUpdatedLaterThan(Item leftItem, Item rightItem) {
	string leftDateTime = leftItem.displayLastUpdatedTime();
	string rightDateTime = rightItem.displayLastUpdatedTime();

	return (leftDateTime > rightDateTime);
}

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

bool Schedule::filterDisplayScheduleByDateTime(int index, DateTime startTime, DateTime endTime) {
	if (!isRelevantDateTime(_displaySchedule[index].getStartTime(), _displaySchedule[index].getEndTime(), startTime, endTime)) {
		_displaySchedule.erase(_displaySchedule.begin() + index);
		return true;
	} else {
		return false;
	}
}