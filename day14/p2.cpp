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

std::string applyMaskforAddress(std::string mask, std::string address)
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
		if (mask[i] == '0')
			result[i] = address[i];
		if (mask[i] == '1')
			result[i] = '1';
		if (mask[i] == 'X')
			result[i] = 'X';
		--i;
	}
	return result;
}

std::string applyMaskforValue(std::string mask, std::string value)
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

std::vector<long long int> xPositions(std::string s)
{
	std::vector<long long int> result;
	for (auto i = s.begin(); i < s.end(); ++i)
	{
		if (*i == 'X')
			result.push_back(std::distance(s.begin(), i));
	}
	return result;
}


std::string completeX(std::string address, std::vector<long long int> positionsForPermutations, int i)
{

	for (int j = positionsForPermutations.size() - 1; j >= 0; --j)
	{
		if (i % 2 == 0)
			address[positionsForPermutations[j]] = '0';
		else
			address[positionsForPermutations[j]] = '1';
		i /= 2;
	}
	return address;
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

				//----work on address----
				std::string address = frombase10tobase2(index, mask.size());
				address = applyMaskforAddress(mask, address);
				std::vector<long long int> positionsForPermutations = xPositions(address);
				int nrPermutations = std::pow(2, positionsForPermutations.size());
				for (auto i = 0; i < nrPermutations ; ++i)
				{
					std::string currentAddress = completeX(address, positionsForPermutations, i);
					long long int currentAddressDec = frombase2to10(currentAddress);
					

					memory[currentAddressDec] = valueDec;
				}

				//memory[index] = resultbase10;


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
