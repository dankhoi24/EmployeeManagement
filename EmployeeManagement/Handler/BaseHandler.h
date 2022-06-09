#pragma once
#include <string>

class BaseHandler {
	virtual void executeRequest(int action) = 0;
	virtual void printMenu() = 0;
};
