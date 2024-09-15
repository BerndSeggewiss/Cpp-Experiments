// StrCh10Ex11.cpp : 
// Wite a program that produces the sum of all the whitespace-separted 
// integers in text file, bears: 17 elephants 9 end.

#include "std_lib_facilities.h"

int main()
{
    string filePath = "C:\\Users\\Win11 Pro\\Downloads";
    string fileName = "fileCh10Ex11.txt";
    string fullFilePath1 = filePath + "\\" + fileName;
    ifstream file(fullFilePath1);
    if (!file.is_open())
    {
        cerr << "One or more of the files could not be opened" << endl;
        return 1;
    }
    int sum = 0;
    string word;
    while (file >> word)
    {
        try
        {
			int number = stoi(word);
            sum += number;
        }
        catch (invalid_argument&)
        {

        }
    }
	cout << "The sum of the numbers in the file is: " << sum << endl;
}