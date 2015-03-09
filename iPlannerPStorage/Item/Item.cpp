//	Item (Tasks, Deadlines, Events)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#include "Item.h"

//	Constructor
Item::Item() { }

//	Destructor
Item::~Item() { }

string Item::setItemName(string itemName) {
	_itemName = itemName;
	return _itemName;
}

string Item::setDescription(string description) {
	_description = description;
	return _description;
}

DateTime Item::setStartTime(DateTime startTime) {
	_startTime = startTime;
	return _startTime;
}

DateTime Item::setEndTime(DateTime endTime) {
	_endTime = endTime;
	return _endTime;
}

unsigned int Item::setItemID(unsigned int itemID) {
	_itemID = itemID;
	return _itemID;
}

char Item::setPriority(char priority) {
	_priority = priority;
	return _priority;
}

char Item::setLabel(char label) {
	_label = label;
	return _label;
}

bool Item::setCompletion(bool isCompleted) {
	_isCompleted = isCompleted;
	return _isCompleted;
}

string Item::getItemName() {
	return _itemName;
}

string Item::getDescription()  {
	return _description;
}

DateTime Item::getStartTime(){
	return _startTime;
}

DateTime Item::getEndTime() {
	return _endTime;
}

unsigned int Item::getItemID() {
	return _itemID;
}

char Item::getPriority() {
	return _priority;
}

char Item::getLabel() {
	return _label;
}

bool Item::getCompletion() {
	return _isCompleted;
}

