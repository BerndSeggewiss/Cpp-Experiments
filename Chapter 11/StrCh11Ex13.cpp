/// StrCH11Ex13.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Reverse the order of words (defined as whitespace-separated strings) in a file. For example,
// 'Norwegian Blue parrot' becomes 'parrot Blue Norwegian'.

#include "C:\Users\Win11 Pro\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\std_lib.h"

void reverseOrderOfWordsinFile()
{
	string fullFilePath = "C:\\Users\\Win11 Pro\\Downloads\\TextfileCH11Ex13.txt";
	ifstream ifs(fullFilePath);
	if (!ifs)
		error("can't open input file", fullFilePath);
	vector<string> words;
	for (string word; ifs >> word;)
	{
		words.push_back(word);
	}
	string reversedContent;
	for (int i = words.size(); i > 0; --i)
	{
		reversedContent += words[i - 1] + " ";
	}
	ifs.close();
	cout << "Reversed Text: " << reversedContent << '\n';
	string fullOutputFilePath = "C:\\Users\\Win11 Pro\\Downloads\\ReversedTextCH11Ex13.txt";
	ofstream ofs(fullOutputFilePath);
	if (!ofs)
		error("can't open output file", fullOutputFilePath);
	ofs << reversedContent;
	ofs.close();
}

int main()
{
	try
	{
		reverseOrderOfWordsinFile();
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
}

