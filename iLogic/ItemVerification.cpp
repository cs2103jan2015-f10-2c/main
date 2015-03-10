#include "ItemVerification.h"

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
	if (itemID <= _maxID) {
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

ItemVerification::ItemVerification(Item itemObject, unsigned int currentMaxID) {
	_itemObjectToVerify = itemObject;
	_maxID = currentMaxID;
}

bool ItemVerification::isValidItem() {
	if (isValidName() && isValidStartDateTime() && isValidDescription() &&
		isValidItemID() && isValidPriority() && isValidLabel())  {
		return 1;
	} else {
		return 0;
	}
}