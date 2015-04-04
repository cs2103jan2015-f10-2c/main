#ifndef ITEM_VERIFICATION_H
#define ITEM_VERIFICATION_H

#include <string>
#include <list>
#include <iostream>
#include "DateTimeVerification.h"
#include "..\iStorage\Item.h"
using namespace std;

class ItemVerification {

private:
	Item _itemObjectToVerify;
	list<string> _itemVerificationErrors;
	unsigned int _nextID;

	static const string EMPTY_STRING;
	static const string AVAILABLE_PRIORITIES;
	static const string AVAILABLE_LABELS;
	static const string ERROR_INVALID_NAME2;
	static const string ERROR_INVALID_DESCRIPTION;
	static const string ERROR_INVALID_START_DATE_TIME;
	static const string ERROR_INVALID_END_DATE_TIME;
	static const string ERROR_SAME_START_END_DATE_TIME;
	static const string ERROR_START_DATE_TIME_LATER_THAN_END_DATE_TIME;
	static const string ERROR_INVALID_ID;
	static const string ERROR_INVALID_PRIORITY2;
	static const string ERROR_INVALID_LABEL2;
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

	////////////////////////////////////////
	//CHANGE BACK TO PRIVATE AFTER TESTING//
	////////////////////////////////////////
public:

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