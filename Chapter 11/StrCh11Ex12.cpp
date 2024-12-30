// StrCH11Ex12.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Reverse the orders of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa. 

#include "C:\Users\Win11 Pro\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\std_lib.h"

void reverseOrderOfCharactersinFile()
{
	string FilePath = "C:\\Users\\Win11 Pro\\Downloads";
	string FileName = "TextfileCH11Ex12.txt";
	string fullFilePath = FilePath + "\\" + FileName;
	ifstream ifs(fullFilePath);
	if (!ifs)
		error("can't open input file", fullFilePath);
	string content((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
	ifs.close();
	int n = content.length();
	string reversedContent;
	for (int i = n; i > 0; --i)
	{
		reversedContent += content[i - 1];
	}
	cout << "Reversed Text: " << reversedContent << '\n';
	string outputFileName = "ReversedText_" + FileName;
	string outputFilePath = FilePath + "\\" + outputFileName;
	ofstream ofs(outputFilePath);
	if (!ofs)
		error("can't open output file", outputFilePath);
	ofs << reversedContent;
	ofs.close();
}

int main()
{
	try
	{
		reverseOrderOfCharactersinFile();
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
}


