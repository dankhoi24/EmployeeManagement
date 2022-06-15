/**
 * @file TimeT.h
 * @author ndKhoi (nguyen.khoi@hitachivantara.com)
 * @brief header of TimeT represent for time replace for time_t
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#pragma warning(disable:4996)
#include <string>
#include<iostream>

/**
 * @brief TimeT is an alternative class of time_t
 * 
 */
class TimeT {
	std::string m_day;
	std::string m_month;
	std::string m_year;
	// array of month represent for max day in each month
	const int Month[13] = {0, 31,30,31,30,31,30,31,31,30,31,30,31};

public:
	/**
	 * @brief Construct a new Time T object
	 * 
	 * @param day 
	 * @param month 
	 * @param year 
	 */
	TimeT(std::string day, std::string month, std::string year);
	/**
	 * @brief Construct a new Time T object
	 * 
	 */
	TimeT();
	/**
	 * @brief get date represent by string
	 * 
	 * @return std::string 
	 */
	std::string getDate()const;
	/**
	 * @brief convert string to TimtT
	 * 
	 * @param date 
	 * @return true 
	 * @return false 
	 */
	bool setDate(std::string date);
	/**
	 * @brief operator overloading <<
	 * 
	 * @param output 
	 * @param input 
	 * @return std::ostream& 
	 */
	friend std::ostream& operator<<(std::ostream& output, const TimeT& input);
	/**
	 * @brief Get the Now time
	 * 
	 * @return TimeT 
	 */
	static TimeT getNow();
	/**
	 * @brief check string is numeric
	 * 
	 * @param data 
	 * @return true 
	 * @return false 
	 */
	bool isNumeric(const std::string& data)const;
	/**
	 * @brief check is day
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isDay()const;
	/**
	 * @brief check is month
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isMonth()const;
	/**
	 * @brief check is year
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isYear()const;
	/**
	 * @brief check is date
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isDate()const;
	/**
	 * @brief check is leap year
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isLeapYear()const;
};
