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


enum Actions
{
	N = 1,E,S,W,R,F
};

int x = 0, y = 0;
int currentPos = 2;


void move(char rule, int nr)
{
	bool moveforward = true;

	while (moveforward == true)
	{


		moveforward = false;
		switch (rule)
		{
		case 'N': {
			y += nr;
			continue;

		};
		case 'S': {
			y -= nr;
			continue;

		};
		case 'E': {
			x += nr;
			continue;

		}
		case 'W': {
			x -= nr;
			continue;

		}
		case 'L': {
			if (currentPos - (nr / 90) >= 1)
				currentPos = currentPos - (nr / 90);
			else
				currentPos = (currentPos - (nr / 90)) + 4;
			switch (currentPos)
			{
			case 1: rule = 'N'; continue;
			case 2: rule = 'E'; continue;
			case 3: rule = 'S'; continue;
			case 4: rule = 'W'; continue;
			case 5: rule = 'L'; continue;
			case 6: rule = 'R'; continue;

			default:
				break;
			}
			continue;
		}
		case 'R': {
			if ((nr / 90) + currentPos > 4)
				currentPos = ((nr / 90) + currentPos) % 4;
			else
				currentPos = ((nr / 90) + currentPos);
			switch (currentPos)
			{
			case 1: rule = 'N'; continue;
			case 2: rule = 'E'; continue;
			case 3: rule = 'S'; continue;
			case 4: rule = 'W'; continue;
			case 5: rule = 'L'; continue;
			case 6: rule = 'R'; continue;

			default:
				break;
			}
			continue;

		}
		case 'F': {
			//position[currentPos] += nr;
			moveforward = true;
			switch (currentPos)
			{
			case 1: rule = 'N'; continue;
			case 2: rule = 'E'; continue;
			case 3: rule = 'S'; continue;
			case 4: rule = 'W'; continue;
			case 5: rule = 'L'; continue;
			case 6: rule = 'R'; continue;

			default:
				break;
			}

		}
		default:
			break;
		}
	}
}



int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	std::string line;
	Actions actions;
	int position[10]{};
	bool moveforward = false;
	char rule;
	int nr;

	std::vector<std::pair<char, int>> r;
	while (!in.eof()) 
	{
		

		in >> line;
		rule = line[0];
		line.erase(0, 1);
		nr = std::stoi(line);
		

		r.push_back(std::make_pair(rule, nr));

	}

	for (int i = 0; i < r.size(); ++i)
	{
		move(r[i].first, r[i].second);
	}
	std::cout << abs(x) << " " << abs(y) << std::endl;
	std::cout << "distance: " << abs(x) + abs(y);
	return 0;
}
