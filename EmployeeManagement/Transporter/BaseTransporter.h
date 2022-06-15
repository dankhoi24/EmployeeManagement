/**
 * @file BaseTransporter.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief header of Base Transporter is Base class for all host class as a Subject connect all handler
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "../Handler/BaseHandler.h"
#include "../Handler/ViewHandler.h"

/**
 * @brief Base class for all host class as a Subject connect all handler
 * 
 */
class BaseTransporter {
protected:
	// sub handler
	static BaseHandler* m_handler;
	// default handler
	static BaseHandler* m_default_handler;
	// database instance
	static DBConnection* m_database;
public:
	/**
	 * @brief Destroy the Base Transporter object
	 * 
	 */
	~BaseTransporter();
	/**
	 * @brief if property changed(by user) notify to handler
	 * 
	 * @param message 
	 */
	static void onPropertyChanged(std::string message);

	/**
	 * @brief Set the Handler object
	 * 
	 * @param handler 
	 */
	static void setHandler(BaseHandler* handler);


};

