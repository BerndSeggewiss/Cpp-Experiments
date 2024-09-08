// StrCh10Ex8.cpp : 
// Write a program that taketwo file names and produces a new file that is
// contents of the first file followed by  the contend of the second; that 
// is the program concatenates the two files. 

#include "std_lib_facilities.h"

int main()
{
    string filePath = "C:\\Users\\Win11 Pro\\Downloads";
    string fileName1 = "file1.txt";
    string fileName2 = "file2.txt";
    string outputFileName = "FilesMerged.txt";
    string fullFilePath1 = filePath + "\\" + fileName1;
    string fullFilePath2 = filePath + "\\" + fileName2;
    string fullOutputFilePath = filePath + "\\" + outputFileName;
    ifstream file1(fullFilePath1.c_str());
    ifstream file2(fullFilePath2.c_str());
    ofstream outputFile(fullOutputFilePath.c_str());

    if (!file1.is_open() || !file2.is_open())
    {
        cerr << "One or more of the files could not be openend";
    }

    string line;
    while (getline(file1, line))
    {
        outputFile << line << "\n";
    }

    while (getline(file2, line))
    {
        outputFile << line << "\n";
    }

    file1.close();
    file2.close();
    outputFile.close();
}
