#include "textfile.h"

textfile::textfile(string newFilename, int newLineamount, int newWordcount, int newCharacters)
{
	fileName = newFilename;
	lineAmount = newLineamount;
	wordCount = newWordcount;
	characters = newCharacters;
}

bool textfile::equalityCheck(int a, int b)
{
	if (a == b)
	{
		return true;
	}
	return false;
}

bool textfile::compareLines(int x, int y)
{
	if (x > y)
	{
		return true;
	}
	return false;
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


