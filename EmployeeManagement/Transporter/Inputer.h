/**
 * @file Inputer.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief get input from user and notify to handler
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <string>
#include <iostream>
#include "BaseTransporter.h"

/**
 * @brief get input from user and notify to handler 
 * 
 */
class Inputer: public BaseTransporter{
	// input from user
	static std::string m_value;
public:
	/**
	 * @brief Set the Value by user
	 * 
	 */
	static void setValue();
	/**
	 * @brief Get the Action from user
	 * 
	 * @return int 
	 */
	static int getAction();
	
	
};
