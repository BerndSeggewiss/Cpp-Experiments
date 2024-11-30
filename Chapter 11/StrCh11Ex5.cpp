// StrCH11Ex5.cpp :
// Write a program that reads strings and for each string outputs the 
// character classification of each character, as defined by the character classification
// in chapter 11.6. Note that a character can have several classification (e.g., x is both
// a letter and an alphanumeric).

#include "std_lib.h"

void classifyCharacters(const string& input)
{
	string classifications;
	for (char ch : input)
	{
		if (isalpha(ch))
		{
			cout << "Character: " << ch;
			classifications += " - Alphabetical";
			{
				if (isupper(ch))
				{
					classifications += " ,- Uppercase";
					cout << classifications << "\n";
				}
				if (islower(ch))
				{
					classifications += " ,- Lowercase";
					cout << classifications << "\n";
				}
			}
			classifications = "";
		}
		if (isdigit(ch))
		{
			cout << "Character: " << ch;
			classifications += " - Digit";
			cout << classifications << "\n";
			classifications = "";
		}
		if (isspace(ch))
		{
			cout << "Character: " << ch;
			classifications += " - Whitespace";
			cout << classifications << "\n";
			classifications = "";
		}
		if (ispunct(ch))
		{
			cout << "Character: " << ch;
			classifications += " - Punctuation";
			cout << classifications << "\n";
			classifications = "";
		}
	}
}

int main()
{
	string input;
	cout << "Enter a string: ";
	getline(cin, input);
	classifyCharacters(input);
}

