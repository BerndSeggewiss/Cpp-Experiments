// StrCh11Ex2_.cpp : 
// Write a program that given a file name and a word outputs each line
// that contains that word together with the line number: Hint getline()

#include "std_lib.h"

void openFile(const string& filename, vector<string>& lines)
{
	ifstream ist(filename.c_str());
	if (!ist) throw runtime_error("Can't open file: " + filename);
	string line;
	int line_number = 0;
	while (getline(ist, line))
	{
		istringstream iss(line);
		string word;
		if (iss >> word && !(iss >> word))
		{
			lines.push_back(line);
			line_number++;
			cout << "line" << line_number << ": " << line << endl;
		}
	}
}

int main()
{
	string filepath = "C:\\Users\\Win11 Pro\\Downloads";
	string file_name = "Text_Ex2.txt";
	string fullpath = filepath + "\\" + file_name;
	string word = "word";
	try
	{
		vector<string> lines;
		openFile(fullpath, lines);
		cout << "File opened successfully." << endl;
	}
	catch (const runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
	}
}

