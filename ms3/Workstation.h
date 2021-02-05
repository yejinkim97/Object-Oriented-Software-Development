// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 25th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

class Workstation : public Station
{
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;
public:
	Workstation(const Workstation&) = delete;
	Workstation& operator=(Workstation&) = delete;
	Workstation(Workstation&&) noexcept = delete;
	Workstation& operator=(Workstation&&) noexcept = delete;
	Workstation(const std::string&);
	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Workstation& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
	Workstation& operator+=(CustomerOrder&&);
};

#endif