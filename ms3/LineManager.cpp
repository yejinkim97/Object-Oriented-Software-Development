// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 25th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "LineManager.h"
#include"Utilities.h"
using namespace std;

LineManager::LineManager(const std::string& str, std::vector<Workstation*>& work, std::vector<CustomerOrder>& cust)
{
	Utilities myUtil;

	ifstream ifs(str);
	if(!ifs.is_open())
		throw string("ERROR: Unable to open");
	string record = "";
	string current = "";
	string next = "";
	size_t next_pos;
	bool more;

	while (!ifs.eof())
	{
		next_pos = 0;
		getline(ifs, record);

		current= myUtil.extractToken(record, next_pos, more);
		if (more)
			next = myUtil.extractToken(record, next_pos, more);
		else
			next = "";

		for (size_t i = 0;i < work.size();i++)
		{
			if (work[i]->getItemName() == current)
			{
				for (size_t y = 0;y < work.size();y++)
				{
					if (work[y]->getItemName() == next)
					{
						work[i]->setNextStation(*work[y]);
						break;
					}
				}
				if (m_Station==nullptr)
					m_Station=work[i];
			}
		}
	}
	ifs.close();

	for (size_t x = 0;x < cust.size();x++)
		ToBeFilled.push_back(move(cust[x]));

	m_cntCustomerOrder = ToBeFilled.size();
	AssemblyLine = work;
}
bool LineManager::run(std::ostream& os)
{
	static size_t cnt = 0;
	cout << "Line Manager Iteration: " << ++cnt << endl;
	if (!ToBeFilled.empty())
	{
		*m_Station += move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (size_t x = 0;x < AssemblyLine.size();x++)
		AssemblyLine[x]->runProcess(os);
	for (size_t x = 0u;x < AssemblyLine.size();++x)
	{
		
			AssemblyLine[x]->moveOrder();
		
		
			CustomerOrder order;
			if (AssemblyLine[x]->getIfCompleted(order))
				Completed.push_back(move(order));
		
	}
	if (Completed.size() == m_cntCustomerOrder)
		return true;
	else 
		return false;
}
void LineManager::displayCompletedOrders(std::ostream& os) const
{
	for (auto i = Completed.begin(); i != Completed.end(); i++)
	{
		(*i).display(os);
	}
}
void LineManager::displayStations() const
{
	for (size_t i = 0; i < AssemblyLine.size(); i++)
		AssemblyLine[i]->display(cout);
}
void LineManager::displayStationsSorted() const
{
	const Workstation* iter = m_Station;
	while (iter != nullptr)
	{
		iter->display(cout);
		iter = iter->getNextStation();
	}
}