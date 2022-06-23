#include "Date.h"

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
		for (int i = first.month-1; i < months; i++)
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

int main()
{
	Date first(01, 10, 2021);
	Date second(15, 10, 2022);
	std::cout << first - second;
	std::cout <<std::endl;

	Date Three = first + 365;
	Three.PrintDate();

	if (first < second)
		std::cout << "ok!\n";
	else
		std::cout << "no\n";

	if (first > second)
		std::cout << "ok!\n";
	else
		std::cout << "no\n";

	if (first == second)
		std::cout << "ok!\n";
	else
		std::cout << "no\n";

	if (first != second)
		std::cout << "ok!\n";
	else
		std::cout << "no\n";

	Date today;
	today.PrintDate();
}
