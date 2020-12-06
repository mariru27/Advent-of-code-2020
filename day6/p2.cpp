#include<iostream>
#include<fstream>
#include<vector>
#include <string> 
#include<unordered_map>
#include<map>
#include <algorithm>    
#include "mynamespace.h"
#include<set>


void updateSet(std::set<int>& s, int val)
{

	if (s.find(val) == s.end())
	{
		
	}
	
}

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");

	std::set<int> questions;
	//std::vector<int> answer;
	std::string line;
	std::vector<std::string> s;
	int sum = 0;
	int sumpart2 = 0;
	while (!in.eof())
	{
		std::getline(in, line);
		if (line != "")
		{
			s.push_back(line);
			for (auto i = line.begin(); i < line.end(); ++i)
			{
				questions.insert(*i);
			}

		}

		if (line == "")
		{

			
			int answer[300]{};


			for (int i = 0; i < s.size(); ++i)
			{
				for (auto j = s[i].begin(); j != s[i].end(); ++j)
				{
					++answer[*j];
				}
			}


			for (auto j = 'a'; j <= 'z'; ++j)
			{
				if (answer[j] == s.size())
					++sumpart2;
			}
				//std::cout << sumpart2 << " ";
			
			//std::cout << questions.size();
			
			sum += questions.size();
			questions.clear();
			s.clear();
		}
	}
	std::cout << sumpart2;
	
	return 0;
}
