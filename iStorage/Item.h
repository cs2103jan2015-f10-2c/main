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
	string _itemName;
	DateTime _startTime;
	DateTime _endTime;
	string _description;
	unsigned int _itemID;
	char _priority;
	char _label;
	bool _isCompleted;

public:
	//	Constructor
	//	Pre:	Nil
	//	Post:	Item object is created; attributes have no assigned values
	Item();

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
	DateTime setEndTime(DateTime);
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

	// display attributes
	// Pre:		Nil
	// Post:	Displays all attributes
	string displayItem();
};

#endif