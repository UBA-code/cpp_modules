#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << " love having extra bacon for my\
7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl << std::endl;
}
void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\
years whereas you started working here since last month.";
	std::cout << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	func functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (; i < 4 && arr[i].compare(level); i++)
		;
	switch (i)
	{
		case 0:
			(this->*functions[0])();
		case 1:
			(this->*functions[1])();
		case 2:
			(this->*functions[2])();
		case 3:
		{
			(this->*functions[3])();
			break;
		}
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
