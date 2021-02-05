// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 25th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "Workstation.h"
using namespace std;

Workstation::Workstation(const std::string& rec) : Station(rec)
{
	m_pNextStation = nullptr;
}
void Workstation::runProcess(std::ostream& os)
{
	if (m_orders.empty())
		return;
	m_orders.front().fillItem(*this, os);
}
bool Workstation::moveOrder()
{
	if (!m_orders.empty()){
	if (m_orders.front().isItemFilled(this->getItemName()) && m_pNextStation)
	{
		*m_pNextStation += move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	}
		return false;
	
}
void Workstation::setNextStation(Workstation& station)
{
	m_pNextStation = &station;
}
const Workstation* Workstation::getNextStation() const
{
	return m_pNextStation;
}
bool Workstation::getIfCompleted(CustomerOrder& order)
{
	bool flag = false;
	if (m_orders.empty())
	{
		return flag;
	}
	flag = m_orders.front().isOrderFilled();
	if (flag)
	{
		order = move(m_orders.front());
		m_orders.pop_front();
	}
	return flag;
}
void Workstation::display(std::ostream& os) const
{
	if (!m_pNextStation)
		os << getItemName() << " --> END OF LINE" << endl;
	else
		os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;

}
Workstation& Workstation::operator+=(CustomerOrder&& co)
{
	m_orders.push_back(move(co));
	return *this;
}