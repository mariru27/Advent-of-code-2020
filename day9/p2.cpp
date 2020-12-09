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
	

	unsigned long long int  min = 0, max = 0;
	unsigned long long int numberPartOne = 1930745883;
	//unsigned long long int numberPartOne = 127;
	bool findresult = false;

	for (int i = 0; i < numbers.size(); ++i)
	{
		unsigned long long int sum = 0;
		min = numbers[i];
		max = 0;
		for (int j = i; j < numbers.size(); ++j)
		{
			if (min > numbers[j])
				min = numbers[j];
			if (max < numbers[j])
				max = numbers[j];
			sum += numbers[j];
			if (numberPartOne == sum)
			{
				findresult = true;
				break;
			}
			if (sum > numberPartOne)
				break;
		}
		if (findresult == true)
			break;
		
	}
	std::cout << min + max;
	
	return 0;
}
