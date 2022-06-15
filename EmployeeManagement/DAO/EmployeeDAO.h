/**
 * @file EmployeeDAO.h
 * @author ndKhoi(nguyen.khoi@hitachivantara.com)
 * @brief get data from Employee
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "BaseDAO.h"
#include <vector>
#include "../Model/Employee.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

/**
 * @brief get to get data from employee
 * 
 */
class EmployeeDAO: public BaseDAO<Employee>{
public:
	/** Construct
	*	@brief  
	*/
	EmployeeDAO(DBConnection*);
	/**
	 * @brief Get the All entry of table
	 * 
	 */
	std::vector<Employee> getAll() override;
	/**
	 * @brief Get the Current Employee
	 * 
	 * @return std::vector<Employee> 
	 */
	std::vector<Employee> getCurrent();

	/**
	 * @brief Get the Former employee
	 * 
	 * @return std::vector<Employee> 
	 */
	std::vector<Employee> getFormer();

	/**
	 * @brief Get employee by ID
	 * 
	 * @param employee_id 
	 * @return Employee* 
	 */
	Employee* getByID(std::string employee_id);


	/**
	 * @brief fire employee by id
	 * 
	 * @param employee_id 
	 * @return true 
	 * @return false 
	 */
	bool FireEmployee(std::string employee_id);
	/**
	 * @brief delete employee by id
	 * 
	 * @param employee_id 
	 * @return true 
	 * @return false 
	 */
	bool deleteEmployee(std::string employee_id);

	/**
	 * @brief Get the Role By Id object
	 * 
	 * @param employee_id 
	 * @return std::string 
	 */
	std::string getRoleById(int employee_id);

	/**
	 * @brief Set the Role for Employee 
	 * 
	 * @param employee_id 
	 * @param role 
	 */
	void setRoleEmployee(std::string employee_id, std::string role);
	/**
	 * @brief add new employee to database
	 * 
	 * @param employee 
	 */
	void addEmployee(const Employee& employee);
};
