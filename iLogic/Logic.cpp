#include "Logic.h"
#include <exception>

const string Logic::MESSAGE_SUCCESS = "execution success";
const string Logic::MESSAGE_INVALID_INPUT = "invalid input";
const string Logic::COMMAND_ADD = "add";
const string Logic::COMMAND_DELETE = "delete";
const string Logic::COMMAND_EDIT = "edit";
const string Logic::COMMAND_EXIT = "exit";

const string Logic::TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME = "directory.txt";
const string Logic::DEFAULT_FILENAME = "save.txt";

char Logic::buffer[300];
const string Logic::ADD_TASK_SUCCESSFUL = "Task is added to schedule";
const string Logic::DELETE_TASK_SUCCESSFUL = "Task %d is removed from schedule";


Logic::Logic() {
	_nextItemID = 1;
	//failure in add,delete,add function will return an item with ID = 0
	_scheduleSize = 0;
	//schedule size initialised to 0
	_directoryToBeSaved = "";
	//if saving directory is an empty string, the directory is set to default
	_fileNameToBeSaved = DEFAULT_FILENAME;
	//default file name is save.txt
}

Logic::~Logic() {}

void Logic::printSchedule(){
	cout << endl;
	cout << "SCHEDULE" << endl;
	cout << "--------" << endl;
	for (unsigned int lineNumber = 0; lineNumber < getScheduleSize(); lineNumber++){
		cout << lineNumber + 1 << ". " << endl;
		printItem(getSchedule()[lineNumber].displayItemForUser());
		cout << endl;
	}
	cout << endl;
}

void Logic::printItem(string itemToBePrinted){
	cout << itemToBePrinted << endl;
	return;
}

void Logic::printAddTaskSuccessful(string itemInformationToBePrinted){
	sprintf_s(buffer, ADD_TASK_SUCCESSFUL.c_str(), itemInformationToBePrinted);
	cout << buffer << endl;
}

void Logic::printDeleteTaskSuccessful(string itemInformationToBePrinted){
	sprintf_s(buffer, ADD_TASK_SUCCESSFUL.c_str(), itemInformationToBePrinted);
	cout << buffer << endl;
}
/*
unsigned int Logic::addTask(Item itemToBeAdded){
unsigned int addedItemID = DEFAULT_ITEM_ID;
try{
if (isValidItemInLogic(itemToBeAdded)) {
itemToBeAdded.setItemID(_nextItemID);
_nextItemID++;
_scheduleSize++;
addedItemID = _logicSchedule.addItem(itemToBeAdded);
}
else{
throw ("invalid input for addTask");
}
}
catch (const char* e){
cout << e << endl;
}
printSchedule();
return addedItemID;
}
*/
unsigned int Logic::addTask(string itemInformation){
	unsigned int addedItemID = DEFAULT_ITEM_ID;
	Item *newItemToBeAdded;
	newItemToBeAdded = new Item;
	newItemToBeAdded->setItemName(itemInformation);
	newItemToBeAdded->setItemID(_nextItemID);
	string addCompleted = _logicSchedule.addItem(newItemToBeAdded);
	addedItemID = _nextItemID;
	_nextItemID++;
	printAddTaskSuccessful(addCompleted);
	printSchedule();
	return addedItemID;
}

bool Logic::isValidItemInLogic(Item itemToBeChecked){
	ItemVerification itemVerifier(itemToBeChecked, _nextItemID);
	if (itemVerifier.isValidItem()) {
		return true;
	}
	else {
		return false;
	}
}

int Logic::deleteTask(string itemInformation){
	int lineIndexToBeDeleted = stoi(itemInformation);
	unsigned int itemIDToBeDeleted;
	cout << "lineIndex = " << lineIndexToBeDeleted << endl;
//	try{
		if (isValidLineIndex(lineIndexToBeDeleted)){
			cout << "HERE" << endl;
			itemIDToBeDeleted = getItemIDFromLineIndex(lineIndexToBeDeleted);
			string deletedItem = _logicSchedule.deleteItem(itemIDToBeDeleted);
			printDeleteTaskSuccessful(deletedItem);
			_scheduleSize--;//Delete successful
			printSchedule();
//		}
/*		else{
			throw("invalid lineIndex for deleteTask"); //Delete failed
			printSchedule();
			
		}*/
	}
	//catch (const char* e){
//cout << e << endl;
	//}
	return 1;
}


unsigned int Logic::getItemIDFromLineIndex(unsigned int lineIndex){
	unsigned int id = getSchedule()[lineIndex - 1].getItemID();
	return id;
}



bool Logic::isValidLineIndex(unsigned int lineIndexToBeChecked){
	if (getScheduleSize() >= lineIndexToBeChecked){
		return true;
	}
	else{
		return false;
	}
}

vector<Item> Logic::getSchedule(){
	return _logicSchedule.retrieveSchedule();
}

unsigned int Logic::getScheduleSize(){
	return _logicSchedule.getSizeOfSchedule();
}
/*
Item Logic::assignDescription(Item item, string descriptionToBeAdded){
item.setDescription(descriptionToBeAdded);
return item;
}

Item Logic::assignDescriptionToNewTask(Item item, string descriptionToBeAdded){
int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setDescription(descriptionToBeAdded);
return _logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule];
}
Item Logic::assignDescriptionToExistingTask(string descriptionToBeAdded, unsigned int lineIndex){
_logicSchedule.retrieveSchedule()[lineIndex - 1].setDescription(descriptionToBeAdded);
return _logicSchedule.retrieveSchedule()[lineIndex - 1];
}

Item Logic::assignTiming(Item item, string timingType, DateTime datetime){
if (timingType == "start"){
item.setStartTime(datetime);
}
else if (timingType == "due" || timingType == "end"){
item.setEndTime(datetime);
}
return item;
}


Item Logic::assignTimingToNewTask(string timingType, DateTime dateTime){
int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
if (timingType == "start"){
_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setStartTime(dateTime);
}
else if (timingType == "end"){
_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setEndTime(dateTime);
}
return _logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule];
}

Item Logic::assignTimingToExistingTask(string timingType, DateTime datetime, unsigned int lineIndex){
if (timingType == "start"){
_logicSchedule.retrieveSchedule()[lineIndex - 1].setStartTime(datetime);
}
else if (timingType == "end"){
_logicSchedule.retrieveSchedule()[lineIndex - 1].setEndTime(datetime);
}
return _logicSchedule.retrieveSchedule()[lineIndex - 1];

}

Item Logic::assignPriority(Item item, char priorityType){
try {
throw "";
}
catch (char priorityType) {
item.setPriority('L');
}
item.setPriority(priorityType);
return item;
}

Item Logic::assignPriorityToNewTask(char priorityType){
int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setPriority(priorityType);
return _logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule];
}

Item Logic::assignPriorityToExistingTask(char priorityType, unsigned int lineIndex){
_logicSchedule.retrieveSchedule()[lineIndex - 1].setPriority(priorityType);
return _logicSchedule.retrieveSchedule()[lineIndex - 1];
}

Item Logic::assignLabel(Item item, char labelType){
try {
throw "";
}
catch (char labelType) {
item.setLabel('P');
}
item.setLabel(labelType);
return item;
}
Item Logic::assignLabelToNewTask(char labelType){
int lastLineIndexOfSchedule = getScheduleSize() - 1;//new task will be at the very back of the schedule vector
_logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule].setLabel(labelType);
return _logicSchedule.retrieveSchedule()[lastLineIndexOfSchedule];
}

Item Logic::assignLabelToExistingTask(char labelType, unsigned int lineIndex){
_logicSchedule.retrieveSchedule()[lineIndex - 1].setLabel(labelType);
return _logicSchedule.retrieveSchedule()[lineIndex - 1];
}
*/
string Logic::getCommand(COMMAND_AND_TEXT parseInfoToBeProcessed){
	return parseInfoToBeProcessed.command;
}

string Logic::getText(COMMAND_AND_TEXT parseInfoToBeProcessed){
	return parseInfoToBeProcessed.text;
}

COMMAND_AND_TEXT Logic::getParseInfo(iParser parser, string input){
	parser.parse(input);
	return parser.getParseInfo().back();
}

void Logic::initiateCommandAction(iParser parser, string input) {
	COMMAND_AND_TEXT parseInfoToBeProcessed = getParseInfo(parser, input);
	string command = getCommand(parseInfoToBeProcessed);
	string itemInformation = getText(parseInfoToBeProcessed);
	//	if (parseInfoToBeProcessed.hasValidInput()) {
	if (command == COMMAND_ADD) {
		addTask(itemInformation);
	}
	else if (command == COMMAND_DELETE) {
		deleteTask(itemInformation);
	}
	/*
	else if (command == "edit") {
	string partsToBeEdited = parseInfoToBeProcessed.getEditString();
	editTask(partsToBeEdited, itemToBeProcessed, lineIndexToBeProcessed);
	}*/
	else if (command == "exit"){
		ofstream writeFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
		writeFile << _directoryToBeSaved << endl;
		writeFile << _fileNameToBeSaved << endl;
		writeFile << _scheduleSize;
		exit(0);
	}
	/*}
	else {
	cout << "Error: " << MESSAGE_INVALID_INPUT << endl << endl;
	}*/
}
/*
int Logic::editTask(string command, Item itemToBeEdited, unsigned int lineIndexToBeEdited){
if (command == "priority"){
char priorityToBeAssigned = itemToBeEdited.getPriority();
assignPriorityToExistingTask(priorityToBeAssigned, lineIndexToBeEdited);
}
else if (command == "label"){
char labelToBeAssigned = itemToBeEdited.getLabel();
assignLabelToExistingTask(labelToBeAssigned, lineIndexToBeEdited);
}
else if (command == "start"){
DateTime startTimeToBeAssigned = itemToBeEdited.getStartTime();
assignTimingToExistingTask("start", startTimeToBeAssigned, lineIndexToBeEdited);
}
else if (command == "desc"){
string descriptionToBeAssigned = itemToBeEdited.getDescription();
assignDescriptionToExistingTask(descriptionToBeAssigned, lineIndexToBeEdited);
}
else if (command == "end" || command == "due"){
DateTime endTimeToBeAssigned = itemToBeEdited.getEndTime();
assignTimingToExistingTask("end", endTimeToBeAssigned, lineIndexToBeEdited);
}

printSchedule();
return 1;
}




vector<Item> Logic::searchTask(string phraseToSearch){
vector<Item> searchedItems;
Item foundItem;
unsigned int lineIndex;
unsigned int scheduleSize = getScheduleSize();
for (lineIndex = 0; lineIndex < scheduleSize; lineIndex++){
if (isFound(lineIndex, phraseToSearch)){
foundItem = getItemFromLineIndex(lineIndex);
searchedItems.push_back(foundItem);
}
}
return searchedItems;
}

bool Logic::isFound(int lineIndex, string& phraseToSearch){
Item itemFromLogicSchedule;
itemFromLogicSchedule = getItemFromLineIndex(lineIndex);
unsigned int phraseFoundFromItemName;
unsigned int phraseFoundFromItemDescription;
phraseFoundFromItemName = itemFromLogicSchedule.getItemName().find(phraseToSearch);
if (phraseFoundFromItemName != string::npos) {
return true;
}
phraseFoundFromItemDescription = itemFromLogicSchedule.getDescription().find(phraseToSearch);
if (phraseFoundFromItemDescription != string::npos) {
return true;
}
return false;
}

Item Logic::getItemFromLineIndex(unsigned int lineIndex) {
Item itemToBeReturned;
itemToBeReturned.setItemID(getSchedule()[lineIndex].getItemID());
itemToBeReturned.setItemName(getSchedule()[lineIndex].getItemName());
itemToBeReturned.setLabel(getSchedule()[lineIndex].getLabel());
itemToBeReturned.setDescription(getSchedule()[lineIndex].getDescription());
itemToBeReturned.setStartTime(getSchedule()[lineIndex].getStartTime());
itemToBeReturned.setEndTime(getSchedule()[lineIndex].getEndTime());
itemToBeReturned.setPriority(getSchedule()[lineIndex].getPriority());
itemToBeReturned.setCompletion(getSchedule()[lineIndex].getCompletion());
return itemToBeReturned;
}

string Logic::changeSavingDirectory(string directoryToBeSaved){
string directoryToMake = "";
int truncateDirectory;

while (directoryToBeSaved != ""){
truncateDirectory = directoryToBeSaved.find_first_of('/');
if (truncateDirectory != -1){
directoryToMake = directoryToMake + directoryToBeSaved.substr(0, truncateDirectory + 1);
directoryToBeSaved = directoryToBeSaved.substr(truncateDirectory + 1);
}
else {
directoryToMake = directoryToMake + directoryToBeSaved;
directoryToBeSaved = "";
}
_mkdir(directoryToMake.c_str());
}
_directoryToBeSaved = directoryToMake;
return directoryToMake;
}

void Logic::saveDirectoryToTextFile(){
ofstream writeFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
writeFile << _directoryToBeSaved << endl;
writeFile << _fileNameToBeSaved << endl;
writeFile << _scheduleSize;
}

string Logic::getDirectoryAndFileName(){
if (_directoryToBeSaved == ""){
if (_fileNameToBeSaved == ""){
_fileNameToBeSaved == DEFAULT_FILENAME;
}
return _fileNameToBeSaved;
}
else{
return _directoryToBeSaved + "/" + _fileNameToBeSaved;
}
}

string Logic::retrieveDirectoryFromTextFile(){
ifstream readFile(TEXTFILE_TO_STORE_DIRECTORY_AND_FILENAME);
getline(readFile, _directoryToBeSaved);
getline(readFile, _fileNameToBeSaved);
readFile >> _scheduleSize;
cout << _directoryToBeSaved + "/" + _fileNameToBeSaved << endl;
if (_directoryToBeSaved == ""){
if (_fileNameToBeSaved == ""){
_fileNameToBeSaved == DEFAULT_FILENAME;
}
return _fileNameToBeSaved;
}
else{
return _directoryToBeSaved + "/" + _fileNameToBeSaved;
}
}

string Logic::changeSavingFileName(string FileNameToBeSaved){
_fileNameToBeSaved = FileNameToBeSaved;
saveDirectoryToTextFile();
return FileNameToBeSaved;
}

int Logic::readDataFromFile() {
ifstream readFile(getDirectoryAndFileName());
for (unsigned int lineNumber = 0; lineNumber < _scheduleSize; lineNumber++){
//while (!readFile.eof()){
string itemName;
string description;
string junk;
char priority;
char label;
int DD;
int MM;
int YYYY;
int hh;
int mm;
getline(readFile, itemName);
readFile >> YYYY;
readFile >> MM;
readFile >> DD;
readFile >> hh;
readFile >> mm;
DateTime startTime(YYYY, MM, DD, hh, mm);
readFile >> YYYY;
readFile >> MM;
readFile >> DD;
readFile >> hh;
readFile >> mm;
DateTime EndTime(YYYY, MM, DD, hh, mm);
getline(readFile, junk);
getline(readFile, description);
readFile >> priority;
readFile >> label;
getline(readFile, junk);
Item item;
item.setItemName(itemName);
item.setStartTime(startTime);
item.setEndTime(EndTime);
item.setDescription(description);
item.setPriority(priority);
item.setLabel(label);
_logicSchedule.addItem(item);
}
cout << "Schedule received" << endl;
printSchedule();
return 1;
}

int Logic::writeDataOntoFile(){
ofstream writeFile(getDirectoryAndFileName());
for (unsigned int lineNumber = 0; lineNumber < _logicSchedule.getSizeOfSchedule(); lineNumber++){
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getItemName() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getYear() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getMonth() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getDay() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getHour() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getStartTime().getMinute() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getYear() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getMonth() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getDay() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getHour() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getEndTime().getMinute() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getDescription() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getPriority() << endl;
writeFile << _logicSchedule.retrieveSchedule()[lineNumber].getLabel() << endl;
}
saveDirectoryToTextFile();
return 1;
}

// With much love,
// Chon Beng
int iParser::convertToDigit(string text) {
	int digit;
	istringstream convert(text);
	convert >> digit;

	return digit;
}

/*

void Logic::printItemVector(vector<Item> itemVector){
for (int lineIndex = 0; lineIndex < itemVector.size(); lineIndex++){
printItem(itemVector[lineIndex]);
if (lineIndex < itemVector.size() - 1){
cout << endl;
}
}
return;
}

void Logic::printItem(Item item){
cout << item.getItemName() << '\t';
cout << item.getDescription() << '\t';
//cout << item.getStartTime() << '\t';   Need print function for DateTime
//cout << item.getEndTime() << '\t';
cout << item.getLabel() << '\t';
cout << item.getPriority();
return;
}

DateTime Logic::setDateTime(int year, int month, int day, int hour, int minute){
DateTime datetime;
if (datetime.isValidYearRange(year) && datetime.isValidMonthRange(month) && datetime.isValidDate(day, month, year)
&& datetime.isValidHourRange(hour) && datetime.isValidMinuteRange(minute)){
datetime.setYear(year);
datetime.setMonth(month);
datetime.setDay(day);
datetime.setHour(hour);
datetime.setMinute(minute);
}
return datetime;
}

DateTime Logic::setDateTime(int year, int month, int day){
DateTime datetime;
if (datetime.isValidYearRange(year) && datetime.isValidMonthRange(month) && datetime.isValidDate(day, month, year)){
datetime.setYear(year);
datetime.setMonth(month);
datetime.setDay(day);
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
*/
/*
int Logic::sortTask(){

}


int Logic::changeView(){

}

int Logic::showHelpMenu(){

}
*/
/*
void Logic::assignSaveFolder(){

}
*/
