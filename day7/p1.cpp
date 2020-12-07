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


void updateSet(std::set<int>& s, int val)
{

	if (s.find(val) == s.end())
	{
		
	}
	
}

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");


	std::unordered_map<std::string, int> bags;
	std::unordered_map<std::string, std::vector<std::string>> colorsbags;
	std::unordered_map<std::string, std::vector<std::string>> parentsChildcolor;
	std::string line;

	while (!in.eof())
	{
		std::getline(in, line);
		int linesize = line.size();
		std::string firstcolorbag{};
		bool isfirstcolor = false;
		//std::cout << std::endl;
		while (!line.empty())
		{
			
			int nrofBag{};
			if (linesize != line.size())
			{
				nrofBag = mynamespace::extractFirstNumber(line);
				isfirstcolor = false;
			}
			else
			{
				isfirstcolor = true;
			}
			if (line[0] == ',' || line[0] == '.' || line[0] == ' ')
				line.erase(0, 1);
			std::pair<int, std::string> itbag(0, " bag");
			std::pair<int, std::string> itbags(0, " bags");
			itbag.first = line.find(itbag.second);
			itbags.first = line.find(itbags.second);
			std::string color;
			if ((itbag.first < itbags.first) || itbags.first == -1)
			{
				color = mynamespace::getstringToAnum(line, itbag.first);
				line.erase(0, itbag.second.size());

			}
			else
			{
				color = mynamespace::getstringToAnum(line, itbags.first );
				line.erase(0, itbags.second.size());
			}			
			line.erase(0, 1);

			bags[color] = nrofBag;
			if (color == "contain no other")
				color = "";
			if (isfirstcolor == true)
			{
				firstcolorbag = color;
				//std::cout << firstcolorbag << " ->> ";
			}
			else
			{
				parentsChildcolor[color].push_back(firstcolorbag);
				//std::cout << color << " --- " << firstcolorbag << std::endl;
				colorsbags[firstcolorbag].push_back(color);
				//std::cout << color << ", ";
			}
			
		}


	}
	std::string findColor = "shiny gold";
	int nrparentsToRoot = 0;
	std::queue<std::string> q;
	q.push(findColor);
	//parentsChildcolor.find(findColor) != parentsChildcolor.end()
	std::set<std::string> parents;
	while (!q.empty())
	{
		//++nrparentsToRoot;
		findColor = q.front();
		parents.insert(findColor);
		q.pop();
		if (parentsChildcolor.find(findColor) != parentsChildcolor.end())
		{
			for (auto i = parentsChildcolor[findColor].begin(); i != parentsChildcolor[findColor].end(); ++i)
			{
				q.push(*i);
			}
		}
	}

	std::cout << parents.size() - 1;

	return 0;
}
