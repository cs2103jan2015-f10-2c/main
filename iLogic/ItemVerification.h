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
	static const string ERROR_INVALID_NAME;
	static const string ERROR_INVALID_DESCRIPTION;
	static const string ERROR_INVALID_START_DATE_TIME;
	static const string ERROR_INVALID_END_DATE_TIME;
	static const string ERROR_SAME_START_END_DATE_TIME;
	static const string ERROR_START_DATE_TIME_LATER_THAN_END_DATE_TIME;
	static const string ERROR_INVALID_ID;
	static const string ERROR_INVALID_PRIORITY;
	static const string ERROR_INVALID_LABEL;

public:
	ItemVerification(Item itemObject, unsigned int nextItemID);
	bool isValidItem();
	list<string> getItemVerificationErrors();
	
	//////////////////////////////////
	// PULLED TO PUBLIC FOR TESTING //
	//////////////////////////////////
	bool isValidName();
	bool isValidDescription();
	bool isValidStartDateTime();
	bool isValidEndDateTime();
	bool isValidTimeFrame();
	bool isValidID();
	bool isValidPriority();
	bool isValidLabel();

};


#endif