#include "EmployeeDAO.h"

void EmployeeDAO::getAll(){

	if (!checkQueryString("S")) {
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

	//return new std::vector<Employee>();

}

EmployeeDAO::EmployeeDAO(DBConnection * dbConnection):BaseDAO<Employee>(dbConnection){

}
