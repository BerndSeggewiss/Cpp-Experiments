/*
This Drill simply involves getting the sequence of versions of ‘Date’ to work.
For each version define a Date called today initialized to June 25, 1978. 
Then, define a Date called tomorrow and give it a value by copying today into
it and increasing its day by one using add_day(). Finally, output today and 
tomorrow using a << defined in chapter 9.8.
*/

#include "std_lib_facilities.h"
#include "Chrono.h"

void version941()
{
    using namespace Chrono941;
    Date today;
    cout << "Chapter 9.4.1\n";
    init_day(today, 1978, 5, 8);
    cout << "Today: " << today << endl;
    add_day(today, 1);
    cout << "Tomorrow: " << today << endl;
}

void version942()
{
    using namespace Chrono942;
    Date today(1980, 10, 9);
    cout << "\nChapter 9.4.2\n";
    cout << "Today: " << today << endl;
    Date Tomorrow = today;
    Tomorrow.add_day(1);
    cout << "Tomorrow: " << Tomorrow;
    Date christmas = Date{ 1990, 12, 24 };
    cout << "\nChristmas is on: " << christmas;
    cout << endl;
    // Date today( 12, 24, 2007 );  // Runtime error
    // Date my_birthday;    // Error: my_birthday not initiallized
}

void version943()
{
    using namespace Chrono943;
    cout << "\nChapter 9.4.3\n";
    Date birthday { 2000, 10, 30 };
    //birthday.m = 14;
    cout << "Birthday is on:";
    cout << birthday.day() << ","; // provided way to read private member varibales
    cout << birthday.month() << ",";
    cout << birthday.year();
    cout << endl;
    Date NewDate = { 1980, 1, 1 };
    cout << "New date: " << NewDate;
    Date Tomorrow = NewDate;
    Tomorrow.add_day(1);
    cout << "\nTomorrow is: " << Tomorrow;
}

void version971()
{
    using namespace Chrono971;
    cout << endl;
    cout << "\nChapter 9.7.1";
    cout << endl;
    Date birthday { 2003, Date::jan , 8 };
    cout << "Birthday: " << birthday;
    //Date x1 { 1998, 4, 3 }; // error 2nd argument not a month
    //Date x2 { 1998, 4, Date::mar }; // error 2nd argument not a mont; third arg. not a day
    //Date x3{ Date::dec, 4, 1989 };
    Date x4{ 1998, Date::feb, 28 };
    cout << endl;
    cout << "Date: " << x4 << endl;
    Date DayAfterTomorrow = x4;
    DayAfterTomorrow.add_day(2);
    cout << "Day after Tomorrow: " << DayAfterTomorrow;
}

void version974()
{
    using namespace Chrono974;
    cout << endl;
    cout << "\nChapter 9.7.4";
    const Date cd { 2001, Date::feb, 21 };
    cout << "\nConst day: " << cd.day();
    cout <<"\nConst month: " << cd.month();
    cout << "\nConst year: " << cd.year();
    Date d{ 2000, Date::jan, 20 };
    cout << "\nDate: " << d;
    Date Tomorrow = d;
    Tomorrow.add_day(1);
    cout << "\nTomorrow: " << Tomorrow << endl;
    Date NextYear = d;
    NextYear.add_year(1);
    cout << "Next year: " << NextYear << endl;
}

int main()
{
    version941();
    version942();
    version943();
    version971();
    version974();
}