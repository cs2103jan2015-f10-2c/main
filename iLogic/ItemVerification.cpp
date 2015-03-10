#include "ItemVerification.h"

bool ItemVerification::isValidName() {
	string name = itemObjectToVerify.getItemName();
	if (name == EMPTY_STRING) {
		return 1;
	} else {
		cout << ERROR_EMPTY_STRING;
		return 0;
	}
}

bool ItemVerification::isValidStartDateTime() {
	DateTime startDateTime = itemObjectToVerify.getStartTime();
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
	DateTime endDateTime = itemObjectToVerify.getStartTime();
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
	string description = itemObjectToVerify.getDescription();
	if (description == EMPTY_STRING) {
		return 1;
	} else {
		cout << ERROR_EMPTY_STRING;
		return 0;
	}
}

bool ItemVerification::isValidItemID() {
	unsigned int itemID = itemObjectToVerify.getItemID();
	if (itemID <= maxID) {
		return 1;
	} else {
		cout << ERROR_INVALID_ID;
		return 0;
	}
}

bool ItemVerification::isValidPriority() {
	string priorityString;
	char priorityChar = itemObjectToVerify.getPriority();
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
	char labelChar = itemObjectToVerify.getPriority();
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
	itemObjectToVerify = itemObject;
	maxID = currentMaxID;
}

bool ItemVerification::isValidItem() {
	if (isValidName() && isValidStartDateTime() && isValidDescription() &&
		isValidDescription() && isValidItemID() && isValidPriority() && isValidLabel())  {
		return 1;
	} else {
		return 0;
	}
}