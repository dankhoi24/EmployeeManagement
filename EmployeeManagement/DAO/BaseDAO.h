/**
 * @file BaseDAO.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief a base class for query oparations
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include "DBConnection.h"

/**
 * @brief BaseDAO is a template used to handle query statement and provide query method for subclasses
 * 
 * @tparam T is typename 
 */
template <class T>
class BaseDAO{
protected:
	DBConnection *m_dbConnection; // use to connect to database and allocate environment
	SQLHANDLE m_SqlStmtHandle;    // use to handle query statement

public:
/**
 * @brief Get the All entry of table
 * 
 */
	virtual	void getAll() = 0; 
	// SQLHANDLE getSQlStatementHandle();
	/**
	 * @brief checking query string 
	 * 
	 * @param query_string 
	 * @return true 
	 * @return false 
	 */
	bool allocateEnvironment() {
		

		const char sth[] = "SELECT* FROM Employee;";

		//allocate environment
		if (!m_dbConnection->allocateEnvironment(m_SqlStmtHandle)) {
			return false;
		}
		// checking statement
		//if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle, const_cast<SQLWCHAR*>((sth)), SQL_NTS)) {

		//	MESSAGE_BOX("A2", "ERROR");
		//	return false;
		//}

		return true;
	}

	/**
	 * @brief Construct a new Base D A O< T> object
	 * 
	 * @param dbConnection 
	 */
	BaseDAO<T>(DBConnection* dbConnection) :m_dbConnection(dbConnection) {
		//m_SqlStmtHandle = NULL;
	}


};
