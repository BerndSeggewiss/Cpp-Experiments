
// Chrono.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "Chrono.h"

namespace Chrono941
{
    void init_day(Date& dd, int y, int m, int d)
    {
        if (m < 1 || m > 12 || d < 1 || y < 1978) error("Invalid");
        dd.y = y;
        dd.m = m;
        dd.d = d;
    }

    void add_day(Date& dd, int x)
    {
        dd.d += x;
    }

    ostream& operator<<(ostream& os, const Date& dd)
    {
        return os << dd.y << ',' << dd.m << ',' << dd.d;
    }
}

namespace Chrono942
{
    Date::Date(int y, int m, int d)
        :y(y), m(m), d(d)
    {
        if (m < 1 || m > 12 || d < 1 || y < 1978) error("Invalid");
    }

    void Date::add_day(int x)
    {
        d += x;
    }

    ostream& operator<<(ostream& os, const Date& dd)
    {
        return os << dd.y << ',' << dd.m << ',' << dd.d;
    }
}

namespace Chrono943
{
    Date::Date(int y, int m, int d)
        :y(y), m(m), d(d)
    {
        if (m < 1 || m > 12 || d < 1 || y < 1978) error("Invalid");
    }

    void Date::add_day(int n)
    {
        d += n;
    }

    ostream& operator<<(ostream& os, Date& date)
    {
        return os << date.year() << "," << date.month() << "," << date.day();
    }
}

namespace Chrono971
{

    Date::Date(int y, Month m, int d)
        :y(y), m(m), d(d)
    {
        if (m < Date::jan || m > Date::dec  || d < 1 || d > 31 || y < 1978) error("Invalid");
    }

    void Date::add_day(int n)
    {
        d += n;
        if (d > 31) error("Invalid day");
    }

    ostream& operator<<(ostream& os, Date& date)
    {
        return os << date.year() << "," << date.month() << "," << date.day();
    }
}

namespace Chrono974
{
    Date::Date(int y, Month m, int d)
        :y(y), m(m), d(d)
    {
        if (m < Date::jan || m > Date::dec || d < 1 || d > 31 || y < 1978) error("Invalid");
    }

    int Date::day() const
    {
        // ++d; // error: not changeable
        return d;
    }

    Date::Month Date::month() const
    {
        return m;
    }

    int Date::year() const
    {
        // ++d; // error: not changeable
        return y;
    }

    void Date::add_day(int x)
    {
        d += x;
        if (d > 31) error("Invalid day");
    }

    void Date::add_year(int x)
    {
        y += x;
    }

    ostream& operator<<(ostream& os, Date& date)
    {
        return os << date.year() << "," << date.month() << "," << date.day();
    }
}



