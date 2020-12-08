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

std::string instruction;
int value;
int accumulator = 0;
int i = 0;

struct ins {
	std::string instruction;
	int value = 0;
	bool visited = false;
	int position = 0;
};
std::vector<ins> instructions;
ins instructionStruct;

bool executeIntructions(std::vector<ins> instructions)
{
	i = 0;
	accumulator = 0;
	while (i < instructions.size() )
	{
		if (instructions[i].visited == true)
			break;
		
		if (instructions[i].instruction == "acc")
		{
			//instructions[i].position = i;
			instructions[i].visited = true;
			accumulator += instructions[i].value;
			++i;
			continue;

		}
		if (instructions[i].instruction == "nop")
		{
			//instructions[i].position = i;
			instructions[i].visited = true;
			++i;

			continue;
		}

		if (instructions[i].instruction == "jmp")
		{
			//instructions[i].position = i;
			instructions[i].visited = true;
			i += instructions[i].value;


		}

	}
	if (i  == instructions.size() )
		return true;
	else
	{
		return false;
	}

}

std::vector<ins> findinst(std::string s)
{
	std::vector<ins> v;

	for (auto i = instructions.begin(); i != instructions.end(); ++i)
	{
		if (i->instruction == s)
			v.push_back(*i);
	}
	return v;

}


int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");


	while (!in.eof())
	{
		in >> instruction >> value;
		
		instructionStruct.value = value;
		instructionStruct.instruction = instruction;
		
		instructions.push_back(instructionStruct);
		instructions[instructions.size() - 1].position = instructions.size() - 1;
	}

	std::vector<ins> nops = findinst("nop");
	std::vector<ins> jumps = findinst("jmp");
	ins rem;
	bool findResult = false;
	for (auto j = nops.begin(); j != nops.end(); ++j)
	{
		rem = *j;
		instructions[j->position].instruction = "jmp";
		accumulator = 0;
		if (executeIntructions(instructions) == true)
		{
			findResult = true;
			break;
		}
		else
		{
			instructions[j->position].instruction = "nop";
		}

	}
	if (findResult == false)
	{

	for (auto j = jumps.begin(); j != jumps.end(); ++j)
	{
		rem = *j;
		instructions[j->position].instruction = "nop";
		accumulator = 0;
		if (executeIntructions(instructions) == true)
		{
			break;
		}
		else
		{
			instructions[j->position].instruction = "jmp";
		}

	}
	}



	std::cout << accumulator;



	return 0;
}
