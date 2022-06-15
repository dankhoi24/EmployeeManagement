/**
 * @file SidebarHandler.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "SidebarHandler.h"
#include "../Transporter/Inputer.h"
#include "AddHandler.h"




	std::string SidebarHandler::getFileName() {
		// return path of file view
		return SIDEBAR_HANDLER_MENU;
	}

	
	void SidebarHandler::collectParamater(std::string paramater) {
		// get paramater
	}
		 
	void SidebarHandler::executeRequest(int action) {
		// check which action
		switch (action)
		{
		case NONE_ACTION: // NONE action
			return;
		case VIEW: // view action
		 	// set handler =  ViewHandler
			Inputer::setHandler(new ViewHandler(DBConnection::getInstance())); 
			return;
		case SEARCH: // search action
		 	// set handler = SearchHandler
			Inputer::setHandler(new SearchHandler(DBConnection::getInstance()));
			return;
		case ADD: // add action
			// set handler = AddHandler
			Inputer::setHandler(new AddHandler(DBConnection::getInstance()));
			return;
		case EDIT:
			return;
		}
		// warning no option . . .
	}
