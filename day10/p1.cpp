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
	//int nr;
	std::vector<int> adaptersjoltage;
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
		if(temp <= 3)
			++ratings[temp];
	}
	joltagerating += 3;
	++ratings[3];
	std::cout << ratings[1] * ratings[3];
	return 0;
}
