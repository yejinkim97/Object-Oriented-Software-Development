// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 25th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include "Workstation.h"

class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder = 0 ;

	Workstation*  m_Station=nullptr;
public:
	LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};

#endif