#include<iostream>
#include<fstream>
#include<vector>

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");

	int value;
	std::vector<int> v;
	while (in >> value)
	{
		v.push_back(value);
	}

	for (int i = 0; i < v.size() - 1; ++i)
	{
		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[i] + v[j] == 2020)
			{
				std::cout << v[i] << " " << v[j] << std::endl;
				std::cout << "produs: " << v[i] * v[j];
				break;
			}
		}
	}

	return 0;
}
