// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 12th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <list>
#include <iomanip>
#include <vector>
#include "Utilities.h"
class Station
{
	unsigned int m_id;
	std::string m_name;
	std::string m_desc;
	unsigned int m_serialNumber{ 0 };
	unsigned int m_quantity{ 0 };
	static unsigned int m_widthField;
	static unsigned int id_generator;
public:
	Station(const std::string& str);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif