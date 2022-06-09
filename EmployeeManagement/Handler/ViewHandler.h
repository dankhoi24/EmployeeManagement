#pragma once
#include "BaseHandler.h"

class ViewHandler: public BaseHandler{
	enum Action
	{
		NONE_ACTION = 0, VIEW_ALL, VIEW_CURRENT, VIEW_FORMER
	};

public:

	void executeRequest(int action)override {
		switch (action)
		{
		case NONE_ACTION:
			//sth
			return;
		case VIEW_ALL:
			return;
		case VIEW_CURRENT:
			return;
		case VIEW_FORMER:
			return;
		}
		// warning no option . . .
	}

};
