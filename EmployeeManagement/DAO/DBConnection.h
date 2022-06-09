/**
 * @file DBConnection.h
 * @author ndKhoi (nguyen.khoi@hitachivantara.com)
 * @brief class DBConnection used to connect to database 
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <Windows.h>
#include <thread>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

/**
 * @brief macro alter message to user
 * 
 */
#define MESSAGE_BOX(x,y){\
	MessageBox(NULL, TEXT(x), TEXT(y), MB_OKCANCEL);\
}
#define SQL_RETURN_CODE_LEN 1000

/**
 * @brief Connect to database
 * 
 */
class DBConnection {

private:
#pragma region Properties

	SQLHANDLE m_SqlConnHandle;
	SQLHANDLE m_SqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

	static DBConnection *s_instance;
	DBConnection();
#pragma endregion

public:
#pragma region Constructor and Destructor


	~DBConnection();

#pragma endregion

#pragma region Methods

	static DBConnection* getInstance();

	void connectToDB();

	bool allocateEnvironment(SQLHANDLE &sqlStmtHandle);

	void SQLQuery();
#pragma endregion

};






