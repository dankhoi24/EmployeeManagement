#pragma once
#include <string>

class BaseHandler {
public:
	virtual void executeRequest(int action) = 0;
	virtual void printMenu() = 0;
	~BaseHandler() {
		delete m_subHandler;
	}
private:
	BaseHandler* m_subHandler = NULL;
};
