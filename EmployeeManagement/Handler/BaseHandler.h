#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../DAO/EmployeeDAO.h"
#include <filesystem>
class BaseHandler {


public:
	virtual void executeRequest(int action) = 0;
	virtual void collectParamater(std::string paramater) = 0;
	virtual std::string getFileName() = 0;
	virtual void printTitle() {
		std::cout << "#########################\n";
	}
	~BaseHandler();


	void printMenu(std::string filename);
	void updateAction(int action);
	void updateParamater(std::string paramater);
	bool isAction();


protected:
	BaseHandler* m_subHandler = NULL;
	int m_action;
	std::string m_paramater;



	static enum e_message_type {
		ACTION = 1, PARAMATER
	};

	e_message_type m_state = e_message_type::ACTION;
};
