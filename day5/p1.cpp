#include<iostream>
#include<fstream>
#include<vector>
#include <string> 
#include<unordered_map>
#include <algorithm>    
#include "mynamespace.h"



int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");

	std::string line;
	int res1 = 0, res2 = 0;
	int maxid = -1;
	while (in >> line)
	{
		/*std::getline(in, line);*/
		std::string rules = line.substr(0, 7);
		int front = 0, back = 127;
		int mid = 0;
		int i = 0;
		while (i < rules.size())
		{
			mid = front + (back - front) / 2;
			if (rules[i] == 'F')
			{
				back = mid - 1;
			}
			if (rules[i] == 'B')
			{
				front = mid + 1;
			}

			++i;
		}
		if (rules[rules.size() - 1] == 'F')
			res1 = front;
		else
			res1 = back;

		std::string rules2 = line.substr(7, line.size() - 7);
		int left = 0, right = 7;
		int mid2 = 0;
		int j = 0;
		while (j < rules2.size())
		{
			mid2 = left + (right - left) / 2;
			if (rules2[j] == 'R')
			{
				left = mid2 + 1;
			}
			if (rules2[j] == 'L')
			{
				right = mid2 - 1;
			}

			++j;
		}
		if (rules2[rules2.size() - 1] == 'L')
			res2 = left;
		else
			res2 = right;

		if (maxid < (res1 * 8) + res2)
			maxid = (res1 * 8) + res2;
	}
	//std::cout << res1 << " " << res2 << std::endl;
	//std::cout << (res1 *8) + res2;
	std::cout << maxid;
	
	return 0;
}
