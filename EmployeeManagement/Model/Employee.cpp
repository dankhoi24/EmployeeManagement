#pragma warning(disable:4996)


#include "Employee.h"
#include <time.h>
#include <sstream>
#include <filesystem>
#include <iomanip>
#include <ctime>
#include <chrono>


	Employee::Employee(int ID,  String name, String phone, String address, String mail, char gender, TimeT start_date, TimeT end_date, bool is_working, int title_ID)
		: m_ID(ID), m_name(name), m_phone(phone), m_address(address), m_mail(mail), m_gender(gender), m_start_date(start_date), m_end_date(end_date), m_is_working(is_working), m_title_ID(title_ID) 
	{

	}

	Employee::Employee() {

	}

	Employee::~Employee(){}






	int Employee::getId() {
		return m_ID;
	}




	void Employee::setId(int id) {
		
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
		m_title_ID = 1;
	}
	bool Employee::setStartDate(std::string date) {
		return m_start_date.setDate(date);

		
	}

	void Employee::setEndDate(std::string date) {
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
	std::string Employee::getGender() const{
		return std::to_string(m_gender);
	}
	std::string Employee::getStartDate() const{
		return m_start_date.getDate();
	}
	std::string Employee::getEndDate() const{
		return m_end_date.getDate();
	}
	std::string Employee::getRole() const{
		return "1";
	}

