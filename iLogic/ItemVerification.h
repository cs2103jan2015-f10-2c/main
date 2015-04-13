//author A0108462J

#ifndef ITEM_VERIFICATION_H
#define ITEM_VERIFICATION_H

#include <string>
#include <list>
#include <iostream>
#include "DateTimeVerification.h"
#include "..\iStorage\Item.h"
#include "..\iPlanner Log\Log.h"

using namespace std;

class ItemVerification {

private:
	Log _itemVerificationLogger;
	Item _itemObjectToVerify;
	list<string> _itemVerificationErrors;
	unsigned int _nextID;
	string _name;
	string _description;
	unsigned int _itemID;
	DateTime _startTime;
	DateTime _endTime;
	char _priority;
	char _label;
	bool _isCompleted;

	static const string ITEM_VERIFICATION_EMPTY_STRING;
	static const string ITEM_VERIFICATION_AVAILABLE_PRIORITIES;
	static const string ITEM_VERIFICATION_AVAILABLE_LABELS;
	static const string ITEM_VERIFICATION_ERROR_INVALID_NAME;
	static const string ITEM_VERIFICATION_ERROR_INVALID_DESCRIPTION;
	static const string ITEM_VERIFICATION_ERROR_INVALID_START_DATE_TIME;
	static const string ITEM_VERIFICATION_ERROR_INVALID_END_DATE_TIME;
	static const string ITEM_VERIFICATION_ERROR_SAME_START_END_DATE_TIME;
	static const string ITEM_VERIFICATION_ERROR_START_DATE_TIME_LATER_THAN_END_DATE_TIME;
	static const string ITEM_VERIFICATION_ERROR_INVALID_ID;
	static const string ITEM_VERIFICATION_ERROR_INVALID_PRIORITY;
	static const string ITEM_VERIFICATION_ERROR_INVALID_LABEL;

	static const string ITEM_VERIFICATION_LOG_VALID_NAME_SUCCESS;
	static const string ITEM_VERIFICATION_LOG_VALID_NAME_FAILURE;
	static const string ITEM_VERIFICATION_LOG_VALID_DESC_SUCCESS;
	static const string ITEM_VERIFICATION_LOG_VALID_START_TIME;
	static const string ITEM_VERIFICATION_LOG_INVALID_START_TIME;
	static const string ITEM_VERIFICATION_LOG_VALID_END_TIME;
	static const string ITEM_VERIFICATION_LOG_INVALID_END_TIME;
	static const string ITEM_VERIFICATION_LOG_VALID_TIME_FRAME;
	static const string ITEM_VERIFICATION_LOG_INVALID_TIME_FRAME;
	static const string ITEM_VERIFICATION_LOG_VALID_ID_SUCCESS;
	static const string ITEM_VERIFICATION_LOG_VALID_ID_FAILURE;
	static const string ITEM_VERIFICATION_LOG_VALID_PRIORITY_SUCCESS;
	static const string ITEM_VERIFICATION_LOG_VALID_PRIORITY_FAILURE;

	static const int ITEM_VERIFICATION_INT_ZERO;

	// Conducts the validity checks on the individual
	// fields within the item
	bool isValidName();
	bool isValidDescription();
	bool isValidStartDateTime();
	bool isValidEndDateTime();
	bool isValidTimeFrame();
	bool isValidID();
	bool isValidPriority();
	bool isValidLabel();

public:
	ItemVerification(Item itemObject, unsigned int nextItemID);

	// Does comprehensive checks to the given Item object to 
	// determine if it can be considered a valid Item according
	// to iPlanner standards.
	bool isValidItem();

	// Allows retrieval of a list of errors with the given
	// Item object.
	list<string> getItemVerificationErrors();

};

#endif