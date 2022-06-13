#pragma once

#include "BaseHandler.h"
#include <vector>

#define UPDATE_HANDLER_MENU "Transporter/Printer/UpdateMenu.txt"


class UpdateHandler : public BaseHandler{

	enum Action {
		NONE_ACTION = 6, UPDATE_INFO, FIRE_EMPLOYEE, PROMOTE_EMPLOYEE, DEMOTE_EMPLOYEE
	};

	Employee *m_employee;
	std::vector < std::vector<std::string>> m_Roles;

public:
	UpdateHandler(Employee* employee);

	void executeRequest(int action) override;
	void collectParamater(std::string paramater) override;
	std::string getFileName() override;

	void getRole();

	void deleteLeadSpace(std::string& str);

	void deleteTrailingSpace(std::string& str);

	void getString(std::string& str, int& index);
	
	void readFile();

	void promoteEmployee();
	void demoteEmployee();

	int getIndex();


};
