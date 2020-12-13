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

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	std::string line;
	int earliestTimestamp;
	std::vector<int> ids;

	in >> earliestTimestamp;
	in >> line;
	while (line != "") 
	{
		int nr = mynamespace::extractFirstNumber(line);
		ids.push_back(nr);
	}


	std::vector<int>timestamps;

	for (int i = 0; i < ids.size(); ++i)
	{
		int j = 1;
		int times = 0;
		while (times <= earliestTimestamp)
		{
			times = ids[i] * j;
			++j;
		}
		timestamps.push_back(times);
	}

	int earliestBus = *std::min_element(timestamps.begin(), timestamps.end());

	auto busit = std::find(timestamps.begin(), timestamps.end(), earliestBus);

	int waitT = abs(earliestTimestamp - earliestBus);

	std::cout << waitT * ids[std::distance(timestamps.begin(),busit)];

	return 0;
}
