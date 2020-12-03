#include<iostream>
#include<fstream>
#include<vector>
#include <string> 



int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");


	std::vector<std::string> v;
	std::string row;
	while (in >> row)
	{
		v.push_back(row);
		
	}

	int i = 0, j = 0;
	int tree = 0;
	while (i < v.size() - 1)
	{
		
		j = j + 3;
		++i;

		if (v[i][j % row.size()] == '#')
			++tree;
		
	}

	std::cout << tree;
	return 0;
}
