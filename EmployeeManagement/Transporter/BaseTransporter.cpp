/**
 * @file BaseTransporter.cpp
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief Base Transporter is Base class for all host class as a Subject connect all handler
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "BaseTransporter.h"
#include "../Handler/SidebarHandler.h"
#include "Inputer.h"

	BaseTransporter::~BaseTransporter() {
		// delete handler pointer
		delete m_handler;
	}

	void BaseTransporter::onPropertyChanged(std::string message) {

		// if handler =NULL => message belong to default handler (sildebar handler)
		if (m_handler == NULL) {
			// Update action of default handler
			m_default_handler->updateAction(Inputer::getAction());
		}
		else {
			//check state of handler is ACTION or PARAMATER
			if (m_handler->isAction()) {
				//if action belong to 1-5 mean belong to default handler (Sidebar)
				if (Inputer::getAction() >= 1 && Inputer::getAction() <= 5) {
					// Update action of default handler
					m_default_handler->updateAction(Inputer::getAction());
				}
				else {
					//if action not belong to 1-5 mean belong to default handler (Sidebar)
					// Update action of handler
					m_handler->updateAction(Inputer::getAction());
				}
			}
			else {
				// not handler state is PARAMATER
				m_handler->updateParamater(message);
			}
		}
		// print menu of sub handler
		m_handler->printMenu(m_handler->getFileName());
		// print menu of default handler (sidebar)
		m_default_handler->printMenu(m_default_handler->getFileName());
	}

	 void BaseTransporter::setHandler(BaseHandler * handler) {
		// set sub handler
		m_handler = handler;
	}
	 // init sub handler = NULL
	 BaseHandler* BaseTransporter::m_handler = NULL;

	// default handler always have data
	 BaseHandler* BaseTransporter::m_default_handler = new SidebarHandler();
	// get database instance
	 DBConnection* BaseTransporter::m_database = DBConnection::getInstance();
