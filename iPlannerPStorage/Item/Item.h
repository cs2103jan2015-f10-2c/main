//	Item (Tasks, Deadlines, Events)
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Andy Soh Wei Zhi, A0112042E

#include <string>
#include <vector>
#include "..\DateTime\DateTime.h"
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
	//	Pre:
	//	Post:
	Item();

	//	Destructor
	//	Pre:
	//	Post:
	~Item();

	//	Sets the attribute
	//	Pre:	ItemName is a string
	//			Start Time and End Time are DateTime objects
	//			Description is a string
	//			Item ID is an unsigned integer
	//			Priority is a character - L, M, or H
	//			Label is a character - P, O, or M
	//			Completion is a boolean value - true if item is completed
	//	Post:	_(attribute) is set, and value is returned
	string setItemName(string);
	DateTime setStartTime(DateTime);
	DateTime setEndTime(DateTime);
	string setDescription(string);
	unsigned int setItemID(unsigned int);
	char setPriority(char);
	char setLabel(char);
	bool setCompletion(bool);

	//	Sets the attribute
	//	Pre:	Attribute has been previously set.
	//	Post:	_(attribute) is returned
	string getItemName(string);
	DateTime getStartTime(DateTime);
	DateTime getEndTime(DateTime);
	string getDescription(string);
	unsigned int getItemID(unsigned int);
	char getPriority(char);
	char getLabel(char);
	bool getCompletion(bool);
};