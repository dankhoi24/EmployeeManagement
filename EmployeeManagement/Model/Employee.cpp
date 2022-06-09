#include "Employee.h"
	Employee::Employee(int ID, const String &name, const String &phone, const String &address, const String &mail, char gender, time_t start_date, time_t end_date, bool is_working, int title_ID)
		: m_ID(ID), m_name(name), m_phone(phone), m_address(address), m_mail(mail), m_gender(gender), m_start_date(start_date), m_end_date(end_date), m_is_working(is_working), m_title_ID(title_ID) 
	{

	}

	Employee::~Employee(){}
