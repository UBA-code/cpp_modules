#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	try {
		Bureaucrat bureaucrat("ash", 1);
		ShrubberyCreationForm form1("Shrubbery");
		RobotomyRequestForm form2("Robotomy");
		PresidentialPardonForm form3("President");

		std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
		try
		{
			bureaucrat.signForm(form1);
			bureaucrat.executeForm(form1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
		try
		{
			bureaucrat.signForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	try {
		Bureaucrat bureaucrat("ash", 6);
		ShrubberyCreationForm form1("Shrubbery");
		RobotomyRequestForm form2("Robotomy");
		PresidentialPardonForm form3("President");

		std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
		try
		{
			bureaucrat.signForm(form1);
			bureaucrat.executeForm(form1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
		try
		{
			bureaucrat.signForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";
	try {
		Bureaucrat bureaucrat("ash", 30);
		ShrubberyCreationForm form1("Shrubbery");
		RobotomyRequestForm form2("Robotomy");
		PresidentialPardonForm form3("President");

		std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
		try
		{
			bureaucrat.signForm(form1);
			bureaucrat.executeForm(form1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
		try
		{
			bureaucrat.signForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
			bureaucrat.executeForm(form2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
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
