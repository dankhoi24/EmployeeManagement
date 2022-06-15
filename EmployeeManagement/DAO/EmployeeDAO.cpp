/**
 * @file EmployeeDAO.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief get data of Employee from database
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "EmployeeDAO.h"
#include <ctime>
#include <chrono>
#include <time.h>
// disable warining local date
#pragma warning(disable:4996)




/**
 * @brief add employee to database
 * 
 * @param employee 
 */
void EmployeeDAO::addEmployee( const Employee& employee) {
	//allocate envinroment for database
	if (!allocateEnvironment()) {
		MESSAGE_BOX("Allocate environment fail","ERROR");
		return;
	}

	// quetry string
	std::string a =
		"insert into Employee(Name, Phone, Address, Mail, Gender, StartDate, EndDate, isWorking, Title_ID) \
Values('" + employee.getName() +"', '"+ employee.getPhone() + "','"+ employee.getAddress() + "', '"+employee.getMail() + "','"+employee.getGenderId()
	+ "', '"+employee.getStartDate() + "','0001-01-01',1," + employee.getRoleId() + ");";
	
	//convert string to Wstring
	std::wstring str(a.begin(), a.end());
	

	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {
		MESSAGE_BOX("Query string invalid", "ERROR");
		return;
	}
	std::vector<Employee> v_employees;

	int id = 0;
	char name[101] = {};
	char phone[16] = {};
	char address[101] = {};
	char mail[51] = {};
	char gender[2] = {};
	TIMESTAMP_STRUCT* start_date = new tagTIMESTAMP_STRUCT();
	TIMESTAMP_STRUCT* end_date = new tagTIMESTAMP_STRUCT();
	bool is_working = true;

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &phone, sizeof(phone), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLLEN sth;
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_DEFAULT, &phone, sizeof(phone), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
	}
}





/**
 * @brief Fire Employe
 * 
 * @param employee_id 
 * @return true 
 * @return false 
 */
bool EmployeeDAO::FireEmployee(std::string employee_id) {
	
	// check allocate for database
	if (!allocateEnvironment()) {
		MESSAGE_BOX("Allocate environment fail","ERROR");
		return NULL;
	}
	// query string
	std::string a =
			"UPDATE Employee \
			SET isWorking = 0, EndDate = getdate() \
			WHERE ID = " + employee_id;

	//convert string to Wstring
	std::wstring str(a.begin(), a.end());

	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {
		MESSAGE_BOX("Query string invalid", "ERROR");
		return NULL;
	}

	std::vector<Employee> v_employees;

	int id = 0;
	char name[101] = {};
	char phone[16] = {};
	char address[101] = {};
	char mail[51] = {};
	char gender[2] = {};
	TIMESTAMP_STRUCT* start_date = new tagTIMESTAMP_STRUCT();
	TIMESTAMP_STRUCT* end_date = new tagTIMESTAMP_STRUCT();
	bool is_working = true;

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &phone, sizeof(phone), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLLEN sth;
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_DEFAULT, &phone, sizeof(phone), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);

		std::cout << id << " " << name << " "
			<< phone << " "
			<< address << " "
			<< mail << " "
			<< gender << " "
			<< start_date->day << " "
			<< end_date->day << " "
			<< is_working

			<< std::endl;

	}
	return true;
}





/**
 * @brief delete Employee from database
 * 
 * @param employee_id 
 * @return true 
 * @return false 
 */
bool EmployeeDAO::deleteEmployee(std::string employee_id) {

	// check allocate environment
	if (!allocateEnvironment()) {
		MESSAGE_BOX("Allocate environment fail","ERROR");
		return NULL;
	}
	// query string
	std::string a =
		"delete from Employee where Employee.ID = " + employee_id+ " ;";
	// convert
	std::wstring str(a.begin(), a.end());



		// checking statement
		if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {

			MESSAGE_BOX("A2", "ERROR");
			return NULL;
		}

		

		 
		 


	std::vector<Employee> v_employees;

	int id = 0;
	char name[101] = {};
	char phone[16] = {};
	char address[101] = {};
	char mail[51] = {};
	char gender[2] = {};
	TIMESTAMP_STRUCT* start_date = new tagTIMESTAMP_STRUCT();
	TIMESTAMP_STRUCT* end_date = new tagTIMESTAMP_STRUCT();
	bool is_working = true;

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &phone, sizeof(phone), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLLEN sth;
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_DEFAULT, &phone, sizeof(phone), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);

		std::cout << id << " " << name << " "
			<< phone << " "
			<< address << " "
			<< mail << " "
			<< gender << " "
			<< start_date->day << " "
			<< end_date->day << " "
			<< is_working

			<< std::endl;

	}

	return new Employee();




	}



Employee* EmployeeDAO::getByID(std::string employee_id) {



	if (!allocateEnvironment()) {
		return NULL;
	}

	std::string a =
		"select * from Employee where Employee.ID = " + employee_id+ ";";

	std::wstring str(a.begin(), a.end());



		// checking statement
		if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {

			MESSAGE_BOX("A2", "ERROR");
			return NULL;
		}


		Employee* employee = NULL;

	int id = 0;
	char name[101] = {};
	char phone[16] = {};
	char address[101] = {};
	char mail[51] = {};
	char gender[2] = {};
	TIMESTAMP_STRUCT* start_date = new tagTIMESTAMP_STRUCT();
	TIMESTAMP_STRUCT* end_date = new tagTIMESTAMP_STRUCT();
	bool is_working = true;

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &phone, sizeof(phone), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLLEN sth;
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_DEFAULT, &phone, sizeof(phone), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);

		std::cout << id << " " << name << " "
			<< phone << " "
			<< address << " "
			<< mail << " "
			<< gender << " "
			<< start_date->day << " "
			<< end_date->day << " "
			<< is_working

			<< std::endl;

		//TimeT x = TimeT(1,2,3)


			 //struct tm tm;
			 //std::string start_date_str = std::to_string(start_date->month) +
				// " " + std::to_string(start_date->day) +
				// " " + std::to_string(end_date->year);
			 TimeT start_date_struct(std::to_string(start_date->day), std::to_string( start_date->month), std::to_string(start_date->year));
			 TimeT end_date_struct;

   			
	employee = new Employee(id, std::string(name),std::string(phone), std::string(address), std::string(mail), gender[0], start_date_struct, end_date_struct, is_working, 1);


	}
	return employee;
}






std::vector<Employee> EmployeeDAO::getAll(){

	if (!allocateEnvironment()) {
		return std::vector<Employee>();
	}
	std::string hehe = "SELECT * FROM Employee;";
	std::wstring str(hehe.begin(), hehe.end());
	//std::wstring str =L"SELECT * FROM Employee;";



		// checking statement
		if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {

			MESSAGE_BOX("A2", "ERROR");
		return std::vector<Employee>();
		}


	std::vector<Employee> v_employees;

	int id = 0;
	char name[101] = {};
	char phone[16] = {};
	char address[101] = {};
	char mail[51] = {};
	char gender[2] = {};
	TIMESTAMP_STRUCT* start_date = new tagTIMESTAMP_STRUCT();
	TIMESTAMP_STRUCT* end_date = new tagTIMESTAMP_STRUCT();
	bool is_working = true;
	int title_id = 0;

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &phone, sizeof(phone), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
	SQLBindCol(this->m_SqlStmtHandle,  10, SQL_C_DEFAULT, &title_id, sizeof(title_id), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLLEN sth;
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_DEFAULT, &phone, sizeof(phone), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 10, SQL_C_DEFAULT, &title_id, sizeof(title_id), NULL);

	/*	std::cout << id << " " << name << " "
			<< phone << " "
			<< address << " "
			<< mail << " "
			<< gender << " "
			<< start_date->day << " "
			<< end_date->day << " "
			<< is_working

			<< std::endl;*/


			 TimeT start_date_struct(std::to_string(start_date->day), std::to_string( start_date->month), std::to_string(start_date->year));
			 TimeT end_date_struct(std::to_string(end_date->day), std::to_string( end_date->month), std::to_string(end_date->year));

		Employee* employee = new Employee(id, std::string(name),std::string(phone), std::string(address), std::string(mail), gender[0], start_date_struct, end_date_struct, is_working, title_id);
		v_employees.push_back(*employee);



	}
	return v_employees;
}



std::vector<Employee> EmployeeDAO::getCurrent() {

	if (!allocateEnvironment()) {
		return std::vector<Employee>();
	}


	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(
		m_SqlStmtHandle,
		const_cast<SQLWCHAR*>(TEXT(
		"select * from Employee where Employee.isWorking = 1;")),
		SQL_NTS)) {

		MESSAGE_BOX("A2", "ERROR");
		return std::vector<Employee>();
	}


	std::vector<Employee> v_employees;

	int id = 0;
	char name[101] = {};
	char phone[16] = {};
	char address[101] = {};
	char mail[51] = {};
	char gender[2] = {};
	TIMESTAMP_STRUCT* start_date = new tagTIMESTAMP_STRUCT();
	TIMESTAMP_STRUCT* end_date = new tagTIMESTAMP_STRUCT();
	bool is_working = true;
	int title_id = 0;

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &phone, sizeof(phone), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
	SQLBindCol(this->m_SqlStmtHandle,10, SQL_C_DEFAULT, &title_id, sizeof(title_id), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLLEN sth;
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_DEFAULT, &phone, sizeof(phone), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
		SQLBindCol(this->m_SqlStmtHandle,10, SQL_C_DEFAULT, &title_id, sizeof(title_id), NULL);

	/*	std::cout << id << " " << name << " "
			<< phone << " "
			<< address << " "
			<< mail << " "
			<< gender << " "
			<< start_date->day << " "
			<< end_date->day << " "
			<< is_working
			<< std::endl;*/


			 TimeT start_date_struct(std::to_string(start_date->day), std::to_string( start_date->month), std::to_string(start_date->year));
			 TimeT end_date_struct(std::to_string(end_date->day), std::to_string( end_date->month), std::to_string(end_date->year));

			 Employee* employee = new Employee(id, std::string(name), std::string(phone), std::string(address), std::string(mail), gender[0], start_date_struct, end_date_struct, is_working, title_id);
		v_employees.push_back(*employee);

	}
	return v_employees;
}






std::vector<Employee> EmployeeDAO::getFormer() {

	if (!allocateEnvironment()) {
		return std::vector<Employee>();
	}


	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(
		m_SqlStmtHandle,
		const_cast<SQLWCHAR*>(TEXT(
		"select * from Employee where Employee.isWorking = 0;")),
		SQL_NTS)) {

		MESSAGE_BOX("A2", "ERROR");
		return std::vector<Employee>();
	}

	std::vector<Employee> v_employees;


	int id = 0;
	char name[101] = {};
	char phone[16] = {};
	char address[101] = {};
	char mail[51] = {};
	char gender[2] = {};
	TIMESTAMP_STRUCT* start_date = new tagTIMESTAMP_STRUCT();
	TIMESTAMP_STRUCT* end_date = new tagTIMESTAMP_STRUCT();
	bool is_working = true;
	int title_id = 0;

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &phone, sizeof(phone), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
	SQLBindCol(this->m_SqlStmtHandle,10, SQL_C_DEFAULT, &title_id, sizeof(title_id), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLLEN sth;
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_DEFAULT, &phone, sizeof(phone), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 4, SQL_C_DEFAULT, &address, sizeof(address), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 5, SQL_C_DEFAULT, &mail, sizeof(mail), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 6, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 7, SQL_C_TYPE_DATE, start_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 8, SQL_C_TYPE_DATE, end_date, sizeof(SQL_TIMESTAMP_LEN), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 9, SQL_C_DEFAULT, &is_working, sizeof(is_working), NULL);
		SQLBindCol(this->m_SqlStmtHandle,10, SQL_C_DEFAULT, &title_id, sizeof(title_id), NULL);
		//std::cout << id << " " << name << " "
		//	<< phone << " "
		//	<< address << " "
		//	<< mail << " "
		//	<< gender << " "
		//	<< start_date->day << " "
		//	<< end_date->day << " "
		//	<< is_working

		//	<< std::endl;

			 TimeT start_date_struct(std::to_string(start_date->day), std::to_string( start_date->month), std::to_string(start_date->year));
			 TimeT end_date_struct(std::to_string(end_date->day), std::to_string( end_date->month), std::to_string(end_date->year));

		Employee* employee = new Employee(id, std::string(name),std::string(phone), std::string(address), std::string(mail), gender[0], start_date_struct, end_date_struct, is_working, title_id);
		v_employees.push_back(*employee);


	}
	return v_employees;
}







void EmployeeDAO::setRoleEmployee(std::string employee_id, std::string role) {

	std::cout << "GO TO PROMOTE \n";

	if (!allocateEnvironment()) {
		return;
	}

	std::string a =
		"update Employee \
		set Title_ID = (select ID from Title where name = \'" + role + "\')"+
	"where Employee.ID = " + employee_id;


	std::wstring str(a.begin(), a.end());



	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle, (SQLWCHAR*)str.c_str(), SQL_NTS)) {

		MESSAGE_BOX("A2", "ERROR");
		return;
	}


	char name[101] = {};

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);

	}


	}





std::string EmployeeDAO::getRoleById(int employee_id) {


	std::cout << "GO TO PROMOTE \n"; 

	if (!allocateEnvironment()) {
		MessageBox(NULL, TEXT("ENVIRONMENT"), TEXT("WARNING"), MB_OKCANCEL);
		return "";
	}

	std::string a =
		"select title.Name from employee \
		join title on title.ID = employee.Title_ID \
	where employee.ID = " + std::to_string(employee_id);


	std::wstring str(a.begin(), a.end());



		// checking statement
		if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {

			MESSAGE_BOX("A2", "ERROR");
			return "";
		}


	char name[101] = {};

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_CHAR, &name, sizeof(name), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_CHAR, &name, sizeof(name), NULL);

	}
	std::cout << name << std::endl;
	return std::string(name);


	}


EmployeeDAO::EmployeeDAO(DBConnection * dbConnection):BaseDAO<Employee>(dbConnection){

}
