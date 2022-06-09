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

/**
 * @brief Main function
 * 
 * @return int 
 */
int main() {
	//Init Connection to database
	//DBConnection *x = DBConnection::getInstance();
	//x->connectToDB();
	//EmployeeDAO k(x);
	//if (k.checkQueryString("s")) {
	//	k.getAll();
	//}
	

	std::string a = "a";
	try {

		int x = std::stoi(a);
	}
	catch(std::invalid_argument e) {
		std::cout << "f" << "\n";
	}



	/*const char str[] = "SELECT* FROM Title";
	x->SQLQuery();
*/


	std::cout << "END" << std::endl;




	std::cin.get();
}