/**
 * @file DBConnection.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief Connect to database
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "DBConnection.h"
/**
 * @brief static pointer point to unique instance 
 * 
 */
#pragma region Properties
DBConnection* DBConnection::s_instance = NULL;
#pragma endregion


#pragma region Constructor and Destructor

	DBConnection:: DBConnection() {
		m_SqlConnHandle = NULL;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_SqlEnvHandle)) {
			MESSAGE_BOX("Connected to database", "Notify")
		}
		if (SQL_SUCCESS != SQLSetEnvAttr(m_SqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
			MESSAGE_BOX("Connected to database", "Notify")
		}
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, m_SqlEnvHandle, &m_SqlConnHandle)) {
			MESSAGE_BOX("Connected to database", "Notify")
		}
	}

	DBConnection:: ~DBConnection() {
		std::cout << "))))))))))))))))))))))))))))))))))))))0\n";
		delete DBConnection::s_instance;
	}

#pragma endregion

#pragma region Methods
		/**
		 * @brief get unique instance of DBConnection class
		 * 
		 * @return DBConnection* 
		 */
		DBConnection *DBConnection::getInstance(){
		if (DBConnection::s_instance == NULL) {
			s_instance = new DBConnection();
		}

		return s_instance;
	}
 
	/**
	 * @brief Connect to database
	 * 
	 */
	  void  DBConnection::connectToDB() {
		  switch (SQLDriverConnectW
		  (
			  m_SqlConnHandle,
			  NULL,
			  (SQLWCHAR*)TEXT("DRIVER={SQL Server};Server=MSI;DATABASE=Employee_M;Truested=true;"),
			  SQL_NTS,
			  retconstring,
			  1024,
			  NULL,
			  SQL_DRIVER_NOPROMPT

		  )
		  )

		  {
		  case SQL_SUCCESS:
			  MESSAGE_BOX("Connected to Database 1 ", "Notify");
			  break;
		  case SQL_SUCCESS_WITH_INFO:
			  MESSAGE_BOX("Connected to Database 2 ", "Notify");
			  break;
		  case SQL_INVALID_HANDLE:
			  std::cout << SQL_INVALID_HANDLE << std::endl;
			  //showSQLError(SQL_HANDLE_DBC, m_SqlConnHandle);
			  MESSAGE_BOX("Can NOT connect to Database 1 ", "Notify");
			  break;
		  case SQL_ERROR:
			  MESSAGE_BOX("Can NOT connect to Database 2 ", "Notify");
			  //showSQLError(SQL_HANDLE_DBC, m_SqlConnHandle);
			  break;
		  default:
			  break;
		  }
	  }

	  bool DBConnection::allocateEnvironment(SQLHANDLE &sqlStmtHandle) {

		  if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, m_SqlConnHandle, &sqlStmtHandle)) {
			  MESSAGE_BOX("A1", "ERROR");
			  return false;
		  }
		  return true;
	  }

	  //void DBConnection::SQLQuery() {
		 // const char str[] = "SELECT* FROM Title;";

		 // /*if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, m_SqlConnHandle, &m_SqlStmtHandle)) {
			//  MESSAGE_BOX("A1", "ERROR");
		 // }*/
		 // if (SQL_SUCCESS != SQLExecDirectW(m_SqlStmtHandle,const_cast<SQLWCHAR*>( TEXT("SELECT* FROM Title;")), SQL_NTS)) {
		 // 
			//  MESSAGE_BOX("A2", "ERROR");
		 // }
			//	  char name[100];
		 // SQLBindCol(m_SqlStmtHandle, 1, SQL_C_CHAR, &name, sizeof(name), NULL);
			//  while (SQLFetch(m_SqlStmtHandle)==SQL_SUCCESS)
			//  {
			//	  SQLGetData(m_SqlStmtHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);

			//	  std::cout << name << std::endl;
			//	  
			//  }
	  //}
#pragma endregion


















