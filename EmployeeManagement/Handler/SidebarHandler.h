/**
 * @file SidebarHandler.h
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
#include "SearchHandler.h"

// string of file path to sidebar menu view
#define SIDEBAR_HANDLER_MENU "Transporter/Printer/SidebarMenu.txt"

/**
 * @brief Sidebar handler perform action from sidebar choosed by user
 * 
 */
class SidebarHandler : public BaseHandler {
	// all action
	enum Action {
		NONE_ACTION = 0 ,VIEW , SEARCH, ADD, EDIT
	};
	//DBConnection* m_database;
public:
	/**
	 * @brief Get the File path so menu view
	 * 
	 * @return std::string 
	 */
	std::string getFileName()override;
	/**
	 * @brief execute request from customer
	 * 
	 * @param action 
	 */
	void executeRequest(int action)override;
	/**
	 * @brief collect paramater from customer
	 * 
	 * @param paramater 
	 */
	void collectParamater(std::string paramater) override;
};
