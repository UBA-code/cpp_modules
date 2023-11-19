#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw (std::invalid_argument("unvalid arguments"));
		btc bitcoin("./data.csv");

		bitcoin.processInput(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}