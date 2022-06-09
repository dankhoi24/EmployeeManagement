#pragma once

#include "BaseHandler.h"


class SidebarHandler : public BaseHandler {
	enum Action {
		NONE_ACTION = 0 ,VIEW , SEARCH, FILTER, ADD, EDIT
	};
public:
	void executeRequest(int action)override {
		switch (action)
		{
		case NONE_ACTION:
			//sth
			return;
		case VIEW:
			return;
		case SEARCH:
			return;
		case FILTER:
			return;
		case ADD:
			return;
		case EDIT:
			return;
		}
		// warning no option . . .
	}
};
