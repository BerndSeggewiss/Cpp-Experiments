// StrCH11Ex10.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated
// substrings from argument s.

#include "C:/Users/Win11 Pro/OneDrive/Codesammlung/C++/Stroustr Prog - Principles and Practise Using C++/std_lib.h"

vector<string> split(const string& s)
{
	istringstream is(s);
	string str;
	vector<string> substr;
	while (is >> str)
	{
		substr.push_back(str);
	}
	return substr;
}

int countWhitespaces(const string& s)
{
	int count = 0;
	for (char c : s)
	{
		if (isspace(c))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	cout << "Enter a string: ";
	string s;
	getline(cin, s);
	vector<string> substr = split(s);
	for (int i = 0; i < substr.size(); i++)
	{
		cout << substr[i] << endl;
	}
	cout << "Number of whitespaces: " << countWhitespaces(s) << endl;
}