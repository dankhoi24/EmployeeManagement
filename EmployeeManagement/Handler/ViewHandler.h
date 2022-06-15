/**
 * @file ViewHandler.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief header of view handler perform view action
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "../Lib/PrintLib.h"
#include "BaseHandler.h"


// string of file path to view handler menu
#define VIEW_HANDLER_MENU "Transporter/Printer/ViewMenu.txt"

/**
 * @brief View handler perform action
 * 
 */
class ViewHandler: public BaseHandler{

	// all action state
	enum Action
	{
		NONE_ACTION = 6, VIEW_ALL, VIEW_CURRENT, VIEW_FORMER
	};
	// database instance
	DBConnection* m_database;

public:
	/**
	 * @brief Construct a new View Handler object
	 * 
	 * @param database 
	 */
	ViewHandler(DBConnection* database);
	
	/**
	 * @brief [Override] execute request from user
	 * 
	 * @param action 
	 */
	void executeRequest(int action)override;
	/**
	 * @brief collect paramater from user
	 * 
	 */
	void collectParamater(std::string)override;
	/**
	 * @brief Get the File path to view handler menu
	 * 
	 * @return std::string 
	 */
	std::string getFileName() override;
};
