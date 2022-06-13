#pragma once

#include "BaseHandler.h"


#define SEARCH_HANDLER_MENU "Transporter/Printer/SearchMenu.txt"
#define SEARCH_HANDLER_INPUT "Transporter/Printer/SearchInput.txt"
 


class SearchHandler: public BaseHandler{
	Employee * m_employee;
	DBConnection* m_database;

	enum Action {
		NONE_ACTION = 6, DELETE_EMPLOYEE, UPDATE_EMPLOYEE
	};

public:

	SearchHandler(DBConnection* database);

	void executeRequest(int action)override;
	void collectParamater(std::string paramater) override;
	std::string getFileName() override;
	
};
