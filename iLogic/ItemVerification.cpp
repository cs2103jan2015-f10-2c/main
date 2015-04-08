#include "ItemVerification.h"

const string ItemVerification::ITEM_VERIFICATION_EMPTY_STRING = "";
const string ItemVerification::ITEM_VERIFICATION_AVAILABLE_PRIORITIES = "HMLE";  // High, Medium, Low, *Empty*
const string ItemVerification::ITEM_VERIFICATION_AVAILABLE_LABELS = "PMOE";  // Personal, Milestone, Official, *Empty*
const string ItemVerification::ITEM_VERIFICATION_ERROR_INVALID_NAME = "Invalid Name";
const string ItemVerification::ITEM_VERIFICATION_ERROR_INVALID_DESCRIPTION = "Invalid Description";
const string ItemVerification::ITEM_VERIFICATION_ERROR_INVALID_START_DATE_TIME = "Invalid Start Date/Time";
const string ItemVerification::ITEM_VERIFICATION_ERROR_INVALID_END_DATE_TIME = "Invalid End Date/TIME";
const string ItemVerification::ITEM_VERIFICATION_ERROR_SAME_START_END_DATE_TIME = "Start Date/Time same as End Date/Time";
const string ItemVerification::ITEM_VERIFICATION_ERROR_START_DATE_TIME_LATER_THAN_END_DATE_TIME = "Start Date/Time is later than End Date/Time";
const string ItemVerification::ITEM_VERIFICATION_ERROR_INVALID_ID = "Invalid ID";
const string ItemVerification::ITEM_VERIFICATION_ERROR_INVALID_PRIORITY = "Invalid Priority";
const string ItemVerification::ITEM_VERIFICATION_ERROR_INVALID_LABEL = "Invalid Label";

ItemVerification::ItemVerification(Item itemObject, unsigned int nextItemID) {
	_itemObjectToVerify = itemObject;
	_nextID = nextItemID;
}

bool ItemVerification::isValidName() {
	string name = _itemObjectToVerify.getItemName();
	if (name == ITEM_VERIFICATION_EMPTY_STRING) {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_NAME);
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
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_START_DATE_TIME);
		return false;
	}
}

bool ItemVerification::isValidEndDateTime() {
	DateTime endDateTime = _itemObjectToVerify.getEndTime();
	DateTimeVerification endDateTimeVerification(endDateTime);
	if (endDateTimeVerification.isValidDateTime()) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_END_DATE_TIME);
		return false;
	}
}

bool ItemVerification::isValidTimeFrame() {
	DateTime startDateTime = _itemObjectToVerify.getStartTime();
	DateTime endDateTime = _itemObjectToVerify.getEndTime();
	DateTime emptyDateTime;
	DateTimeVerification startDateTimeVerification(startDateTime);
	DateTimeVerification endDateTimeVerification(endDateTime);
	if (startDateTimeVerification.isValidDateTime() && endDateTimeVerification.isValidDateTime()) {
		if (startDateTimeVerification.hasHourMinute() && endDateTimeVerification.hasHourMinute()) {
			if (startDateTime == endDateTime) {
				_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_SAME_START_END_DATE_TIME);
				return false;
			} else if (startDateTime.isAfter(endDateTime)) {
				_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_START_DATE_TIME_LATER_THAN_END_DATE_TIME);
				return false;
			} else {
				return true;
			}
		} else {
			if (startDateTime == emptyDateTime || endDateTime == emptyDateTime) {
				return true;
			} else if (endDateTime.getYear() > startDateTime.getYear()) {
				return true;
			} else if (endDateTime.getYear() == startDateTime.getYear() && endDateTime.getMonth() > startDateTime.getMonth()) {
				return true;
			} else if (endDateTime.getYear() == startDateTime.getYear() && endDateTime.getMonth() == startDateTime.getMonth() && endDateTime.getDay() >= startDateTime.getDay()) {
				return true;
			} else {
				_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_START_DATE_TIME_LATER_THAN_END_DATE_TIME);
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
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_ID);
		return false;
	}
}

bool ItemVerification::isValidPriority() {
	string priorityString;
	char priorityChar = _itemObjectToVerify.getPriority();
	unsigned int priorityFound;
	priorityString.push_back(priorityChar);
	priorityFound = priorityString.find_first_of(ITEM_VERIFICATION_AVAILABLE_PRIORITIES);
	if (priorityFound != string::npos) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_PRIORITY);
		return false;
	}
}

bool ItemVerification::isValidLabel() {
	string labelString;
	char labelChar = _itemObjectToVerify.getLabel();
	unsigned int labelFound;
	labelString.push_back(labelChar);
	labelFound = labelString.find_first_of(ITEM_VERIFICATION_AVAILABLE_LABELS);
	if (labelFound != string::npos) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_LABEL);
		return false;
	}
}

bool ItemVerification::isValidItem() {

	_itemVerificationErrors.clear();

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

list<string> ItemVerification::getItemVerificationErrors() {
	return _itemVerificationErrors;
}