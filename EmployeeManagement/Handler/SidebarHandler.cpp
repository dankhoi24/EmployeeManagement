#include "SidebarHandler.h"
#include "../Transporter/Inputer.h"
#include "AddHandler.h"



//SidebarHandler::SidebarHandler(DBConnection* database) :m_database(database){
//	
//	}

	std::string SidebarHandler::getFileName() {
		return SIDEBAR_HANDLER_MENU;
	}


	void SidebarHandler::collectParamater(std::string paramater) {
		// get paramater
	}
		 
	void SidebarHandler::executeRequest(int action) {
		switch (action)
		{
		case NONE_ACTION:
			//sth
			return;
		case VIEW: // View Mode
			Inputer::setHandler(new ViewHandler(DBConnection::getInstance()));
			return;
		case SEARCH:
			Inputer::setHandler(new SearchHandler(DBConnection::getInstance()));
			return;
		case ADD:
			Inputer::setHandler(new AddHandler(DBConnection::getInstance()));
			return;
		case EDIT:
			return;
		}
		// warning no option . . .
	}
