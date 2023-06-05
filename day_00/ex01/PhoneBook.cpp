#include "PhoneBook.hpp"

bool check_empty(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ' && str[i] != '	')
			return (1);
	return (0);
}

int	is_degits(std::string s)
{
	for (int i = 0; i < (int)s.length(); i++)
		if (!isdigit(s[i]) && s[i] != '+')
			return (0);
	return (1);
}

void PhoneBook::add()
{
	std::string arr[5] = {"first name", "last name", "nick name", "phone number", "darkest secret"};
	std::string str;

	if (this->i == 8)
		this->i = 0;
	int i = 0;
	while (i < 5)
	{
		this->contacts[this->i].set_value(5, "");
		std::cout << "\033[0;36m" << arr[i] << ": \033[0;37m";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return ;
		if (str.length() > 0 && check_empty(str))
		{
			if (i == 3 && !is_degits(str))
			{
				std::cerr << "unvalid phone number" << std::endl;
				continue ;
			}
			this->contacts[this->i].set_value(i, str);
		}
		else
		{
			std::cerr << "\033[0;31mempty fild\033[0;37m" << std::endl;
			continue ;
		}
		i++;
	}
	++(this->i);
}

void PhoneBook::search()
{
	std::string index;
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
	std::getline(std::cin, index);
	if (std::cin.eof())
		return ;
	if (index.empty())
		return;
	for (int i = 0; index[i]; i++)
		if (!isdigit(index[i]))
		{
			std::cerr << "\033[0;31mnon degit value\033[0;37m" << std::endl;
			return;
		}
	if (std::stoi(index) > 7 || this->contacts[std::stoi(index)].get_value(5) != "filled")
	{
		std::cerr << "\033[0;31mout of range\033[0;37m" << std::endl;
		return;
	}
	this->list(std::stoi(index));
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
	std::cout << std::right << std::setw(10) << temp << "|";
}

PhoneBook::PhoneBook()
{
	std::cout << "constructor called" << std::endl;
	this->i = 0;
}
