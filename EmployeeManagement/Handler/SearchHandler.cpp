#include "SearchHandler.h"


void SearchHandler::executeRequest(int action) {

	EmployeeDAO employeeDB(m_database);
	switch (action)
	{
	case NONE_ACTION:
		return;
	case DELETE_EMPLOYEE:
		employeeDB.deleteEmployee("6");
		m_state = e_message_type::PARAMATER;
		return;
	case UPDATE_EMPLOYEE:
		return;

	default:
		break;
	}


	}
std::string SearchHandler::getFileName() {
	if (m_state == e_message_type::ACTION) {
		return SEARCH_HANDLER_MENU;
	}
	else {
		return SEARCH_HANDLER_INPUT; 
	} 
}




void SearchHandler::collectParamater(std::string paramater) {
	EmployeeDAO employeeDB(m_database);
	employeeDB.getByID(paramater);

	m_state = e_message_type::ACTION;
	}



SearchHandler::SearchHandler(DBConnection *database)
	:m_database(database) {

	m_state = e_message_type::PARAMATER;
	}


