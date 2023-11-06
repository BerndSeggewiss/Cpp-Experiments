#pragma once
#include "std_lib_facilities.h"

namespace Chrono941
{
	struct Date
	{
		int y;
		int m;
		int d;
	};
	void init_day(Date& dd, int y, int m, int d);
	void add_day(Date& dd, int x);
	ostream& operator<<(ostream& os, const Date& dd);
}

namespace Chrono942
{
	struct Date
	{
		int y, m, d;
		Date(int y, int m, int d);
		void add_day(int x);
	};
	ostream& operator<<(ostream& os, const Date& dd);
}

namespace Chrono943
{
	class Date
	{
	private:
		int y, m, d;
	public:
		Date(int y, int m, int d);
		void add_day(int n);
		int year() { return y; }
		int month() { return m; }
		int day() { return d; }
	};
	ostream& operator<<(ostream& os, Date& date);
}

namespace Chrono971
{
	class Date
	{
	public:
		enum Month
		{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
		Date(int y, Month m, int d);
		void add_day(int n);
		int year() { return y; }
		Month month() { return m; }
		int day() { return d; }

	private:
		int y;
		Month m;
		int d;
	};
	ostream& operator<<(ostream& os, Date& date);
}

namespace Chrono974
{
	class Date
	{
	public:
		enum Month
		{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
		Date(int y, Month m, int d);

		int day() const;
		Month month() const;
		int year() const;

		void add_day(int x);
		void add_year(int x);

	private:
		int y;
		Month m;
		int d;
	};
	ostream& operator<<(ostream& os, Date& date);
}


