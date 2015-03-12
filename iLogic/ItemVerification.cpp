#include "ItemVerification.h"

const string ItemVerification::EMPTY_STRING = "";
const string ItemVerification::AVAILABLE_PRIORITIES = "HML";
const string ItemVerification::AVAILABLE_LABELS = "PMO";
const string ItemVerification::ERROR_EMPTY_STRING = "Error: Empty String Specified.\n";
const string ItemVerification::ERROR_INVALID_START_DATE = "Error: Invalid Start Date.\n";
const string ItemVerification::ERROR_INVALID_START_TIME = "Error: Invalid Start Time.\n";
const string ItemVerification::ERROR_INVALID_END_DATE = "Error: Invalid End Date.\n";
const string ItemVerification::ERROR_INVALID_END_TIME = "Error: Invalid End Time.\n";
const string ItemVerification::ERROR_INVALID_ID = "Error: An item has an invalid ID.\n";
const string ItemVerification::ERROR_INVALID_PRIORITY = "Error: An item has an invalid Priority.\n";
const string ItemVerification::ERROR_INVALID_LABEL = "Error: An item has an invalid Label.\n";

ItemVerification::ItemVerification(Item itemObject, unsigned int nextItemID) {
	_itemObjectToVerify = itemObject;
	_nextID = nextItemID;
}

bool ItemVerification::isValidName() {
	string name = _itemObjectToVerify.getItemName();
	if (name == EMPTY_STRING) {
		cout << ERROR_EMPTY_STRING;
		return false;
	} else {
		return true;
	}
}

bool ItemVerification::isValidStartDateTime() {
	DateTime startDateTime = _itemObjectToVerify.getStartTime();
	DateTimeVerification startDateTimeVerification(startDateTime);
	if (startDateTimeVerification.isValidDate() && startDateTimeVerification.isValidTime()) {
		return true;
	} else {
		if (!startDateTimeVerification.isValidDate()) {
			cout << ERROR_INVALID_START_DATE;
		}
		if (!startDateTimeVerification.isValidTime()) {
			cout << ERROR_INVALID_START_TIME;
		}
		return false;
	}
}

bool ItemVerification::isValidEndDateTime() {
	DateTime endDateTime = _itemObjectToVerify.getStartTime();
	DateTimeVerification endDateTimeVerification(endDateTime);
	if (endDateTimeVerification.isValidDate() && endDateTimeVerification.isValidTime()) {
		return true;
	} else {
		if (!endDateTimeVerification.isValidDate()) {
			cout << ERROR_INVALID_END_DATE;
		}
		if (!endDateTimeVerification.isValidTime()) {
			cout << ERROR_INVALID_END_TIME;
		}
		return false;
	}
}

bool ItemVerification::isValidDescription() {
	return true;
}

bool ItemVerification::isValidItemID() {
	unsigned int itemID = _itemObjectToVerify.getItemID();
	if (itemID < _nextID) {
		return true;
	} else {
		cout << ERROR_INVALID_ID;
		return false;
	}
}

bool ItemVerification::isValidPriority() {
	string priorityString;
	char priorityChar = _itemObjectToVerify.getPriority();
	unsigned int priorityFound;
	priorityString.push_back(priorityChar);
	priorityFound = priorityString.find_first_of(AVAILABLE_PRIORITIES);
	if (priorityFound != string::npos || priorityChar == '\0') {
		return true;
	} else {
		cout << ERROR_INVALID_PRIORITY;
		return false;
	}
}

bool ItemVerification::isValidLabel() {
	string labelString;
	char labelChar = _itemObjectToVerify.getLabel();
	unsigned int labelFound;
	labelString.push_back(labelChar);
	labelFound = labelString.find_first_of(AVAILABLE_LABELS);
	if (labelFound != string::npos || labelChar =='\0') {
		return true;
	}
	else {
		cout << ERROR_INVALID_LABEL;
		return false;
	}
}

bool ItemVerification::isValidItem() {
	if (isValidName() && isValidStartDateTime() && isValidDescription() &&
		/*isValidItemID() &&*/ isValidPriority() && isValidLabel())  {
		return true;
	} else {
		return false;
	}
}