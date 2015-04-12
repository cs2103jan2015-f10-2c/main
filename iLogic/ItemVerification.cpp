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
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_START_TIME = "ITEM VERIFICATION:: Valid Start Time";
const string ItemVerification::ITEM_VERIFICATION_LOG_INVALID_START_TIME = "ITEM VERIFICATION:: Invalid Start Time";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_END_TIME = "ITEM VERIFICATION:: Valid End Time";
const string ItemVerification::ITEM_VERIFICATION_LOG_INVALID_END_TIME = "ITEM VERIFICATION:: Invalid End Time";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_TIME_FRAME = "ITEM VERIFICATION:: Valid Time Frame";
const string ItemVerification::ITEM_VERIFICATION_LOG_INVALID_TIME_FRAME = "ITEM VERIFICATION:: Invalid Time Frame";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_ID_SUCCESS = "ITEM VERIFICATION:: Valid ID";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_ID_FAILURE = "ITEM VERIFICATION:: Invalid ID";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_PRIORITY_SUCCESS = "ITEM VERIFICATION:: Valid Priority";
const string ItemVerification::ITEM_VERIFICATION_LOG_VALID_PRIORITY_FAILURE = "ITEM VERIFICATION:: Invalid Priority";

const int ItemVerification::ITEM_VERIFICATION_INT_ZERO = 0;

ItemVerification::ItemVerification(Item itemObject, unsigned int nextItemID) {
	_itemObjectToVerify = itemObject;
	_name = _itemObjectToVerify.getItemName();
	_description = _itemObjectToVerify.getDescription();
	_itemID = _itemObjectToVerify.getItemID();
	_startTime = _itemObjectToVerify.getStartTime();
	_endTime = _itemObjectToVerify.getEndTime();
	_priority = _itemObjectToVerify.getPriority();
	_label = _itemObjectToVerify.getLabel();
	_isCompleted = _itemObjectToVerify.getCompletion();
	_nextID = nextItemID;
}

bool ItemVerification::isValidName() {
	string name = _itemObjectToVerify.getItemName();
	if (name == ITEM_VERIFICATION_EMPTY_STRING) {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_NAME);
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_NAME_FAILURE);
		assert(!_itemVerificationErrors.empty());
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
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_START_TIME);
		return true;
	} else {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_START_DATE_TIME);
		assert(!_itemVerificationErrors.empty());
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_INVALID_START_TIME);
		return false;
	}
}

bool ItemVerification::isValidEndDateTime() {
	DateTime endDateTime = _itemObjectToVerify.getEndTime();
	DateTimeVerification endDateTimeVerification(endDateTime);
	if (endDateTimeVerification.isValidDateTime()) {
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_END_TIME);
		return true;
	} else {
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_END_DATE_TIME);
		assert(!_itemVerificationErrors.empty());
		_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_INVALID_END_TIME);
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
				assert(!_itemVerificationErrors.empty());
				_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_INVALID_TIME_FRAME);
				return false;
			} else if (startDateTime.isAfter(endDateTime)) {
				_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_START_DATE_TIME_LATER_THAN_END_DATE_TIME);
				assert(!_itemVerificationErrors.empty());
				_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_INVALID_TIME_FRAME);
				return false;
			} else {
				_itemVerificationLogger.writeToLogFile(ITEM_VERIFICATION_LOG_VALID_TIME_FRAME);
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
				assert(!_itemVerificationErrors.empty());
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
		assert(!_itemVerificationErrors.empty());
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
		assert(_priority != 'H' && _priority != 'M' && _priority != 'L' && _priority != 'E');
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_PRIORITY);
		assert(!_itemVerificationErrors.empty());
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
		assert(_label != 'P' && _label != 'M' && _label != 'O' && _label != 'E');
		_itemVerificationErrors.push_back(ITEM_VERIFICATION_ERROR_INVALID_LABEL);
		assert(!_itemVerificationErrors.empty());
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
		assert(_name != ITEM_VERIFICATION_EMPTY_STRING);
		assert(_priority == 'H' || _priority == 'M' || _priority == 'L' || _priority == 'E');
		assert(_label == 'P' || _label == 'M' || _label == 'O' || _label == 'E');
		assert(_itemID > ITEM_VERIFICATION_INT_ZERO);
		return true;
	} else {
		return false;
	}
}

list<string> ItemVerification::getItemVerificationErrors() {
	return _itemVerificationErrors;
}