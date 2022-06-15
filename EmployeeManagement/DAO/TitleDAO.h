/**
 * @file TitleDAO.h
 * @author dnkhoi (nguyen.khoi@hitachivantara.com)
 * @brief header of title DAO
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <string>
#include "BaseDAO.h"
#include"../Model/Title.h"

/**
 * @brief get data from title table
 * 
 */
class TitleDAO : public BaseDAO<Title>{
	
public:
	/**
	 * @brief Get the Title By Id
	 * 
	 * @param title_id 
	 * @return std::string 
	 */
	std::string getTitleById(std::string title_id);
	/**
	 * @brief Construct a new TitleDAO object
	 * 
	 * @param database 
	 */
	TitleDAO(DBConnection* database);
	/**
	 * @brief Get the All title in database
	 * 
	 * @return std::vector<Title> 
	 */
	std::vector<Title> getAll() override;
};
