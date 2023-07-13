#include "Bureaucrat.hpp"
#include "Form.hpp"


void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	try {
		Bureaucrat b("Bureaucrat_1", 1);
		Form o("Form_1", 5, 2);
		try {
			o.beSigned(b);
		}
		catch (std::exception & err)
		{
			std::cerr << "error: " << err.what();
		}
		std::cout << o;
		b.signForm(o);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what();
	}
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	try {
		Bureaucrat b("Bureaucrat_2", 0);
		Form o("Form_2", -1, 2);
		try {
			o.beSigned(b);
		}
		catch (std::exception & err)
		{
			std::cerr << "error: " << err.what();
		}
		std::cout << o;
		b.signForm(o);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what();
	}
	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";
	try {
		Bureaucrat b("Bureaucrat_2", 10);
		Form o("Form_2", 10, 2);
		try {
			o.beSigned(b);
		}
		catch (std::exception & err)
		{
			std::cerr << "error: " << err.what();
		}
		std::cout << o;
		b.signForm(o);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what();
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