/**
 * @file Employee.h
 * @author ndKhoi (nguyen.khoi@hitachivantara.com)
 * @brief Model of Employee
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <string>
#include <ctime>
// macro represent std::string -> String
#define String std::string


/**
 * @brief  Model of Employ
 * 
 */
class Employee {
private:
	int m_ID;
	String m_name;
	String m_phone;
	String m_address;
	String m_mail;
	char m_gender;
	std::time_t m_start_date;
	std::time_t m_end_date;
	bool m_is_working;
	int m_title_ID;

public:
	/**
	 * @brief Construct a new Employee object
	 * 
	 * @param ID 
	 * @param name 
	 * @param phone 
	 * @param address 
	 * @param mail 
	 * @param gender 
	 * @param start_date 
	 * @param end_date 
	 * @param is_working 
	 * @param title_ID 
	 */
	Employee(int ID, const String &name, const String &phone, const String &address, const String &mail, char gender, time_t start_date, time_t end_date, bool is_working, int title_ID);
	
	/**
	 * @brief Destroy the Employee object
	 * 
	 */
	~Employee();





};
