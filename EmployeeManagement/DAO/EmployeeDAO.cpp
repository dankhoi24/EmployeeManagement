#include "EmployeeDAO.h"

void EmployeeDAO::getAll(){
					  char name[100];
	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_CHAR, &name, sizeof(name), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(this->m_SqlStmtHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);

		std::cout << name << std::endl;

	}

	//return new std::vector<Employee>();

}

EmployeeDAO::EmployeeDAO(DBConnection * dbConnection):BaseDAO<Employee>(dbConnection){

}
