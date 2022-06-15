/**
 * @file SearchHandler.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "SearchHandler.h"
#include "../Transporter/Inputer.h"
#include "UpdateHandler.h"


void SearchHandler::executeRequest(int action) {

	// init employe DAO instance 
	EmployeeDAO employeeDB(m_database);
	// check which action
	switch (action)
	{
	case NONE_ACTION: //NONE action
		return;
	case DELETE_EMPLOYEE: // delete employee action
		employeeDB.deleteEmployee(std::to_string(m_employee->getId())); // delete employee by id
		m_state = e_message_type::PARAMATER; // set handler state now is PARAMATER
		return;
	case UPDATE_EMPLOYEE: // update employee action
		Inputer::setHandler(new UpdateHandler(m_employee)); // changed handler to UpdateHandler
		return;

	default:
		break;
	}


	}
std::string SearchHandler::getFileName() {
	// check with partial view will be shown
	// action view 
	if (m_state == e_message_type::ACTION) {
		return SEARCH_HANDLER_MENU;
	}
	else { // input view
		return SEARCH_HANDLER_INPUT; 
	} 
}




void SearchHandler::collectParamater(std::string paramater) {
	//employe DAO instance
	EmployeeDAO employeeDB(m_database);
	// get id of employee from user
	m_employee = employeeDB.getByID(paramater);
	//print header of table
	Employee::printHeader();
	// print employee
	PrintLib<Employee>::printEntry(*m_employee);
	// set state to action after get employeeID (PARAMATER mode)
	m_state = e_message_type::ACTION;
	}



SearchHandler::SearchHandler(DBConnection *database)
	:m_database(database) {
	// init default handler state (PARAMATER)
		m_state = e_message_type::PARAMATER;
	}


