// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 16th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "Utilities.h"
#include "Station.h"

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src)
	{
	};
};
class CustomerOrder
{
	
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(const std::string& rec);  
	CustomerOrder(const CustomerOrder&);
	CustomerOrder(CustomerOrder&& other) noexcept;
	CustomerOrder& operator=(CustomerOrder&& other) noexcept;
	~CustomerOrder();
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};

#endif