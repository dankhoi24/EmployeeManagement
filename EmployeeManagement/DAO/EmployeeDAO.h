#pragma once
#include "BaseDAO.h"
#include <vector>
#include "../Model/Employee.h"

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

	bool deleteEmployee(std::string employee_id);


};
