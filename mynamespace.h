#pragma once
#include<string>
#include<iostream>

namespace mynamespace
{
	
	std::string extractStringToc(std::string& s, char c)
	{
		std::string result;
		int i = 0;
		while (i < s.size() && s[i] != c)
		{
			++i;
		}
		result = s.substr(0, i);
		s.erase(0, i + 1);

		return result;
	}

	int extractFirstNumber(std::string& s)
	{
		std::string result;
		int i = 0;	
		while (i < s.size())
		{
			if (s[i] >= '0' && s[i] <= '9')
				break;
			++i;
		}

		int a = i;
		while (i < s.size() && s[i] >= '0' && s[i] <= '9')
		{
			++i;
		}

		result = s.substr(a, i-a);
		s.erase(0, i);
		int nr = std::stoi(result);
		return nr;
	}
	
	
}
