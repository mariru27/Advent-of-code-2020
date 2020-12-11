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

void updateGrid(std::vector<std::string>& firstGrid, std::vector<std::string>& secondGrid)
{
	int occupiedSeat = 0;
	int freeSeats = 0;
	for (auto j = 0; j < firstGrid.size(); ++j)
	{

		for (auto l = 0; l < firstGrid[j].size(); ++l)
		{
			occupiedSeat = 0;
			freeSeats = 0;
			//1
			if (j >= 1 && l >=1 && firstGrid[j - 1][l - 1] == '#' )
			{
				++occupiedSeat;
			}
			if(j >=1 && l >=1 && (firstGrid[j - 1][l - 1] == 'L' || firstGrid[j - 1][l -1] == '.' || firstGrid[j - 1][l - 1] == '0'))
				++freeSeats;
			
			//2
			if (j >= 1 && firstGrid[j - 1][l] == '#')
			{
				++occupiedSeat;
			}
			if (j >= 1 && (firstGrid[j - 1][l] == 'L' || firstGrid[j-1][l] == '.' || firstGrid[j - 1][l] == '0'))
				++freeSeats;

			//3
			if (j >= 1 && l + 1 < firstGrid[j].size() && firstGrid[j - 1][l + 1] == '#')
			{
				++occupiedSeat;
			}
			if (j >= 1 && l + 1 < firstGrid[j].size() && (firstGrid[j - 1][l + 1] == 'L' || firstGrid[j-1][l+1] ==  '.' || firstGrid[j - 1][l + 1] == '0'))
				++freeSeats;
		
			//4
			if (l >= 1 && firstGrid[j][l - 1] == '#')
			{
				++occupiedSeat;
			}
			if (l >= 1 && (firstGrid[j][l - 1] == 'L' || firstGrid[j][l - 1] == '.' || firstGrid[j][l - 1] == '0'))
				++freeSeats;

			//5
			if (l + 1 < firstGrid[j].size() && firstGrid[j][l + 1] == '#')
			{
				++occupiedSeat;
			}
			if (l + 1 < firstGrid[j].size() && (firstGrid[j][l + 1] == 'L' || firstGrid[j][l+1] == '.' || firstGrid[j][l + 1] == '0'))
				++freeSeats;

			//6
			if (j + 1 < firstGrid.size() && l >= 1 &&firstGrid[j + 1][l - 1] == '#')
			{
				++occupiedSeat;
			}
			if (j + 1 < firstGrid.size() && l >= 1 && (firstGrid[j + 1][l - 1] == 'L' || firstGrid[j + 1][l - 1] == '.' || firstGrid[j + 1][l - 1] == '0'))
				++freeSeats;

			//7
			if (j + 1 < firstGrid.size() && firstGrid[j + 1][l] == '#')
			{
				++occupiedSeat;
			}
			if (j + 1 < firstGrid.size()  && (firstGrid[j + 1][l] == 'L' || firstGrid[j + 1][l] == '.' || firstGrid[j + 1][l] == '0'))
				++freeSeats;

			//8
			if (j + 1 < firstGrid.size() && l + 1< firstGrid[j].size() && firstGrid[j + 1][l + 1] == '#')
			{
				++occupiedSeat;
			}
			if (j + 1 < firstGrid.size() && l + 1 < firstGrid[j].size() && (firstGrid[j + 1][l + 1] == 'L' || firstGrid[j+1][l+1] == '.' || firstGrid[j + 1][l + 1] == '0'))
				++freeSeats;

	
			if (firstGrid[j][l] == 'L' && freeSeats == 8)
			{
				secondGrid[j][l] = '#';
			}
			if (firstGrid[j][l] == '#' && occupiedSeat >= 4)
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

	
	std::cout << countOccupiedSeats(firstGrid);

	return 0;
}
