/**
 * @file Inputer.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief get input from user and notify to handler
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Inputer.h"

	void Inputer::setValue() {
		// get input from user
		getline(std::cin, m_value);
		// clear buffer
		fflush(stdin);
		// Notify to handler
		onPropertyChanged(m_value);
	}


	int Inputer::getAction() {
		try {
			// convert string to int (action)
			return std::stoi(m_value);
		}
		catch (std::invalid_argument e) {
			return 0;
		}
	}
	// init value of action
	std::string Inputer::m_value = "";
