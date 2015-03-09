//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J & Shri Kishen Rajendran A0105180W

#pragma once
#include "..\..\iPlannerPStorage\iPlannerPStorage\Pstorage.h"
#include "..\..\iPlannerTStorage\iPlannerTStorage\Tstorage.h"
#include "..\..\iPlannerPStorage\Item\Item.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Logic
{
private:
  vector<Item> taskList;
  vector<DateTime> taskDateTime;

public:
	Logic();
	~Logic();
	int addTask();
	int editTask();
	int deleteTask();
	int searchTask();
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

	DateTime setDateTime(int year, int month, int day, int hour, int minute);
	Item setItem(string itemName, DateTime startTime,	DateTime endTime, string description,	char priority, char label, bool isCompleted);
};

