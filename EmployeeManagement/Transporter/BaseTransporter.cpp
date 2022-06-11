#include "BaseTransporter.h"
#include "../Handler/SidebarHandler.h"


	BaseTransporter::~BaseTransporter() {
		delete m_handler;
	}

	void BaseTransporter::onPropertyChanged(int action) {
		if (m_handler == NULL) {

			m_default_handler->updateAction(action);
		}
		else {
			m_handler->updateAction(action);
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
