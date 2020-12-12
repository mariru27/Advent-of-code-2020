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

int wayPx = 10, wayPy = 1;
int pointX = 0, pointY = 0;



void rotateLeft()
{
	std::swap(wayPx, wayPy);
	wayPx *= -1;
}

void rotateRight()
{
	std::swap(wayPx, wayPy);
	wayPy *= -1;
}


void moveShip(char rule, int nr)
{
	pointX += nr * wayPx;
	pointY += nr * wayPy;
}


int currentPos = 2;
void moveWayPoint(char rule, int nr)
{

	bool moveforward = true;
	while (moveforward == true)
	{
		moveforward = false;
		switch (rule)
		{
		case 'N': {
			wayPy += nr;
			continue;

		};
		case 'S': {
			wayPy -= nr;
			continue;

		};
		case 'E': {
			wayPx += nr;
			continue;

		}
		case 'W': {
			wayPx -= nr;
			continue;

		}
		case 'L': {
			int num = nr / 90;

			for (int i = 1; i <= num; ++i)
			{
				rotateLeft();
			}
			continue;
		}
		case 'R': {
			int num = nr / 90;

			for (int i = 1; i <= num; ++i)
			{
				rotateRight();
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
		if (r[i].first == 'F')
		{
			moveShip(r[i].first, r[i].second);
		}
		else
		{
			moveWayPoint(r[i].first, r[i].second);
		}
	}
	std::cout << "distance: " << abs(pointX) + abs(pointY);
	return 0;
}
