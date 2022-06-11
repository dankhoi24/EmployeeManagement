#include "BaseHandler.h"
#include "../Transporter/Inputer.h"
#include "SidebarHandler.h"

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

	BaseHandler::~BaseHandler() {
		delete m_subHandler;
	}


