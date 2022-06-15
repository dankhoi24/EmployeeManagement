/**
 * @file AddHandler.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief Add handler to manage adding employee operator
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "AddHandler.h"
#include "../Transporter/Inputer.h"
#include "../DAO/TitleDAO.h"
#include "../Lib/PrintLib.h"




AddHandler::AddHandler(DBConnection* database)
	:m_database(database) { // init database
	// set handler state for addhander = PARAMATER
	m_state = e_message_type::PARAMATER;
	// set action state for addhandler = NAME
	m_add_state = State::NAME;
	}

bool AddHandler::isFinsh() {
	// if action state == TITLE mean -> finish adding operator
	return m_add_state == State::TITLE;
}


void AddHandler::updateEmployee() {
	//update database
	EmployeeDAO employeeDb(m_database);
	employeeDb.addEmployee(m_employee);
	//print result
	Employee::printHeader();
	PrintLib<Employee>::printEntry(m_employee);

	// changed handler
	Inputer::setHandler(new ViewHandler(DBConnection::getInstance()));
}


void AddHandler::executeRequest(int action) {
	std::cout << "ADDING ACTION \n";
}


void AddHandler::collectParamater(std::string paramater) {
	std::cout << m_add_state << "\n";
	// check which curent action state
	switch (m_add_state)
	{
	case NAME: // adding name sate
		m_employee.setName(paramater); // get paramater from user
		m_add_state = State::PHONE;	   // set next action state [PHONE]
		return;
	case PHONE: // adding contect No state
		m_employee.setPhone(paramater); //get paramater from user
		m_add_state = State::ADDRESS;   // set next actions state [ADDRESS]
		return;
	case ADDRESS: // adding address state
		m_employee.setAddess(paramater); // get paramater from user
		m_add_state = State::MAIL; // set next action state [MAIL]
		return;
	case MAIL: // adding mail state
		m_employee.setMail(paramater); // get paramater from user
		m_add_state = State::GENDER;  // set next action state [GENDER]
		return;
	case GENDER: // adding gender state
		m_employee.setGender(paramater[0]); // get paramater from user
		m_add_state = State::STARTDATE;  // set next action state [START DATE]
		return;
	case STARTDATE: // adding gender state 
	 	// check user input date isValid
		if (m_employee.setStartDate(paramater)) { 
			MessageBox(NULL, TEXT("Invalid date"), TEXT("Error"), MB_OKCANCEL);
			return;
		}
		m_add_state = State::TITLE; // set next action state [TITLE]
		return;
	case TITLE: // adding title state
		m_employee.setRole(paramater); // get paramater from user
		
		// done adding operator
		// update employee to database
		updateEmployee();
		return;
	default:
		break;
	}

	}
std::string AddHandler::getFileName() {
	// return string of file name 
	return ADD_HANDLER_MENU;
	}


void AddHandler::printTitleOption() {
	// create title_DAO
	TitleDAO titledb(DBConnection::getInstance());
	// get all title
	std::vector<Title> v_title = titledb.getAll();
	// show all title to console 
	for (auto it = v_title.begin(); it != v_title.end(); it++) {
		std::cout << it->getTitleID() << ". " << it->getTitleName() << std::endl;
	}

}

void AddHandler::printTitle() {
	// print title for each adding operator
	switch (m_add_state)
	{
	case NAME:
		std::cout << "Enter employee's name\n";
		return;
	case PHONE:
		std::cout << "Enter employee's phone\n";
		return;
	case ADDRESS:
		std::cout << "Enter employee's address\n";
		return;
	case MAIL:
		std::cout << "Enter employee's mail\n";
		return;
	case GENDER:
		std::cout << "Enter employee's gender\n";
		std::cout << "0. Female" << std::endl;
		std::cout << "1. Male" << std::endl;
		std::cout << "any number. Undefined" << std::endl;
		return;
	case STARTDATE:
		std::cout << "Enter employee's start date [YYYY-MM-DD]\n";
		return;
	case TITLE:
		std::cout << "Enter employee's title\n";
		printTitleOption();
		return;

	default:
		break;
	}
}







