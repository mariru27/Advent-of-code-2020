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

int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");





	std::string instruction;
	int value;
	int accumulator = 0;
	
	struct ins {
		std::string instruction;
		int value = 0;
		bool visited = false;
	};
	std::vector<ins> instructions;
	ins instructionStruct;
	while (!in.eof())
	{
		in >> instruction >> value;
		
		instructionStruct.value = value;
		instructionStruct.instruction = instruction;
		instructions.push_back(instructionStruct);
	}

	int i = 0;
	while (instructions[i].visited == false)
	{
		if (instructions[i].instruction == "acc")
		{
			instructions[i].visited = true;
			accumulator += instructions[i].value;
			++i;
			continue;

		}
		if (instructions[i].instruction == "nop")
		{
			instructions[i].visited = true;
			++i;

			continue;
		}
			
		if (instructions[i].instruction == "jmp")
		{
			instructions[i].visited = true;
			i += instructions[i].value;

			
		}

	}



	std::cout << accumulator;



	return 0;
}
