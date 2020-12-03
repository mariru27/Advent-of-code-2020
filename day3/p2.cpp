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
	int tree1 = 0;
	while (i < v.size() - 1)
	{
		
		j = j + 3;
		++i;

		if (v[i][j % row.size()] == '#')
			++tree1;
		
	}

	i = 0;
	j = 0;
	int tree2 = 0;
	while (i < v.size() - 1)
	{

		j = j + 1;
		++i;

		if (v[i][j % row.size()] == '#')
			++tree2;

	}

	i = 0;
	j = 0;
	int tree3 = 0;

	while (i < v.size() - 1)
	{

		j = j + 5;
		++i;

		if (v[i][j % row.size()] == '#')
			++tree3;

	}

	i = 0;
	j = 0;
	int tree4 = 0;

	while (i < v.size() - 1)
	{

		j = j + 7;
		++i;

		if (v[i][j % row.size()] == '#')
			++tree4;

	}

	i = 0;
	j = 0;
	int tree5 = 0;

	while (i < v.size() - 1)
	{

		j = j + 1;
		i = i + 2;

		if (v[i][j % row.size()] == '#')
			++tree5;

	}

	std::cout << tree1 * tree2 * tree3 * tree4 * tree5;
	return 0;
}
