#include "stdio.h"
#include "iostream"
#include <ctype.h>

int main(int ac, char **av)
{
	if (ac != 1)
	{
		std::string joindStings = "";

		int i = 1;

		while (i < ac)
		{
			joindStings = joindStings + av[i];
			i++;
		}

		for (int i = 0; i < (int)joindStings.length(); i++)
			std::cout << (char)toupper(joindStings[i]);
		std::cout << "\n";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return 0;
}
