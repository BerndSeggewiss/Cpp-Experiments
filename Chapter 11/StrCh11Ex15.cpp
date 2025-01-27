// StrCh11Ex15.cpp :
// Write a program that reads a file of whitespaced-separated numbers and outputs a file of
// numbers using scientific format and precision 8 in four fields of 20 characters per line.

#include "C:\Users\Win11 Pro\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\std_lib.h"

void outputPrecisionFormat()
{
	string fullFilePath = "C:\\Users\\Win11 Pro\\Downloads\\TextfileCH11Ex15.txt";
	ifstream ifs(fullFilePath);
	if (!ifs) error("Error: File could not be opened.");
	string line;
	vector<double> numbers;
	while (getline(ifs, line))
	{
		replace(line.begin(), line.end(), ',', '.');
		stringstream ss(line);
		double number;
		while (ss >> number)
		{
			numbers.push_back(number);
		}
	}
	ifs.close();
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << scientific << setprecision(8) << setw(20) << numbers[i];
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
}

int main()
{
	try
	{
		outputPrecisionFormat();
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << endl;
		return 1;
	}
}

