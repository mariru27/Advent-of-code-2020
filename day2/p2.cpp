#include<iostream>
#include<fstream>
#include<vector>
#include <string> 



int findnr(std::string &s)
{
	int i = 0;
	int nr = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nr = nr * 10 + (s[i] - '0');
		++i;
	}
	if (s[i] == '-')
		++i;
	if (s[i] == ' ')
		++i;
	s.erase(0, i );
	return nr;
}



int main()
{
	std::ifstream in;
	std::ofstream out;
	in.open("in.txt");
	out.open("out.txt");

	std::string policyPassword;
	int validPasswords = 0;

	while (std::getline(in, policyPassword))
	{
		int leastAp = findnr(policyPassword);
		int mostAp = findnr(policyPassword);
		
		char c = policyPassword[0];
		policyPassword.erase(0, 3);

		int timesApC = 0;

		if (policyPassword[leastAp - 1] == c)
			++timesApC;
		if (policyPassword[mostAp - 1] == c)
			++timesApC;

		if (timesApC == 1)
			++validPasswords;
	}

	std::cout << validPasswords;

	return 0;
}
