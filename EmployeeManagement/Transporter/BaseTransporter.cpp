#include "BaseTransporter.h"
#include "../Handler/SidebarHandler.h"
#include "Inputer.h"

	BaseTransporter::~BaseTransporter() {
		delete m_handler;
	}

	void BaseTransporter::onPropertyChanged(std::string message) {


		if (m_handler == NULL) {

			m_default_handler->updateAction(Inputer::getAction());
		}
		else {


			// check message type
			if (m_handler->isAction()) {
				if (Inputer::getAction() >= 1 && Inputer::getAction() <= 5) {
					
					m_default_handler->updateAction(Inputer::getAction());
				}
				else {

					m_handler->updateAction(Inputer::getAction());
				}
			}
			else {
				m_handler->updateParamater(message);
			}
		}
		m_handler->printMenu(m_handler->getFileName());
		m_default_handler->printMenu(m_default_handler->getFileName());
	}

	 void BaseTransporter::setHandler(BaseHandler * handler) {
		m_handler = handler;
	}
	 BaseHandler* BaseTransporter::m_handler = NULL;

	 BaseHandler* BaseTransporter::m_default_handler = new SidebarHandler();

	 DBConnection* BaseTransporter::m_database = DBConnection::getInstance();
