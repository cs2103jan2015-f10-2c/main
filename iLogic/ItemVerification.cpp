#include "ItemVerification.h"

const string EMPTY_STRING = "";
const string AVAILABLE_PRIORITIES = "HML";
const string AVAILABLE_LABELS = "PMO";
const string ERROR_EMPTY_STRING = "Error: Empty String Specified.\n";
const string ERROR_INVALID_START_DATE = "Error: Invalid Start Date.\n";
const string ERROR_INVALID_START_TIME = "Error: Invalid Start Time.\n";
const string ERROR_INVALID_END_DATE = "Error: Invalid End Date.\n";
const string ERROR_INVALID_END_TIME = "Error: Invalid End Time.\n";
const string ERROR_INVALID_ID = "Error: An item has an invalid ID.\n";
const string ERROR_INVALID_PRIORITY = "Error: An item has an invalid Priority.\n";
const string ERROR_INVALID_LABEL = "Error: An item has an invalid Label.\n";

bool ItemVerification::isValidName() {
	string name = _itemObjectToVerify.getItemName();
	if (name == EMPTY_STRING) {
		cout << ERROR_EMPTY_STRING;
		return 0;
	} else {
		return 1;
	}
}

bool ItemVerification::isValidStartDateTime() {
	DateTime startDateTime = _itemObjectToVerify.getStartTime();
	DateTimeVerification startDateTimeVerification(startDateTime);
	if (startDateTimeVerification.isValidDate() && startDateTimeVerification.isValidTime()) {
		return 1;
	} else {
		if (!startDateTimeVerification.isValidDate()) {
			cout << ERROR_INVALID_START_DATE;
		}
		if (!startDateTimeVerification.isValidTime()) {
			cout << ERROR_INVALID_START_TIME;
		}
		return 0;
	}
}

bool ItemVerification::isValidEndDateTime() {
	DateTime endDateTime = _itemObjectToVerify.getStartTime();
	DateTimeVerification endDateTimeVerification(endDateTime);
	if (endDateTimeVerification.isValidDate() && endDateTimeVerification.isValidTime()) {
		return 1;
	} else {
		if (!endDateTimeVerification.isValidDate()) {
			cout << ERROR_INVALID_END_DATE;
		}
		if (!endDateTimeVerification.isValidTime()) {
			cout << ERROR_INVALID_END_TIME;
		}
		return 0;
	}
}

bool ItemVerification::isValidDescription() {
	return 1;
}

bool ItemVerification::isValidItemID() {
	unsigned int itemID = _itemObjectToVerify.getItemID();
	if (itemID < _nextID) {
		return 1;
	} else {
		cout << ERROR_INVALID_ID;
		return 0;
	}
}

bool ItemVerification::isValidPriority() {
	string priorityString;
	char priorityChar = _itemObjectToVerify.getPriority();
	unsigned int priorityFound;
	priorityString.push_back(priorityChar);
	priorityFound = priorityString.find_first_of(AVAILABLE_PRIORITIES);
	if (priorityFound != string::npos || priorityChar == '\0') {
		return 1;
	} else {
		cout << ERROR_INVALID_PRIORITY;
		return 0;
	}
}

bool ItemVerification::isValidLabel() {
	string labelString;
	char labelChar = _itemObjectToVerify.getLabel();
	unsigned int labelFound;
	labelString.push_back(labelChar);
	labelFound = labelString.find_first_of(AVAILABLE_LABELS);
	if (labelFound != string::npos || labelChar =='\0') {
		return 1;
	}
	else {
		cout << ERROR_INVALID_LABEL;
		return 0;
	}
}

ItemVerification::ItemVerification(Item itemObject, unsigned int nextItemID) {
	_itemObjectToVerify = itemObject;
	_nextID = nextItemID;
}

bool ItemVerification::isValidItem() {
	if (isValidName() && isValidStartDateTime() && isValidDescription() &&
		isValidItemID() && isValidPriority() && isValidLabel())  {
		return 1;
	} else {
		return 0;
	}
}