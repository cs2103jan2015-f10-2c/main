//@author A0105180W
// Log
// Group : F10-2C
// Coder : Shri Kishen Rajendran
#ifndef LOG_H
#define LOG_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Log {	
public:
	void writeToLogFile(string);
	void clearLogFile();
};
#endif