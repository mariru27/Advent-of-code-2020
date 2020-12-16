#include<iostream>
#include<fstream>
#include<vector>
#include <string> 
#include<unordered_map>
#include<map>
#include <algorithm>    
#include "mynamespace.h"
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iterator>
#include<map>

bool ticketInRange(std::map<int, int>  rangeTickets, int  ticket)
{
	int range;
	for (auto i = rangeTickets.begin(); i != rangeTickets.end(); ++i)
	{
		if (ticket >= i->first && ticket <= i->second)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	std::string line;
	std::vector<int> mytickets;
	std::map<int,int> rangeTickets;
	int sumInvalidTickets = 0;

	while (!in.eof())
	{
		std::getline(in,line);
		//read ranges
		while (!line.empty())
		{
			int bRange = mynamespace::extractFirstNumber(line);
			int eRange = mynamespace::extractFirstNumber(line);
			rangeTickets[bRange] = eRange;

			bRange = mynamespace::extractFirstNumber(line);
			eRange = mynamespace::extractFirstNumber(line);
			rangeTickets[bRange] = eRange;
			std::getline(in, line);
		}
		//read my tickets
		std::getline(in, line);
		std::getline(in, line);
		while (!line.empty())
		{
			int t = mynamespace::extractFirstNumber(line);
			mytickets.push_back(t);
		}

		//read nearby tickets
		std::getline(in, line);
		std::getline(in, line);
		while (!in.eof())
		{
			std::getline(in, line);
			while (!line.empty())
			{
				int nearbyTiket = mynamespace::extractFirstNumber(line);
				if (ticketInRange(rangeTickets, nearbyTiket) == false)
				{
					sumInvalidTickets += nearbyTiket;
				}
			}

		}

	}
	std::cout << sumInvalidTickets;
	return 0;
}
