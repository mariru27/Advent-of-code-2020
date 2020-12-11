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


int countSeats(bool s[10])
{
	int c = 0;
	for (auto i = 1; i <= 8; ++i)
	{
		if (s[i] == true)
			++c;
	}
	return c;
}


void updateGrid(std::vector<std::string>& firstGrid, std::vector<std::string>& secondGrid)
{
	int occupiedSeat = 0;
	int freeSeats = 0;
	int distance = std::max(firstGrid.size(), firstGrid[0].size());
	for (auto j = 0; j < firstGrid.size(); ++j)
	{
		for (auto l = 0; l < firstGrid[j].size(); ++l)
		{

			bool seeOccupiedSeats[10]{};
			bool seeEmptySeats[10]{};

			for (int k = 1; k < distance; ++k)
			{
				//1
				if (seeEmptySeats[1] == false && j >= k && l >=k && firstGrid[j - k][l - k] == '#' )
				{
					seeOccupiedSeats[1] = true;

				}
				if(seeOccupiedSeats[1] == false && j >=k && l >=k && (firstGrid[j - k][l - k] == 'L' || firstGrid[j - k][l - k] == '0'))
					seeEmptySeats[1] = true;
			
				//2
				if (seeEmptySeats[2] == false && j >= k && firstGrid[j - k][l] == '#')
				{
					seeOccupiedSeats[2] = true;
				}
				if (seeOccupiedSeats[2] == false && j >= k && (firstGrid[j - k][l] == 'L' || firstGrid[j - k][l] == '0'))
					seeEmptySeats[2] = true;

				//3
				if (seeEmptySeats[3] == false && j >= k && l + k < firstGrid[j].size() && firstGrid[j - k][l + k] == '#')
				{
					seeOccupiedSeats[3] = true;
				}
				if (seeOccupiedSeats[3] == false && j >= k && l + k < firstGrid[j].size() && (firstGrid[j - k][l + k] == 'L' || firstGrid[j - k][l + k] == '0'))
					seeEmptySeats[3] = true;

				//4
				if (seeEmptySeats[4] == false && l >= k && firstGrid[j][l - k] == '#')
				{
					seeOccupiedSeats[4] = true;
				}
				if (seeOccupiedSeats[4] == false && l >= k && (firstGrid[j][l - k] == 'L' || firstGrid[j][l - k] == '0'))
					seeEmptySeats[4] = true;

				//5
				if (seeEmptySeats[5] == false && l + k < firstGrid[j].size() && firstGrid[j][l + k] == '#')
				{
					seeOccupiedSeats[5] = true;
				}
				if (seeOccupiedSeats[5] == false && l + k < firstGrid[j].size() && (firstGrid[j][l + k] == 'L' || firstGrid[j][l + k] == '0'))
					seeEmptySeats[5] = true;

				//6
				if (seeEmptySeats[6] == false && j + k < firstGrid.size() && l >= k &&firstGrid[j + k][l - k] == '#')
				{
					seeOccupiedSeats[6] = true;
				}
				if (seeOccupiedSeats[6] == false && j + k < firstGrid.size() && l >= k && (firstGrid[j + k][l - k] == 'L' || firstGrid[j + k][l - k] == '0'))
					seeEmptySeats[6] = true;

				//7
				if (seeEmptySeats[7] == false && j + k < firstGrid.size() && firstGrid[j + k][l] == '#')
				{
					seeOccupiedSeats[7] = true;
				}
				if (seeOccupiedSeats[7] == false && j + k < firstGrid.size()  && (firstGrid[j + k][l] == 'L' || firstGrid[j + k][l] == '0'))
					seeEmptySeats[7] = true;

				//8
				if (seeEmptySeats[8] == false && l + k < firstGrid[j].size() && j + k < firstGrid.size() && firstGrid[j + k][l + k] == '#')
				{
					seeOccupiedSeats[8] = true;
				}
				if (seeOccupiedSeats[8] == false  && l + k < firstGrid[j].size() && j + k < firstGrid.size() && (firstGrid[j + k][l + k] == 'L' || firstGrid[j + k][l + k] == '0'))
					seeEmptySeats[8] = true;
			}

	
			if (firstGrid[j][l] == 'L' && countSeats(seeEmptySeats) == 8)
			{
				secondGrid[j][l] = '#';
			}
			if (firstGrid[j][l] == '#' && countSeats(seeOccupiedSeats) >= 5)
			{
				secondGrid[j][l] = 'L';
			}
		}

	}
}

int countOccupiedSeats(std::vector<std::string> s)
{
	int countseats = 0;
	for (auto i = 0; i < s.size(); ++i)
	{
		for (auto j = 0; j < s[i].size(); ++j)
		{
			if (s[i][j] == '#')
				++countseats;
		}
	}
	return countseats;
}

void printvec(std::vector<std::string> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << std::endl;
		for (int j = 0; j < v[i].size(); ++j) 
		{
			std::cout << v[i][j] << " ";
		}
	}

}

bool thesame(std::vector<std::string> f, std::vector<std::string> s)
{
	int sizeg = 0;
	for (int i = 0; i < f.size(); ++i)
	{
		for (int j = 0; j < f[i].size(); ++j)
		{
			if (f[i][j] == s[i][j])
				++sizeg;
		}
	}
	return sizeg == s.size() * s[0].size();
}


int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	std::vector<std::string> firstGrid, secondGrid;
	std::string line;
	std::string firstline;
	//int nr = 12;
	int nr = 92 + 2;

	for (auto i = 0; i < nr; ++i)
	{
		firstline.push_back('0');
	}
	firstGrid.push_back(firstline);
	secondGrid.push_back(firstline);

	while (!in.eof())
	{
		
		in >> line;
		line.push_back('0');
		line = "0" + line;
		firstGrid.push_back(line);
		secondGrid.push_back(line);
	}

	firstGrid.push_back(firstline);
	secondGrid.push_back(firstline);

	//for (int i = 1; i <= 5; ++i)
	//{
	//	
	//	updateGrid(firstGrid, secondGrid);
	//	firstGrid = secondGrid;
	//	//std::cout << std::endl;
	//	//std::cout << std::endl << i;
	//	//
	//	//printvec(firstGrid);
	//}
	

	do  
	{
		firstGrid = secondGrid;
		updateGrid(firstGrid, secondGrid);

	} while (thesame(firstGrid, secondGrid) == false);
	printvec(firstGrid);
	
	std::cout << countOccupiedSeats(firstGrid);

	return 0;
}
