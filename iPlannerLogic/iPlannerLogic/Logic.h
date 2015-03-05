//	Logic
//	Tutorial Group 8 (Friday, 10:00AM); Group 2C
//	Coder:	Yu Young Bin A0116229J

#pragma once
#include "PStorage.h"
#include "TStorage.h"
#include <iostream>
#include <vector>
#include <string>
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
		void addItem();
		void editItem();
		void deleteItem();
		void searchItem();
		void sortItem();
		void assignTiming();
		void assignPriority();
		void assignLabel();
		void markDone();
		void markUndone();
		void undoPreviousAction();
		void redoPreviousAction();
		void changeView();
		void setNotification();
		void setRecurringTask();
		void showHelpMenu();

		void addToTStorage();
		void addToPStorage();
		void deleteFromPStorage();
		void editPStorage();
		
		void assignSaveFolder();
		void readDataFromFile();
		void writeDataOntoFile();
	};

	