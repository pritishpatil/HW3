

#include <iostream>
#include <fstream>
#include <string>
#include "textfile.h"
using namespace std; 


textfile* processFile(string fileName)
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
        file.close();

        textfile* filePtr = new textfile(fileName, lineCount, wordCount, charCount);
        return filePtr;
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

    cout << "Enter the name of file 1: " << endl;
    cin >> file1;
    
    cout << "Enter the name of file 2: " << endl;
    cin >> file2;
   
  
    textfile* File1Ptr = processFile(file1);
    textfile* File2Ptr = processFile(file2);
    
    ofstream outputFile;
    outputFile.open("Properties.txt");

    outputFile << "Filename: " << File1Ptr->getFilename() << endl;
    outputFile << "Number of Characters: " << File1Ptr->getCharacters() << endl;
    outputFile << "Number of Words: " << File1Ptr->getWordcount() << endl;
    outputFile << endl;
    outputFile << "Filename: " << File2Ptr->getFilename() << endl;
    outputFile << "Number of Characters: " << File2Ptr->getCharacters() << endl;
    outputFile << "Number of Words: " << File2Ptr->getWordcount() << endl;
    outputFile << endl;

    outputFile.close();

    delete File1Ptr;
    delete File2Ptr;
   
    

    return 0;
}

