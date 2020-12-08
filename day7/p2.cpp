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

struct Node {
	std::string parent;
	std::string current;
	int val;
	bool operator==(const Node& other) { return current == other.current && parent == other.parent && val == other.val; };
};
std::unordered_map<std::string, int> bags;
std::unordered_map<std::string, std::vector<Node>> colorsbags;
std::unordered_map<std::string, std::string> parentsChildcolor;
std::string shinygold = "shiny gold";

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	std::string line;

	while (!in.eof())
	{
		std::getline(in, line);
		int linesize = line.size();
		std::string firstcolorbag{};
		bool isfirstcolor = false;
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
				color = mynamespace::getstringToAnum(line, itbags.first);
				line.erase(0, itbags.second.size());
			}
			line.erase(0, 1);

			bags[color] = nrofBag;
			if (nrofBag == -1)
				nrofBag = 0;
			if (color == "contain no other")
				color = "";
			if (isfirstcolor == true)
			{
				firstcolorbag = color;
			}
			else
			{
				if (color != "")
				{
					parentsChildcolor[color] = firstcolorbag;
				}
				Node p;
				p.current = color;
				p.parent = firstcolorbag;
				p.val = nrofBag;


				if (color != "")
				{
					colorsbags[firstcolorbag].push_back(p);
				}
			}
		}
	}

	std::set<std::string> parents;
	int bagsum = 0;
	std::unordered_map <std::string, int> chidsbagsum;
	std::vector<Node> visited;
	std::stack <Node> s;
	Node findColor{ "", "shiny gold",1 };
	s.push(findColor);


	while (!s.empty())
	{
		findColor = s.top();
		bool visitedchild = false;

		for (auto i = colorsbags[findColor.current].begin(); i != colorsbags[findColor.current].end(); ++i)
		{

			if (std::find(visited.begin(), visited.end(), *i) == visited.end())
			{
				visitedchild = true;
				visited.push_back(*i);
				s.push(*i);
			}
		}
		if (!visitedchild)
		{
			int sum = 0;
			sum = (1 + chidsbagsum[findColor.current]) * findColor.val;

			s.pop();
			if (s.empty())
			{
				std::cout << sum - 1;
				break;
			}
			chidsbagsum[findColor.parent] += sum;

		}

	}
	return 0;
}
