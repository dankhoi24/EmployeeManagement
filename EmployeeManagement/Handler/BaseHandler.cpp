/**
 * @file BaseHandler.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "BaseHandler.h"
#include "../Transporter/Inputer.h"
#include "SidebarHandler.h"
#include "../Lib/ColorLib.h"

	bool BaseHandler::isAction() {
		//check handler state is action or not
		return m_state == e_message_type::ACTION;
	}


	void BaseHandler::printMenu(std::string filename){
		// reading menu file
		std::ifstream readMenu(filename);
		if (readMenu.is_open()) {
		}
		std::string line = "";
		while (getline(readMenu, line)) {
			CYAN_WORD
			std::cout << line << std::endl;
			CLEAR_COLOR
		}
		readMenu.close();

		// print out title for action operator (if any)
		printTitle();
		// check handler is sidebarhand -> perform input value from user
		if (dynamic_cast<SidebarHandler*>(this)) {

			Inputer::setValue();
		}
	}
	


	void BaseHandler::updateAction(int action) {
		m_action = action;
		executeRequest(action);
	}

	void BaseHandler::updateParamater(std::string paramater) {
		m_paramater = paramater;
		collectParamater(paramater);
			
	}

	BaseHandler::~BaseHandler() {
		delete m_subHandler;
	}


