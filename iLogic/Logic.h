//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J & Shri Kishen Rajendran A0105180W

#pragma once

#ifndef LOGIC_H
#define LOGIC_H

#include "..\iStorage\Schedule.h"
#include "..\iStorage\Item.h"
#include "..\iParser\iParser.h"
#include "..\iParser\UserCommand.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Logic
{
private:
	Schedule _logicSchedule;
	unsigned int _nextItemID;
	
public:
	Logic();
	~Logic();

	unsigned int addTask(Item itemToBeAdded);
	bool isValidItem(Item itemToBeChecked);
	Item deleteTask(unsigned int lineIndexToBeDeleted);
	unsigned int getItemIdFromLineIndex(int lineIndex);
	bool isValidLineIndex(unsigned int lineIndexToBeChecked);
	vector<Item> getSchedule();
	unsigned int getScheduleSize();
	int deleteAndAddEditedItem(unsigned int lineIndexToBeEdited, Item editedItemToBeAdded);

	Item assignTiming(Item item, string timingType, DateTime datetime);
	int assignTimingToNewTask(string timingType, DateTime datetime);
	int assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex);
	Item assignPriority(Item item, char priorityType);
	int assignPriorityToNewTask(char priorityType);
	int assignPriorityToExistingTask(char priorityType, unsigned int lineIndex);
	Item assignLabel(Item item, char labelType);
	int assignLabelToNewTask(char labelType);

	/*
	void readUserInput();
	void showUserInput(list<userCommand> userCommandList);

	
	int editTask(string partToEdit, unsigned int lineIndexToBeEdited);
	
	
	int searchTask(string phraseToSearch);
	bool isFound(int lineIndex, string& phraseToSearch);
	int sortTask();
	int changeView();
	int showHelpMenu();

	void assignSaveFolder();
	int readDataFromFile(char * fileName, vector<Item> itemVector);
	int writeDataOntoFile(char * fileName, vector<Item> itemVector);

	
	
	
	void printItem(Item item);
	void printItemVector(vector<Item> itemVector);

	Item getItem(unsigned int itemID);

	
	DateTime setDateTime(int year, int month, int day, int hour, int minute);
	DateTime setDateTime(int year, int month, int day);
	Item setItem(string itemName, DateTime startTime, DateTime endTime, string description, char priority, char label, bool isCompleted);
	
	*/
	};

#endif
