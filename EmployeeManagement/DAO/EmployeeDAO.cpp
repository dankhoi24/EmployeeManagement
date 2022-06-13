#include "EmployeeDAO.h"
#include <ctime>
#include <chrono>
#include <time.h>

#pragma warning(disable:4996)


void convertStringToWString(std::wstring& ws, std::string& str) {
	std::wstring wsTmp(str.begin(), str.end());

	ws = wsTmp;
}




void EmployeeDAO::addEmployee( const Employee& employee) {

	std::cout << "GO TO FIRE \n";

	if (!allocateEnvironment()) {
		return;
	}
	std::string a =
		"insert into Employee(Name, Phone, Address, Mail, Gender, StartDate, EndDate, isWorking, Title_ID) \
Values('" + employee.getName() +"', '"+ employee.getPhone() + "','"+ employee.getAddress() + "', '"+employee.getMail() + "','"+employee.getGender() 
	+ "', '"+employee.getStartDate() + "','0001-01-01',1,"+employee.getRole() + ");";
	
	std::cout << a << '\n';

	std::wstring str(a.begin(), a.end());



		// checking statement
		if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {

			MESSAGE_BOX("A2", "ERROR");
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

	}






bool EmployeeDAO::FireEmployee(std::string employee_id) {

	std::cout << "GO TO FIRE \n";

	if (!allocateEnvironment()) {
		return NULL;
	}

	std::string a =
			"UPDATE Employee \
			SET isWorking = 0, EndDate = getdate() \
			WHERE ID = " + employee_id;


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

	return true;




	}






bool EmployeeDAO::deleteEmployee(std::string employee_id) {

	std::cout << "GO TO DELETE \n";

	if (!allocateEnvironment()) {
		return NULL;
	}

	std::string a =
		"delete from Employee where Employee.ID = " + employee_id+ " ;";

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


			 struct tm tm;
			 std::istringstream iss(std::to_string(start_date->month) + 
			 " " + std::to_string(start_date->day) + 
				 " " + std::to_string(end_date->year) );

    iss >> std::get_time(&tm, "%b %d %Y");
    TimeT times = mktime(&tm);

		std::cout <<times<<'\n';

			time(&times);
	std::cout << ctime(&times);

			
	employee = new Employee(id, std::string(name),std::string(phone), std::string(address), std::string(mail), gender[0], times, times, is_working, 1);


	}
	return employee;
}






void EmployeeDAO::getAll(){

	if (!allocateEnvironment()) {
		return;
	}
	std::string hehe = "SELECT * FROM Employee;";
	std::wstring str(hehe.begin(), hehe.end());
	//std::wstring str =L"SELECT * FROM Employee;";



		// checking statement
		if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {

			MESSAGE_BOX("A2", "ERROR");
			return ;
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
}


void EmployeeDAO::getCurrent() {

	if (!allocateEnvironment()) {
		return;
	}


	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(
		m_SqlStmtHandle,
		const_cast<SQLWCHAR*>(TEXT(
		"select * from Employee where Employee.isWorking = 1;")),
		SQL_NTS)) {

		MESSAGE_BOX("A2", "ERROR");
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
}






void EmployeeDAO::getFormer() {

	if (!allocateEnvironment()) {
		return;
	}


	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(
		m_SqlStmtHandle,
		const_cast<SQLWCHAR*>(TEXT(
		"select * from Employee where Employee.isWorking = 0;")),
		SQL_NTS)) {

		MESSAGE_BOX("A2", "ERROR");
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
