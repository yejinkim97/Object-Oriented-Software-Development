// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 16th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "CustomerOrder.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;
CustomerOrder::CustomerOrder()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;

}
CustomerOrder::CustomerOrder(const std::string& rec)
{
	Utilities util;
	size_t pos = 0;
	bool more = false;
	if (rec.empty())
	{
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	else
	{
		m_name = util.extractToken(rec, pos, more);
		if (more)
		{
			m_product = util.extractToken(rec, pos, more);
		}
		string strItems = rec.substr(pos, rec.length() - pos);
		m_cntItem = (count(strItems.begin(), strItems.end(), util.getDelimiter())) + 1;
		m_lstItem = new Item * [m_cntItem];
		for (auto i = 0u; i < m_cntItem && more; i++)
			m_lstItem[i] = new Item(util.extractToken(rec, pos, more));
		if (m_widthField < util.getFieldWidth())
			m_widthField = util.getFieldWidth();
	}
}
CustomerOrder::CustomerOrder(const CustomerOrder&)
{
	throw "ERROR No Copy!";
}
CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept
{
	m_lstItem = nullptr;
	m_cntItem = 0;
	*this = move(other);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept
{
	if (this != &other)
	{
		for (auto i = 0u; i < m_cntItem;i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_name = other.m_name;
		m_product = other.m_product;
		m_cntItem = other.m_cntItem;
		m_lstItem = other.m_lstItem;

		other.m_lstItem = nullptr;
		other.m_cntItem = 0;
	}
	return *this;
}
CustomerOrder::~CustomerOrder()
{
	for (auto i = 0u; i < m_cntItem; ++i)
		delete m_lstItem[i];
	delete[] m_lstItem;
}
bool CustomerOrder::isOrderFilled() const
{
	bool filled = true;
	for (unsigned int i = 0;i < m_cntItem;i++)
	{
		if (!m_lstItem[i]->m_isFilled)
			filled = false;
	}
	return filled;
}
bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	for (unsigned int i = 0;i < m_cntItem;i++)
	{
		if (m_lstItem[i]->m_itemName == itemName)
			return m_lstItem[i]->m_isFilled;
	}
	return true;
}
void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for (unsigned int i = 0;i < m_cntItem;i++)
	{
		if (m_lstItem[i]->m_itemName == station.getItemName())
		{
			if (station.getQuantity() > 0)
			{
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				station.updateQuantity();
				os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
			}else
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
		}
	}
}
void CustomerOrder::display(std::ostream& os) const
{
	string fill;
	os << m_name << " - " << m_product << endl;
	for (unsigned int i = 0; i < m_cntItem; i++)
	{
		if ((m_lstItem[i]->m_isFilled))
			fill = "FILLED";
		else
			fill = "MISSING";
		os << "[" << right << setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber << "] "
			<< left << setfill(' ') << setw(m_widthField) << m_lstItem[i]->m_itemName << " - " << fill << endl;
	}
}
