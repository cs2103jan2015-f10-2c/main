#include "Logic.h"

Logic::Logic(){

}


Logic::~Logic(){

}

int Logic::addTask(Item itemToBeAdded){
	_schedule.addItem(itemToBeAdded);
}
int Logic::editTask(){

}
int Logic::deleteTask(unsigned int lineIndexToBeDeleted){
	//if(schedule size > lineIndextoBeDeleted)
	_schedule.deleteItem(lineIndexToBeDeleted);
	return 1;
}
int Logic::searchTask(){

}
int Logic::sortTask(){

}
int Logic::assignTiming(){
}
int Logic::assignPriority(){

}
int Logic::assignLabel(){

}
int Logic::changeView(){

}
int Logic::showHelpMenu(){

}

void Logic::addToTStorage(){

}
void Logic::addToPStorage(){

}
void Logic::deleteFromPStorage(){

}
void Logic::editPStorage(){

}

void Logic::assignSaveFolder(){

}
void Logic::readDataFromFile(){

}
int Logic::writeDataOntoFile(char * fileName) {
	// Variable to denote successful processing of function
	int retCode = -1;
	ofstream outfile(fileName);

	if (!outfile.bad()) {
		outfile << setItem << endl << setDateTime << endl;
		outfile.close();
		retCode = 0;
	}

	return retCode;
}

unsigned int Logic::getIdFromIndex(int lineIndex){
	unsigned int Id = _schedule._
}
DateTime Logic::setDateTime(int year, int month, int day, int hour, int minute){
	DateTime datetime;
	if (datetime.isValidYearRange(year) && datetime.isValidMonthRange(month) && datetime.isValidDate(day,month,year)
		&& datetime.isValidHourRange(hour) && datetime.isValidMinuteRange(minute)){
		datetime.setYear(year);
		datetime.setMonth(month);
		datetime.setDay(day);
		datetime.setHour(hour);
		datetime.setMinute(minute);
	}
	return datetime;
}

Item Logic::setItem(string itemName, DateTime startTime, DateTime endTime, string description, char priority, char label, bool isCompleted){
	Item item;

	item.setItemName(itemName);
  item.setStartTime(startTime);
  item.setEndTime(endTime);
	item.setDescription(description);
	item.setPriority(priority);
	item.setLabel(label);
	item.setCompletion(isCompleted);
	
  return item;
}
