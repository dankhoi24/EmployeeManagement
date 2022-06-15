/**
 * @file UpdateHandler.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "UpdateHandler.h"

void UpdateHandler::executeRequest(int action) {
	// init employee database
	EmployeeDAO employeedb(DBConnection::getInstance());
	// check which action
	switch (action)
	{
	case NONE_ACTION: // None action
		return;
	case UPDATE_INFO: // update info action
		return;
	case FIRE_EMPLOYEE: // fire employee action
	 	// fire employee by ID
		employeedb.FireEmployee(std::to_string(m_employee->getId()));
		return;
	case PROMOTE_EMPLOYEE: // promote employee action
		promoteEmployee();
		return;
	case DEMOTE_EMPLOYEE: // demote employee action
		demoteEmployee();
		return;
 default:
		break;
	}
}


int UpdateHandler::getIndex() {
	// init employee database
	EmployeeDAO employeeDb(DBConnection::getInstance());
	// get role id by employee id
	std::string role = employeeDb.getRoleById(m_employee->getId());
	
	// find role index in role hierarchical structure
	for (int i = 0; i < m_Roles.size(); i++) {
		for (int j = 0; j < m_Roles[i].size(); j++) {
			std::cout << m_Roles[i][j] << std::endl;
			if (m_Roles[i][j] == role ) {
				return i;
			}
			
		}

	}
	
	return -1;
}



void UpdateHandler::demoteEmployee() {

	// get role index in role hierarchical structure
	int index = getIndex();
	if (index == -1) {
		return;
	}

	// check employee's role is lowest
	if (index == (m_Roles.size() - 1 )){
		// can not promote 
		MessageBox(NULL, TEXT("NOT EXIST"), TEXT("WARNING"), MB_OKCANCEL);
		return;

	}
	// get name of role
	std::string role = m_Roles[index + 1 ][0];

	// init employee database
	EmployeeDAO employeeDb(DBConnection::getInstance());
	// set role for employee
	employeeDb.setRoleEmployee(std::to_string(m_employee->getId()), role);
}

void UpdateHandler::promoteEmployee() {
	
	// get role index in role hierarchical structure
	int index = getIndex();
	if (index == -1) {
		MessageBox(NULL, TEXT("NOT EXIST"), TEXT("WARNING"), MB_OKCANCEL);
		return;
	}


	// check employee's role is highest
	if (index == 0){
		// can not promote 
		MessageBox(NULL, TEXT("CAN NOT PROMOTE"), TEXT("WARNING"), MB_OKCANCEL);
		return;
	}
	// get name of role
	std::string role = m_Roles[index-1][0];

	// init employee database
	EmployeeDAO employeeDb(DBConnection::getInstance());
	// set role for employee
	employeeDb.setRoleEmployee(std::to_string(m_employee->getId()), role);
}
	


UpdateHandler::UpdateHandler(Employee * employee) 
	:m_employee(employee) {
	// init role heirarchical structure
	getRole();
}


void UpdateHandler::deleteLeadSpace( std::string& str) {
	// delete lead speace
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}



void UpdateHandler::deleteTrailingSpace( std::string& str) {
	// delete trailing space
	str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), str.end());
}

void UpdateHandler::getString(std::string& str, int&index){
	/**
	 * @brief remove lead and trailing space from string
	 * 
	 */
	deleteLeadSpace(str);
	deleteTrailingSpace(str);
	/////////////////////////////////
	
	// check if string employ
	if (str == "") {
		return;
	}


	std::cout << m_Roles.size() << std::endl;
	// if encounter "{" increase level to +1
	if (str == "{") {
		index++;
		if (m_Roles.size() < index) {
			m_Roles.push_back(std::vector<std::string>());
		}
	}
	// if encount "}" decrease level to -1
	else if (str == "}") {
		index--;
	}
	// if encounter any character -> handle to get role name
	else {
		//get string in "STRING"
		str = str.substr(1);
		str = str.substr(0, str.find("\""));


		std::cout << "Break\n";
		// push string to role heirarchical structure
		m_Roles[index-1].push_back(str);
	}
}


void UpdateHandler::readFile() {
	// init role level
	int index = 0;
	// role vector-2d
	std::vector < std::vector<std::string>> m_Roles;
	// role name
	std::string str;
	// reading file
	std::ifstream file("Model/Roles.txt");
	while (getline(file, str)) {
		std::cout << str << std::endl;
		getString(str, index);
	}
	file.close();

	for (int i = 0; i < m_Roles.size(); i++) {
		std::cout << "----\n";
		for (int j = 0; j < m_Roles[i].size();  j++) {
			std::cout << m_Roles[i][j] << std::endl;
		}

		std::cout << "----\n";
	}
}

// get role from Roles file [Model/Roles.txt]
void UpdateHandler::getRole() {
	readFile();
}



void UpdateHandler::collectParamater(std::string paramater) {
	// colect paramater (if any)
	}

std::string UpdateHandler::getFileName() {
	// return file path update menu
	return UPDATE_HANDLER_MENU;
	}
