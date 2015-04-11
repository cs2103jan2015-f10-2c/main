#ifndef LOG_H
#define LOG_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Log {
private:
	static vector<string> logData;
public:
	void writeToLogFile(string);

};
#endif