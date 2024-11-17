// StrCh11Ex4.cpp :
// Write a program that prompts a user the user to enter integers in any combination of
// decimal, octal, or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers
// correctly and converts them to decimal form. Then output the values in properly spaced columns.

#include "std_lib.h"

int main()
{
	string input;
	string token;
	cout << "Enter decimal, hexadecimal or octal number (separated by whitespace):\n";
	getline(cin, input);
	istringstream iss(input);
	cout << endl;
	while (iss >> token)
	{
		int number = 0;
		if (token.find("0x") == 0 || token.find("0X") == 0)
		{
			if (all_of(token.begin() + 2, token.end(), ::isxdigit))
			{
				istringstream(token) >> hex >> number;
				cout << token << " is hexadecimal" << setw(10) << "Decimal:" << number << endl;
			}
			else
				cout << token << " is wrong hexadecimal input\n";
		}
		else if (token[0] == '0' && token.size() > 1)
		{
			if (all_of(token.begin() + 2, token.end(), ::isdigit))
			{
				istringstream(token) >> oct >> number;
				cout << token << " is octadecimal" << setw(10) << "Decimal:" << number << endl;
			}
			else
				cout << token << " is wrong octadecimal input\n";
		}
		else
		{
			istringstream(token) >> number;
			cout << token << " is decimal" << setw(10) << "Decimal:" << number << endl;
		}

	}
}

