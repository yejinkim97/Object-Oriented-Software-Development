// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 12th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "Station.h"

using namespace std;

unsigned int Station::m_widthField = 0;
unsigned int Station::id_generator = 0;

Station::Station(const std::string& str)
{
	Utilities utilObj;
	size_t next_pos = 0;
	bool more = true;

	m_id = ++Station::id_generator;
	if (str.empty())
	{
		m_name = "";
		m_serialNumber = 0;
		m_quantity = 0;
	}
	else
	{
		m_name = utilObj.extractToken(str, next_pos, more);
		if (more)
		{
			string tmp = utilObj.extractToken(str, next_pos, more);
			m_serialNumber = atoi(tmp.c_str());
		}
		if (more)
		{
			string tmp = utilObj.extractToken(str, next_pos, more);
			m_quantity = atoi(tmp.c_str());
		}
		if (m_widthField < utilObj.getFieldWidth())
			m_widthField = utilObj.getFieldWidth();
		if (more)
		{
			m_desc = utilObj.extractToken(str, next_pos, more);
		}
	}
	
}
const string& Station::getItemName() const
{
	return m_name;
}
unsigned int Station::getNextSerialNumber()
{
	return m_serialNumber++;
}
unsigned int Station::getQuantity() const
{
	return m_quantity;
}
void Station::updateQuantity()
{
	m_quantity--;
	if (m_quantity < 0)
		m_quantity = 0;
}
void Station::display(ostream& os, bool full) const
{
	if (!full)
	{
		os << "[" << right << setw(3) << setfill('0') << m_id << "]"
			<< " Item: " << left << setw(m_widthField) << setfill(' ') << m_name
			<< " [" << right << setw(6) << setfill('0') << m_serialNumber << "]" << endl;
	}
	else
	{
		os << "[" << right << setw(3) << setfill('0') << m_id << "]"
			<< " Item: " << left << setw(m_widthField) << setfill(' ') << m_name
			<< " [" << right << setw(6) << setfill('0') << m_serialNumber << "]"
			<< " Quantity: " << left << setw(m_widthField) << setfill(' ') << m_quantity
			<< " Description: " <<  m_desc << endl;
	}
}