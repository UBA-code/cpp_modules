#include "iostream"
#include "RPN.hpp"
#include <vector>

int main(int ac, char **av)
{
	try {
		if (ac != 2)
			throw (std::logic_error("Invalid argumnets"));
		std::string a(av[1]);

		rpn(a);
	}
	catch (const std::exception& err) {
		std::cout << "Error: " << err.what() << "\n";
		return (1);
	}
	return (0);
}
