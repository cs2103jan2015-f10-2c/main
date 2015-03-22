#include "ItemVerification.h"

const string ItemVerification::EMPTY_STRING = "";
const string ItemVerification::AVAILABLE_PRIORITIES = "HMLE";  // High, Medium, Low, *Empty*
const string ItemVerification::AVAILABLE_LABELS = "PMOE";  // Personal, Milestone, Official, *Empty*
const string ItemVerification::ERROR_INVALID_NAME = "Error: Invalid Name";
const string ItemVerification::ERROR_INVALID_DESCRIPTION = "Error: Invalid Description";
const string ItemVerification::ERROR_INVALID_START_DATE_TIME = "Error: Invalid Start Date/Time";
const string ItemVerification::ERROR_INVALID_END_DATE_TIME = "Error: Invalid End Date/TIME";
const string ItemVerification::ERROR_SAME_START_END_DATE_TIME = "Error: Start Date/Time same as End Date/Time";
const string ItemVerification::ERROR_START_DATE_TIME_EARLIER_THAN_END_DATE_TIME = "Error: Start Date/Time is earlier than End Date/Time";
const string ItemVerification::ERROR_INVALID_ID = "Error: Invalid ID";
const string ItemVerification::ERROR_INVALID_PRIORITY = "Error: Invalid Priority";
const string ItemVerification::ERROR_INVALID_LABEL = "Error: Invalid Label";

ItemVerification::ItemVerification(Item itemObject, unsigned int nextItemID) {
	_itemObjectToVerify = itemObject;
	_nextID = nextItemID;
}

bool ItemVerification::isValidName() {
	string name = _itemObjectToVerify.getItemName();
	if (name == EMPTY_STRING) {
		_itemVerificationErrors.push_back(ERROR_INVALID_NAME);
		return false;
	} else {
		return true;
	}
}

bool ItemVerification::isValidDescription() {
	return true;
}

bool ItemVerification::isValidStartDateTime() {
	DateTime startDateTime = _itemObjectToVerify.getStartTime();
	DateTimeVerification startDateTimeVerification(startDateTime);
	if (startDateTimeVerification.isValidDateTime()) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ERROR_INVALID_START_DATE_TIME);
		return false;
	}
}

bool ItemVerification::isValidEndDateTime() {
	DateTime endDateTime = _itemObjectToVerify.getEndTime();
	DateTimeVerification endDateTimeVerification(endDateTime);
	if (endDateTimeVerification.isValidDateTime()) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ERROR_INVALID_END_DATE_TIME);
		return false;
	}
}

bool ItemVerification::isValidTimeFrame() {
	DateTime startDateTime = _itemObjectToVerify.getStartTime();
	DateTime endDateTime = _itemObjectToVerify.getEndTime();
	DateTimeVerification startDateTimeVerification(startDateTime);
	DateTimeVerification endDateTimeVerification(endDateTime);
	if (startDateTimeVerification.isValidDateTime() && endDateTimeVerification.isValidDateTime()) {
		if (startDateTimeVerification.hasHourMinute() && endDateTimeVerification.hasHourMinute()) {
			if (startDateTime == endDateTime) {
				_itemVerificationErrors.push_back(ERROR_SAME_START_END_DATE_TIME);
				return false;
			} else if (startDateTime.isAfter(endDateTime)) {
				_itemVerificationErrors.push_back(ERROR_START_DATE_TIME_EARLIER_THAN_END_DATE_TIME);
				return false;
			} else {
				return true;
			}
		} else {
			if (endDateTime.getYear() > startDateTime.getYear()) {
				return true;
			} else if (endDateTime.getYear() == startDateTime.getYear() && endDateTime.getMonth() > startDateTime.getMonth()) {
				return true;
			} else if (endDateTime.getYear() == startDateTime.getYear() && endDateTime.getMonth() == startDateTime.getMonth() && endDateTime.getDay() > startDateTime.getDay()) {
				return true;
			} else {
				_itemVerificationErrors.push_back(ERROR_START_DATE_TIME_EARLIER_THAN_END_DATE_TIME);
				return false;
			}
		}
	} else {
		return false;
	}
}

bool ItemVerification::isValidID() {
	unsigned int itemID = _itemObjectToVerify.getItemID();
	if (itemID <= _nextID) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ERROR_INVALID_ID);
		return false;
	}
}

bool ItemVerification::isValidPriority() {
	string priorityString;
	char priorityChar = _itemObjectToVerify.getPriority();
	unsigned int priorityFound;
	priorityString.push_back(priorityChar);
	priorityFound = priorityString.find_first_of(AVAILABLE_PRIORITIES);
	if (priorityFound != string::npos) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ERROR_INVALID_PRIORITY);
		return false;
	}
}

bool ItemVerification::isValidLabel() {
	string labelString;
	char labelChar = _itemObjectToVerify.getLabel();
	unsigned int labelFound;
	labelString.push_back(labelChar);
	labelFound = labelString.find_first_of(AVAILABLE_LABELS);
	if (labelFound != string::npos) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ERROR_INVALID_LABEL);
		return false;
	}
}

bool ItemVerification::isValidItem() {
	bool hasValidName = isValidName();
	bool hasValidDescription = isValidDescription();
	bool hasValidStartDateTime = isValidStartDateTime();
	bool hasValidEndDateTime = isValidEndDateTime();
	bool hasValidTimeFrame = isValidTimeFrame();
	bool hasValidID = isValidID();
	bool hasValidPriority = isValidPriority();
	bool hasValidLabel = isValidLabel();

	if (hasValidName &&
		hasValidDescription &&
		hasValidStartDateTime &&
		hasValidEndDateTime &&
		hasValidTimeFrame &&
		hasValidID &&
		hasValidPriority &&
		hasValidLabel) {
		return true;
	} else {
		return false;
	}
}