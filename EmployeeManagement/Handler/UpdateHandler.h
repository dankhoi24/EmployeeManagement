#pragma once

#include "BaseHandler.h"


#define UPDATE_HANDLER_MENU "Transporter/Printer/UpdateMenu.txt"


class UpdateHandler : public BaseHandler{

	enum Action {
		NONE_ACTION = 6, UPDATE_INFO, FIRE_EMPLOYEE, PROMOTE_EMPLOYEE, DEMOTE_EMPLOYEE
	};

public:
	void executeRequest(int action) override;
	void collectParamater(std::string paramater) override;
	std::string getFileName() override;


};
