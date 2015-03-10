//	Schedule
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "Schedule.h"

Schedule::Schedule() {}

Schedule::~Schedule() {}

//	Retrieves the entire schedule
const vector<Item>& Schedule::retrieveSchedule() {
	return _schedule;
}

//	Retrieves the size of the schedule
unsigned int Schedule::getSizeOfSchedule() {
	return _schedule.size();
}

//	Retrieves vector index given itemID
unsigned int Schedule::findVectorIndexGivenItemID(unsigned int itemID) {
	for (unsigned int index = 0; index < getSizeOfSchedule(); index++) {
		if (itemID = _schedule[index].getItemID()) {
			return index;
		}
	}

	return -1;
}

//	Adds the item to the schedule, returns the itemID
unsigned int Schedule::addItem(Item item) {
	_schedule.push_back(item);
	return item.getItemID();
}

//	Deletes an item from the schedule, returns deleted item
Item Schedule::deleteItem(unsigned int itemID) {
	unsigned int index = findVectorIndexGivenItemID(itemID);
	Item itemToBeDeleted = _schedule[index];
	
	_schedule.erase(_schedule.begin() + index);
	return itemToBeDeleted;
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











/*
vector <Item>& Schedule::sortScheduleByDate() {
	sort(_schedule.begin(), _schedule.end()/*, compare item dates*//*);
	return _schedule;
}

vector <Item>& Schedule::sortScheduleByLastUpdate() {
	sort(_schedule.begin(), _schedule.end()/*, compare item update datetime*//*);
	return _schedule;
}

*/

