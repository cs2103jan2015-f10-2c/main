//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J & Shri Kishen Rajendran A0105180W

#pragma once

#ifndef LOGIC_H
#define LOGIC_H

#include "..\iStorage\Schedule.h"
#include "..\iStorage\Item.h"
#include "..\iParser\iParser.h"
#include "..\iLogic\ItemVerification.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;

class Logic
{
private:
	Schedule _logicSchedule;
	unsigned int _nextItemID;

	static const string MESSAGE_SUCCESS;
	static const string MESSAGE_INVALID_INPUT;
	static const string COMMAND_ADD;
	static const string COMMAND_DELETE;
	static const string COMMAND_EDIT;
	static const string COMMAND_EXIT;
	static const int ZERO_INDEX = 0;
	static const unsigned int DEFAULT_ITEM_ID = 0;

	static char buffer[300];
	static const string ASSIGNED_PRIORITY;
	static const string ASSIGNED_LABEL;
	static const string ASSIGNED_START_TIME;
	static const string ASSIGNED_END_TIME;
	static const string ASSIGNED_NAME;
	static const string ASSIGNED_DESCRIPTION;
public:
	Logic();
	~Logic();
	void printSchedule();
	void printItem(Item itemToBePrinted);
	void printAssignedPriority(Item itemToBePrinted);
	void printAssignedLabel(Item itemToBePrinted);
	void printAssignedStartTime(Item itemToBePrinted);
	void printAssignedEndTime(Item itemToBePrinted);
	void printAssignedName(Item itemToBePrinted);
	void printAssignedDescription(Item itemToBePrinted);
	
	unsigned int addTask(Item itemToBeAdded);

	string processedCommand(ParseInfo parseInfoToBeProcessed);
	unsigned int processedLineIndex(ParseInfo parseInfoToBeProcessed);
	Item processedItem(ParseInfo parseInfoToBeProcessed);
	void initiateCommandAction(ParseInfo parseInfoToBeProcessed);
	bool isValidItemInLogic(Item itemToBeChecked);
	Item deleteTask(unsigned int lineIndexToBeDeleted);
	unsigned int getItemIDFromLineIndex(unsigned int lineIndex);
	Item getItemFromLineIndex(unsigned int lineIndex);
	bool isValidLineIndex(unsigned int lineIndexToBeChecked);
	vector<Item> getSchedule();
	unsigned int getScheduleSize();
	Item deleteAndAddEditedItem(unsigned int lineIndexToBeEdited, Item editedItemToBeAdded);

	Item assignDescription(Item item, string descriptionToBeAdded);
	Item assignDescriptionToNewTask(Item item, string descriptionToBeAdded);
	Item assignDescriptionToExistingTask(string descriptionToBeAdded, unsigned int lineIndex);
	Item assignTiming(Item item, string timingType, DateTime datetime);
	Item assignTimingToNewTask(string timingType, DateTime datetime);
	Item assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex);
	Item assignPriority(Item item, char priorityType);
	Item assignPriorityToNewTask(char priorityType);
	Item assignPriorityToExistingTask(char priorityType, unsigned int lineIndex);
	Item assignLabel(Item item, char labelType);
	Item assignLabelToNewTask(char labelType);
	Item assignLabelToExistingTask(char labelType, unsigned int lineIndex);
	
//	void readUserInput();
//	void showUserInput(list<userCommand> userCommandList);
	
	int editTask(string command, Item itemToBeEdited, unsigned int lineIndexToBeEdited);
	
	
	vector<Item> searchTask(string phraseToSearch);
	bool isFound(int lineIndex, string& phraseToSearch);
	int sortTask();
	int changeView();
	int showHelpMenu();

	//void assignSaveFolder();
	int readDataFromFile(char * fileName);
	int writeDataOntoFile(char * fileName, vector<Item> itemVector);
	/*
	
	
	
	void printItem(Item item);
	void printItemVector(vector<Item> itemVector);



	
	DateTime setDateTime(int year, int month, int day, int hour, int minute);
	DateTime setDateTime(int year, int month, int day);
	Item setItem(string itemName, DateTime startTime, DateTime endTime, string description, char priority, char label, bool isCompleted);
	*/
};

#endif
