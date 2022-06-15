#include "TitleDAO.h"


std::string TitleDAO::getTitleById(std::string title_id) {
	// allocate environment for database
	if (!allocateEnvironment()) {
		return NULL;
	}

	// query string
	std::string a =
		"select * from Title where Title.ID = " + title_id+ ";";
	//convert string to Wstring
	std::wstring str(a.begin(), a.end());

	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,(SQLWCHAR*)str.c_str(), SQL_NTS)) {

		MESSAGE_BOX("A2", "ERROR");
		return NULL;
	}


	// title name
	char name[101] = {};

	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	}
	// return title name
	return std::string(name);
}



std::vector<Title> TitleDAO::getAll() {

	// allocate environment for database
	if (!allocateEnvironment()) {
		return std::vector<Title>();
	}
	std::string hehe = "SELECT * FROM Title;";
	//convert string to Wstring
	std::wstring str(hehe.begin(), hehe.end());
	//std::wstring str =L"SELECT * FROM Employee;";

	// checking statement
	if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle, (SQLWCHAR*)str.c_str(), SQL_NTS)) {
		MESSAGE_BOX("Invalid query string", "ERROR");
		return std::vector<Title>();
	}

	/**
	 * @brief vector store all title name
	 *
	 */
	std::vector<Title> v_title;
	// all column of title table
	int id = 0;
	char name[101] = {};
	double salary = 0.0;


	// get data from table still the end 
	SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
	SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &salary, sizeof(salary), NULL);
	while (SQLFetch(this->m_SqlStmtHandle) == SQL_SUCCESS)
	{
		SQLLEN sth;
		SQLBindCol(this->m_SqlStmtHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 2, SQL_C_CHAR, &name, sizeof(name), NULL);
		SQLBindCol(this->m_SqlStmtHandle, 3, SQL_C_CHAR, &salary, sizeof(salary), NULL);

		// push title to vector
		Title* title = new Title(id, std::string(name), salary);
		v_title.push_back(*title);

	}
	// return vector<title>
	return v_title;
}

TitleDAO:: TitleDAO(DBConnection* database) :BaseDAO<Title>(database) {

}






