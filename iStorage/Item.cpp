//	Item (Tasks, Deadlines, Events)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#include <iostream>
#include "Item.h"
#include "assert.h"

const string Item::EMPTYFIELD_ITEMNAME = "";
const string Item::EMPTYFIELD_DESCRIPTION = "";
const string Item::EMPTYFIELD_TIME = "";
const string Item::ALLOWABLEOPTIONS_PRIORITY = "LMH";
const string Item::ALLOWABLEOPTIONS_LABEL = "POM";
const unsigned int Item::EMPTYFIELD_ITEMID = 0;
const char Item::EMPTYFIELD_PRIORITY = 'E';
const char Item::EMPTYFIELD_LABEL = 'E';

//	Checks if item has a valid item name
bool Item::hasValidItemName(){
	if (_itemName != EMPTYFIELD_ITEMNAME) {
		return true;
	}

	assert(_itemName == EMPTYFIELD_ITEMNAME);
	return false;
}

//	Checks if item has a valid start time
bool Item::hasValidItemStartTime(){
	if (_startTime.displayDateTime() != EMPTYFIELD_TIME){
		return true;
	}

	assert(_startTime.displayDateTime() == EMPTYFIELD_TIME);
	return false;
}

//	Checks if item has a valid end time
bool Item::hasValidItemEndTime(){
	if (_endTime.displayDateTime() != EMPTYFIELD_TIME){
		return true;
	}

	assert(_endTime.displayDateTime() == EMPTYFIELD_TIME);
	return false;
}

//	Checks if item has a valid description
bool Item::hasValidItemDescription(){
	if (_description != EMPTYFIELD_DESCRIPTION) {
		return true;
	}

	assert(_description == EMPTYFIELD_DESCRIPTION);
	return false;
}

//	Checks if item has a valid item ID
bool Item::hasValidItemID(){
	if (_itemID > EMPTYFIELD_ITEMID) {
		return true;
	}

	assert(_itemID <= EMPTYFIELD_ITEMID);
	return false;
}

//	Checks if item has a valid priority
bool Item::hasValidItemPriority(){
	if (ALLOWABLEOPTIONS_PRIORITY.find_first_of(_priority) != string::npos) {
		return true;
	}

	assert(_priority != 'L' && _priority != 'M' &&_priority != 'H');
	return false;
}

//	Checks if item has a valid label
bool Item::hasValidItemLabel(){
	if (ALLOWABLEOPTIONS_LABEL.find_first_of(_label) != string::npos) {
		return true;
	}

	assert(_priority != 'P' && _priority != 'O' &&_priority != 'M');
	return false;
}

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

//	Retrieves the key item details for user display (string)
string Item::displayItemForUser() {
	ostringstream displayOutput;

	if (hasValidItemName()) {
		displayOutput << "Name:\t" << _itemName << endl;
	}

	try{
		if (hasValidItemStartTime()) {
			displayOutput << "Start Time:\t" << _startTime.displayDateTime() << endl;
		}

		if (displayOutput.str()[displayOutput.str().length() - 3] == '-') {
			throw "Printing of of field in Start Time that does not exist!";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}

	try {
		if (hasValidItemEndTime()) {
			displayOutput << "End Time:\t" << _endTime.displayDateTime() << endl;
		}

		if (displayOutput.str()[displayOutput.str().length() - 3] == '-') {
			throw "Printing of of field in End Time that does not exist!";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}


	if (hasValidItemDescription()) {
		displayOutput << "Description:\t" << _description << endl;
	}

	return displayOutput.str();
}

//	Retrieves the full item details (string)
string Item::displayItemFullDetails() {
	ostringstream displayOutput;

	if (hasValidItemID()){
		displayOutput << "Item ID:\t" << _itemID << endl;
	}

	displayOutput << displayItemForUser();

	if (hasValidItemPriority()) {
		displayOutput << "Priority:\t" << _priority << endl;
	}

	if (hasValidItemLabel()) {
		displayOutput << "Label:\t" << _label << endl;
	}

	displayOutput << "Completed?\t" << boolalpha << _isCompleted << endl;

	return displayOutput.str();
}

//	Retrieves the item start time (string)
string Item::displayStartTime() {
	return _startTime.displayDateTime();
}

//	Retrieves the item end time (string)
string Item::displayEndTime() {
	return _endTime.displayDateTime();
}