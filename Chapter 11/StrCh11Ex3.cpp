// StrCh11Ex3.cpp :
// Write a program that remove all vowels from a file. For example,
// 'Once upon a time!' becomes 'nc pn tm!'.

#include "std_lib.h"

// Vowels: A, E, I, O, U

string removeVowels(const string& line)
{
	string result;
	for (char c : line)
	{
		if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
			c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
		{
			result += c;
		}
	}
	return result;
}

void openFile(const string& filename, vector<string>& lines)
{
	ifstream ifs(filename.c_str());
	if (!ifs) throw runtime_error("Unable to open file " + filename);
	string line;
	while (getline(ifs, line))
	{
		line = removeVowels(line);
		lines.push_back(line);
	}
}

int main()
{
	string filepath = "C:\\Users\\Win11 Pro\\Downloads";
	string filename = "text_Ex3.txt";
	string fullpath = filepath + "\\" + filename;
	try
	{
		vector<string> lines;
		openFile(fullpath, lines);
		cout << "File content without vowels:" << endl;
		for (const string& line : lines)
		{
			cout << line << endl;
		}
	}
	catch (const runtime_error& e)
	{
		cerr << e.what() << endl;
	}
}

