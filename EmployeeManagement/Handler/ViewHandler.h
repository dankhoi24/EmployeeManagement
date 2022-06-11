#pragma once
#include "BaseHandler.h"

#define VIEW_HANDLER_MENU "Transporter/Printer/ViewMenu.txt"

class ViewHandler: public BaseHandler{

	enum Action
	{
		NONE_ACTION = 6, VIEW_ALL, VIEW_CURRENT, VIEW_FORMER
	};

	DBConnection* m_database;

public:
	ViewHandler(DBConnection* database);
	
	void executeRequest(int action)override;
	void collectParamater(std::string)override;
	std::string getFileName() override;
};
