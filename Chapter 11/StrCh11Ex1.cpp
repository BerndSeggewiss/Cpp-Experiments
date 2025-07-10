// StrCh11Ex1.cpp :
// Write a program that reads a text file and convert its input to all
// lower case, producing a new file. 

#include "std_lib.h"

vector<string> readDataFromTextFile(const string& filename)
{
	ifstream ist(filename.c_str());
	if (!ist) throw runtime_error("Can't open file: " + filename);
	vector<string> lines;
	string line;
	while (getline(ist, line))
	{
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		lines.push_back(line);
	}
	return lines;
}

void writeDataToTextFile(const string& filename, const vector<string>& lines)
{
	ofstream ost(filename.c_str());
	if (!ost) throw runtime_error("Can't open file: " + filename);
	for (const string& line : lines)
	{
		ost << line << "\n";
	}
}

int main()
{
	string inputFilename = "Text.txt";
	string outputFilename = "TextLower.txt";
	try
	{
		vector<string> lines = readDataFromTextFile(inputFilename);
		writeDataToTextFile(outputFilename, lines);
		cout << "File converted successfully from " << inputFilename << " to " << outputFilename << endl;
	}
	catch (const runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
	}
}
