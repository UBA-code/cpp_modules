#include "iostream"
#include "PmergeMe.hpp"

void	parse(char **av)
{
	for (int i = 0; av[i]; i++)
	{
		for (int x = 0; av[i][x]; x++)
		{
			if (isdigit(av[i][x]) && av[i][x + 1] && !isdigit(av[i][x + 1]))
				throw (std::logic_error("Unvalid argument: " + std::string(av[i])));
			if (av[i][x] == '+' && !isdigit(av[i][x + 1]))
				throw (std::logic_error("Unvalid argument: " + std::string(av[i])));
			if (av[i][x] != '+' && !isdigit(av[i][x]))
				throw (std::logic_error("Unvalid argument: " + std::string(av[i])));
		}
	}
}
int main (int ac, char **av)
{
	try
	{
		if (ac < 2)
			throw (std::logic_error("Invalid arguments"));
		(void)av;
		// std::cout << (double)clock() / CLOCKS_PER_SEC << "\n";
		pMergeMe(av + 1, VECTOR);
		pMergeMe(av + 1, DEQUE);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}
