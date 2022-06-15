/**
 * @file UpdateHandler.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief header of Update Handler [perform update action]
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "BaseHandler.h"
#include <vector>

// string of file path to Update view menu
#define UPDATE_HANDLER_MENU "Transporter/Printer/UpdateMenu.txt"

/**
 * @brief Update Handler perform update action 
 * 
 */
class UpdateHandler : public BaseHandler{
	// all action state of Update Handler
	enum Action {
		NONE_ACTION = 6, UPDATE_INFO, FIRE_EMPLOYEE, PROMOTE_EMPLOYEE, DEMOTE_EMPLOYEE
	};
	// Employee which user want to update
	Employee *m_employee;
	// Vector-2d Roles represent for Role hierarchical structure
	std::vector < std::vector<std::string>> m_Roles;

public:
	/**
	 * @brief Construct a new Update Handler object
	 * 
	 * @param employee 
	 */
	UpdateHandler(Employee* employee);

	/**
	 * @brief [Override] execute all request from user
	 * 
	 * @param action 
	 */
	void executeRequest(int action) override;

	/**
	 * @brief [override] collect paramater from user
	 * 
	 * @param paramater 
	 */
	void collectParamater(std::string paramater) override;
	
	/**
	 * @brief [Override] get file path to Update View menu
	 * 
	 * @return std::string 
	 */
	std::string getFileName() override;

	/**
	 * @brief get role from role file [Model/Roles.txt] and represent to vector-2d 
	 * 
	 */
	void getRole();

	/**
	 * @brief remove leading space from string
	 * 
	 * @param str 
	 */
	void deleteLeadSpace(std::string& str);

	/**
	 * @brief remove trailing space from string
	 * 
	 * @param str 
	 */
	void deleteTrailingSpace(std::string& str);

	/**
	 * @brief Get the role name and push to vector-2d Roles
	 * 
	 * @param str 
	 * @param index 
	 */
	void getString(std::string& str, int& index);
	
	/**
	 * @brief reading file and get role name
	 * 
	 */
	void readFile();

	/**
	 * @brief promote employee
	 * 
	 */
	void promoteEmployee();
	
	/**
	 * @brief demote employee
	 * 
	 */
	void demoteEmployee();

	/**
	 * @brief get index of role in vector-2d [role hierarchcal structure]
	 * 
	 * @return int 
	 */
	int getIndex();


};
