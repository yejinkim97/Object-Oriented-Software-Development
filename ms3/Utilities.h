// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 12th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Station.h"
class Utilities
{
	size_t m_widthField{ 1 };
	static char m_delimiter;
public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};

#endif