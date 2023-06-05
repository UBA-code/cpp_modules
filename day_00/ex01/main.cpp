#include "PhoneBook.hpp"

int main()
{
	PhoneBook phone;
	std::string cmd;

	while (1)
	{
		std::cout << "Enter cmd: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (check_empty(cmd))
		{
			if (cmd == "ADD")
				phone.add();
			else if (cmd == "SEARCH")
				phone.search();
			else if (cmd == "EXIT")
				exit(0);
			else
				std::cout << "\033[0;31mcommand not found\033[0;37m" << std::endl;
		}
	}
	return 0;
}
