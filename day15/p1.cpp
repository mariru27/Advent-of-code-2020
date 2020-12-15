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

int findnr(std::vector<int> n, int val)
{
	for (int i = n.size() - 2; i >=0; --i)
	{
		if (n[i] == val)
			return i;
	}
	return -1;
}

int computeNumbers(std::vector<int> numbers)
{
	int recentlySpoken = 0;


	for (int i = numbers.size() - 1; i < 2020; ++i)
	{
		recentlySpoken = numbers[i];
		//auto it = std::find(numbers.rbegin() + 1, numbers.rend() , recentlySpoken);
		int index = findnr(numbers, recentlySpoken);
		if (index != -1)
		{
			recentlySpoken = i - index;
			numbers.push_back(recentlySpoken);
		}
		else
			numbers.push_back(0);
	}
	return numbers[numbers.size() - 2];
}

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	std::vector<int> numbers;
	std::string line;
	
	in >> line;

	while (!line.empty()) 
	{
		int nr = mynamespace::extractFirstNumber(line);
		numbers.push_back(nr);
	}

	std::cout << computeNumbers(numbers);

	return 0;
}
