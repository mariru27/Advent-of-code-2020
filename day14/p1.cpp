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

std::string frombase10tobase2(long long int nr,long long int size)
{
	std::string result;
	long long int i = 0;
	while (i != size)
	{
		result += '0';
		++i;
	}

	i = result.size() - 1;
	while (nr != 0 && i >= 0)
	{
		if (nr % 2 == 1)
			result[i] = '1';
		else
			result[i] = '0';
		nr /= 2;
		--i;
	}
	return result;

}

std::string applyMask(std::string mask, std::string value)
{
	std::string result;
	long long int i = 0;
	while (i != mask.size())
	{
		result += '0';
		++i;
	}


	i = mask.size() - 1;
	while (i >= 0)
	{
		if (mask[i] == 'X')
			result[i] = value[i];
		if (mask[i] == '1' || mask[i] == 0)
			result[i] = mask[i];
		--i;
	}
	return result;
}

long long int frombase2to10(std::string s)
{
	long long int result = 0;
	for (long long int i = s.size() - 1; i >= 0; --i)
	{
		long long int paw = std::pow(2, s.size() - 1 - i);
		long long int bit = s[i] - '0';
		result += paw * bit;
	}

	return result;
}

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	std::string line;
	std::string mask, wmask;
	std::string wvalue, value;
	std::unordered_map<long long int, long long int> memory;
	bool readmask = false;

	while (!in.eof()) 
	{
		std::string c;
		if (readmask == true)
		{
			mask = value;
			readmask = false;
		}else
			in >> wmask >> c >> mask;

		while (true)
		{
			if (in.eof())
				break;
			in >> wvalue >> c >> value;
			if (wmask == wvalue)
			{
				readmask = true;
				break;
			}
			else
			{
				long long int valueDec = std::stoi(value);
				long long int index = mynamespace::extractFirstNumber(wvalue);

				std::string valuebase2 = frombase10tobase2(valueDec, mask.size() );
				std::string result = applyMask(mask, valuebase2);
				long long int resultbase10 = frombase2to10(result);
				memory[index] = resultbase10;
			}
		}


	}
	long long int sum = 0;
	for (auto i = memory.begin(); i != memory.end(); ++i)
	{
		sum += i->second;
	}
	std::cout << sum;
	return 0;
}
