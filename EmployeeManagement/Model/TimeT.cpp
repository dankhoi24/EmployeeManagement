#include "TimeT.h"
#include <ctime>
#include <string.h>
#include <cstring>


	 std::ostream &operator<<(std::ostream& output, const TimeT& input) {
		output << input.m_year << "-" << input.m_month << "-" << input.m_day;
		return output;
	}


	 TimeT::TimeT(std::string day, std::string month, std::string year) 
		 :m_day(day), m_month(month), m_year(year){

	}


	 std::string TimeT::getDate() {
		 return m_year + "-" + m_month + "-" + m_day;

	}

	 
	 TimeT TimeT::getNow() {
		 std::time_t time_now = std::time(0);
		 std::tm* now = std::localtime(&time_now);
		 TimeT result(std::to_string(now->tm_year), std::to_string(now->tm_mon), std::to_string(now->tm_mday));
		 return result;


	}


	 void TimeT::setDate(std::string date) {
		 char*sth = strtok(const_cast<char*>(date.c_str()), "-");
	}







