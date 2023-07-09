#include "Bureaucrat.hpp"
#include "Form.hpp"


void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	try {
		Bureaucrat b("Ana", 1);
		std::cout << b << "\n";
		b.inc();
		std::cout << "-> increase\n";
		std::cout << b << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	try {
		Bureaucrat b("Ana", -1);
		std::cout << b << "\n";
		b.inc();
		std::cout << "-> increase\n";
		std::cout << b << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";
	try {
		Bureaucrat b("Ana", 50);
		std::cout << b << "\n";
		b.inc();
		std::cout << "-> increase\n";
		std::cout << b << "\n";
		b.dec();
		std::cout << "-> decrease\n";
		std::cout << b << "\n";
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main ()
{
	Form o;
	std::cout << o.getName() << "\n";
	// test1();
	// test2();
	// test3();
	return (0);
}