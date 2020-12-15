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
#include<iterator>

std::unordered_map<long long int, long long int> memory;
long long int k = 1;
long long int recentlySpoken = 0;
long long int lastnr = 0;
long long int lastAge = 0;

long long int computeNumbers()
{

	while (k <= 30000000)
	{

		if (lastAge + 1 == k)
		{
			lastnr = 0;
			lastAge = k - memory[0];
			memory[0] = k;
			++k;
		}
		else
		{
			lastnr = lastAge;
			lastAge = k - memory[lastnr];
			memory[lastnr] = k;
			++k;
		}
		
	}

	return lastnr;
}

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	std::string line;

	in >> line;

	while (!line.empty())
	{
		long long int nr = mynamespace::extractFirstNumber(line);
		memory[nr] = k;
		lastnr = nr;
		lastAge = k;
		++k;
		
	}

	std::cout << computeNumbers();

	return 0;
}
