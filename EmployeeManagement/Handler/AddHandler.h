/**
 * @file AddHandler.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "BaseHandler.h"

// string of file path show manu of adding handler
#define	ADD_HANDLER_MENU "Transporter/Printer/AddMenu.txt" 

/**
 * @brief add handler to perform addding operators 
 * 
 */
class AddHandler: public BaseHandler{
	/**
	 * @brief all state of adding action
	 * 
	 */
	enum State {
		NAME = 0, PHONE, ADDRESS, MAIL,GENDER, STARTDATE, TITLE
	};

	// pointer point to instance of database
	DBConnection* m_database;
	// instance of employee database
	Employee m_employee;
	// adding state
	State m_add_state;

public:
	/**
	 * @brief Destroy the Add Handler object
	 * 
	 */
	~AddHandler() {
		delete m_database;
		//delete m_employee;
			
	}
	/**
	 * @brief check is adding operator finish or not
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isFinsh();
	/**
	 * @brief override function -> execute request from user
	 * 
	 * @param action 
	 */
	void executeRequest(int action) override;
	/**
	 * @brief get paramater from user
	 * 
	 * @param paramater 
	 */
	void collectParamater(std::string paramater) override;
	/**
	 * @brief Get the File path to AddHandler menu
	 * 
	 * @return std::string 
	 */
	std::string getFileName()override;
	/**
	 * @brief print out current title for each adding operator
	 * 
	 */
	void printTitle() override;
	/**
	 * @brief adding employee to database
	 * 
	 */
	void updateEmployee();

	/**
	 * @brief Construct a new Add Handler object
	 * 
	 * @param database 
	 */
	AddHandler(DBConnection *database);
};
