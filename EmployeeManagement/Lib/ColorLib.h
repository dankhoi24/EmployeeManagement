/**
 * @file ColorLib.h
 * @author ndkhoi (nguyen.khoi@hitachivantara.com)
 * @brief Library for set collect to text 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <windows.h>


/**
 * @brief set color of text
 * 
 */
#define BLUE_WORD SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 1);
#define RED_WORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
#define CYAN_WORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
#define LIGHT_BLUE_WORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
/**
 * @brief clear color of text
 * 
 */
#define CLEAR_COLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
 