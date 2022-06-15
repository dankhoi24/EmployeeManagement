/**
 * @file TimeT.cpp
 * @author ndKhoi (nguyen.khoi@hitachivantara.com)
 * @brief TimeT is an alternative class time_t 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TimeT.h"
#include <ctime>
#include <string.h>
#include <cstring>
#include <vector>


	 std::ostream &operator<<(std::ostream& output, const TimeT& input) {
		// print date follow format YYYY-DD-MM
		output << input.m_year << "-" << input.m_month << "-" << input.m_day;
		return output;
	}


	 TimeT::TimeT(std::string day, std::string month, std::string year) 
		 :m_day(day), m_month(month), m_year(year){

	}


	 std::string TimeT::getDate()const {
		// return date as string follow format YYYY-MM-DD
		 return m_year + "-" + m_month + "-" + m_day;

	}

	 
	 TimeT TimeT::getNow() {
		 //get time now
		 std::time_t time_now = std::time(0);
		// convert time_t to tm
		 std::tm* now = std::localtime(&time_now);
		// init TimeT by time_t
		 TimeT result(std::to_string(now->tm_year), std::to_string(now->tm_mon), std::to_string(now->tm_mday));
		 // return TimeT
		 return result;
	}

	
	 bool TimeT::setDate(std::string date) {
		 // position of "-" character
		 size_t pos = 0;
		 // store sub string 
		 std::string temp_str = "";
		 // count string after each time slpit by "-"
		 int count = 0;
		 // store date
		 std::vector<std::string> list_date;




		// slpit string untill the end (separate by "-")
		 while ((pos = date.find("-")) != std::string::npos) {
			 // get string after slpit
			 temp_str = date.substr(0, pos);
			 // it string contain 3 "-" => return false
			 if (count == 3) {
				 return false;
			 }
			 // push date to vectore
			 list_date.push_back(temp_str);
			 // increate count each time slpit
			 count++;
			// delete string after split
			 date.erase(0, pos + 1);
		 }
		 	// push last string to vector
			 list_date.push_back(date);
			 // if string contain 2 "-" => valid string
		 if (count == 2) {
			 m_day = list_date[0]; 
			 m_month = list_date[1];
			 m_year = list_date[2];
			 return isDate();
		 }
		 return false;
			 
	 }

	
	 bool TimeT::isNumeric(const std::string &data) const{
		 std::string::const_iterator it = data.begin();
		 // check each character in string in is numeric
		 while (it != data.end() && std::isdigit(*it)) {
			 ++it;
		 }
		// if travel all string and string not empyt => true
		 return	!data.empty() && it == data.end();
	 }


	  bool TimeT::isDay() const{
			// check numeric
		 if (!isNumeric(m_day)) return false;
		 int day = atoi(m_day.c_str());
		// check valid day
		 return day >= 1 && day <= 31;
	 }
	 bool TimeT::isMonth() const{
		 // check numeric
		 if (!isNumeric(m_month)) return false;
		 int month = atoi(m_month.c_str());
		// check valid month
		 return month >= 1 && month <= 12;
	 }
	  bool TimeT::isYear() const{
		// check numeric
		 if (!isNumeric(m_year)) return false;
		 // check string length == 4
		 return m_year.length() == 4;
		 
	 }


	  bool TimeT::isLeapYear()const {
		// check leap year
		  int year = atoi(m_year.c_str());
		  if (year % 400==0) {
			  return true;
		  }

		  if (year % 100 == 0) {
			  return false;
		  }
		  if (year % 4 == 0) {
			  return true;
		  }

		  return false;
	}

	  bool TimeT::isDate() const{
			// check day, month and year valid
		  if (isDay() && isMonth() && isYear()) {
			// check day valid with relative month
			  if (Month[atoi(m_month.c_str())] >= atoi(m_day.c_str())) {
				  // check leap year
				  if (isLeapYear()) {
					// check february in leap year
					  if (atoi(m_month.c_str()) == 2) {
						  return atoi(m_day.c_str()) <= 29;
					  }
					  else {
						  return true;
					  }
				  }
				  else {
					  return true;
				  }
			  }
		}
	 }

		// init date = 0001-01-01
	  TimeT::TimeT() :m_day("01"), m_month("01"), m_year("0001"){
		  
	}




