/**
 * @file PrintLib.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief Print library 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <vector>
#include <iostream>


/**
 * @brief printer class contain function<T> to print out database of paramater
 * 
 * @tparam T 
 */
template<typename T>
class PrintLib {


public:
	/**
	 * @brief print vector 
	 * 
	 * @param v_entity 
	 */
	static void printVector(const std::vector<T>& v_entity);
	static void printEntry(const T& entity);

};

	template<typename T>
	 void PrintLib<T>::printVector(const std::vector<T> &v_entity){
		// travel all element from vector and print to console
		for (auto it = v_entity.begin(); it!= v_entity.end();it++){
			std::cout << (*it) << "\n";
		}
	}

	 template<typename T>
	void PrintLib<T>::printEntry(const T& entity) {
		std::cout << entity << std::endl;
	}

	 
