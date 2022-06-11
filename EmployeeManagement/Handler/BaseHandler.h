#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../DAO/EmployeeDAO.h"
#include <filesystem>
class BaseHandler {


public:
	virtual void executeRequest(int action) = 0;
	virtual std::string getFileName() = 0;
	~BaseHandler();


	void printMenu(std::string filename);
	void updateAction(int action);
protected:
	BaseHandler* m_subHandler = NULL;
	int m_action;
};
