#include<iostream>
#include<fstream>
#include<vector>
#include <string> 
#include<unordered_map>
#include <algorithm>    

std::pair<std::string, std::string> extractpassFiled(std::string &s)
{
	std::pair<std::string, std::string> result;
	int i = 0;
	result.first = s.substr(0, 3);
	
	s.erase(0, 4);

	while (s[i] != ' ' && (i < s.size()))
	{
		++i;
	}

	result.second = s.substr(0, i);
	
	s.erase(0, i+1);

	return result;
}
const std::vector<std::string> fileds{ "byr","iyr","eyr","hgt","hcl","ecl","pid","cid" };
const std::vector<std::string> eclfileds{ "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };


int validatepss(std::unordered_map<std::string, std::string> p)
{
	int validnr = 0;
	for (auto i = p.begin(); i != p.end(); ++i)
	{
		//const std::string s = i->first;
		//switch (s)
		//{
		//case fileds[0]:
		//	int num = std::stoi(i->second);
		//default:
		//	break;
		//}
		if (i->first == "byr")
		{
			int num = std::stoi(i->second);
			if (num >= 1920 && num <= 2002)
				++validnr;
			continue;
		}
		if (i->first == "iyr")
		{
			int num = std::stoi(i->second);
			if (num >= 2010 && num <= 2020)
				++validnr;
			continue;

		}
		if (i->first == "eyr")
		{
			int num = std::stoi(i->second);
			if (num >= 2020 && num <= 2030)
				++validnr;
			continue;

		}
		if (i->first == "hgt")
		{
			std::string value = i->second;
			std::string hgt = i->second.substr(i->second.size() - 2, i->second.size() - 1);
			value.erase(value.size() - 2, value.size() - 1);
			int num = std::stoi(value);
			if (hgt == "cm" && num >= 150 && num <= 193)
			{
				++validnr;
			}
			if (hgt == "in" && num >= 59 && num <= 76)
			{
				++validnr;
			}
			continue;			
		}
		if (i->first == "hcl")
		{
			std::string value = i->second;
			if (value[0] == '#' && value.size() == 7)
			{
				value.erase(0, 1);
				int countd = 0;
				for (auto j = value.begin(); j != value.end(); ++j)
				{
					if ((*j >= '0' && *j <= '9') || (*j >= 'a' && *j <= 'f'))
					{
						++countd;
					}
				}
				if (countd == 6)
					++validnr;
			}
			continue;

		}
		if (i->first == "ecl")
		{
			auto it = std::find(eclfileds.begin(), eclfileds.end(), i->second);
			if (it != eclfileds.end())
				++validnr;
			continue;

		}
		if (i->first == "pid")
		{
			std::string value = i->second;
			int countd = 0;

			for (auto j = value.begin(); j != value.end(); ++j)
			{
				
				if ((*j >= '0' && *j <= '9'))
				{
					++countd;
				}
			}
			if (countd == 9 )
			{
				++validnr;
			}
			continue;

		}
		if (i->first == "cid")
		{
			++validnr;
		}
	}
	if (p.find(fileds[fileds.size() - 1]) == p.end())
		++validnr;
	return validnr;
}

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");


	std::string line;
	int validpassnr = 0;
	std::unordered_map<std::string, std::string> passfiledsKp;
	int passnum = 0;
	int j = 0;
	while (!in.eof())
	{
		std::getline(in, line);
		//std::cout << line << std::endl;
		if (line.empty())
		{
			if (passfiledsKp.find(fileds[fileds.size() - 1]) == passfiledsKp.end())
				++passnum;
			int validatenumber = validatepss(passfiledsKp);
			if (passnum == 8 && validatenumber == 8)
				++validpassnr;
			passfiledsKp.clear();
			passnum = 0;
			++j;
		}
		while (!line.empty())
		{
			std::pair<std::string, std::string> passfiled = extractpassFiled(line);
			//passfileds.push_back(passfiled);
			passfiledsKp[passfiled.first] = passfiled.second;
			auto it = std::find(fileds.begin(), fileds.end(), passfiled.first);
			if (it != fileds.end())
				++passnum;
		}

	}

	
	std::cout << validpassnr ;
	return 0;
}
