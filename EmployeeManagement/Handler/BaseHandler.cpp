#include "BaseHandler.h"
#include "../Transporter/Inputer.h"
#include "SidebarHandler.h"


	bool BaseHandler::isAction() {
		return m_state == e_message_type::ACTION;
	}


	void BaseHandler::printMenu(std::string filename){

		std::ifstream readMenu(filename);
		if (readMenu.is_open()) {
		}
		std::string line = "";
		while (getline(readMenu, line)) {
			std::cout << line << std::endl;
		}
		readMenu.close();

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


