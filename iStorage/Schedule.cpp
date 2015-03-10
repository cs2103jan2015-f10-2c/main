//	Schedule
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#include "Schedule.h"

Schedule::Schedule() {}

Schedule::~Schedule() {}

//	Retrieves the entire schedule
const vector<Item>& Schedule::retrieveSchedule() {
	return _schedule;
}

//	Adds the item to the schedule, returns the itemID
unsigned int Schedule::addItem(Item item) {
	_schedule.push_back(item);
	return item.getItemID();
}
/*
//	Deletes an item from the schedule, returns deleted item
Item Schedule::deleteItem(unsigned int itemID) {
	//	find the item based on itemID
	//	obtain the vector index of the item
	//	make a copy of the item
	//	delete the item, via the vector index
	//	return the item that was deleted
	return _schedule[0];
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

unsigned int Schedule::getSizeOfSchedule() {
	unsigned int sizeOfSchedule;
	sizeOfSchedule = _schedule.size();
	return sizeOfSchedule;
}
