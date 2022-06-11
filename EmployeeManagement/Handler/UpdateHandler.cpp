#include "UpdateHandler.h"



void UpdateHandler::executeRequest(int action) {
	EmployeeDAO employeedb(DBConnection::getInstance());

	switch (action)
	{
	case NONE_ACTION:
		return;
	case UPDATE_INFO:
		return;
	case FIRE_EMPLOYEE:
		return;
	case PROMOTE_EMPLOYEE:
		return;
	case DEMOTE_EMPLOYEE:
		return;
 default:
		break;
	}
}
void UpdateHandler::collectParamater(std::string paramater) {

	}
std::string UpdateHandler::getFileName() {

	}
