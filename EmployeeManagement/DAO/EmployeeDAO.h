#pragma once
#include "BaseDAO.h"
#include <vector>
#include "../Model/Employee.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>


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
	void getAll() ;
	void getCurrent();
	void getFormer();

	Employee* getByID(std::string employee_id);

	bool FireEmployee(std::string employee_id);
	bool deleteEmployee(std::string employee_id);


	std::string getRoleById(int employee_id);

	void setRoleEmployee(std::string employee_id, std::string role);
	void addEmployee(const Employee& employee);
};
