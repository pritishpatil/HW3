#pragma once

#include <iostream>
#include <string>
using namespace std; 

class textfile
{
public:

	textfile(string, int, int, int);
	bool equalityCheck(int, int);
	bool compareLines(int, int);

	string getFilename();
	int getCharacters();
	int getLineamount();
	int getWordcount();

private: 

	int characters;
	int lineAmount;
	int wordCount;
	string fileName;
};

