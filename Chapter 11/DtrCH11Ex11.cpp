// StrCH11Ex11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a funtion vector <string> split(const& s, const string& w) that returns a vector of whitespce-separated 
// substrings from the argument of s, where whitespace is defined as "ordinary whitespace" plus the characters in w.


#include "C:/Users/Win11 Pro/OneDrive/Codesammlung/C++/Stroustr Prog - Principles and Practise Using C++/std_lib.h"

vector<string> split(const string& s, const string& w)
{
    string temp = s;
	for (int i = 0; i < temp.size(); ++i)
	{
		bool found = false;
		for (int j = 0; j < w.size(); ++j)
		{
			if (temp[i] == w[j])
			{
				found = true;
				break;
			}
		}
		if (found)
			temp[i] = ' ';
	}
	vector<string> result;
	istringstream is(temp);
	string word;
	while (is >> word)
	{
		result.push_back(word);
	}
	return result;
}

int main()
{
	cout << "Enter a string with seperation characters: ";
	string s;
    string w = ",&!.";
	while (getline(cin, s))
	{
		vector<string> v = split(s, w);
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
	}
}

