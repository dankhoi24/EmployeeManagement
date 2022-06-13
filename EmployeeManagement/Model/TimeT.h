#pragma once
#pragma warning(disable:4996)
#include <string>
#include<iostream>


class TimeT {
	std::string m_day;
	std::string m_month;
	std::string m_year;

public:
	TimeT(std::string day, std::string month, std::string year);
	std::string getDate();
	static TimeT getNow();
	void setDate(std::string date);

	friend std::ostream& operator<<(std::ostream& output, const TimeT& input);
};
