//	Schedule
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "Schedule.h"

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

//	Retrieves schedule vector index given itemID
unsigned int Schedule::findVectorIndexGivenItemID(unsigned int itemID) {
	unsigned int vectorIndex = 0;

	while (vectorIndex <= _schedule.size() && !isMatchingItemID(vectorIndex, itemID)) {
		vectorIndex++;
	}

	return vectorIndex;
}

//	Retrieves item ID given display vector index
unsigned int Schedule::findItemIDGivenDisplayVectorIndex(unsigned int displayVectorIndex){
	return _displaySchedule[displayVectorIndex-1].getItemID();
}

//	Retrieves the size of the schedule
unsigned int Schedule::getSizeOfSchedule() {
	return _schedule.size();
}

//	Retrieves the size of the display schedule
unsigned int Schedule::getSizeOfDisplaySchedule(){
	return _displaySchedule.size();
}

//	Resets the display schedule to the schedule
unsigned int Schedule::resetDisplaySchedule() {
	_displaySchedule = _schedule;
	return getSizeOfDisplaySchedule();
}

//	Adds the item to the schedule, returns full details of the item (string)
string Schedule::addItem(Item* item) {
	_schedule.push_back(*item);
	return _schedule.back().displayItemFullDetails();
}

//	Retrieves a copy of an existing item in the schedule give Item ID
Item Schedule::retrieveItemGivenItemID(unsigned int itemID){
	unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);
	return _schedule[vectorIndex];
}

//	Retrieves a copy of an existing item in the schedule given the item's display vector index
Item Schedule::retrieveItemGivenDisplayVectorIndex(unsigned int displayVectorIndex){
	unsigned int itemID = findItemIDGivenDisplayVectorIndex(displayVectorIndex);
	return retrieveItemGivenItemID(itemID);
}

//	Replaces an existing item in the schedule, returns full details of the item (string)
string Schedule::replaceItemGivenItemID(Item* replacementItem, unsigned int itemID) {
	unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);
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

	_schedule.erase(_schedule.begin() + index);
	return itemToBeDeleted.displayItemFullDetails();
}

//	Deletes an item from the schedule given item's display vector index
string Schedule::deleteItemGivenDisplayVectorIndex(unsigned int displayVectorIndex) {
	unsigned int itemID = findItemIDGivenDisplayVectorIndex(displayVectorIndex);
	return deleteItemGivenItemID(itemID);
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
bool Schedule::isEarlierThan(Item leftItem, Item rightItem){
	string leftDateTime = "";
	string rightDateTime = "";

	if (leftItem.displayStartTime() != "") {
		leftDateTime = leftItem.displayStartTime();
	}
	else if (leftItem.displayEndTime() != "") {
		leftDateTime = leftItem.displayEndTime();
	}

	if (rightItem.displayStartTime() != "") {
		rightDateTime = rightItem.displayStartTime();
	}
	else if (rightItem.displayEndTime() != "") {
		rightDateTime = rightItem.displayEndTime();
	}

	return (leftDateTime < rightDateTime);
}

//	Sorts the display schedule by date, returns constant reference to sorted display schedule
const vector<Item>& Schedule::retrieveDisplayScheduleByDate() {
	sort(_displaySchedule.begin(), _displaySchedule.end(), isEarlierThan);
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
	sort(_displaySchedule.begin(), _displaySchedule.end(), isAlphabeticallySmallerThan);
	return retrieveDisplaySchedule();
}

//	Checks if an item is of lower priority than another
bool Schedule::isLowerPriorityThan(Item leftItem, Item rightItem) {
	char leftItemPriority = leftItem.getPriority();
	char rightItemPriority = rightItem.getPriority();

	if (leftItemPriority = 'H') {
		leftItemPriority = '1';
	}
	else if (leftItemPriority = 'M') {
		leftItemPriority = '2';
	}
	else if (leftItemPriority = 'L') {
		leftItemPriority = '3';
	}
	else {
		leftItemPriority = '4';
	}

	if (rightItemPriority = 'H') {
		rightItemPriority = '1';
	}
	else if (rightItemPriority = 'M') {
		rightItemPriority = '2';
	}
	else if (rightItemPriority = 'L') {
		rightItemPriority = '3';
	}
	else {
		rightItemPriority = '4';
	}

	return (leftItemPriority < rightItemPriority);
}

//	Sorts the display schedule by priority, returns constant reference to sorted display schedule
const vector<Item>& Schedule::retrieveDisplayScheduleByPriority() {
	sort(_displaySchedule.begin(), _displaySchedule.end(), isLowerPriorityThan);
	return retrieveDisplaySchedule();
}

//	Checks if an item is less completed than another (completed vs incomplete)
bool Schedule::isLessCompleteThan(Item leftItem, Item rightItem) {
	return (leftItem.getCompletion() < rightItem.getCompletion());
}

//	Sorts the display schedule by completion status (completed first), returns constant reference to sorted display schedule
const vector<Item>& Schedule::retrieveDisplayScheduleByCompletionStatus() {
	sort(_displaySchedule.begin(), _displaySchedule.end(), isLessCompleteThan);
	return retrieveDisplaySchedule();
}




/*
//	Sorts the display schedule by last update (latest first), returns constant reference to sorted display schedule
const vector<Item>& Schedule::retrieveDisplayScheduleByLastUpdate() {
return retrieveDisplaySchedule();
}


//	Filters the schedule by Priority
const vector<Item>& Schedule::retrieveScheduleFilteredByPriority(char priority){
_filteredSchedule.clear();

for (unsigned int index = 0; index < getSizeOfSchedule(); index++) {
if (priority = _schedule[index].getPriority()) {
_filteredSchedule.push_back(_schedule[index]);
}
}

return _filteredSchedule;
}

//	Filters the schedule by Label
const vector<Item>& Schedule::retrieveScheduleFilteredByLabel(char label){
_filteredSchedule.clear();

for (unsigned int index = 0; index < getSizeOfSchedule(); index++) {
if (label = _schedule[index].getLabel()) {
_filteredSchedule.push_back(_schedule[index]);
}
}

return _filteredSchedule;
}

//	Filters the schedule by Completion
const vector<Item>& Schedule::retrieveScheduleFilteredByCompletion(bool isCompleted){
_filteredSchedule.clear();

for (unsigned int index = 0; index < getSizeOfSchedule(); index++) {
if (isCompleted = _schedule[index].getCompletion()) {
_filteredSchedule.push_back(_schedule[index]);
}
}

return _filteredSchedule;
}
*/