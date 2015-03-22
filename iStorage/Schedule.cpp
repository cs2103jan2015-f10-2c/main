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

unsigned int Schedule::findItemIDGivenDisplayVectorIndex(unsigned int vectorIndex){
	unsigned int itemID = 0;
	return _displaySchedule[vectorIndex].getItemID();
}

//	Retrieves the size of the schedule
unsigned int Schedule::getSizeOfSchedule() {
	return _schedule.size();
}

//	Adds the item to the schedule, returns full details of the item (string)
string Schedule::addItem(Item* item) {
	_schedule.push_back(*item);
	return _schedule.back().displayItemFullDetails();
}

//	Retrieves a copy of the item
Item Schedule::retrieveItemGivenItemID(unsigned int itemID){
	unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);
	return _schedule[vectorIndex];
}

//	Replaces an existing item in the schedule, returns full details of the item (string)
string Schedule::replaceItemGivenItemID(Item* replacementItem, unsigned int itemID) {
	unsigned int vectorIndex = findVectorIndexGivenItemID(itemID);
//	Item previousItem = _schedule[vectorIndex];

	_schedule[vectorIndex] = *replacementItem;
	return _schedule[vectorIndex].displayItemFullDetails();
}

//	Deletes an item from the schedule, returns full details of the item (string)
string Schedule::deleteItemGivenItemID(unsigned int itemID) {
	unsigned int index = findVectorIndexGivenItemID(itemID);
	Item itemToBeDeleted = _schedule[index];
	
	_schedule.erase(_schedule.begin() + index);
	return itemToBeDeleted.displayItemFullDetails();
}

//	Retrieves the entire schedule
const vector<Item>& Schedule::retrieveSchedule() {
	return _schedule;
}

//const vector<Item>& Schedule::retrieveDisplayScheduleByDate() {
//
//}

/*
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












vector <Item>& Schedule::sortScheduleByDate() {
	sort(_schedule.begin(), _schedule.end()/*, compare item dates*//*);
	return _schedule;
}

vector <Item>& Schedule::sortScheduleByLastUpdate() {
	sort(_schedule.begin(), _schedule.end()/*, compare item update datetime*//*);
	return _schedule;
}

*/
