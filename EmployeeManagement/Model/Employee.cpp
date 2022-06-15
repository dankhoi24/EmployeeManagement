/**
 * @file Employee.cpp
 * @author ndKhoi (nguyen.khoi@hitachivantara.com)
 * @brief Employee Model
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma warning(disable:4996)


#include "Employee.h"
#include <time.h>
#include <sstream>
#include <filesystem>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "../DAO/TitleDAO.h"


	Employee::Employee(int ID,  String name, String phone, String address, String mail, char gender, TimeT start_date, TimeT end_date, bool is_working, int title_ID)
		: m_ID(ID), m_name(name), m_phone(phone), m_address(address), m_mail(mail), m_gender(gender), m_start_date(start_date), m_end_date(end_date), m_is_working(is_working), m_title_ID(title_ID) 
	{

	}

	Employee::Employee() {

	}
	

	 void Employee::printHeader() {
		// set text color blue
		LIGHT_BLUE_WORD
		 // print header of employee table
		 std::cout << std::right << std::setw(20) << std::setfill(' ') << "Name" <<
			 std::right << std::setw(20) << std::setfill(' ') << "Phone" <<
			 std::right << std::setw(50) << std::setfill(' ') << "Address" <<
			 std::right << std::setw(20) << std::setfill(' ') << "Mail" <<
			 std::right << std::setw(20) << std::setfill(' ') << "Gender" <<
			 std::right << std::setw(20) << std::setfill(' ') << "Start Date" <<
			 std::right << std::setw(20) << std::setfill(' ') << "End Date" <<
			 std::right << std::setw(20) << std::setfill(' ') << "Role" << std::endl;
		// clear text color
		CLEAR_COLOR
	}
	// operator overloading <<
	std::ostream& operator<< (std::ostream& o, const Employee& obj) {
		 o << std::right << std::setw(20) << std::setfill(' ') << obj.getName() <<
			 std::right << std::setw(20) << std::setfill(' ') << obj.getPhone() <<
			 std::right << std::setw(50) << std::setfill(' ') << obj.getAddress() <<
			 std::right << std::setw(20) << std::setfill(' ') << obj.getMail() <<
			 std::right << std::setw(20) << std::setfill(' ') << obj.getGenderName() <<
			 std::right << std::setw(20) << std::setfill(' ') << obj.getStartDate() <<
			 std::right << std::setw(20) << std::setfill(' ') << obj.getEndDate()<<
			 std::right << std::setw(20) << std::setfill(' ') << obj.getRoleName() << std::endl;
		 
		 return o;

	}

	Employee::~Employee(){}

	int Employee::getId() {
		// return employee ID
		return m_ID;
	}

	void Employee::setId(int id) {
		////////
	}

	void Employee::setName(std::string name) {
		m_name = name;
	}
	void Employee::setAddess(std::string address) {
		m_address = address;
	}
	void Employee::setPhone(std::string phone) {
		m_phone = phone;
	}
	void Employee::setMail(std::string mail) {
		m_mail = mail;
	}
	void Employee::setGender(char gender) {
		m_gender = gender;
	}
	void Employee::setRole(std::string role) {
		// convert string to int (role id)
		m_title_ID = std::atoi(role.c_str());
	}
	bool Employee::setStartDate(std::string date) {
		// convert string to TimT (date)
		return m_start_date.setDate(date);
	}

	void Employee::setEndDate(std::string date) {
		// convert string to TimT (date)
		m_end_date.setDate(date);
	}



	std::string Employee::getName() const{
		return m_name;
	}

	std::string Employee::getAddress() const{
		return m_address;
	}

	std::string Employee::getPhone() const{
		return m_phone;
	}
	std::string Employee::getMail() const{
		return m_mail;
	}
	std::string Employee::getGenderName() const{
		// gender = 0 => female
		if (m_gender == '0') {
			return "Female";
		}
		// gender = 1 => male
		else if (m_gender == '1') {
			return "Male";
		}
		// other mean undefined
		return "Undefined";
	}


	std::string Employee::getGenderId() const{
		// covert string to char
		return std::string(1,m_gender);
	}
	std::string Employee::getStartDate() const{
		// convert TimtT to st
		return m_start_date.getDate();
	}
	std::string Employee::getEndDate() const{
		// convert TimtT to string
		return m_end_date.getDate();
	}
	std::string Employee::getRoleName() const{
		// init title_DAO 
		TitleDAO titleDB(DBConnection::getInstance());
		// get role name by title id
		return titleDB.getTitleById(std::to_string(m_title_ID));

	}


	std::string Employee::getRoleId() const{
		// convert int to string (title id)
		return std::to_string(m_title_ID);
	}

	std::string Employee::getWorkSatus() const {
		//convert bool to string (work status)
		return std::to_string(m_is_working);
	}
