#include "Date.h"

Date::Date()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	day = st.wDay;
	month = st.wMonth;
	year = st.wYear;
}

Date::Date(int day, int month, int year)
{
	SetDayMonthYear(day, month, year);
}

void Date::SetDayMonthYear(int day, int month, int year)
{
	if ((month == JANUARY || month == MARCH || month == MAY || month == JULY || month == AUGUST || month == OCTOBER || month == DECEMBER)
		&& day <= maxDayInMonth1 && day > 0 && year > 0) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else if ((month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) && day <= maxDayInMonth2 && day > 0 && year > 0)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else if (month == FEBRUARY && year % 4 == 0 && year > 0 && day <= maxDayFebruaryLeapYear && day > 0)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else if (month == FEBRUARY && year % 4 != 0 && year > 0 && day <= maxDayFebruary && day > 0)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else
	{
		std::cout << "Incorrect date" << std::endl;
		return;
	}
}

int Date::GetDay() const
{
	return day;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetYear() const
{
	return year;
}

void Date::PrintDate()
{
	std::cout << day << " " << month << " " << year << "\n";
}
