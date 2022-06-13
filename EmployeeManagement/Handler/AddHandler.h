#pragma once
#include "BaseHandler.h"


#define	ADD_HANDLER_MENU "Transporter/Printer/AddMenu.txt" 

// form console

class AddHandler: public BaseHandler{
	enum State {
		NAME = 0, PHONE, ADDRESS, MAIL,GENDER, STARTDATE, TITLE
	};


	DBConnection* m_database;
	Employee m_employee;



	State m_add_state;
public:

	~AddHandler() {
		delete m_database;
		//delete m_employee;
			
	}

	bool isFinsh();

	void executeRequest(int action) override;
	void collectParamater(std::string paramater) override;
	std::string getFileName()override;
	void printTitle() override;

	void updateEmployee();
	AddHandler(DBConnection *database);
};
