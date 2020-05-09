/*
	PIC 10B 2B, Homework 3
	Author: Pritish Patil
	Date: 05/09/2020
*/

#pragma once

#include <iostream>
#include <string>
using namespace std; 

class textfile
{
public:

	textfile();
	void setFileInfo(string, int, int, int);
	string getFilename();
	int getCharacters();
	int getLineamount();
	int getWordcount();
	bool operator>(textfile&);
	bool operator<(textfile&);
	bool operator==(textfile&);


private: 

	int characters;
	int lineAmount;
	int wordCount;
	string fileName;
};

