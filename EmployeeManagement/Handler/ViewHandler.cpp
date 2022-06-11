#include "ViewHandler.h"
	ViewHandler::ViewHandler(DBConnection * database): m_database(database) {
		
		
	}

	void ViewHandler::collectParamater(std::string) {
		// collect paramater
	}
	
	void ViewHandler::executeRequest(int action) {

		EmployeeDAO employee_DAO(m_database);
		switch (action)
		{
		case NONE_ACTION:
			//sth
			return;
		case VIEW_ALL:
			std::cout << "VIEW ALL \n";
				employee_DAO.getAll();
			return;
		case VIEW_CURRENT:
			std::cout << "VIEW CURRENT \n";
			employee_DAO.getCurrent();
			return;
		case VIEW_FORMER:
			std::cout << "VIEW FORMER \n";
			employee_DAO.getFormer();
			return;

		default:
			break;
		}

		// warning no option . . .
	}




	std::string ViewHandler::getFileName() {
		return VIEW_HANDLER_MENU;
	}





	
