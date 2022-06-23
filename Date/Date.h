#pragma once
#include <iostream.>
#include <windows.h>

class Date
{
	int day;
	int month;
	int year;

	static enum MONTH
	{
		JANUARY = 1,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER
	};

	static const int maxDayFebruaryLeapYear = 29;
	static const int maxDayFebruary = 28;
	static const int maxDayInMonth1 = 31;
	static const int maxDayInMonth2 = 30;

public:
	Date();
	Date(int day, int month, int year);

	void SetDayMonthYear(int day, int month, int year);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void PrintDate();
	friend int operator - (const Date& first, const Date& second);
	friend Date operator + (const Date& first, int days);
	friend bool operator < (const Date& first, const Date& second);
	friend bool operator > (const Date& first, const Date& second);
	friend bool operator == (const Date& first, const Date& second);
	friend bool operator != (const Date& first, const Date& second);
};

