/**
 * @file BaseHandler.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../DAO/EmployeeDAO.h"
#include <filesystem>


/**
 * @brief Base handler is base class for all handler
 * 
 */

class BaseHandler {

public:
	/**
	 * @brief execute request from user
	 * 
	 * @param action 
	 */
	virtual void executeRequest(int action) = 0;
	/**
	 * @brief get paramater from user
	 * 
	 * @param paramater 
	 */
	virtual void collectParamater(std::string paramater) = 0;
	/**
	 * @brief Get the File path of menu
	 * 
	 * @return std::string 
	 */
	virtual std::string getFileName() = 0;
	/**
	 * @brief print menu for action operator (if any)
	 * 
	 */
	virtual void printTitle() {
		std::cout << "\
_____ _____ _____ _____ _____ _____ _____ _____  \n  \
\____\\____\\____\\____\\____\\____\\____\\____\  \n \
";
	}
	/**
	 * @brief Destroy the Base Handler object
	 * 
	 */
	~BaseHandler();

	/**
	 * @brief print menu for handler
	 * 
	 * @param filename 
	 */
	void printMenu(std::string filename);

	/**
	 * @brief update action from user when changed
	 * 
	 * @param action 
	 */
	void updateAction(int action);
	/**
	 * @brief update paramater from user when changed
	 * 
	 * @param paramater 
	 */
	void updateParamater(std::string paramater);
	/**
	 * @brief check current value from user belong to action or not(paramater)
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isAction();


protected:
	// sub handler
	BaseHandler* m_subHandler = NULL;
	// current action
	int m_action;
	// current paramater
	std::string m_paramater;
	// state of handler
	static enum e_message_type {
		ACTION = 1, PARAMATER
	};
	// current state of handler
	// set default handler is action
	e_message_type m_state = e_message_type::ACTION;
};
