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
#include <iostream>
#include "TimeT.h"
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
	TimeT m_start_date;
	TimeT m_end_date;
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
	Employee(int ID,  String name, String phone, String address, String mail, char gender, TimeT start_date, TimeT end_date, bool is_working, int title_ID);
	
	/**
	 * @brief Constructor
	 * 
	 */
	Employee();

	
	/**
	 * @brief Destroy the Employee object
	 * 
	 */
	~Employee();



	std::string wtime( TimeT t)const;
	

	int getId();

	void setId(int id);
	void setName(std::string name);
	void setAddess(std::string address);
	void setPhone(std::string phone);
	void setMail(std::string mail);
	void setGender(char gender);
	void setStartDate(std::string date);
	void setEndDate();
	void setRole(std::string role);


	std::string getName()const;
	std::string getAddress()const;
	std::string getPhone()const;
	std::string getMail()const;
	std::string getGender()const;
	std::string getStartDate()const;
	std::string getEndDate()const;
	std::string getRole()const;



	//Employee& operator=(const Employee& other) {
	//	std::cout << "=== \n";

	//	m_ID = other.m_ID;
	//	m_name = other.m_name;
	//	m_phone = other.m_phone;
	//	m_address = other.m_address;
	//	m_mail = other.m_mail;
	//	m_gender = other.m_gender;
	//	m_start_date = other.m_start_date;
	//	m_end_date = other.m_end_date;
	//	m_is_working = other.m_is_working;
	//	m_title_ID = other.m_title_ID;

	//	return *this;
	//	
	//}

	



};
