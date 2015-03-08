//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J & Shri Kishen Rajendran A0105180W

#pragma once
#include "..\..\iPlannerPStorage\iPlannerPStorage\Pstorage.h"
#include "..\..\iPlannerTStorage\iPlannerTStorage\Tstorage.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Logic
{
		private:

		
	

		enum _dayOfTheWeek { monday, tuesday, wednesday, thursday, friday, saturday, sunday };
		int _year;
		int _month;
		int _day;
		int _hour;
		int _minute;
		int _taskIndex;
		string _taskName;
		string _taskDescription;
		string _taskPriority;
		string _taskLabel;

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
		int markDone();
		int markUndone();
		int undoPreviousAction();
		int redoPreviousAction();
		int changeView();
		int setNotification();
		int setRecurringTask();
		int showHelpMenu();

		void addToTStorage();
		void addToPStorage();
		void deleteFromPStorage();
		void editPStorage();
		
		void assignSaveFolder();
		void readDataFromFile();
		int writeDataOntoFile(char * fileName);
	};

	