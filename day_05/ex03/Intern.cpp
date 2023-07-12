#include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(Intern& obj){(void)obj;}
Intern& Intern::operator=(Intern& obj){
	(void)obj;
	return (*this);
}
Intern::~Intern(){}

std::string	getLower(std::string str)
{
	std::string tmp = "";
	for (int i = 0; i < (int)str.length(); i++)
		tmp += tolower(str[i]);
	return (tmp);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string	arr[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	AForm** arrObj = new AForm*[3];
	AForm* finalObj = 0;
	arrObj[0] = new ShrubberyCreationForm(target);
	arrObj[1] = new RobotomyRequestForm(target);
	arrObj[2] = new PresidentialPardonForm(target);
	for (int i = 0; i < (int)(sizeof(arr) / sizeof(std::string)); i++)
		if (getLower(arr[i]) == getLower(name))
			finalObj = arrObj[i]->clone(); 
	for (int x = 0; x < 3; x++)
		delete arrObj[x];
	delete[] arrObj;
	if (!finalObj)
		throw (Intern::unvalidName());
	std::cout << "Intern Creates " << finalObj->getName() << "\n";
	return (finalObj);
}
