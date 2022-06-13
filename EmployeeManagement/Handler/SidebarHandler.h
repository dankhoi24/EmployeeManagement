#pragma once

#include "BaseHandler.h"
#include "SearchHandler.h"

#define SIDEBAR_HANDLER_MENU "Transporter/Printer/SidebarMenu.txt"

class SidebarHandler : public BaseHandler {
	enum Action {
		NONE_ACTION = 0 ,VIEW , SEARCH, ADD, EDIT
	};
	//DBConnection* m_database;
public:
	//SidebarHandler(DBConnection*);
	std::string getFileName()override;
		 
	void executeRequest(int action)override;
	void collectParamater(std::string paramater) override;
};
