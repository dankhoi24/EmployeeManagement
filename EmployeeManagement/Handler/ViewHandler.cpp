#include "ViewHandler.h"
	ViewHandler::ViewHandler(DBConnection * database): m_database(database) {
		
		
	}

	
	void ViewHandler::executeRequest(int action) {

		EmployeeDAO x(m_database);
		switch (action)
		{
		case NONE_ACTION:
			//sth
			return;
		case VIEW_ALL:
			std::cout << "VIEW ALL \n";
				x.getAll();
			return;
		case VIEW_CURRENT:
			return;
		case VIEW_FORMER:
			return;

		default:
			break;
		}

		// warning no option . . .
	}




	std::string ViewHandler::getFileName() {
		return VIEW_HANDLER_MENU;
	}





	
