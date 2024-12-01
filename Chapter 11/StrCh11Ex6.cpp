// StrCH11Ex6.cpp :
// Write a program that replaces punctuation with whitespace. 
// Consider .(dot), ;(semicolon), ,(comma), ?(question mark), -(dash), 
// '(single quote) and "(double quote). Don't modify characters within 
// a pair of double quotes (").

#include "std_lib.h"

vector<string> readFile()
{
	string filePath = "C:\\Users\\Win11 Pro\\Downloads";
	string fileName = "FileStrCH11EX6.txt";
	string fullFilePath = filePath + "\\" + fileName;
	ifstream file(fullFilePath);
	vector<string> lines;
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}
string replacePunctuation(const string& text)
{
	string result = text;
	bool insideQuotes = false;
	int count = 0, r;
	for (char& ch : result)
	{
		if (ch == '"')
		{
			count++;
			r = (count % 2);
			insideQuotes = (r == 1);
			if (insideQuotes)
			{
				insideQuotes = true;
			}
			else
			{
				insideQuotes = false;
			}
		}
		if (insideQuotes)
		{
			continue;
		}
		else if (!insideQuotes)
		{
			if (ch == '.' || ch == ';' || ch == ',' ||
				ch == '?' || ch == '-' || ch == '\'')
			{
				ch = ' ';
			}
		}
	}
	return result;
}

int main()
{
	vector<string> lines = readFile();
	string text;
	for (const string& line : lines)
	{
		text += line + "\n";
	}
	string modifiedText = replacePunctuation(text);
	cout << modifiedText << endl;
}
