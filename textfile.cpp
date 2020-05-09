/*
	PIC 10B 2B, Homework 3
	Author: Pritish Patil
	Date: 05/09/2020
*/

#include "textfile.h"

textfile::textfile() 
{
	fileName = "";
	lineAmount = 0;
	wordCount = 0;
	characters = 0;
};

void textfile::setFileInfo(string newFilename, int newLineamount, int newWordcount, int newCharacters)
{
	fileName = newFilename;
	lineAmount = newLineamount;
	wordCount = newWordcount;
	characters = newCharacters;
}

string textfile::getFilename()
{
	return fileName;
}

int textfile::getCharacters()
{
	return characters;
}

int textfile::getLineamount()
{
	return lineAmount;
}

int textfile::getWordcount()
{
	return wordCount;
}

// overloaded operators
bool textfile::operator>(textfile& otherFile)
{
	return lineAmount > otherFile.getLineamount();
}

bool textfile::operator<(textfile& otherFile)
{
	return lineAmount < otherFile.getLineamount();
}

bool textfile::operator==(textfile& otherFile)
{
	return lineAmount == otherFile.getLineamount();
}


