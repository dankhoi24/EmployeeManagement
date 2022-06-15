/**
 * @file SearchHandler.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief header of search handler 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "BaseHandler.h"

// path file to menu view and input view
#define SEARCH_HANDLER_MENU "Transporter/Printer/SearchMenu.txt"
#define SEARCH_HANDLER_INPUT "Transporter/Printer/SearchInput.txt"
 

/**
 * @brief Search Handler perform operator searching employee
 * 
 */
class SearchHandler: public BaseHandler{
	Employee * m_employee; // employee which is searched
	DBConnection* m_database; // instance of database

	// handler state
	enum Action {
		NONE_ACTION = 6, DELETE_EMPLOYEE, UPDATE_EMPLOYEE
	};

public:
	/**
	 * @brief Construct a new Search Handler object
	 * 
	 * @param database 
	 */
	SearchHandler(DBConnection* database);
	/**
	 * @brief execute request from user
	 * 
	 * @param action 
	 */
	void executeRequest(int action)override;
	/**
	 * @brief collect paramater from user
	 * 
	 * @param paramater 
	 */
	void collectParamater(std::string paramater) override;
	/**
	 * @brief Get the File path to view of handler
	 * 
	 * @return std::string 
	 */
	std::string getFileName() override;
	
};
