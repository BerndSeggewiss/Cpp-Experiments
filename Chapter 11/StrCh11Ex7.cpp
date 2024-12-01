// StrCH11EX7.cpp : 
// Modify the program from the previous excercise so that 
// it replaces don’t with do not, can’t with can not, etc.; 
// leaves hyphens within words intact, so that we get 
// 'do not use the as-if rule'; and converts all characters to lower case.

#include "std_lib.h"

vector<string> readFile()
{
	string filePath = "C:\\Users\\Win11 Pro\\Downloads";
	string fileName = "FileStrCH11EX7.txt";
	string fullFilePath = filePath + "\\" + fileName;
	ifstream file(fullFilePath);
	if (!file)
	{
		error("Error opening file: ", fullFilePath);
	}
	vector<string> lines;
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}

string replaceWords(const string& text)
{
	stringstream ss(text);
	string word;
	string result;
	while (ss >> word)
	{
		for (char& c : word)
		{
			c = tolower(c);
		}
		if (word == "don't" || word == "Don't")
		{
			word = "do not";
		}
		if (word == "can't" || word == "Can't")
		{
			word = "can not";
		}
		result += word + " ";
	}
	if (!result.empty())
	{
		result.pop_back();
	}
	return result;
}

int main()
{
	try
	{
		vector<string> lines = readFile();
		for (string& line : lines)
		{
			line = replaceWords(line);
			cout << line << endl;
		}
	}
	catch (const runtime_error& e)
	{
		cerr << e.what() << endl;
	}
}

