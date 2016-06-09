#include "Date.h"

Date::Date(int d, int m, int y)
{
	day = d; month = m; year = y;
}


void Date::Set_day(int val)
{
	day = val;
}

int Date::Get_day()
{
	return day;
}

void Date::Set_month(int val)
{
	month = val;
}

int Date::Get_month()
{
	return month;
}

void Date::Set_year(int val)
{
	year = val;
}

int Date::Get_year()
{
	return year;
}

int Date::No_Of_Days(Date &other)
{
	int t, t1, t2;
	t = other.year - year;
	if (t < 0)
		t *= -1;
	t1 = other.month - month;
	if (t1 < 0)
		t1 *= -1;
	t1 += (t * 12);
	t2 = other.day - day;
	if (t2 < 0)
		t2 *= -1;
	t2 += t1 * 30;

	return t2;
}

Date::~Date()
{
}
