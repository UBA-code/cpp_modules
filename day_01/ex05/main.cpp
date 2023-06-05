#include "iostream"
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl h;

		h.complain(av[1]);
	}
	else
		std::cerr << "check args please" << std::endl;
	return 0;
}
