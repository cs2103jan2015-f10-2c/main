#include <exception>
#include <assert.h>
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
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_NAME_SUCCESS = "ITEM VERIFICATION:: Valid Name";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_NAME_FAILURE = "ITEM VERIFICATION:: Invalid Name";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_DESC_SUCCESS = "ITEM VERIFICATION:: Valid Description";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_ID_SUCCESS = "ITEM VERIFICATION:: Valid ID";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_ID_FAILURE = "ITEM VERIFICATION:: Invalid ID";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_PRIORITY_SUCCESS = "ITEM VERIFICATION:: Valid Priority";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_PRIORITY_FAILURE = "ITEM VERIFICATION:: Invalid Priority";
const string ItemVerification::EXCEPTION_SPOILT_BOOL = "This boolean is spoilt";
const int ItemVerification::ITEM_VERIFICATION_INT_ZERO = 0;
const int ItemVerification::ITEM_VERIFICATION_INT_MINUS_TWO = -20000;

ItemVerification::ItemVerification(Item itemObject, unsigned int nextItemID) {
	_itemObjectToVerify = itemObject;
	_nextID = nextItemID;
}

bool ItemVerification::isValidName() {
	string name = _itemObjectToVerify.getItemName();
	if (name == ITEM_VERIFICATION_EMPTY_STRING) {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_NAME);
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_NAME_FAILURE);
		return false;
	} else {
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_NAME_SUCCESS);
		return true;
	}
}

bool ItemVerification::isValidDescription() {
	_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_DESC_SUCCESS);
	return true;
}

bool ItemVerification::isValidStartDateTime() {
	DateTime startDateTime = _itemObjectToVerify.getStartTime();
	DateTimeVerification startDateTimeVerification(startDateTime);
	if (startDateTimeVerification.isValidDateTime()) {
		return true;
	} else {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_START_DATE_TIME);
		int year = startDateTime.getYear();
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
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_ID_SUCCESS);
		return true;
	} else {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_ID);
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_ID_FAILURE);
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
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_PRIORITY_SUCCESS);
		return true;
	} else {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_PRIORITY);
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_PRIORITY_FAILURE);
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

	try {
		if (hasValidName == true && hasValidName == false) {
			throw EXCEPTION_SPOILT_BOOL;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}

	try {
		if (hasValidDescription == true && hasValidDescription == false) {
			throw EXCEPTION_SPOILT_BOOL;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}

	try {
		if (hasValidStartDateTime == true && hasValidStartDateTime == false) {
			throw EXCEPTION_SPOILT_BOOL;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}

	try {
		if (hasValidEndDateTime == true && hasValidEndDateTime == false) {
			throw EXCEPTION_SPOILT_BOOL;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}

	try {
		if (hasValidTimeFrame == true && hasValidTimeFrame == false) {
			throw EXCEPTION_SPOILT_BOOL;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}

	try {
		if (hasValidID == true && hasValidID == false) {
			throw EXCEPTION_SPOILT_BOOL;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}

	try {
		if (hasValidPriority == true && hasValidPriority == false) {
			throw EXCEPTION_SPOILT_BOOL;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}

	try {
		if (hasValidLabel == true && hasValidLabel == false) {
			throw EXCEPTION_SPOILT_BOOL;
		}
	} catch (string errorMessage) {
		cerr << errorMessage << endl;
	}

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