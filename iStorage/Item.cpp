//	Item (Tasks, Deadlines, Events)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "Item.h"

const string Item::EMPTYFIELD_ITEMNAME = "";
const string Item::EMPTYFIELD_DESCRIPTION = "";
const int Item::EMPTYFIELD_ITEMID = 0;
const char Item::EMPTYFIELD_PRIORITY = 'E';
const char Item::EMPTYFIELD_LABEL = 'E';

//	Constructor
Item::Item() {
	_itemName = EMPTYFIELD_ITEMNAME;
	_description = EMPTYFIELD_DESCRIPTION;
	_itemID = EMPTYFIELD_ITEMID;
	_priority = EMPTYFIELD_PRIORITY;
	_label = EMPTYFIELD_LABEL;
	_isCompleted = false;
}

//	Overloaded Constructor with itemName
Item::Item(string itemName){
	_itemName = itemName;
	_description = EMPTYFIELD_DESCRIPTION;
	_itemID = EMPTYFIELD_ITEMID;
	_priority = EMPTYFIELD_PRIORITY;
	_label = EMPTYFIELD_LABEL;
	_isCompleted = false;
}

//	Overloaded Constructor with itemID
Item::Item(unsigned int itemID){
	_itemID = itemID;
	_itemName = EMPTYFIELD_ITEMNAME;
	_description = EMPTYFIELD_DESCRIPTION;
	_priority = EMPTYFIELD_PRIORITY;
	_label = EMPTYFIELD_LABEL;
	_isCompleted = false;
}

//	Overloaded Constructor with itemName and itemID
Item::Item(string itemName, unsigned int itemID){
	_itemID = itemID;
	_itemName = itemName;
	_description = EMPTYFIELD_DESCRIPTION;
	_priority = EMPTYFIELD_PRIORITY;
	_label = EMPTYFIELD_LABEL;
	_isCompleted = false;
}

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

string Item::displayItem() {
	ostringstream output;
	
	output	<< "ItemName: "		<< _itemName << endl
			<< "StartTime: "	<< _startTime.displayDateTime() << endl
			<< "EndTime: "		<< _endTime.displayDateTime() << endl
			<< "Description: "	<< _description << endl;

	return output.str();
}