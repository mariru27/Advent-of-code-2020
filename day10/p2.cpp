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
	std::vector<int> adaptersjoltage;
	adaptersjoltage.push_back(0);
	while (!in.eof())
	{
		int jolts;
		in >> jolts;
		adaptersjoltage.push_back(jolts);

	}

	std::sort(adaptersjoltage.begin(), adaptersjoltage.end());

	int ratings[4]{};
	int joltagerating = 0;

	for (auto i = adaptersjoltage.begin(); i != adaptersjoltage.end(); ++i)
	{
		int temp = abs(joltagerating - (*i));
		joltagerating += temp;
		if (temp <= 3)
			++ratings[temp];

	}
	joltagerating += 3;
	++ratings[3];
	adaptersjoltage.push_back(joltagerating);

	//std::cout << ratings[1] * ratings[3];
	

	int arrange = 1;
	std::vector<long long int> adapters(adaptersjoltage.size());
	adapters[0] = 1;

	for (auto j = 1; j < adaptersjoltage.size(); ++j)
	{
		int result = 0;

		if (j - 1 >= 0 && adaptersjoltage[j] - adaptersjoltage[j - 1] <= 3)
			result++;
		if (j - 2 >= 0 && adaptersjoltage[j] - adaptersjoltage[j - 2] <= 3)
			result++;
		if (j - 3 >= 0 && adaptersjoltage[j] - adaptersjoltage[j - 3] <= 3)
			result++;

		if (result == 1)
			adapters[j] = adapters[j - 1];
		if (result == 2)
			adapters[j] = adapters[j - 1] + adapters[j - 2];
		if (result == 3)
			adapters[j] = adapters[j - 1] + adapters[j - 2] + adapters[j - 3];

	}

	std::cout << adapters[adaptersjoltage.size() - 1];

	return 0;
}
