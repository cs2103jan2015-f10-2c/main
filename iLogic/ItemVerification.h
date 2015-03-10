#ifndef ITEM_VERIFICATION_H
#define ITEM_VERIFICATION_H

#include <string>
#include <iostream>
#include "DateTimeVerification.h"
#include "..\iStorage\Item.h"
using namespace std;

static const string EMPTY_STRING = "";
static const string ERROR_EMPTY_STRING = "Error: Empty String Specified.\n";
static const string ERROR_INVALID_START_DATE = "Error: Invalid Start Date.\n";
static const string ERROR_INVALID_START_TIME = "Error: Invalid Start Time.\n";
static const string ERROR_INVALID_END_DATE = "Error: Invalid End Date.\n";
static const string ERROR_INVALID_END_TIME = "Error: Invalid End Time.\n";
static const string ERROR_INVALID_ID = "Error: An item has an invalid ID.\n";
static const string ERROR_INVALID_PRIORITY = "Error: An item has an invalid Priority.\n";
static const string ERROR_INVALID_LABEL = "Error: An item has an invalid Label.\n";

class ItemVerification {
private:
	Item itemObjectToVerify;
	int maxID;

	bool isValidName();
	bool isValidStartDateTime();
	bool isValidEndDateTime();
	bool isValidDescription();
	bool isValidItemID();
	bool isValidPriority();
	bool isValidLabel();

public:
	ItemVerification(Item itemObject, unsigned int currentMaxID);
	bool isValidItem();

};


#endif