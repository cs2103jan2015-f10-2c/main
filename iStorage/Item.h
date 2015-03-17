//	Item (Tasks, Deadlines, Events)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "DateTime.h"
using namespace std;

class Item
{
private:
	static const string EMPTYFIELD_ITEMNAME;
	static const string EMPTYFIELD_DESCRIPTION;
	static const string EMPTYFIELD_TIME;
	static const string ALLOWABLEOPTIONS_PRIORITY;
	static const string ALLOWABLEOPTIONS_LABEL;
	static const unsigned int EMPTYFIELD_ITEMID;
	static const char EMPTYFIELD_PRIORITY;
	static const char EMPTYFIELD_LABEL;

	string _itemName;
	DateTime _startTime;
	DateTime _endTime;
	string _description;
	unsigned int _itemID;
	char _priority;
	char _label;
	bool _isCompleted;

	bool hasValidItemName();
	bool hasValidItemStartTime();
	bool hasValidItemEndTime();
	bool hasValidItemDescription();
	bool hasValidItemID();
	bool hasValidItemPriority();
	bool hasValidItemLabel();

public:
	//	Constructor
	//	Pre:	Nil
	//	Post:	Item object is created; attributes have assigned to defaults
	Item();

	//	Overloaded Constructors
	//	Pre:	itemName and itemID are valid
	//	Post:	Item is created with _itemName and _itemID assigned
	Item(string);
	Item(unsigned int);
	Item(string, unsigned int);

	//	Destructor
	//	Pre:	Nil
	//	Post:	Item object is destroyed
	~Item();

	//	Sets the attribute
	//	Pre:	ItemName is a string
	//			Description is a string
	//			Start Time and End Time are DateTime objects
	//			Item ID is an unsigned integer
	//			Priority is a character - L, M, or H
	//			Label is a character - P, O, or M
	//			Completion is a boolean value - true if item is completed
	//	Post:	_(attribute) is set, and value is returned
	string setItemName(string);
	string setDescription(string);
	DateTime setStartTime(DateTime);
	DateTime setStartTime(int, int, int);
	DateTime setStartTime(int, int, int, int, int);
	DateTime setEndTime(DateTime);
	DateTime setEndTime(int, int, int);
	DateTime setEndTime(int, int, int, int, int);
	unsigned int setItemID(unsigned int);
	char setPriority(char);
	char setLabel(char);
	bool setCompletion(bool);

	//	Sets the attribute
	//	Pre:	Attribute has been previously set.
	//	Post:	_(attribute) is returned
	string getItemName();
	string getDescription();
	DateTime getStartTime();
	DateTime getEndTime();
	unsigned int getItemID();
	char getPriority();
	char getLabel();
	bool getCompletion();

	// Returns string with item details
	// Pre:		Nil
	// Post:	String with existing details are returned
	string displayItemForUser();
	string displayItemFullDetails();
	string displayStartTime();
	string displayEndTime();
};

#endif