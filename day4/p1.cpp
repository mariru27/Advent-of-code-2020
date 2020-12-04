#include<iostream>
#include<fstream>
#include<vector>
#include <string> 
#include<unordered_map>
#include <algorithm>    

std::string extractpassFiled(std::string &s)
{
	std::string resultf;
	int i = 0;
	resultf = s.substr(0, 3);

	while (s[i] != ' ' && i < s.size())
	{
		++i;
	}

	
	s.erase(0, i+1);

	return resultf;
}

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	const std::vector<std::string> fileds{"byr","iyr","eyr","hgt","hcl","ecl","pid","cid"};


	std::string line;
	int validpassnr = 0;
	std::vector<std::string> passfileds;
	int passnum = 0;
	int j = 0;
	while (!in.eof())
	{
		std::getline(in, line);
		//std::cout << line << std::endl;
		if (line.empty())
		{

			//for (auto i = passfileds.begin(); i != passfileds.end(); ++i)
			//{
			//	auto it = std::find(fileds.begin(), fileds.end(), *i);
			//	if (it != passfileds.end())
			//		++passnum;
			//}
			auto it = std::find(passfileds.begin(), passfileds.end(), fileds[fileds.size() - 1]);
			if (it == passfileds.end())
				++passnum;
			if (passnum == 8)
				++validpassnr;
			passfileds.clear();
			passnum = 0;
			++j;
		}
		while (!line.empty())
		{
			std::string passfiled = extractpassFiled(line);
			passfileds.push_back(passfiled);
			auto it = std::find(fileds.begin(), fileds.end(), passfiled);
			if (it != fileds.end())
				++passnum;
		}

	}

	
	std::cout << validpassnr ;
	return 0;
}
