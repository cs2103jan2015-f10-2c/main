//	Item (Tasks, Deadlines, Events)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include "Item.h"

const string Item::EMPTYFIELD_ITEMNAME = "";
const string Item::EMPTYFIELD_DESCRIPTION = "";
const int Item::EMPTYFIELD_ITEMID = 0;
const char Item::EMPTYFIELD_PRIORITY = 'E';
const char Item::EMPTYFIELD_LABEL = 'E';

//	Default Constructor
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

//	Sets the item name
string Item::setItemName(string itemName) {
	_itemName = itemName;
	return _itemName;
}

//	Sets the item description
string Item::setDescription(string description) {
	_description = description;
	return _description;
}

//	Sets the item start time, given DateTime object
DateTime Item::setStartTime(DateTime startTime) {
	_startTime = startTime;
	return _startTime;
}

//	Sets the item start time, given year, month, day
DateTime Item::setStartTime(int year, int month, int day) {
	DateTime dateTime(year, month, day);
	_startTime = dateTime;
	return _startTime;
}

//	Sets the item start time, given year, month, day, hour, minute
DateTime Item::setStartTime(int year, int month, int day, int hour, int minute) {
	DateTime dateTime(year, month, day, hour, minute);
	_startTime = dateTime;
	return _startTime;
}

//	Sets the item end time, given DateTime object
DateTime Item::setEndTime(DateTime endTime) {
	_endTime = endTime;
	return _endTime;
}

//	Sets the item end time, given year, month, day
DateTime Item::setEndTime(int year, int month, int day) {
	DateTime dateTime(year, month, day);
	_endTime = dateTime;
	return _endTime;
}

//	Sets the item end time, given year, month, day, hour, minute
DateTime Item::setEndTime(int year, int month, int day, int hour, int minute) {
	DateTime dateTime(year, month, day, hour, minute);
	_endTime = dateTime;
	return _endTime;
}

//	Sets the item ID
unsigned int Item::setItemID(unsigned int itemID) {
	_itemID = itemID;
	return _itemID;
}

//	Sets the item priority (H, M, L)
char Item::setPriority(char priority) {
	_priority = priority;
	return _priority;
}

//	Sets the item label (P, O, M)
char Item::setLabel(char label) {
	_label = label;
	return _label;
}

//	Sets the item completion status
bool Item::setCompletion(bool isCompleted) {
	_isCompleted = isCompleted;
	return _isCompleted;
}

//	Retrieves the item name
string Item::getItemName() {
	return _itemName;
}

//	Retrieves the item description
string Item::getDescription()  {
	return _description;
}

//	Retrieves the item start time (DateTime object)
DateTime Item::getStartTime(){
	return _startTime;
}

//	Retrieves the item end time (DateTime object)
DateTime Item::getEndTime() {
	return _endTime;
}

//	Retrieves the item ID
unsigned int Item::getItemID() {
	return _itemID;
}

//	Retrieves the item priority
char Item::getPriority() {
	return _priority;
}

//	Retrieves the item label
char Item::getLabel() {
	return _label;
}

//	Retrieves the item completion status
bool Item::getCompletion() {
	return _isCompleted;
}

//	Retrieves the item full details (string)
string Item::displayItem() {
	ostringstream output;
	
	output	<< "ItemName: "		<< _itemName << endl
			<< "StartTime: "	<< _startTime.displayDateTime() << endl
			<< "EndTime: "		<< _endTime.displayDateTime() << endl
			<< "Description: "	<< _description << endl;

	return output.str();
}

//	Retrieves the item start time (string)
string Item::displayStartTime() {
	return _startTime.displayDateTime();
}

//	Retrieves the item end time (string)
string Item::displayEndTime() {
	return _endTime.displayDateTime();
}