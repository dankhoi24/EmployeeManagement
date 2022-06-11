#pragma once
#include <string>
#include <iostream>
#include "BaseTransporter.h"

class Inputer: public BaseTransporter{
	static std::string m_value;
public:
	static void setValue();
	static int getValue();
	
	
};
