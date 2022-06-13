#include "AddHandler.h"
#include "../Transporter/Inputer.h"




AddHandler::AddHandler(DBConnection* database)
	:m_database(database) {
	m_state = e_message_type::PARAMATER;
	m_add_state = State::NAME;
	}

bool AddHandler::isFinsh() {

	return m_add_state == State::TITLE;

	}

void AddHandler::updateEmployee() {
	//update database
	EmployeeDAO employeeDb(m_database);
	employeeDb.addEmployee(m_employee);

	// changed handler
	Inputer::setHandler(new ViewHandler(DBConnection::getInstance()));

}
void AddHandler::executeRequest(int action) {
	std::cout << "ADDING ACTION \n";
	}
void AddHandler::collectParamater(std::string paramater) {
	std::cout << m_add_state << "\n";



	switch (m_add_state)
	{
	case NAME:

		m_employee.setName(paramater);
		m_add_state = State::PHONE;
		return;
	case PHONE:
		m_employee.setPhone(paramater);
		m_add_state = State::ADDRESS;
		return;
	case ADDRESS:
		m_employee.setAddess(paramater);
		m_add_state = State::MAIL;
		return;
	case MAIL:
		m_employee.setMail(paramater);
		m_add_state = State::GENDER;
		return;
	case GENDER:
		m_employee.setAddess(paramater);
		m_add_state = State::STARTDATE;
		return;
	case STARTDATE:
		m_employee.setStartDate(paramater);
		m_add_state = State::TITLE;
		return;
	case TITLE:
		m_employee.setRole("sth");
		// do sth
		updateEmployee();
		return;
	default:
		break;
	}

	}
std::string AddHandler::getFileName() {
	return ADD_HANDLER_MENU;
	}





void AddHandler::printTitle() {
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
		return;
	case STARTDATE:
		std::cout << "Enter employee's start date\n";
		return;
	case TITLE:
		std::cout << "Enter employee's title\n";
		return;

	default:
		break;
	}



	}







