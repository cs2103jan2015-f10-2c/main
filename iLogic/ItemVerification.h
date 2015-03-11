#ifndef ITEM_VERIFICATION_H
#define ITEM_VERIFICATION_H

#include <string>
#include <iostream>
#include "DateTimeVerification.h"
#include "..\iStorage\Item.h"
using namespace std;

class ItemVerification {
private:
	Item _itemObjectToVerify;
	int _nextID;

	static const string EMPTY_STRING;
	static const string AVAILABLE_PRIORITIES;
	static const string AVAILABLE_LABELS;
	static const string ERROR_EMPTY_STRING;
	static const string ERROR_INVALID_START_DATE;
	static const string ERROR_INVALID_START_TIME;
	static const string ERROR_INVALID_END_DATE;
	static const string ERROR_INVALID_END_TIME;
	static const string ERROR_INVALID_ID;
	static const string ERROR_INVALID_PRIORITY;
	static const string ERROR_INVALID_LABEL;

public:
	ItemVerification(Item itemObject, unsigned int nextItemID);
	bool isValidItem();
	
	// PULLED TO PUBLIC FOR TESTING
	bool isValidName();
	bool isValidStartDateTime();
	bool isValidEndDateTime();
	// TO BE CODED LATER ON!! bool isValidTimeframe();
	bool isValidDescription();
	bool isValidItemID();
	bool isValidPriority();
	bool isValidLabel();

};


#endif