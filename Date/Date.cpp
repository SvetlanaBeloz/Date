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

int operator - (const Date& first, const Date& second)
{
	int result = 0;
	int daysInYear = 365;
	int daysInLeapYear = 366;
	int yearDifference = second.year - first.year - 1;
	int year = first.year;
	for (int i = 0; i < yearDifference; i++) {
		if (year % 4 == 0 || year % 400 == 0 && year % 100 == 0)
			result += daysInLeapYear;
		else
			result += daysInYear;
		year++;
	}
	if (first.month == second.month && yearDifference == 0) {
		if (year % 4 == 0 || year % 400 == 0 && year % 100 == 0)
			result += daysInLeapYear;
		else
			result += daysInYear;
	}
	const int months = 12;
	int daysInMonth[months]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (first.month == second.month)
		result += 0;
	else {
		if (year % 4 == 0 || year % 400 == 0 && year % 100 == 0)
			daysInMonth[1] = 29;
		for (int i = first.month - 1; i < months; i++)
			result += daysInMonth[i];
		for (int i = 0; i < second.month - 2; i++)
			result += daysInMonth[i];
	}
	if (first.day == second.day) {
		result += 0;
	}
	else if (first.month == second.month)
		result += second.day - first.day;
	else {
		result += daysInMonth[second.month - 1] - first.day + second.day;
	}
	return result;
}

Date operator + (const Date& first, int days)
{
	int day = first.day;
	int month = first.month;
	int year = first.year;
	while (days != 0) {

		if (day == Date::maxDayInMonth1 && (month == Date::JANUARY || month == Date::MARCH || month == Date::MAY || month == Date::JULY
			|| month == Date::AUGUST || month == Date::OCTOBER) || day == Date::maxDayInMonth2 && (month == Date::APRIL || month == Date::JUNE
				|| month == Date::SEPTEMBER || month == Date::NOVEMBER) || day == Date::maxDayFebruaryLeapYear &&
			(month == Date::FEBRUARY && year % 4 == 0) || day == Date::maxDayFebruary && (month == Date::FEBRUARY && year % 4 != 0))
		{
			day = 1;
			month++;
		}
		else if (day == Date::maxDayInMonth1 && month == Date::DECEMBER)
		{
			day = 1;
			month = 1;
			year++;
		}
		else
		{
			day++;
		}
		days--;
	}
	Date another(day, month, year);
	return another;
}

bool operator < (const Date& first, const Date& second)
{
	if (first.year < second.year)
		return true;
	else if (first.year == second.year && first.month < second.month)
		return true;
	else if (first.year == second.year && first.month == second.month && first.day < second.day)
		return true;
	else return false;
}

bool operator > (const Date& first, const Date& second)
{
	if (first.year > second.year)
		return true;
	else if (first.year == second.year && first.month > second.month)
		return true;
	else if (first.year == second.year && first.month == second.month && first.day > second.day)
		return true;
	else return false;
}

bool operator == (const Date& first, const Date& second)
{
	return  first.year == second.year && first.month == second.month && first.day == second.day;
}

bool operator != (const Date& first, const Date& second)
{
	return first.year != second.year || first.month != second.month || first.day != second.day;
}

std::istream& operator >> (std::istream& is, Date& original)
{
	std::cout << "Please enter day: ";
	is >> original.day;
	std::cout << "Please enter month: ";
	is >> original.month;
	std::cout << "Please enter year: ";
	is >> original.year;
	return is;
}

std::ostream& operator << (std::ostream& os, Date& original)
{
	os << original.day << " " << original.month << " " << original.year << "\n";
	return os;
}
