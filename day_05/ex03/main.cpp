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
		Bureaucrat bureaucrat("ash", 1);
		ShrubberyCreationForm form1("Shrubbery");
		RobotomyRequestForm form2("Robotomy");
		PresidentialPardonForm form3("President");

		std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::string err) {
		std::cout << "Error: " << err << std::endl;
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
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::string err) {
		std::cout << "Error: " << err << std::endl;
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
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::string err) {
		std::cout << "Error: " << err << std::endl;
	}
	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main ()
{
	try {
		Intern l;
		AForm *x = l.makeForm("Shrubbery Creation", "UBA");

		std::cout << x->getName() << "\n";
	}
	catch (std::exception& err)
	{
		std::cerr << "error: " << err.what();
	}
	// test1();
	// test2();
	// test3();
	return (0);
}
