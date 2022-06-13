#include "TimeT.h"
#include <ctime>
#include <string.h>
#include <cstring>
#include <vector>


	 std::ostream &operator<<(std::ostream& output, const TimeT& input) {
		output << input.m_year << "-" << input.m_month << "-" << input.m_day;
		return output;
	}


	 TimeT::TimeT(std::string day, std::string month, std::string year) 
		 :m_day(day), m_month(month), m_year(year){

	}


	 std::string TimeT::getDate()const {
		 return m_year + "-" + m_month + "-" + m_day;

	}

	 
	 TimeT TimeT::getNow() {
		 std::time_t time_now = std::time(0);
		 std::tm* now = std::localtime(&time_now);
		 TimeT result(std::to_string(now->tm_year), std::to_string(now->tm_mon), std::to_string(now->tm_mday));
		 return result;
	}


	 bool TimeT::setDate(std::string date) {
		 size_t pos = 0;
		 std::string temp_str = "";
		 int count = 0;
		 std::vector<std::string> list_date;





		 while ((pos = date.find("-")) != std::string::npos) {
			 temp_str = date.substr(0, pos);
			 if (count == 3) {
				 return false;
			 }
			 list_date.push_back(temp_str);
			 count++;

			 date.erase(0, pos + 1);
		 }
		 
			 list_date.push_back(date);
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
		 while (it != data.end() && std::isdigit(*it)) {
			 ++it;
		 }
		 return	!data.empty() && it == data.end();
	 }


	  bool TimeT::isDay() const{
			
		 if (!isNumeric(m_day)) return false;
		 int day = atoi(m_day.c_str());

		 return day >= 1 && day <= 31;
	 }
	 bool TimeT::isMonth() const{
		 if (!isNumeric(m_month)) return false;
		 int month = atoi(m_month.c_str());

		 return month >= 1 && month <= 12;
	 }
	  bool TimeT::isYear() const{

		 if (!isNumeric(m_year)) return false;
		 return m_year.length() == 4;
		 
	 }


	  bool TimeT::isLeapYear()const {
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
		  if (isDay() && isMonth() && isYear()) {
			  if (Month[atoi(m_month.c_str())] >= atoi(m_day.c_str())) {
				  if (isLeapYear()) {
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


	  TimeT::TimeT() :m_day("01"), m_month("01"), m_year("0001"){
		  
	}




