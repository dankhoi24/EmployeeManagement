/***********************************************************************
 * @file EMain.cpp
 * @author your name (you@domain.com)
 * @brief Main function
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
***********************************************************************/
#include <iostream>



#include"DAO/DBConnection.h"
#include "DAO/EmployeeDAO.h"
#include "Handler/BaseHandler.h"
#include "Handler/ViewHandler.h"
#include "Handler/SidebarHandler.h"


void showLogo() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
    SetConsoleTextAttribute(hConsole, 1);


		std::ifstream readMenu("Transporter/Printer/logo.txt");
		if (readMenu.is_open()) {
		}
		std::string line = "";
		while (getline(readMenu, line)) {
			std::cout << line << std::endl;
			Sleep(500);
		}
		readMenu.close();
    SetConsoleTextAttribute(hConsole, 15);

}

void initProgram(DBConnection * &database, BaseHandler *&current_handler, SidebarHandler *&sidebar_handler) {


	showLogo();


	database = DBConnection::getInstance();
	database->connectToDB();
	EmployeeDAO *x= new EmployeeDAO(database);
	current_handler = new ViewHandler(database);
	sidebar_handler = new SidebarHandler();
	sidebar_handler->printMenu(sidebar_handler->getFileName());

}






/**
 * @brief Main function
 * 
 * @return int 
 */
int main() {
	//Init Connection to database
	DBConnection* database;// = DBConnection::getInstance();
	BaseHandler *current_handler;
	SidebarHandler* sidebar_handler;
	initProgram(database, current_handler, sidebar_handler);
	//if (k.checkQueryString("s")) {
	//	k.getAll();
	//}
	

	//std::string a = "a";
	//try {

	//	int x = std::stoi(a);
	//}
	//catch(std::invalid_argument e) {
	//	std::cout << "f" << "\n";
	//}



	/*const char str[] = "SELECT* FROM Title";
	x->SQLQuery();
*/


	std::cout << "END" << std::endl;




	std::cin.get();
}