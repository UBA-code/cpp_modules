#include "iostream"
#include "Harl.hpp"

int main(int ac, const char **av)
{
	Harl h;
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;
	if (ac != 2)
	{
		std::cerr << "check args please" << std::endl;
		return (1);
	}
	for (; i < 4; i++)
		if (!arr[i].compare(av[1]))
			break;
	switch (i)
	{
		case 0:
			h.complain("DEBUG");
		case 1:
			h.complain("INFO");
		case 2:
			h.complain("WARNING");
		case 3:
		{
			h.complain("ERROR");
			break;
		}
		default:
			std::cerr << "unvalid argumnet" << std::endl;
	}
	return 0;
}
