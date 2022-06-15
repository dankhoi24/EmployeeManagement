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
#include "Lib/ColorLib.h"





/**
 * @brief show Employee logo of software [Transporter/Printer/logo.txt]
 * 
 */
void showLogo() {
	 	//read data from file
		std::ifstream readMenu("Transporter/Printer/logo.txt");
		// check opened file
		if (!readMenu.is_open()) {
			MessageBox(NULL,TEXT("Logo can't be loaded"),TEXT("Warning"),MB_OK);
			return;
		}
		// print out logo to console
		std::string line = "";
		while (getline(readMenu, line)) {
			// set blue text for logo
			BLUE_WORD
			std::cout << line << std::endl;
			CLEAR_COLOR
			Sleep(500);
		}
		readMenu.close();
}


/**
 * @brief init program 
 *        show logo, init database, set handler
 * 
 * @param database get pointer to database instance
 * @param current_handler get current handler or sub menu
 * @param sidebar_handler get sidebar hadnler or main menu
 */
void initProgram(DBConnection * &database, BaseHandler *&current_handler, SidebarHandler *&sidebar_handler) {

	// show logo to console
	showLogo();

	// init database
	database = DBConnection::getInstance();
	database->connectToDB();
	// init handler
	EmployeeDAO *x= new EmployeeDAO(database);
	current_handler = new ViewHandler(database); // sub handler
	sidebar_handler = new SidebarHandler();      // main handler
	sidebar_handler->printMenu(sidebar_handler->getFileName()); // print out default menu
}


/**
 * @brief Main function
 * 
 * @return int 
 */
int main() {
	//Init Connection to database
	DBConnection* database;// = DBConnection::getInstance();
	BaseHandler *current_handler; //current handler
	SidebarHandler* sidebar_handler; // sildebar handler
	initProgram(database, current_handler, sidebar_handler); // init program
	

	std::cout << "END" << std::endl;
	std::cin.get();
}