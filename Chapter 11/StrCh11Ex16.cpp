// StrCh11Ex16.cpp : 
// Write a program to read a file of whitespace-separated numbers and output them in order (lowest value first),
// one value per line. Write a value only once, and if ot occurs more than once write the count of its occurrences 
// on its line. For example, 7 5 5 7 3 117 5 should give
// 3
// 5 3
// 7 2
// 117

#include "C:\Users\Win11 Pro\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\std_lib.h"

void countNumberOccurences()
{
	string fullFilePath = "C:\\Users\\Win11 Pro\\Downloads\\TextfileCH11Ex16.txt";
	ifstream ifs(fullFilePath);
	if (!ifs) error("Error: File could not be opened.");
	vector<int> numbers;
	int number;
	for (int number; ifs >> number;)
	{
		numbers.push_back(number);
	}
	ifs.close();
	sort(numbers.begin(), numbers.end());
	numbers;
	int count = 1;
	for (int i = 0; i < numbers.size(); ++i)
	{
		//cout << "num: " << numbers[i] << " i = " << i << endl;
		if (i < numbers.size() - 1 && numbers[i] == numbers[i + 1])
			count++;
		else
		{
			if (count > 1)
				cout << numbers[i] << " " << count << endl;
			else
				cout << numbers[i] << endl;
			count = 1;
		}
	}
}

int main()
{
	try
	{
		countNumberOccurences();
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << endl;
		return 1;
	}
}
