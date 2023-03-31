#include "PhoneBook.hpp"

bool check_empty(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ' && str[i] != '	')
			return (1);
	return (0);
}

void PhoneBook::add()
{
	std::string arr[5] = {"first name", "last name", "nick name", "phone number", "darkest secret"};
	std::string temp;

	if (this->i == 8)
		this->i = 0;
	for (int i = 0; i < 5; i++)
	{
		this->contacts[this->i].set_value(5, "");
		std::cout << "\033[0;36m" << arr[i] << ": \033[0;37m";
		std::getline(std::cin, temp);
		if (temp.length() > 0 && check_empty(temp))
			this->contacts[this->i].set_value(i, temp);
		else
		{
			std::cerr << "\033[0;31mempty fild\033[0;37m" << std::endl;
			return;
		}
	}
	++(this->i);
}

void PhoneBook::search()
{
	std::string temp;
	std::string str;

	std::cout << "\033[0;36m"
			  << std::right << std::setw(10) << "index"
			  << "|"
			  << std::right << std::setw(10) << "first name"
			  << "|"
			  << std::right << std::setw(10) << "last name"
			  << "|"
			  << std::right << std::setw(10) << "nick name"
			  << "|"
			  << "\033[0;37m" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].get_value(5) == "filled")
		{
			std::cout << std::right << std::setw(10) << i << "|";
			printStr(this->contacts[i].get_value(0));
			printStr(this->contacts[i].get_value(1));
			printStr(this->contacts[i].get_value(2));
			std::cout << "\033[0;37m" << std::endl;
		}
	}
	std::cout << "chose contact to list: ";
	std::getline(std::cin, temp);
	if (temp.empty())
		return;
	for (int i = 0; temp[i]; i++)
		if (!isdigit(temp[i]))
		{
			std::cerr << "\033[0;31mnon degit value\033[0;37m" << std::endl;
			return;
		}
	if (this->contacts[std::stoi(temp)].get_value(5) != "filled")
	{
		std::cerr << "\033[0;31mout of range\033[0;37m" << std::endl;
		return;
	}
	this->list(std::stoi(temp));
}

void PhoneBook::list(int index)
{
	std::string arr[5] = {"first name", "last name", "nick name", "phone name", "darkest secret"};

	for (int i = 0; i < 5; i++)
	{
		std::cout << "\033[0;34m";
		std::cout << arr[i] << ": \033[0;37m" << this->contacts[index].get_value(i) << std::endl;
	}
}

void printStr(std::string str)
{
	std::string temp;

	if (str.length() > 10)
	{
		temp = str.substr(0, 9);
		temp = temp + ".";
	}
	else
		temp = str;
	std::cout << std::right << std::setw(10) << temp;
}

PhoneBook::PhoneBook()
{
	this->i = 0;
}