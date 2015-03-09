//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J & Shri Kishen Rajendran A0105180W

#pragma once
#include "..\..\iPlannerPStorage\iPlannerPStorage\Storage.h"
#include "..\..\iPlannerPStorage\Item\Item.h"
#include "..\..\iPlannerParser\iPlannerParser\iPlannerParser.h"
#include "..\..\iPlannerParser\userCommand\userCommand.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Logic
{
private:
	Schedule _schedule;

public:
	Logic();
	~Logic();
	int addTask(Item itemToBeAdded);
	int editTask();
	int deleteTask(unsigned int lineIndexToBeDeleted);
	int searchTask(string phraseToSearch);
	bool isFound(int lineIndex, string& phraseToSearch);
	int sortTask();
	int assignTiming();
	int assignPriority();
	int assignLabel();
	int changeView();
	int showHelpMenu();

	void addToTStorage();
	void addToPStorage();
	void deleteFromPStorage();
	void editPStorage();

	void assignSaveFolder();
	void readDataFromFile();
	int writeDataOntoFile(char * fileName);
	
	void printItem(Item item);
	void printItemVector(vector<Item> itemVector);
	unsigned int getScheduleSize();
	unsigned int getItemIdFromLineIndex(int lineIndex);
	DateTime setDateTime(int year, int month, int day, int hour, int minute);
	Item setItem(string itemName, DateTime startTime, DateTime endTime, string description,	char priority, char label, bool isCompleted);
};

