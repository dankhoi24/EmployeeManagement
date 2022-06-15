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
#include "../Lib/ColorLib.h"
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
	

	/**
	 * @brief Set the Id object
	 * 
	 * @param id 
	 */
	void setId(int id);
	/**
	 * @brief Set the Name object
	 * 
	 * @param name 
	 */
	void setName(std::string name);
	/**
	 * @brief Set the Addess object
	 * 
	 * @param address 
	 */
	void setAddess(std::string address);
	/**
	 * @brief Set the Phone object
	 * 
	 * @param phone 
	 */
	void setPhone(std::string phone);
	/**
	 * @brief Set the Mail object
	 * 
	 * @param mail 
	 */
	void setMail(std::string mail);
	/**
	 * @brief Set the Gender object
	 * 
	 * @param gender 
	 */
	void setGender(char gender);
	/**
	 * @brief Set the Start Date object
	 * 
	 * @param date 
	 * @return true 
	 * @return false 
	 */
	bool setStartDate(std::string date);
	/**
	 * @brief Set the End Date object
	 * 
	 * @param date 
	 */
	void setEndDate(std::string date);
	/**
	 * @brief Set the Role object
	 * 
	 * @param role 
	 */
	void setRole(std::string role);

	/**
	 * @brief Get the Id object
	 * 
	 * @return int 
	 */
	int getId();
	std::string getName()const;
	/**
	 * @brief Get the Address object
	 * 
	 * @return std::string 
	 */
	std::string getAddress()const;
	/**
	 * @brief Get the Phone object
	 * 
	 * @return std::string 
	 */
	std::string getPhone()const;
	/**
	 * @brief Get the Mail object
	 * 
	 * @return std::string 
	 */
	std::string getMail()const;
	/**
	 * @brief Get the Gender Name object
	 * 
	 * @return std::string 
	 */
	std::string getGenderName() const;
	/**
	 * @brief Get the Gender Id object
	 * 
	 * @return std::string 
	 */
	std::string getGenderId() const;
	/**
	 * @brief Get the Start Date object
	 * 
	 * @return std::string 
	 */
	std::string getStartDate()const;
	/**
	 * @brief Get the End Date object
	 * 
	 * @return std::string 
	 */
	std::string getEndDate()const;
	/**
	 * @brief Get the Role Name object
	 * 
	 * @return std::string 
	 */
	std::string getRoleName() const;
	/**
	 * @brief Get the Role Id object
	 * 
	 * @return std::string 
	 */
	std::string getRoleId() const;
	/**
	 * @brief Get the Work Satus object
	 * 
	 * @return std::string 
	 */
	std::string getWorkSatus() const;






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

	/**
	 * @brief operator overloading <<
	 * 
	 * @param o 
	 * @param obj 
	 * @return std::ostream& 
	 */
	friend std::ostream &operator<< (std::ostream & o, const Employee & obj);

	/**
	 * @brief print header of table before show data to user
	 * 
	 */
	static void printHeader();


};
