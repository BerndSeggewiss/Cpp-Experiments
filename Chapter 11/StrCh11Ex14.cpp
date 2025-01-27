// StrCH11Ex14.cpp : Write a program that reads a text file and writes out how many characters
// of each character classification are in the file.

#include "C:\Users\Win11 Pro\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\std_lib.h"

void characterClassifiction()
{
	string fullFilePath = "C:\\Users\\Win11 Pro\\Downloads\\TextfileCH11Ex14.txt";
	ifstream ifs(fullFilePath);
	if (!ifs)
		error("Can't opnen input file: !", fullFilePath);
	char ch;
	int space = 0;
	int alpha = 0;
	int digit = 0;
	int xdigit = 0;
	int upper = 0;
	int lower = 0;
	int alnum = 0;
	int punct = 0;

	while (ifs.get(ch))
	{
		if (isspace(ch))
			++space;
		if (isalpha(ch))
			++alpha;
		if (isdigit(ch))
			++digit;
		if (isxdigit(ch))
			++xdigit;
		if (isupper(ch))
			++upper;
		if (islower(ch))
			++lower;
		if (isalnum(ch))
			++alnum;
		if (ispunct(ch))
			++punct;
	}

	cout << "Space: " << space << endl;
	cout << "Alpha: " << alpha << endl;
	cout << "Digit: " << digit << endl;
	cout << "XDigit: " << xdigit << endl;
	cout << "Upper: " << upper << endl;
	cout << "Lower: " << lower << endl;
	cout << "Alnum: " << alnum << endl;
	cout << "Punct: " << punct << endl;
}

int main()
{
	try
	{
		characterClassifiction();
	}
	catch (exception& e)
	{
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
}

