#include<iostream>
#include<fstream>
#include<vector>
#include <string> 
#include<unordered_map>
#include<map>
#include <algorithm>    
#include "mynamespace.h"
#include<set>


int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");

	std::set<int> questions;

	std::string line;
	int sum = 0;

	while (!in.eof())
	{
		std::getline(in, line);
		if (line != "")
		{
			for (auto i = line.begin(); i < line.end(); ++i)
			{
				questions.insert(*i);
			}
		}

		if (line == "")
		{

			//std::cout << questions.size();
			sum += questions.size();
			questions.clear();
		}
	}
	std::cout << sum;
	
	return 0;
}
