/**
 * @file Title.h
 * @author ndKhoi (nguyen.khoi@hitachivantara.com)
 * @brief Model of Title
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <string>

#define String std::string

/**
 * @brief Model of Title
 * 
 */
class Title {
private:
	int m_ID;
	String m_name;
	double m_salary;

	enum Role {
		 FRESHER = 1, JUNIOR, SENIOR
	};
public:
	/**
	 * @brief Construct a new Title object
	 * 
	 * @param ID 
	 * @param name 
	 * @param salary 
	 */
	Title(int ID,const String &name, double salary);
	/**
	 * @brief Destroy the Title object
	 * 
	 */
	~Title();
};
