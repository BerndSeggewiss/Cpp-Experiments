// StrTestOutput.cpp :
// 1. Start a program called Test_output.cpp. Declare an integer birth_year
// and assign it the year you were born.
// 2. Output your birth_year in decimal, hexadecimal, and octal form.
// 3. Label each value with the name of the base used.
// 4. Did you line up your output in columns? If not, do it.
// 5. Now output your age.
// 6. Was there a problem? What happened? Fix your output to be in decimal.
// 7. Go back to 2 and cause the output to show the base for each output.
// 8. Try reading as octal, hexadecimal, etc.
// 9. Write some code to print the number 1234567.89 three times, first using
//    defaultfloat, then fixed, then scientific forms. Which output form presents
//    the number with the most accurate representation?
// 10. Make a simple table including last name, telephone number, and email address
//     for yourself and at least five of your friends. Experiment with different
//     field widths until you are satisfied that the table is well presented.

#include "std_lib.h"

int main()
{
	int birthyear = 1900;
	cout << "Birth Year: " << "\n";
	cout << "Decimal: " << "\t" << showbase << dec << birthyear << "\n";
	cout << "Hexadecimal: " << "\t" << hex << birthyear << "\n";
	cout << "Octadecimal: " << "\t" << oct << birthyear << "\n";
	int Age = 124;
	cout << "Age:" << "\n";
	cout << "Decimal: " << "\t" << dec << Age << "\n";
	cout << "Hexadecimal " << "\t" << hex << Age << "\n";
	cout << "Octadecimal " << "\t" << oct << Age << "\n";

	int a, b, c, d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

	cout << "\n";
	cout << 1234567.89 << "\n";
	cout << fixed << 1234567.89 << "\n";
	cout << fixed << setprecision(2) << 1234567.89 << "\n";
	cout << scientific << 1234567.89 << "\n";

	cout << "\nAdresstable:\n";
	cout << left << setw(15) << "Last Name" << setw(15) << "First Name" <<
		setw(20) << "Phone Number" << setw(30) << "Email Address" << "\n";
	cout << setw(15) << "Smith" << setw(15) << "John" << setw(20) << "123-456-7890"
		<< setw(30) << "john.smith@example.com" << "\n";
	cout << setw(15) << "Doe" << setw(15) << "Jane" << setw(20) << "234-567-8901"
		<< setw(30) << "jane.doe@example.com" << "\n";
	cout << setw(15) << "Johnson" << setw(15) << "Michael" << setw(20) << "345-678-9012"
		<< setw(30) << "michael.johnson@example.com" << "\n";
	cout << setw(15) << "Davis" << setw(15) << "Emily" << setw(20) << "456-789-0123"
		<< setw(30) << "emily.davis@example.com" << "\n";
	cout << setw(15) << "Brown" << setw(15) << "David" << setw(20) << "567-890-1234"
		<< setw(30) << "david.brown@example.com" << "\n";
	cout << setw(15) << "Wilson" << setw(15) << "Sarah" << setw(20) << "678-901-2345"
		<< setw(30) << "sarah.wilson@example.com" << "\n";
}

