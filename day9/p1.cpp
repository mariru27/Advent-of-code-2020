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
	std::vector<unsigned long long int> numbers;

	while (!in.eof())
	{
		unsigned long long int nr;
		in >> nr;

		numbers.push_back(nr);

	}
	

	int preambleLength = 25;
	bool findsum = true;
	int i = preambleLength ;
	int j = 0;
	unsigned long long int sum = 0;

	while (findsum == true)
	{
		findsum = false;
		j = i - preambleLength;
		for (j ; j < i ; ++j)
		{
			for (auto l = j + 1; l < i; ++l)
			{

				if (j == l)
					continue;
				sum = numbers[j] + numbers[l];
				if (sum == numbers[i])
				{
					findsum = true;
					break;
				}
			}
			if (findsum == true)
				break;
		}
		
		++i;

	}
	std::cout << numbers[i - 1];



	
	return 0;
}
