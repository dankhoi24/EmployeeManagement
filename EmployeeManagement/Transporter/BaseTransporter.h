#pragma once
#include "../Handler/BaseHandler.h"
#include "../Handler/ViewHandler.h"

class BaseTransporter {
protected:
	static BaseHandler* m_handler;
	static BaseHandler* m_default_handler;
	static DBConnection* m_database;
public:
	~BaseTransporter();

	static void onPropertyChanged(int action);

	static void setHandler(BaseHandler* handler);


};

