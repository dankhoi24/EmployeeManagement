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
		employeedb.FireEmployee(std::to_string(m_employee->getId()));
		return;
	case PROMOTE_EMPLOYEE:
		promoteEmployee();
		return;
	case DEMOTE_EMPLOYEE:
		demoteEmployee();
		return;
 default:
		break;
	}
}

//int findRole() {
//	
//}

int UpdateHandler::getIndex() {
	
	EmployeeDAO employeeDb(DBConnection::getInstance());
	std::string role = employeeDb.getRoleById(m_employee->getId());
	std::cout << "ROLE " << role << std::endl;
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

	int index = getIndex();
	if (index == -1) {
		return;
	}


	if (index == (m_Roles.size() - 1 )){
		// can not promote 

		return;

	}

	std::string role = m_Roles[index + 1 ][0];


	EmployeeDAO employeeDb(DBConnection::getInstance());
	employeeDb.setRoleEmployee(std::to_string(m_employee->getId()), role);
	}

void UpdateHandler::promoteEmployee() {
	
	int index = getIndex();
	if (index == -1) {
		MessageBox(NULL, TEXT("NOT EXIST"), TEXT("WARNING"), MB_OKCANCEL);
		return;
	}


	if (index == 0){
		// can not promote 

		MessageBox(NULL, TEXT("CAN NOT PROMOTE"), TEXT("WARNING"), MB_OKCANCEL);
		return;

	}

	std::string role = m_Roles[index-1][0];


	EmployeeDAO employeeDb(DBConnection::getInstance());
	employeeDb.setRoleEmployee(std::to_string(m_employee->getId()), role);
}
	


UpdateHandler::UpdateHandler(Employee * employee) 
	:m_employee(employee) {
	getRole();
	}

// ger Role

void UpdateHandler::deleteLeadSpace( std::string& str) {
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}



void UpdateHandler::deleteTrailingSpace( std::string& str) {
	str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), str.end());
}

void UpdateHandler::getString(std::string& str, int&index){
	deleteLeadSpace(str);
	deleteTrailingSpace(str);
	if (str == "") {
		return;
	}


	std::cout << m_Roles.size() << std::endl;
	if (str == "{") {
		index++;
		if (m_Roles.size() < index) {
			m_Roles.push_back(std::vector<std::string>());
		}
	}
	else if (str == "}") {
		index--;
	}
	else {
		str = str.substr(1);
		str = str.substr(0, str.find("\""));


		std::cout << "Break\n";
		m_Roles[index-1].push_back(str);
	}
	

	
}

void UpdateHandler::readFile() {
	int index = 0;
	std::vector < std::vector<std::string>> m_Roles;
	std::string str;
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


void UpdateHandler::getRole() {
	readFile();

	}



void UpdateHandler::collectParamater(std::string paramater) {

	}
std::string UpdateHandler::getFileName() {
	return UPDATE_HANDLER_MENU;
	}
