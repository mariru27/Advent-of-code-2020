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

	for (int i = 0; i < v.size() - 2; ++i)
	{
		for (int j = i + 1; j < v.size() - 1; ++j)
		{
			for (int k = j + 1; k < v.size(); ++k)
			{
				int sum = v[j] + v[i];
				if (sum + v[k] == 2020)
				{
					std::cout << v[i] << " " << v[j] << " " << v[k] << std::endl;
					int prod = v[j] * v[i];
					std::cout << "produs: " << prod*v[k];
					break;
				}
			}
		}
	}

	return 0;
}
