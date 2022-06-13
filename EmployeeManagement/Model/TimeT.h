#pragma once
#pragma warning(disable:4996)
#include <string>
#include<iostream>


class TimeT {
	std::string m_day;
	std::string m_month;
	std::string m_year;

	const int Month[13] = {0, 31,30,31,30,31,30,31,31,30,31,30,31};

public:
	TimeT(std::string day, std::string month, std::string year);
	TimeT();
	std::string getDate()const;
	bool setDate(std::string date);

	friend std::ostream& operator<<(std::ostream& output, const TimeT& input);

	static TimeT getNow();

	bool isNumeric(const std::string& data)const;
	bool isDay()const;
	bool isMonth()const;
	bool isYear()const;
	bool isDate()const;
	bool isLeapYear()const;
};
