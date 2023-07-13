#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	try {
		Intern l;
		AForm *x = l.makeForm("Shrubbery Creation", "UBA");

		std::cout << x->getName() << "\n";
	}
	catch (std::exception& err)
	{
		std::cerr << "error: " << err.what();
	}
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	try {
		Intern l;
		AForm *x = l.makeForm("Robotomy Request", "HAHA");

		std::cout << x->getName() << "\n";
	}
	catch (std::exception& err)
	{
		std::cerr << "error: " << err.what();
	}
	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";
	try {
		Intern l;
		AForm *x = l.makeForm("Shrubbery", "UBA");

		std::cout << x->getName() << "\n";
	}
	catch (std::exception& err)
	{
		std::cerr << "error: " << err.what();
	}
	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main ()
{
	test1();
	test2();
	test3();
	return (0);
}
