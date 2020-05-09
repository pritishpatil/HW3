/*
    PIC 10B 2B, Homework 3
    Author: Pritish Patil
    Date: 05/09/2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include "textfile.h"
using namespace std; 


void processFile(string fileName, textfile* filePtr)
{
    fstream file;
    string line;

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    string word;

    file.open(fileName, ios::in);
    if (file.fail())
    {
        cerr << "Error opening file1" << endl;
        exit(1);
    }

    if (file.is_open())
    {
        char current = ' ';
        bool spaceEncountered = false;

        while (!file.eof())
        {
            getline(file, line);
            if (!line.empty())
            {
                for (int i = 0; line[i] != '\0'; i++)
                {
                    current = line[i];
                    if (current == ' ' || current == '\t')
                    {
                        // if space or tab encountered add to wordcount, do not count multiple spaces between words 
                        if (spaceEncountered == false)
                        {
                            wordCount++;
                        }
                        spaceEncountered = true;
                    }
                    else
                    {
                        spaceEncountered = false;
                    }
                }
                charCount += line.length();
                lineCount++;
            }
        }

        // account for final word if there is not a space encountered at end of file
        if (spaceEncountered == false)
        {
            wordCount++;
        }

        file.close();

        filePtr->setFileInfo(fileName, lineCount, wordCount, charCount);
    }
    else
    {
        cerr << "Error opening file!" << endl;
        exit(2);
    }
}


int main()
{

    string file1; string file2;

    // user input 
    cout << "Enter the name of file 1: " << endl;
    cin >> file1;
    
    cout << "Enter the name of file 2: " << endl;
    cin >> file2;
   
    // create textfile objects
    textfile file1Object;
    textfile file2Object;
  
    // process files with helper
    processFile(file1, &file1Object);
    processFile(file2, &file2Object);
    
    // output properties to text file  
    ofstream outputFile;
    outputFile.open("Properties.txt");

    outputFile << "Filename: " << file1Object.getFilename() << endl;
    outputFile << "Number of Characters: " << file1Object.getCharacters() << endl;
    outputFile << "Number of Words: " << file1Object.getWordcount() << endl;
    outputFile << endl;
    outputFile << "Filename: " << file2Object.getFilename() << endl;
    outputFile << "Number of Characters: " << file2Object.getCharacters() << endl;
    outputFile << "Number of Words: " << file2Object.getWordcount() << endl;
    outputFile << endl;

    // compare lines via overloaded operators
    bool compareGreater = file1Object > file2Object;
    bool compareLess = file1Object < file2Object;
    bool checkEqual = file1Object == file2Object;

    // produce comparison result
    if (compareGreater == true)
    {
        outputFile << "The file named " << "\"" << file2Object.getFilename() << "\"" << " has less lines than " << "\"" << file1Object.getFilename() << "\"." << endl;
    }
    else if (compareLess == true)
    {
        outputFile << "The file named " << "\"" << file1Object.getFilename() << "\"" << " has less lines than " << "\"" << file2Object.getFilename() << "\"." << endl;
    }
    else if (checkEqual == true)
    {
        outputFile << "\"" << file1Object.getFilename() << "\"" << " has the same number of lines as " << "\"" << file2Object.getFilename() << "\"." << endl;
    }

    outputFile.close();

    return 0;
}

