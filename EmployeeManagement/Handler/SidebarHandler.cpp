#include "SidebarHandler.h"
#include "../Transporter/Inputer.h"



//SidebarHandler::SidebarHandler(DBConnection* database) :m_database(database){
//	
//	}

	std::string SidebarHandler::getFileName() {
		return SIDEBAR_HANDLER_MENU;
	}
		 
	void SidebarHandler::executeRequest(int action) {
		switch (action)
		{
		case NONE_ACTION:
			//sth
			return;
		case VIEW:
			Inputer::setHandler(new ViewHandler(DBConnection::getInstance()));
			return;
		case SEARCH:
			return;
		case FILTER:
			return;
		case ADD:
			return;
		case EDIT:
			return;
		}
		// warning no option . . .
	}
