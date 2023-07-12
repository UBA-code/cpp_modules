#include "Intern.hpp"

std::string	getLower(std::string str)
{
	std::string tmp = "";
	for (int i = 0; i < (int)str.length(); i++)
		tmp += tolower(str[i]);
	return (tmp);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string	arr[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < (int)arr->length(); i++)
		if (getLower(arr[i]) == getLower(name))
			
}