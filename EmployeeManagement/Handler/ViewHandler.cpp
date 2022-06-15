/**
 * @file ViewHandler.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief View handler perform all view operator
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "ViewHandler.h"

	
	ViewHandler::ViewHandler(DBConnection * database)
	: m_database(database) {

	 }


	void ViewHandler::collectParamater(std::string) {
		// collect paramater (if any)
	}
	
	void ViewHandler::executeRequest(int action) {

		// init employee_DAO
		EmployeeDAO employee_DAO(m_database);
		// store return employees after query
		std::vector <Employee>v_employees;
		// print table header of employee before show data as table
		Employee::printHeader();
		
		// check which action
		switch (action)
		{
		case NONE_ACTION: // none action
			//sth
			break;
		case VIEW_ALL: //  view all employee action
			std::cout << "VIEW ALL \n";
					// get all employees and return vector
					v_employees	= employee_DAO.getAll(); 
					break;
			case VIEW_CURRENT: // view current employee action
				std::cout << "VIEW CURRENT \n";
				// get current employees and return vector
				v_employees = employee_DAO.getCurrent();
				break;
			case VIEW_FORMER: // view former employee action
				std::cout << "VIEW FORMER \n";
				// get former employees and return vector
				v_employees = employee_DAO.getFormer();
				break;
			default:
				break;
			}
				// show data after query
				PrintLib<Employee>::printVector(v_employees);
			// warning no option . . .
		}




		std::string ViewHandler::getFileName() {
			// return path file to view handler menu
			return VIEW_HANDLER_MENU;
		}





		
